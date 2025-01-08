#include <stdio.h>
#include <inttypes.h>
#include <math.h>

// Prototypes
float valoisuus(uint16_t rekisteri);

// Main
/* int main() {
    uint16_t rekisteri = 0b0110110000110101;
    float tulos = valoisuus(rekisteri);

    printf("%.2f",tulos);

    return 0;
} */

// Functions
float valoisuus(uint16_t rekisteri) {
    uint16_t maski_e = 0b1111000000000000;
    uint16_t maski_r = 0b0000111111111111;

    uint16_t ryhma_e = (maski_e & rekisteri) >> 12;
    uint16_t ryhma_r = maski_r & rekisteri;

    float lux = 0.01 * pow(2,ryhma_e) * ryhma_r;

    return lux;
}
