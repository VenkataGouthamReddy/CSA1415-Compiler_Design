#include <stdio.h>
#include <string.h>

int main()
{
    char symbol[10][20], key[20];
    int n = 0, choice, i, found;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter symbol: ");
                scanf("%s", symbol[n]);
                n++;
                printf("Symbol Inserted\n");
                break;

            case 2:
                printf("Enter symbol to search: ");
                scanf("%s", key);

                found = 0;
                for (i = 0; i < n; i++)
                {
                    if (strcmp(symbol[i], key) == 0)
                    {
                        found = 1;
                        break;
                    }
                }

                if (found)
                    printf("Symbol Found\n");
                else
                    printf("Symbol Not Found\n");
                break;

            case 3:
                printf("Symbol Table:\n");
                for (i = 0; i < n; i++)
                    printf("%s\n", symbol[i]);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
