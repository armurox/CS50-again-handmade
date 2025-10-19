#include <stdio.h>
#include "cs50.h"

int get_height(void);
void draw_pyramid(int height);

int main(void)
{
    // Get height from user
    int height = get_height();
    // draw the pyramid
    draw_pyramid(height);
}

int get_height(void)
{
    int height;
    while ((height = get_int("Height: ")) <= 0);
    return height;
}


void draw_pyramid(int height)
{
    int spaces;
    int hashes;
    for (int row = 1; row <= height; row++)
    {
        hashes = row;
        spaces = height - row;
        // Print spaces
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }

        // Print hashes
        for (int i = 0; i < hashes; i++)
        {
            printf("#");
        }

        printf("  ");

        // Print hashes again
        for (int i = 0; i < hashes; i++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
