int i, j;

    // Upper half (1 to 9 stars, odd numbers)
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half (7 to 1 stars, odd numbers)
    for (i = 7; i >= 1; i -= 2) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    
    return 0;
    }