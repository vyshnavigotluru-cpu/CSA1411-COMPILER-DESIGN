#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "main", "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else", "enum",
        "extern", "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "unsigned",
        "void", "printf", "while"
    };

    int i;

    for (i = 0; i < 32; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char ch;
    char buffer[50];
    char operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    fp = fopen("flex_input.txt", "r");

    if (fp == NULL)
    {
        printf("Error while opening the file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Ignore single-line comments */
        if (ch == '/')
        {
            char next = fgetc(fp);

            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF)
                    ;
                continue;
            }
            else
            {
                ungetc(next, fp);
            }
        }

        /* Check operators */
        for (i = 0; i < 6; i++)
        {
            if (ch == operators[i])
            {
                printf("%c is operator\n", ch);
                break;
            }
        }

        /* Check identifiers and keywords */
        if (isalnum(ch) || ch == '_')
        {
            if (j < 49)
                buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\t' || ch == '\n' ||
                  ch == '(' || ch == ')' || ch == '{' ||
                  ch == '}' || ch == ',' || ch == ';' ||
                  ch == '"') && j != 0)
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
                printf("%s is keyword\n", buffer);
            else
                printf("%s is identifier\n", buffer);
        }
    }

    /* Process remaining word */
    if (j != 0)
    {
        buffer[j] = '\0';

        if (isKeyword(buffer))
            printf("%s is keyword\n", buffer);
        else
            printf("%s is identifier\n", buffer);
    }

    fclose(fp);

    return 0;
}
