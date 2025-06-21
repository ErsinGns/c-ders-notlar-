#include "denem1.h"
#include <stdio.h>

#define SIZE   100
int main(int argc, char const *argv[])
{
    int dizi[SIZE];
    random();
    random_array(dizi, SIZE);
    printf("burda");
    print_array(dizi, SIZE);
    printf("burda");

    return 0;
}
// cd "c:\Yeni klasör\Masaüstü\c programlama dersleri\modül oluşturma\" ; if ($?) { gcc deneme11.c deneme1.c -o deneme11 } ; if ($?) { .\deneme11 }

