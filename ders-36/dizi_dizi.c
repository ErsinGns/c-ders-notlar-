#include <stdio.h>

// ##t tür yazdırmada define de kulanılıyor ba 3:5:00 da ders 36 

void foo(int(*p)[11], size_t size){
    printf("aaa"); // ikinci aldığı dizi sayısı önemli
}

int main(int argc, char const *argv[])
{
    int a[64];// c de çok boyutlu dizi yoktur
    int b[4][5];// elemanları dizi olan dizi vardır a nın elamanları int[5] türünden matrix değil önemli
    int c[5][6][7]; // 

    printf("a = %d\n", sizeof(a)/sizeof(&a)); //%zu daha doğru
    printf("b = %d\n", sizeof(b)/sizeof(&b));
    printf("c = %d\n", sizeof(c)/sizeof(&c));


    printf("a = %d a+1 = %d\n", a, a + 1);
    printf("&a = %d &a+1 = %d\n", &a, &a + 1);// 65. pointıra gider
    printf("a = %d a+1 = %d\n", a, a + 64);

    int(*p)[5] = b; // b nın kendisi ilk elamanı değiil
    (*p)[1];// böyle yapılabilir

    int dizi[4][11];
    foo(dizi, 4);

    return 0;
}
