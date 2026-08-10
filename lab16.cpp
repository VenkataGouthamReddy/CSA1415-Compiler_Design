#include <stdio.h>

int main()
{
    int n, i;
    char result[20], op1[20], op2[20], op;

    printf("Enter number of statements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s = %s %c %s",
              result, op1, &op, op2);

        printf("LOAD R0, %s\n", op1);

        if (op == '+')
            printf("ADD R0, %s\n", op2);
        else if (op == '-')
            printf("SUB R0, %s\n", op2);
        else if (op == '*')
            printf("MUL R0, %s\n", op2);
        else if (op == '/')
            printf("DIV R0, %s\n", op2);

        printf("STORE %s, R0\n", result);
    }

    return 0;
}
