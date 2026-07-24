#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i]))
            printf("%c is an Identifier\n", str[i]);
        else if(isdigit(str[i]))
            printf("%c is a Constant\n", str[i]);
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
            printf("%c is an Operator\n", str[i]);
    }

    return 0;
}
