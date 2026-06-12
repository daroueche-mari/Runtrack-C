#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

#include "music.h"

// ==========================================
// FONCTIONS D'AFFICHAGE ET COMPARAISON DE BAS NIVEAU
// ==========================================

void print_string(const char *str) 
{
    if (!str) return;
    int len = 0;
    while (str[len]) len++;
    write(1, str, len);
}

static void print_number(int n) 
{
    if (n == 0) {
        write(1, "0", 1);
        return;
    }
    char buffer[12];
    int i = 10;
    buffer[11] = '\0';
    while (n > 0 && i >= 0) {
        buffer[i--] = (n % 10) + '0';
        n /= 10;
    }
    print_string(&buffer[i + 1]);
}

int my_strcmp(const char *s1, const char *s2) 
{
    if (!s1 || !s2) return -1;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

static int my_atoi(const char *str) 
{
    int res = 0;
    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res;
}

// Pointeurs de fonctions pour les tris
static int compare_by_artist(AlbumItem *a, AlbumItem *b) { return my_strcmp(a->artist, b->artist); }
static int compare_by_title(AlbumItem *a, AlbumItem *b) { return my_strcmp(a->title, b->title); }
static int compare_by_year(AlbumItem *a, AlbumItem *b) { return a->year - b->year; }

// ==========================================
// PARSING ET LECTURE DU FICHIER (CSV)
// ==========================================

static char *extract_substring(const char *src, int start, int end) 
{
    int len = end - start;
    char *dest = malloc((len + 1) * sizeof(char));
    if (!dest) return NULL;
    for (int i = 0; i < len; i++) dest[i] = src[start + i];
    dest[len] = '\0';
    return dest;
}

static void parse_line_and_add(char *line, int len, AlbumItem **list) 
{
    int c1 = -1, c2 = -1;
    for (int i = 0; i < len; i++) {
        if (line[i] == ',') {
            if (c1 == -1) c1 = i;
            else if (c2 == -1) c2 = i;
        }
    }
    if (c1 == -1 || c2 == -1) return;
    char *artist = extract_substring(line, 0, c1);
    char *title = extract_substring(line, c1 + 1, c2);
    char *year_str = extract_substring(line, c2 + 1, len);
    int year = my_atoi(year_str);
    free(year_str);
    AlbumItem *new_album = create_album_item(artist, title, year);
    free(artist);
    free(title);
    push_back_album(list, new_album);
}

static int load_file(const char *filename, AlbumItem **list) 
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        print_string("File not found\n");
        return 0;
    }
    char buffer[4096];
    char line[512];
    int line_idx = 0, bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n' || buffer[i] == '\r') {
                if (line_idx > 0) {
                    parse_line_and_add(line, line_idx, list);
                    line_idx = 0;
                }
            } else if (line_idx < 511) {
                line[line_idx++] = buffer[i];
            }
        }
    }
    if (line_idx > 0) parse_line_and_add(line, line_idx, list);
    close(fd);
    return 1;
}


static void print_album_list(AlbumItem *list) 
{
    AlbumItem *curr = list;
    while (curr) {
        print_string("\"");               // Guillemet droit standard de départ
        print_string(curr->title);
        print_string("\" by \"");         // Guillemets droits pour entourer "by"
        print_string(curr->artist);
        print_string("\" released in ");  // Guillemet droit avant released
        print_number(curr->year);
        print_string(".\n");
        curr = curr->next;
    }
}

// ==========================================
// FONCTION MAÎTRESSE DE LANCEMENT
// ==========================================
int run_music_program(int argc, char **argv) 
{
    // 1. Gestion d'erreur : Format incorrect (Manque d'arguments)
    if (argc != 3) {
        print_string("Incorrect format\n");
        return 1;
    }
    // 2. Gestion d'erreur : Méthode de tri inexistante
    int (*cmp_func)(AlbumItem*, AlbumItem*) = NULL;
    if (my_strcmp(argv[2], "artist") == 0) cmp_func = compare_by_artist;
    else if (my_strcmp(argv[2], "title") == 0) cmp_func = compare_by_title;
    else if (my_strcmp(argv[2], "year") == 0) cmp_func = compare_by_year;
    else {
        print_string("Sort method does not exist\n");
        return 1;
    }
    // 3. Gestion d'erreur : Fichier introuvable (géré dans load_file)
    AlbumItem *list = NULL;
    if (!load_file(argv[1], &list)) {
        return 1;
    }
    // 4. Tri et Affichage final
    sort_album_by(&list, cmp_func);
    print_album_list(list);
    // 5. Nettoyage mémoire
    clear_list(&list);
    return 0;
}