#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;
    
    int len = strlen(str);
    int capitalize = 1; 
    for(int i = 0; i < len; i++) {
        if(str[i] == ' ') {
            capitalize = 1;
            putchar(' ');
        } else {
            if(capitalize && isalpha(str[i])) {
                putchar(toupper(str[i]));
                capitalize = 0;
            } else {
                putchar(tolower(str[i]));
            }
        }
    }
    putchar('\n');
    return 0;
}
