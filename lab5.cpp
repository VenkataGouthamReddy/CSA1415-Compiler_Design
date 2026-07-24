#include <stdio.h>

int main() {
    char str[100];
    int i, space=0, newline=0;

    printf("Enter text (use Enter to finish):\n");
    fgets(str, 100, stdin);

    for(i=0; str[i]!='\0'; i++) {
        if(str[i]==' ')
            space++;
        if(str[i]=='\n')
            newline++;
    }

    printf("Spaces = %d\n", space);
    printf("Newlines = %d\n", newline);

    return 0;
}
