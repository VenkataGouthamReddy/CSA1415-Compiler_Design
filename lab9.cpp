#include <stdio.h>

int main()
{
    printf("Given Grammar:\n");
    printf("L -> L,S | S\n\n");

    printf("After Eliminating Left Recursion:\n");
    printf("L  -> SL'\n");
    printf("L' -> ,SL' | e\n");

    return 0;
}
