#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Remplace tout caractère non imprimable par '?'
void str_sanitize(char *s)
{
    int i = 0;
    while (s[i])
    {
        // ASCII imprimable = 32 à 126
        if (!(s[i] >= 32 && s[i] <= 126))
            s[i] = '?';
        i++;
    }
}

int main()
{
    char s[] = "Hello,\b world!\n";
    str_sanitize(s);
    printf("%s", s);
}
