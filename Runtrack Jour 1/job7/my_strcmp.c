#include <stdio.h>

int my_strcmp(char *s1, char *s2) 
{
    int i = 0;

    // Tant que les caractères sont identiques ET qu'on n'est pas à la fin de s1
    while (s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

    // On retourne la différence de valeur ASCII entre les deux caractères là où ça a changé
    return (s1[i] - s2[i]);
}

int main(void) 
{
    // Cas 1 : Chaînes identiques (Doit renvoyer 0)
    char *str1 = "abc";
    char *str2 = "abc";
    printf("Comparaison \"%s\" et \"%s\" : %d\n", str1, str2, my_strcmp(str1, str2));

    // Cas 2 : s1 est inférieure à s2 (Doit renvoyer une valeur négative, ici 'c' - 'd' = -1)
    char *str3 = "abc";
    char *str4 = "abd";
    printf("Comparaison \"%s\" et \"%s\" : %d\n", str3, str4, my_strcmp(str3, str4));

    // Cas 3 : s1 est supérieure à s2 (Doit renvoyer une valeur positive, ici 'z' - 'a' = 25)
    char *str5 = "z";
    char *str6 = "a";
    printf("Comparaison \"%s\" et \"%s\" : %d\n", str5, str6, my_strcmp(str5, str6));

    return 0;
}