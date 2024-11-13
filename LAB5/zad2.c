#include <stdio.h>

// Globalna zmienna 'a', która ma wartość 8
int a = 8;

// Funkcja pomocnicza do wyświetlania wartości zmiennej 'a' w różnych blokach
void info(char *nazwa_bloku, int zmienna) {
    printf("W bloku %s zmienna a = %d\n", nazwa_bloku, zmienna);
}

// Funkcja, która wyświetla wartość globalnej zmiennej 'a'
void funkcja() {
    info("funkcji", a); // Wypisuje: "W bloku funkcji zmienna a = 8"
}

// Funkcja obliczająca sumę dwóch liczb
int suma(int x, int y) {
    return x + y;
}

// Funkcja sprawdzająca, czy liczba jest parzysta
void czy_parzysta(const int);

// Funkcja zwiększająca wartość liczby o 1 i zwracająca wynik
int liczba_zwiekszona(int x) {
    return ++x;
}

// Funkcja, która próbuje zwiększyć wartość 'a', ale bez trwałego efektu
void zwieksz_liczbe(int a) {
    ++a; // Zwiększa tylko lokalną kopię zmiennej 'a'
}

// Funkcja zwiększająca wartość zmiennej przez wskaźnik
void zwieksz_przez_adres(int* x) {
    (*x)++; // Zwiększa wartość zmiennej, na którą wskazuje wskaźnik
}

int main() {
    // Lokalna zmienna 'a' w 'main', która ma wartość 20
    int a = 20;

    // Wyświetlanie wartości lokalnej zmiennej 'a' w 'main'
    info("main", a); // Wypisuje: "W bloku main zmienna a = 20"

    // Wywołanie funkcji, która wyświetla wartość globalnej zmiennej 'a'
    funkcja();

    // Obliczenie sumy dwóch liczb
    int b = 9;
    int wynik = suma(a, b);
    printf("\na + b = %d\n\n", wynik); // Wypisuje: "a + b = 29"

    // Sprawdzenie, czy liczby 'a' i 'b' są parzyste
    czy_parzysta(a); // Wypisuje: "Liczba 20 jest parzysta!"
    czy_parzysta(b); // Wypisuje: "Liczba 9 jest nieparzysta!"

    // Zwiększenie wartości 'a' o 1 i wyświetlenie wyniku
    printf("\na + 1 = %d\n", liczba_zwiekszona(a)); // Wypisuje: "a + 1 = 21"

    // Próba zwiększenia wartości 'a' (bez efektu)
    zwieksz_liczbe(a);
    printf("Zmienna 'a' po wywolaniu zwieksz_liczbe = %d\n", a); // Wypisuje: "20"

    // Zwiększenie wartości 'a' przez wskaźnik (z trwałym efektem)
    zwieksz_przez_adres(&a);
    printf("Zmienna 'a' po zwieksz_przez_adres = %d\n", a); // Wypisuje: "21"

    return 0;
}

// Funkcja sprawdzająca, czy liczba jest parzysta
void czy_parzysta(const int x) {
    if(x % 2 == 0)
        printf("Liczba %d jest parzysta!\n", x);
    else
        printf("Liczba %d jest nieparzysta!\n", x);
}
