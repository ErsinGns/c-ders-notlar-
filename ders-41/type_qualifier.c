#include <stdio.h>

int main(int argc, char const *argv[])
{
    //const ==> değeri değişmiyecek değeri demek
    // const correctness == cosnt doğruluğu const olması gerekiyorsa const yaz
    // int* const p = &x; ===> top-level const const pointer to int right const adres değişmez değer değişebilir
    // const int* p = &x ===> pointer to const int p aracılığıyla değerini değiştiremezsin demek left const low-level const

    int x;
    typedef int* iptr;
    const iptr p = &x; // == int* const p = &x; demek adres değişmesi sentax hatası const pointer

    //volatile ===> program dışı kaynaklardan değiştirilebilir
    volatile int y = 4; // optimize etmez
    volatile int * a; // pointerla aynı mantık
    int* volatile a;


    return 0;
}
