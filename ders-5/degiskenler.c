#include <stdio.h>


int g; // statik ömürlü değer atamassan değeri 0 olur

int main(int argc, char const *argv[])
{
    int g = 33;//! isim maskeleme 
    printf("%d\n", g);

    int x = 13; //? bildirim  ( = oparötör değil) ilk değer verme
    x = 56; //? atama  ( = operator)
    int l = x; //! hata verir yapılmaz (derleyici ayarlarına göre)
    printf("%d\n", l);

 
    int a, b, c, d, f; //! çöp değer tanımsız davranış hata verir (hata vermese çöp değeri kullanır)
    printf("%d %d %d %d %d\n", a, b, c, d, f);
    printf("%d\n", g); // 0 döner 

    int o = 3;
    //! double o = 3.4; hata verir

    {
        double o = 3.4;// scopedan dolayı hata vermez
        printf("%f\n", o);
    }
    printf("%d\n", o);

    
    int _ali = 33; //? şeklinde yapılabilir
    printf("%d\n", _ali);

    return 0;
}


    /*

    char 
    signed char
    unsigned char

    */

    /*

    signed short int 
    short short
    short int
    short

    unsigned short int 
    unsigned int

    signed int
    int 
    signed

    unsigned int
    unsigned

    signed long int
    signed long 
    long int
    long

    unsigned long int
    unsigned long

    signed long long int
    signed long long 
    long long int
    long long

    unsigned long long int
    unsigned long long

    */

    /*

    float 
    double
    long double

    */ 

