#include <stdio.h>
#include <stdlib.h>

char str[100];
int i = 0;

void E();
void T();

void T()
{
    if (str[i] == 'i')
        i++;
    else
    {
        printf("String Rejected\n");
        exit(0);
    }
}

void E()
{
    T();

    if (str[i] == '+')
    {
        i++;
        E();
    }
}

int main()
{
    printf("Enter string: ");
    scanf("%s", str);

    E();

    if (str[i] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
