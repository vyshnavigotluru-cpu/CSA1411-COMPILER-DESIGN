#include <stdio.h>

/* Function to display TRAILING sets */
void trailing()
{
    printf("\nTRAILING sets for the given grammar:\n\n");

    printf("Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    printf("TRAILING(E) = { +, *, ), id }\n");
    printf("TRAILING(T) = { *, ), id }\n");
    printf("TRAILING(F) = { ), id }\n");
}

int main()
{
    printf("========================================\n");
    printf("   TRAILING - Operator Precedence Parser\n");
    printf("========================================\n");

    trailing();

    printf("\nProgram executed successfully.\n");

    return 0;
}
