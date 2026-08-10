#include <stdio.h>

int main()
{
    char str[500];
    int i;
    int spaces = 0;
    int newlines = 0;
    int characters = 0;

    printf("Enter the text.\n");
    printf("Enter ~ to finish:\n");

    i = 0;

    while (i < 499)
    {
        str[i] = getchar();

        if (str[i] == '~')
        {
            str[i] = '\0';
            break;
        }

        if (str[i] == ' ' || str[i] == '\t')
        {
            spaces++;
        }
        else if (str[i] == '\n')
        {
            newlines++;
        }
        else
        {
            characters++;
        }

        i++;
    }

    printf("\nNumber of white spaces: %d", spaces);
    printf("\nNumber of newline characters: %d", newlines);
    printf("\nNumber of characters: %d\n", characters);

    return 0;
}
