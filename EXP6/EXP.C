#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char a[50];
    int flag = 1;
    int i;

    printf("Enter an identifier: ");
    scanf("%49s", a);

    /* First character must be a letter or underscore */
    if (!isalpha(a[0]) && a[0] != '_')
    {
        flag = 0;
    }
    else
    {
        /* Remaining characters can be letters, digits or underscore */
        for (i = 1; a[i] != '\0'; i++)
        {
            if (!isalnum(a[i]) && a[i] != '_')
            {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
    {
        printf("\nValid identifier\n");
    }
    else
    {
        printf("\nNot a valid identifier\n");
    }

    return 0;
}
