#include <stdio.h>
#include <string.h>
#include <ctype.h>

char leading[3][20];
int n = 3;

/* Add a symbol if it is not already present */
void add(int x, char *symbol)
{
    if (strstr(leading[x], symbol) == NULL)
        strcat(leading[x], symbol);
}

/* Find LEADING sets */
void findLeading()
{
    /*
       F -> (E) | id
       First symbols are ( and id
    */
    add(2, "(");
    add(2, "id");

    /*
       T -> T*F | F
       From T*F, add *
       From F, add LEADING(F)
    */
    add(1, "*");

    if (strstr(leading[2], "(") != NULL)
        add(1, "(");

    if (strstr(leading[2], "id") != NULL)
        add(1, "id");

    /*
       E -> E+T | T
       From E+T, add +
       From T, add LEADING(T)
    */
    add(0, "+");

    if (strstr(leading[1], "*") != NULL)
        add(0, "*");

    if (strstr(leading[1], "(") != NULL)
        add(0, "(");

    if (strstr(leading[1], "id") != NULL)
        add(0, "id");
}

int main()
{
    int i;

    /* Initialize LEADING sets */
    for (i = 0; i < n; i++)
        leading[i][0] = '\0';

    printf("Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    findLeading();

    printf("LEADING(E) = { ");
    for (i = 0; leading[0][i] != '\0'; i++)
    {
        if (leading[0][i] == 'i')
        {
            printf("id ");
            i++;
        }
        else
            printf("%c ", leading[0][i]);
    }
    printf("}\n");

    printf("LEADING(T) = { ");
    for (i = 0; leading[1][i] != '\0'; i++)
    {
        if (leading[1][i] == 'i')
        {
            printf("id ");
            i++;
        }
        else
            printf("%c ", leading[1][i]);
    }
    printf("}\n");

    printf("LEADING(F) = { ");
    for (i = 0; leading[2][i] != '\0'; i++)
    {
        if (leading[2][i] == 'i')
        {
            printf("id ");
            i++;
        }
        else
            printf("%c ", leading[2][i]);
    }
    printf("}\n");

    return 0;
}
