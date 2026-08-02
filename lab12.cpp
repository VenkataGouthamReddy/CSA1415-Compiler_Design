#include <stdio.h>
#include <string.h>

char input[20];
int i = 0;

void E();
void EP();
void T();
void TP();
void F();

void E()
{
    T();
    EP();
}

void EP()
{
    if(input[i] == '+')
    {
        i++;
        T();
        EP();
    }
}

void T()
{
    F();
    TP();
}

void TP()
{
    if(input[i] == '*')
    {
        i++;
        F();
        TP();
    }
}

void F()
{
    if(input[i] == 'i' && input[i+1] == 'd')
        i += 2;
    else if(input[i] == '(')
    {
        i++;
        E();
        if(input[i] == ')')
            i++;
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", input);

    E();

    if(input[i] == '\0')
        printf("String Accepted");
    else
        printf("String Rejected");

    return 0;
}
