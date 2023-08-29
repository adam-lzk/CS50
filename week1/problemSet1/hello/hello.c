// Программа приветствие

#include <stdio.h>
#include <cs50.h>

int main()
{
    string username = get_string("What is your name?\n");
    printf("Hello, %s!\n", username);

    return 0;
}
