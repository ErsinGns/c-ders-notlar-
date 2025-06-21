#include <stdio.h>

int main(int argc, char const *argv[])
{
    // const correctness const doğruluğu
    // mutable == değiştirilebilir    immutable == değiştirilemez    
    // lookup table larda const kesinlikle kullan
    // eğer bir değer değiştirlmemesi gerekiyorsa const kullan

    //compiler optimization derleyici kodda oynama yapar

    //! macroların scopu yoktur 


    // int* const p2; const pointer to int - top-level const - right const ==> p2 nin gösterdiği adres değiştirilemez içerideki değer(adres) değiştirilebilir 
    // const int* p1; == int const * p1; pointer to const int - low-level const - left const ==> p1 den (*p1) değer değiştirilemez (değişkenin değeri)
    int x = 5;
    const int* p1 = &x;
    int* const p2 = &x;
    int y = 6;

    p1 = &y;
    p2 = &y; //! hata 

    *p1 = y; //! hata
    *p2 = y;

    //const int* const p3; const pointer to const int ==> ikisi birden

    const int* const p3 = &x;

    p3 = &y; //!hata
    *p3 = y; //!hata


    const int k = 3;
    int *ptr = &k; //! hatalı wornig değişmemesi gereken bir şeyi değişmeye acıyorsun
    *prt = 4; //! ub
    


    return 0;
}
