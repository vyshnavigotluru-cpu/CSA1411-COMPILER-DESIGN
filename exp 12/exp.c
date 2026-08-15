#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

void E();
void E1();
void T();
void T1();
void F();

void E()
{
    T();
    E1();
}

void E1()
{
    if(input[pos] == '+')
    {
        pos++;
        T();
        E1();
    }
}

void T()
{
    F();
    T1();
}

void T1()
{
    if(input[pos] == '*')
    {
        pos++;
        F();
        T1();
    }
}

void F()
{
    if(input[pos] == 'i' && input[pos + 1] == 'd')
    {
        pos += 2;
    }
    else if(input[pos] == '(')
    {
        pos++;
        E();

        if(input[pos] == ')')
            pos++;
        else
        {
            printf("Invalid expression\n");
            return;
        }
    }
    else
    {
        printf("Invalid expression\n");
    }
}

int main()
{
    printf("Enter the expression (use id): ");
    scanf("%s", input);

    E();

    if(input[pos] == '\0')
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");

    return 0;
}
