#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    gets(str);

    printf("Output: ");

    for(i=0; str[i]!='\0'; i++) {
        if(str[i]!=' ' && str[i]!='\t')
            printf("%c", str[i]);
    }

    return 0;
}
