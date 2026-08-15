#include <stdio.h>
#include <string.h>

int main()
{
    char alpha[20], beta[20];

    printf("Enter grammar:\n");
    printf("L -> L,S / S\n\n");

    strcpy(alpha, ",S");
    strcpy(beta, "S");

    printf("After eliminating left recursion:\n\n");

    printf("L -> S L'\n");
    printf("L' -> ,S L' | epsilon\n");

    printf("\nGrammar for S remains:\n");
    printf("S -> (L) | a\n");

    return 0;
}
