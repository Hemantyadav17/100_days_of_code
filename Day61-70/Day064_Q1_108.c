#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int maxLength = 0;
    int left = 0;
    
    // Character last seen index array (for ASCII characters)
    int lastSeen[256];
    
    // Initialize all indices to -1
    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }
    
    // Sliding window approach
    for (int right = 0; right < n; right++) {
        char c = s[right];
        
        // If character was seen before and is within current window
        if (lastSeen[(unsigned char)c] >= left) {
            // Move left pointer to skip the previous occurrence
            left = lastSeen[(unsigned char)c] + 1;
        }
        
        // Update last seen index of current character
        lastSeen[(unsigned char)c] = right;
        
        // Calculate current window length and update maxLength
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}

int main() {
    char s[1000];
    
    printf("Enter a string: ");
    scanf("%999s", s);
    
    int result = lengthOfLongestSubstring(s);
    printf("%d\n", result);
    
    return 0;
}