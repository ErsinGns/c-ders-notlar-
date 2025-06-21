#include <stdio.h>
#include <stdlib.h>


#define max(a, b)  (a > b ? a : b) // parantez koy yoksa başka işlem yapar
// önişlemci max(a, b) gördüğü her yere (,,,) yukardakini yazar
// \ alttan devam etmeyi sağlar
// ; koyma boş statment olur

#define SIZE 43
 
#if SIZE < 10 // if gibi ama endifle bitirilmeli
    int a = 3;
#elif SIZE < 50
    int a = 6;
#else
    int a = 4;
#endif


#ifdef SIZE // daha önce tanımlandımı demek
    int k = 4;
#else 
    int k = 3;
#endif

// #define SIZE 49  //! tanımsız davranış önncesinde undefi kullanmalısın
#undef SIZE // makronun tanımını ortadan kaldırır

#ifndef SIZE // tanımlı değilse girer
    int l = 3;
#else
    int l = 4;
#endif

// ! #iflerdeki karşılaştırmalar tam sayı olmak zorunda


int main(int argc, char const *argv[])
{
    int x = 0;
    if (x == 0)
	{
		printf("%s kaynak dosyasının %d. satirinda %s fonksiyonu icinde sifira bolum hatası", __FILE__,
			__LINE__, __func__); // hangi kaynak dosya hangi satır hangi fonksiyonda hata olduğunu söyler
		abort();
	}

    return 0;
}


