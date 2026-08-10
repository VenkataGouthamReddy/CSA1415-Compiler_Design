#include <stdio.h>
#include <string.h>

char trailing[3][50];

/* Add a symbol to a set if it is not already present */
void add(int set, char symbol[])
{
    if (strstr(trailing[set], symbol) == NULL)
        strcat(trailing[set], symbol);
}

/* Copy all symbols from one set to another */
int copySet(int destination, int source)
{
    int changed = 0;
    int i;

    for (i = 0; trailing[source][i] != '\0'; i++)
    {
        char symbol[3];

        if (trailing[source][i] == 'i')
        {
            strcpy(symbol, "id");
            i++;
        }
        else
        {
            symbol[0] = trailing[source][i];
            symbol[1] = '\0';
        }

        if (strstr(trailing[destination], symbol) == NULL)
        {
            strcat(trailing[destination], symbol);
            changed = 1;
        }
    }

    return changed;
}

void findTrailing()
{
    int changed;

    do
    {
        changed = 0;

        /*
           E -> E + T
           The terminal + occurs before T.
           Therefore + belongs to TRAILING(E).
        */
        if (strstr(trailing[0], "+") == NULL)
        {
            add(0, "+");
            changed = 1;
        }

        /*
           T -> T * F
           The terminal * occurs before F.
           Therefore * belongs to TRAILING(T).
        */
        if (strstr(trailing[1], "*") == NULL)
        {
            add(1, "*");
            changed = 1;
        }

        /*
           F -> ( E )
           The last terminal is ).
           Therefore ) belongs to TRAILING(F).
        */
        if (strstr(trailing[2], ")") == NULL)
        {
            add(2, ")");
            changed = 1;
        }

        /*
           F -> id
           Therefore id belongs to TRAILING(F).
        */
        if (strstr(trailing[2], "id") == NULL)
        {
            add(2, "id");
            changed = 1;
        }

        /*
           E -> T
           TRAILING(T) is included in TRAILING(E).
        */
        if (copySet(0, 1))
            changed = 1;

        /*
           T -> F
           TRAILING(F) is included in TRAILING(T).
        */
        if (copySet(1, 2))
            changed = 1;

    } while (changed);
}

/* Display a TRAILING set */
void display(int set)
{
    int i;

    printf("{ ");

    for (i = 0; trailing[set][i] != '\0'; i++)
    {
        if (trailing[set][i] == 'i')
        {
            printf("id");
            i++;
        }
        else
        {
            printf("%c", trailing[set][i]);
        }

        if (trailing[set][i + 1] != '\0')
            printf(", ");
    }

    printf(" }");
}

int main()
{
    /* Initialize all sets */
    trailing[0][0] = '\0';   /* E */
    trailing[1][0] = '\0';   /* T */
    trailing[2][0] = '\0';   /* F */

    printf("Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    /* Calculate TRAILING sets */
    findTrailing();

    printf("TRAILING(E) = ");
    display(0);

    printf("\nTRAILING(T) = ");
    display(1);

    printf("\nTRAILING(F) = ");
    display(2);

    printf("\n");

    return 0;
}
