#include <stdio.h>
#include <inttypes.h>
#include <math.h>

// Tietorakenteet
struct piste {
  int koordinaatit[3];
  struct piste *seuraava;
};

struct polku {
  double matka;
  struct piste *pisteet;
};

// Prototyypit
void laske_kuljettu_matka(struct polku *polku);

// Main
/* int main() {
    // Luodaan esimerkkidata
    struct piste p1 = {{1, 2, 3}, NULL};
    struct piste p2 = {{3, 4, 6}, NULL};
    struct piste p3 = {{4, 4, 4}, NULL};
    
    p1.seuraava = &p2;
    p2.seuraava = &p3;
    
    struct polku polku = {0.0, &p1};
    
    // Lasketaan kuljettu matka
    laske_kuljettu_matka(&polku);
    
    // Tulostetaan tulos
    printf("Kuljettu matka: %.2f\n", polku.matka);
    
    return 0;
} */

// Funktiot
void laske_kuljettu_matka(struct polku *polku) {
    double kokonaismatka = 0.0;
    struct piste *nykyinen = polku->pisteet;

    while (nykyinen != NULL && nykyinen->seuraava != NULL) {
        int *p1 = nykyinen->koordinaatit;
        int *p2 = nykyinen->seuraava->koordinaatit;

        kokonaismatka += sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));

        nykyinen = nykyinen->seuraava;
    }

    polku->matka = kokonaismatka;
}
