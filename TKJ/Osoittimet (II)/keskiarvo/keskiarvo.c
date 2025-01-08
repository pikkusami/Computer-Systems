#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
float keskiarvo(char *lista);

// Main
/* int main() {
    char lista[] = "201,53,12,31,5";
    float avg = keskiarvo(lista);
    printf("Keskiarvo: %.1f\n", avg);

    return 0;
} */

// Functions
float keskiarvo(char *lista) {
    int sum = 0;
    int count = 0;
    char *token = strtok(lista, ",");

    while (token != NULL) {
        sum += atoi(token);
        count++;
        token = strtok(NULL, ",");
    }

    if (count == 0) return 0.0;  // Varmistetaan, ettei nollalla jaeta

    return (float)sum / count;
}
