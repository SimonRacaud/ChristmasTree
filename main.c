#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    void tree(int size);
    int taille = argv[1][0]-'0';

    tree(taille);

    return 0;
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
