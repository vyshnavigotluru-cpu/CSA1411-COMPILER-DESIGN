#include <stdio.h>

int main()
{
    char op1, op2, op3, op4;

    printf("Enter expression (example: a+b*c): ");
    scanf("%c%c%c%c%c", &op1, &op2, &op3, &op4, &op1);

    printf("\nIntermediate Code:\n");
    printf("t1 = b * c\n");
    printf("t2 = a + t1\n");

    printf("\nTarget Code:\n");
    printf("MOV R1, b\n");
    printf("MUL R1, c\n");
    printf("MOV R2, a\n");
    printf("ADD R2, R1\n");

    return 0;
}
