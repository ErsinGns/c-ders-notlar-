
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

    // C de sonu _s ile biten fonksiyonlar var. Secure dan geliyor.
    // Farkı dizi boyutunu alıyor ve taşma hatasını oluşturmuyor.
    // Maliyeti de var. Sonuçta kontrol ediyor dizi bittimi bitmedimi diye.

	// bazı string fonksiyonları
	// strlen
	// strchr
	// strstr
	// strcpy
	// strcat
	// strrchr
	// strcmp
	// strspn
	// strcspn
	// strncpn
	// strncat
	// strncmp

    // size_t strlen(const char *p);
	// bir yazının uzunluğunu buluyor.Yazı adresi alıyor .
	// bu fonksiyona NULL ptr geçmek UB.

	// Geri dönüş değerini de aynı şekilde saklamak mantıklı.
	// size_t len = strlen(str);
	// mesela bende Unsigned int ten typedef edilmiş size_t.
	
	// size_t yi printf ile yazdırırken %zu conversion specifier kullanmak mantıklı
	// size_t len = strlen(str);
	// printf("%zu\n",len);

    // strchr -> bu bir yazı içerisinde bir karakter arıyor.


	// NULL						'\0'
	// ------------------------|--------------------	
	// symbolic constant		|	character constant
	// pointer degiskenlere	|	s[i] = '\0';


	// if(ptr != NULL && *ptr != '\0')
	// burada eğer pointer null değilse demek istiyor ilk ifadede
	// ikincisinde ise dereference edilen pointer değeri null character değilse demektir
    
    // strrchr -> yazıda karaterin geçtiği son yeri bulur.
	// char * strrchr(const char *p, int ch);


	// strcpy()
	// kopyalama fonksiyonu. String copy.
	// yazıların atama operatörü gibi.

	// char * strcpy(char *pdest, const char *psource) 
	// genelde C de dest ilk başta, sonrada source geliyor.
	// yada yazma amaçlı olarak kullanılan ptr, okuma amaçlı kullanılan
	// ptr den daha önce geliyor.

	// Eğer bir fonksiyon:
	// a - bir adrese bir yazı yerleştiriyor ise
	// b - bir adresteki yazıyı yerleştiriyor ise

	// tipik olarak aldığı adresi döndürür.

	// yani strcpy(s1,s2);
	// geri dönüş değeri s1 dir.

    // ÇOK ÖNEMLİ BİR HATA.
	// strcpy koduna std c fonksiyonunun dökümantasyonuna bakarsak
	// içinde birsürü UB durumu var.mesela

	// strcpy(a+5,a) ;  a[5] ten sonra a ya, a yı kopyala. UNDEFINED BEHAVIOR.


	// char str[SIZE] = "Mehmet";
	// strcpy(str + 3, str);  // UB Oluşturuyor.Overlaps blocks. çünkü source arrayde
	// puts(str);				// kopyalarken değişiyor ve çakılıyor bunlar.

	// Bunun yerine ileride görülecek memmove kullanılacak.
	// bir yazıyı bulunduğu bellek alanından kopyalayıp geri oraya kopyalayacaksak 
	// yani hem okuma hemde yazma amaçlı kullanılacaksa bir block,
	// burada memmove kullanılır.


	// strcat() -> concatanate 
	// bir yazının sonuna başka bir yazı ekler.concat ediyor.ya da birleştiriyor.

	// cont *strcat(char *pdest,const char *psource);

    // YAZILARIN KARŞILAŞTIRILMASI.

	// 6 adet operator var
	// == 
	// !=
	// <
	// <=
	// >
	// >=

	// int retval = compare(a,b)

	// retval > 0 ise a > b
	// retval < 0 ise a < b
	// retval == 0  ise a = b

	// Bunu yapan 

	// int strcmp(const char *p1, const char *p2)
	// return değeri pozitif ise p1 deki p2 dekinden daha büyük
	// negatif ise p1 deki p2 den küçük
	// 0 ise eşitler


	// idiyom
	// if(!strcmp(s1,s2))  eşitse 0 döndüreceğinden burada if e girer. 

	// yazıların büyüklük küçüklüğünü kıyaslayan algoritmaya
	// lexicographical compare denir.

    return 0;
}
