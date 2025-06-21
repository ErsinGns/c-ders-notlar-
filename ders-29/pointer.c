
#include <stdio.h>



int main(int argc, char const *argv[])
{
    int* ptr; // wild pointer

    int a[5];
    ptr = a - 1; // bir anlamı yok yapma hatalı olmayan bir eleman
    ptr = a + 5; // dizinin bitiği yerin adresi önemlii

    // ==    !=   equality operators
    //< > <=  >=  relational operators

    int x = 3;
    // &x++; //! hatalı geçersiz nedeni öncelik &(x++)
    // &++x; aynısı
    // ++&x; hatalı
    // *p++ = 2; gösterdiği değere 2 ata ve p yi bir artır
    //*++p; p yi bir artır ve değerine eriş
    //! dizi ismi bir artırılamaz hata verir a++ hata
    // ++*a == ++(*a) == ++a[0] hata değil  (*a)++ hata değil
    



    return 0;
}
