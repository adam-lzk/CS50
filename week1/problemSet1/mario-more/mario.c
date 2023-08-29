// Pyramid from the Mario game

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    for (int i = 0; i < height; i++)
    {
        for (int j = height - i - 1; j > 0; j--)  // height - i - 1 spaces before the first hashtag in the line
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k ++)  // i + 1 5 hashtags in the left half of the pyramid
        {
            printf("#");
        }

        printf("  ");  // print a gap

        for (int k = 0; k < i + 1; k ++)  // i + 1 5 hashtags in the right half of the pyramid
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
