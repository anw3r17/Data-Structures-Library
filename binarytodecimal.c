#include <stdio.h>
#include <math.h>

int main() {
    int binary, decimal = 0, exponent = 0;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while (binary != 0) {
        int remainder = binary % 10;
        decimal += remainder * pow(2, exponent);
        exponent++;
        binary /= 10;
    }

    printf("The decimal equivalent of the binary number is: %d\n", decimal);

    return 0;
}