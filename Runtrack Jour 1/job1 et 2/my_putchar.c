#include <unistd.h>

int myputchar(char c) {
    write(1, &c, 1);
    return 0;
}


int my_putstr(char *c) {
    myputchar(*c);
    return 0;
}




int main(void) {
    myputchar('C');
    myputchar('o');
    myputchar('l');
    myputchar('l');
    myputchar('e');
    myputchar('g');
    myputchar('e');
    myputchar('!');
    myputchar('\n');
    return 0;
}