#include <stdio.h>
unsigned int clearBits(unsigned int num, int pos1, int pos2) {
    unsigned int mask1 = ~(1 << pos1);
    unsigned int mask2 = ~(1 << pos2);
    unsigned int combinedMask = mask1 & mask2;
    num &= combinedMask;
    return num;
}

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned int num;
    int pos1, pos2;
    printf("Enter a 32-bit unsigned integer\n Eg: 25789458\n ");
    scanf("%u", &num);
    printf("Entered number in binary: ");
    printBinary(num);
    printf("Enter the position of the first bit to clear (0-31): ");
    scanf("%d", &pos1);
    printf("Enter the position of the second bit to clear (0-31): ");
    scanf("%d", &pos2);
    if (pos1 < 0 || pos1 > 31 || pos2 < 0 || pos2 > 31) {
        printf("Error: Bit positions must be between 0 and 31.\n");
        return 1;
    }
    unsigned int result = clearBits(num, pos1, pos2);
    printf("Resulting integer after clearing bits: %u\n", result);
    printf("Resulting number in binary: ");
    printBinary(result);
    return 0;
}