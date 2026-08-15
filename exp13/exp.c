#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

/* Grammar:
   S -> aA
   A -> bA | e
*/

int S()
{
    if(input[pos] == 'a')
    {
        pos++;

        if(input[pos] == 'b')
        {
            while(input[pos] == 'b')
                pos++;

            return 1;
        }
    }

    return 0;
}

int main()
{
    printf("Grammar:\n");
    printf("S -> aA\n");
    printf("A -> bA | e\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    if(S() && input[pos] == '\0')
        printf("String is accepted by the grammar.\n");
    else
        printf("String is rejected by the grammar.\n");

    return 0;
}
