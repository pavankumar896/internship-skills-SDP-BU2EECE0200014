#include <stdio.h>

#define BYTE1(ip) ((ip) >> 24) & 0xFF
#define BYTE2(ip) ((ip) >> 16) & 0xFF
#define BYTE3(ip) ((ip) >> 8) & 0xFF
#define BYTE4(ip) (ip) & 0xFF

int main() {
    unsigned int ip;
    printf("Enter the packed 32-bit unsigned integer (IP address): ");
    scanf("%u", &ip);
    printf("The IP address is: %u.%u.%u.%u\n", BYTE1(ip), BYTE2(ip), BYTE3(ip), BYTE4(ip));
    return 0;
}