#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, discriminant, root1, root2;

    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct.\n");
        printf("Root 1 = %.2f, Root 2 = %.2f\n", root1, root2);
    } 
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and equal.\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    } 
    else {
        float realPart = -b / (2 * a);
        float imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are imaginary.\n");
        printf("Root 1 = %.2f + %.2fi\n", realPart, imagPart);
        printf("Root 2 = %.2f - %.2fi\n", realPart, imagPart);
    }

    return 0;
}

