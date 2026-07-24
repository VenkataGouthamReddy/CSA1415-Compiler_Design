#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a line: ");
    gets(str);

    if(str[0]=='/' && str[1]=='/')
        printf("Single-line Comment");
    else if(str[0]=='/' && str[1]=='*')
        printf("Multi-line Comment");
    else
        printf("Not a Comment");

    return 0;
}
