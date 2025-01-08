#include <stdio.h>
#include <inttypes.h>
#include <math.h>

// Prototypes
uint8_t kuusikulmio(uint32_t luku);

// Main
/* int main() {
    printf("%u",kuusikulmio(14));
} */

// Functions
uint8_t kuusikulmio(uint32_t luku) {
    double n = (sqrt(8 * luku + 1) + 1) / 4;

    if (n == (int)n) {
        return 1;
    }
    return 0;
}
