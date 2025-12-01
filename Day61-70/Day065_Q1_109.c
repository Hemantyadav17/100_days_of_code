/* Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). 
The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. 
Print "Anagram" if they are, otherwise "Not Anagram". */

#include <stdio.h>
#include <string.h>

int main() {
    char s[200], t[200];
    int freq1[26] = {0}, freq2[26] = {0}, i;

    scanf("%s", s);
    scanf("%s", t);

    if (strlen(s) != strlen(t)) {
        printf("Not Anagram");
        return 0;
    }

    for (i = 0; s[i]; i++) freq1[s[i]-'a']++;
    for (i = 0; t[i]; i++) freq2[t[i]-'a']++;

    for (i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            printf("Not Anagram");
            return 0;
        }
    }

    printf("Anagram");
    return 0;
}
