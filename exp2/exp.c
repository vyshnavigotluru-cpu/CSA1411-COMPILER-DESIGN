#include <stdio.h>
#include <string.h>

int main()
{
    char line[200];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    if ((line[0] == '/' && line[1] == '/') ||
        (line[0] == '/' && line[1] == '*'))
    {
        printf("The given line is a COMMENT.");
    }
    else
    {
        printf("The given line is NOT a COMMENT.");
    }

    return 0;
}
