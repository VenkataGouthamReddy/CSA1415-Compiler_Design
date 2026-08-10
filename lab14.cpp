#include <stdio.h>

char s[100];
int temp = 1;

void generate(char op)
{
    int i, j;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == op)
        {
            printf("t%d = %c %c %c\n",
                   temp, s[i-1], op, s[i+1]);

            s[i-1] = '0' + temp;

            for (j = i; s[j] != '\0'; j++)
                s[j] = s[j+2];

            temp++;
            i = -1;
        }
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", s);

    generate('*');
    generate('/');
    generate('+');
    generate('-');

    return 0;
}
