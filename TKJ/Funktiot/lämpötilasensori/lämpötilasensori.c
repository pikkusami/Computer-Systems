#include <stdio.h>
#include <inttypes.h>

// Prototypes
float lampotila(uint16_t rekisteri);

// Main
/* int main() {
    uint16_t rekisteri = 0b0011001000000000;
    double tulos = lampotila(rekisteri);

    printf("%.2f",tulos);

    return 0;
} */

// Functions
float lampotila(uint16_t rekisteri) {
    uint16_t irrotetutbitit = rekisteri >> 2;

    double celcius = irrotetutbitit * 0.03125;

    return celcius;
}
