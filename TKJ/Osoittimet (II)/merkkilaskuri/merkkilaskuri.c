#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

// Prototypes
void merkkilaskuri(char *str, uint8_t *tulos);

// Main
int main() {
    char str[] = "Tämä on esimerkki lause!";
    uint8_t tulos[2];

    merkkilaskuri(str, tulos);

    printf("Vokaalit: %d\n", tulos[0]);
    printf("Konsonantit: %d\n", tulos[1]);

    return 0;
}

// Functions
void merkkilaskuri(char *str, uint8_t *tulos) {
    // Nollataan taulukon arvot
    tulos[0] = 0; // Vokaalit
    tulos[1] = 0; // Konsonantit

    // Käydään merkkijono läpi
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') { // Tarkistetaan, onko merkki kirjain
            switch (ch) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                    tulos[0]++; // Vokaali
                    break;
                default:
                    tulos[1]++; // Konsonantti
                    break;
            }
        }
    }
}
