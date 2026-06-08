#include <stdio.h>

// --- JOB 04 ---
int char_is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

// --- JOB 05 ---
int str_is_digit(char *str) {
    int i = 0;
    
    // Sécurité bonus : si la chaîne est vide, on considère que ce n'est pas un chiffre
    if (str[0] == '\0') {
        return 0;
    }

    while (str[i] != '\0') {
        if (!char_is_digit(str[i])) {
            return 0; // Dès qu'un caractère n'est pas un chiffre, on s'arrête
        }
        i++;
    }
    return 1; // Tous les caractères examinés sont des chiffres
}

// --- ZONE DE TEST ---
int main(void) {
    // 1. Tests pour char_is_digit (Job 04)
    printf("=== TESTS JOB 04 (char_is_digit) ===\n");
    char c1 = '5';
    char c2 = 'a';
    printf("Est-ce que '%c' est un chiffre ? Résultat : %d\n", c1, char_is_digit(c1)); // Doit afficher 1
    printf("Est-ce que '%c' est un chiffre ? Résultat : %d\n\n", c2, char_is_digit(c2)); // Doit afficher 0

    // 2. Tests pour str_is_digit (Job 05)
    printf("=== TESTS JOB 05 (str_is_digit) ===\n");
    char *s1 = "123456";
    char *s2 = "123a56";
    char *s3 = "42";
    printf("Est-ce que \"%s\" ne contient que des chiffres ? Résultat : %d\n", s1, str_is_digit(s1)); // Doit afficher 1
    printf("Est-ce que \"%s\" ne contient que des chiffres ? Résultat : %d\n", s2, str_is_digit(s2)); // Doit afficher 0
    printf("Est-ce que \"%s\" ne contient que des chiffres ? Résultat : %d\n", s3, str_is_digit(s3)); // Doit afficher 1

    return 0;
}