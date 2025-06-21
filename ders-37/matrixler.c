#include <stdio.h>

int a[20];
typedef int (*ar20ptr)[20];

ar20ptr foo(void){// dizinin kendisinini adresini döndürür
    return &a;
}

int (*bar(void))[20]{// üstekinin aynısı
    return &a;
}



int main(int argc, char const *argv[])
{
    int a[16] = { 0 };
    int (*p)[16] = &a; // dizinin kendisini gösterir
    int* ptr = a; // ilk elemanı gösterir

    printf("p = %p  ptr = %p\n", p, ptr);
    printf("p = %p  ptr = %p\n", ++p, ++ptr);

    int diz[][2] = {1, 2, 3, [12] = 5}; // ikincisinde bir sınır olmalı ilkinde olmasada olur

    int (*dp)[20] = foo(); // bu şekilde alınır

    return 0;
}
