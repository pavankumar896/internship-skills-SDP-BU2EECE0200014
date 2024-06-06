#include <stdio.h>

#define SET_BIT(num, bit) ((num) | (1 << (bit)))
#define SET_5TH_AND_12TH_BITS(num) (SET_BIT(SET_BIT((num), 4), 11))

int main() {
    unsigned int number;
    printf("Enter a 16-bit unsigned integer: ");
    scanf("%u", &number);
    if (number > 0xFFFF) {
        printf("The number exceeds 16-bit range. Please enter a valid 16-bit unsigned integer.\n");
        return 1;
    }
    number = SET_5TH_AND_12TH_BITS(number);
    printf("The number after setting the 5th and 12th bits is: %u\n", number);
    return 0;
}
