/*
** EPITECH PROJECT, 2019
** CPool_Tree_2019
** File description:
** Project of the first pool week
*/

// DEBUG \/
#include <stdio.h>

int my_putchar(char c);
int calc_height(int *size);
int calc_width(int *size);
void display_foliage(int *tree_height, int *tree_width);
void display_trunk(int *size, int *tree_width);

void tree(int size)
{
    int tree_height;
    int tree_width;

    tree_height = calc_height(&size);
    tree_width = calc_width(&size);
    display_foliage(&tree_height, &tree_width);
    display_trunk(&size, &tree_width);
}

int calc_height(int *size)
{
    int tree_height = 0;
    int bloc_size = 4;

    for (int i = 0; i < *size; i++) {
        tree_height += bloc_size;
        bloc_size++;
    }
    return (tree_height);
}

int calc_width(int *size)
{
    int bloc_size = 4;
    int bloc_space = 2;
    int tree_width = -1;

    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < bloc_size; j++) {
            tree_width += 2;
        }
        if (i != *size-1)
            tree_width -= (bloc_space+2);
        if ((i+1) % 2 == 0)
            bloc_space += 2;
        bloc_size++;
    }
    return (tree_width);
}

void display_foliage(int *tree_height, int *tree_width)
{
    int bloc_size = 4;
    int bloc_space = 2;
    int curr_width = 1;
    int bloc_i = 0;
    int bloc_count = 1;

    for (int i = 0; i < *tree_height; i++) {
        for (int k=0; k < ((*tree_width/2)-(curr_width/2)); k++)
            my_putchar(' ');
        for (int j=0; j < curr_width; j++)
            my_putchar('*');
        my_putchar('\n');
        curr_width+=2;
        bloc_i++;
        if (bloc_i == bloc_size) {
            bloc_size++;
            curr_width -= (bloc_space+2);
            if (bloc_count % 2 == 0)
                bloc_space += 2;
            bloc_i=0;
            bloc_count++;
        }
    }
}

void display_trunk(int *size, int *tree_width)
{
    int width_trunk = *size;
    if (*size > 1 && ((*size - 1) % 2) != 0) {
        width_trunk = *size+1;
    }
    for (int i = 0; i < *size; i++) {
        for (int k = 0; k < ((*tree_width/2)-(width_trunk/2)); k++) {
            my_putchar(' ');
        }
        for (int j = 0; j < width_trunk; j++) {
            my_putchar('|');
        }
        my_putchar('\n');
    }
}
