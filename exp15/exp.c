#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;

    char path[300];

    /* Get Windows username automatically */
    sprintf(path, "C:\\Users\\%s\\Desktop\\input.txt", getenv("USERNAME"));

    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    fclose(fp);

    printf("\nNumber of characters = %d", characters);
    printf("\nNumber of words = %d", words);
    printf("\nNumber of lines = %d\n", lines);

    return 0;
}
