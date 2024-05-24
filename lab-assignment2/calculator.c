// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>

int main() {
    int a, b, c, choice;

    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid option\n");
        return 1;
    }

    printf("Enter a & b values: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input for numbers\n");
        return 1;
    }


    // Add your code here using switch
    switch (choice) {
    case 1:
        c = a + b;
        printf("Addition\nSum = %d\n", c);
        break;
    case 2:
        c = a - b;
        printf("Subtraction\nDifference = %d\n", c);
        break;
    case 3:
        c = a * b;
        printf("Multiplication\nProduct = %d\n", c);
        break;
    case 4:
        if (b != 0) {
            c = a / b;
            printf("Division\nQuotient = %d r %d\n", c, a % b);
        } else {
            printf("Divide by zero error\n");
        }
        break;
    default:
        printf("Invalid option\n");
        break;
    }

    return 0;
}
