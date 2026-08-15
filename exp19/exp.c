#include <stdio.h>
int main()
{
    int number1, number2, sum;
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);
    sum = number1 + number2;
    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}

another code:
%{
#include <stdio.h>

int characters = 0;
int words = 0;
int lines = 0;
%}

%%
\n              { lines++; characters++; }
[ \t]+          { characters += yyleng; }
[^ \t\n]+       { words++; characters += yyleng; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("sample.c", "r");

    if (yyin == NULL)
    {
        printf("Unable to open sample.c\n");
        return 1;
    }

    yylex();

    fclose(yyin);

    printf("\nNumber of characters = %d\n", characters);
    printf("Number of words = %d\n", words);
    printf("Number of lines = %d\n", lines);

    return 0;
}
