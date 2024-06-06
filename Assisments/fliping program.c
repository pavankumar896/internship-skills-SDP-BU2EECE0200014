#include <stdio.h>

#define FLIP_EVEN_BITS(num) ((num) ^ 0x5555)

int main() {
    unsigned int number;
    printf("Enter a 16-bit unsigned integer: ");
    scanf("%u", &number);
    if (number > 0xFFFF) {
        printf("The number exceeds the 16-bit range. Please enter a valid 16-bit unsigned integer.\n");
        return 1;
    }
    number = FLIP_EVEN_BITS(number);
    printf("The number after flipping even-positioned bits is: %u\n", number);
    return 0;
}
