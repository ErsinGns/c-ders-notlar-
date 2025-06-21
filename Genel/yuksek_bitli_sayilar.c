#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int rand_number_512_bit[16];

    for(int i = 0; i < 16; i++){
        rand_number_512_bit[i] = rand();
        printf("%d ", rand_number_512_bit[i]);
    }
    
    printf("\n");
    for(int i = 0; i < 16; i++){
        printf("%p ", &rand_number_512_bit[i]);
    }

    printf("\n");
    int* rand2_number_512_bit = malloc(16 * sizeof(int));

    for(int i = 0; i < 16; i++){
        rand2_number_512_bit[i] = rand();
        printf("%d ", rand2_number_512_bit[i]);
    }

    printf("\n");
    for(int i = 0; i < 16; i++){
        printf("%p ", &rand2_number_512_bit[i]);
    }

// ikisininde adresleri sıralı





    return 0;
}
