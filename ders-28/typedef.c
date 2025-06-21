#include <stdio.h>
#include <stdint.h>
#include <stddef.h>// mümkün olabildiğince az kütüphane include et stdint den daha az var bunu kullan az şey kullanacaksan

typedef int Mint; // int türüne yeni bir ad vermeyi sağlar skobu vardır nerde yapılırsa ona göre ulaşılır
typedef int inta20[20]; // == int[20]


int main(int argc, char const *argv[])
{
    int y = 4;
    Mint x = 4;
    printf("int = %d - mint = %d", sizeof(y), sizeof(x));

    //inta20 x, y; // == int x[20], y[20];


    typedef int (*FPTR)(int*, int*);
    FPTR fp = NULL;  // == int (*fp)(int*, int*) = NULL;
    FPTR fpa[3]; // == int (*fpa[3])(int*, int*);
    FPTR* fpptr; // == int (**fpptr)(int*, int*);


    // int32_t; // nereye taşırsan taşı 32 bitlik yer ayırır o değişken için
    // uint32_t; // aynısının işaretsizi

    int k;
    int64_t l;
    printf("\nint = %d - int32_t = %d", sizeof(k), sizeof(l));


    //standart
    // ptrdiff_t;
    // size_t;




    return 0;
}
