%{
#include <stdio.h>

int nchar = 0;
int nword = 0;
int nline = 0;
%}

%%

\n              { nline++; nchar++; }
[^ \t\n]+       { nword++; nchar += yyleng; }
.               { nchar++; }

%%

int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");

    if (yyin == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    yylex();

    printf("Number of characters = %d\n", nchar);
    printf("Number of words = %d\n", nword);
    printf("Number of lines = %d\n", nline);

    fclose(yyin);

    return 0;
}
