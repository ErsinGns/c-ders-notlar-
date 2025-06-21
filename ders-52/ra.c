#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdint.h>

/*

uint64_t rand64() {
    uint64_t high = ((uint64_t)rand()) << 32; // Üst 32 bit
    uint64_t low = (uint64_t)rand();          // Alt 32 bit
    return high | low;                        // Birleştir ve 64 bitlik değer döndür
}

int main() {
    srand(time(NULL));  // Rastgele sayı üreticisini başlat

    uint64_t randomValue = rand64();
    printf("64-bit random value: %llu\n", randomValue);

    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


void rand512(uint64_t *result) {
    for (int i = 0; i < 8; i++) {
        uint64_t high = ((uint64_t)rand()) << 32; // Üst 32 bit
        uint64_t low = (uint64_t)rand();          // Alt 32 bit
        result[i] = high | low;                   // 64 bitlik değeri sakla
    }
}

void print512(const uint64_t *value) {
    for (int i = 0; i < 8; i++) {
        printf("%ld ", value[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Rastgele sayı üreticisini başlat

    uint64_t randomValue[8];
    rand512(randomValue);

    printf("512-bit random value: ");
    print512(randomValue);

    return 0;
}

