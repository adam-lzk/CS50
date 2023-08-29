// Population growth

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize = 0, endSize = 0, years = 0;

    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    while (startSize < endSize)
    {
        startSize = startSize + startSize / 3 - startSize / 4;
        years++;
    }

    printf("Years: %i\n", years);

    return 0;
}
