#include <stdio.h>
#include <string.h>

int main()
{
    char p1[] = "iEtS";
    char p2[] = "iEtSeS";
    char prefix[20];
    int i = 0;

    /* Find common prefix */
    while(p1[i] == p2[i] && p1[i] != '\0')
    {
        prefix[i] = p1[i];
        i++;
    }
    prefix[i] = '\0';

    printf("Given Grammar:\n");
    printf("S -> %s | %s | a\n\n", p1, p2);

    printf("Common Prefix = %s\n\n", prefix);

    printf("After Left Factoring:\n");
    printf("S -> %sA | a\n", prefix);
    printf("A -> %s | e\n", p2 + i);

    return 0;
}
