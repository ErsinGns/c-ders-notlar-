// 0101 0110
// 1010 1010 // ikiye tümleyenin kısa yolu
int x;
int x; // geçerli sadece global alana özel 
//ama tek bir tane x değişkeni oluşturulur

int ga = 3;
int ga; // hatalı değil ilk tanımlamadan devam eder tentative definiton aslında ga yaratılmaz

int gb = 5;
// int gb = 8; // bu kod hatalı tek bir kez ilk değer verilebilir

//127 le -128 arasında değer alır işaretli 1 bayt

//	.c -----> C Derleyicisi -----> Object file -----> Bağlayıcı (Linker) -----> Çalıştırılabilir (executable)


// boffer temizleme önemli
void clear_stdin(void)
{
	while (getchar() != '\n')
		;
}

int get_command(void)
{
	int ch;

	while ((ch = getchar()) == ' ' || ch == '\t')
		;

	if (ch != '\n')
		while (getchar() != '\n')
			;

	return ch;
}

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	printf("%d\n", ga);// 3 yazar
	printf("%d\n", gb);// hatalı

    char x;
    for(int i = -129; i < 129; i++){
        x = (char)i;
        printf("x = %d\n", x);
    }
    printf("%-22d%c\n", x, 'd'); // ikisi arasına 22tane boşluk bırakır

    double a = 12.346;

	printf("___%10.2f___\n", a);		/*___     12.35___*/
	printf("___%-10.2f___\n", a);		/*___12.35     ___*/
	printf("___%.10f___\n", a);			/*___12.3460000000___*/
	printf("___%.0f___\n", a);			/*___12___*/


	L'a'; // wide character constants 
	// geniş karakter sabitleri
	//wchar_t türünden

	u'a'; // unicode utf16
	U'a'; // unicode utf32
	// char16_t ve char32_t türleridir
	int b = 48;
	putchar(b);

	// int c = getchar(); // karakter asci yerini alır
	// birden fazla karakter girilirse tampında(buffer) da tutar bafır boş değilse onun değerini alır

	printf("\n%d\n", -11 % 4); // c de -3 kalanı verir
	int c = 3;
	printf("%d  ", ++c * 2); //8
	c = 3;
	printf("%d  \n", c++ * 2);//6

	// 4++ geçersiz sol taraf değeri olması gerekiyor çünki

	int d = 4;
	int f = d = 43;
	printf("%d %d\n", d, f);// bu geçerli

	// int i = j = 34; //! hatalı 

	c = (d = 22, b = 44);
	printf("%d %d %d\n",c , d, b);// c b nin değerini alır



	int n, m, e; // virgül operatör değil ayraç görevinde
	// kuu(a, b); // aynı
	// koo((a, b)); // burda operatör


	printf("%f %f \n", floor(3.5), ceil(4.5)); // alta yuvarla uste yuvarlar

	

		int s = 224;

		{
			int f;
			// int s; // bu yapılırsa dıştaki s in değeri değişmez ama legal
			s = 10;		/* geçerli, a faaliyet gösteriyor  s her yerde değiştirir*/
			int s; // burda tanımlarsan dış bloktaski s değeri değişir ama altaki değişikliklerden etkilenmez
			s =55;
			f = 20;		/* geçerli, b faaliyet gösteriyor */

			{
				double f; // aynı değişkenler farklı faliyet alanlarıda farklı türlerde cağırılabilir
				int s; // bu da legal
			}
		}
		printf("%d\n", s);		/* geçerli, a faaliyet gösteriyor s in yeni değeri yazar */
		printf("%d\n", f);		/* geçersiz! b burada faaliyet göstermiyor */


	int ch;

	while ((ch = getchar()) != 'q')
		putchar(ch);

	for(int i = 0; i < 19; i+=2);

	int i = 0;
	for (; i < 10; i++); // geçerli ve doğru kullanım


	int er = 3;
	int be = 4;
	switch (er)
	{
	case 3:
		printf("aaaaaa");
		case 4: // legal
			printf("aassssssss");
		break;
	
	default:
		break;
	}


// goto <label>; büyük harflarle tanımla genelde öyle
///kod
//goto <label>: alta cıkaçak şekilde kurgula üste de çıkıyor ama tasarımı karmaşıklaştırıyor 
// labeldan sonra değim olması gekekiyor en azından ; 
// aynı fonksyonun içinde kullanılmalı



  // \ bu karakteden sonra enter varsa altan devam et demektir 
	printf("hello\
	world\n");

	int reult = val % 2 == 0 ? 100 : 200;// if e benzer

	if (val % 2 == 0)
		result = 100;
	else
		result = 200;
// aynı anlam ama üsteki daha kompakt 
	printf(val % 2 == 0 ? "cift" : "tek");
	result = a > b ? a > c ? a : c : b > c ? b : c;

// okunurluğu artırmak için parantez kullanılmış
	result = a > b ? (b > c ? b : c) : (b > c ? b : c);












    return 0; 
}

	// %d  ---> signed char, short ve int türlerini 10'luk sistemde yazdırmak için
	// %x  ---> işaretli ve işaretsiz char, short ve int türlerini 16'lık sistemde yazdırmak için
	// %o  ---> işaretli ve işaretsiz char, short ve int türlerini 8'lik sistemde yazdırmak için
	// %ld ---> long türünü 10'luk sistemde yazdırmak için
	// %lld ---> long long türünü 10'luk sistemde yazdırmak için
	// %lx ---> long türünü 16'lık sistemde yazdırmak için
	// %llx ---> long long türünü 16'lık sistemde yazdırmak için
	// %lo ---> long türünü 8'lik sistemde yazdırmak için
	// %llo ---> long long türünü 8'lik sistemde yazdırmak için
	// %u  ---> unsigned char, unsigned short ve unsigned int türlerini 10'luk sistemde yazdırmak için
	// %lu ---> uunsigned long türünü 10'luk sistemde yazdırmak için
	// %f  ---> float ve double türlerini 10'luk sistemde yazdırmak için (default durumda noktadan sonra 6 basamak yuvarlanarak yazdırılır)
	// %e  ---> float ve double türlerini üstel niçimde yazdırmak için.
	// %c  ---> char, short ve int türlerini karakter görüntüsü olarak yazdırmak için


int x;				/* global deişken */

void foo(int n)		/* Parametre değişkeni */
{
	int a;			/* yerel değişken */
	/* ... */
}

int y;				/* global değişken */

int main1(void)
{
	int b;			/* yerel değişken */
	/* ... */

	return 0;
}



	// '\a'		alert (7 numaralı ASCII karakteri), beep sesi çıkar
	// '\b'		back space (8 numaralı ASCII karakteri), sanki back space tuşuna basılmış etkisi oluşur
	// '\f'		form feed (12 numaralı SCII karakterş),  bir sayfa atar
	// '\n'		line feed (10 numaralı ASCII karakteri), imleç aşağı satırın başına geçer
	// '\r'		carriage return  (13 numaralaı ASCII karakteri), imleç bulunduğu satırın başına geçer)
	// '\t'		tab (9 numaralı ASCII karakteri), imle. bir tab ileri gider
	// '\v'		vertical tab (11 numaralı ASCII karakteri), imleç düşey olarak kaydırılır.


//	isupper			Büyük harf bir karakter mi?
//	islower			Küçük harf bir karakter mi?
//	isalpha			Alfabetik karakter mi?
	//isalnum			Alfabetik ya da nümerik bir karakter mi?
	//isdigit			Sayısal bir karakter mi?
	//isxdigit		HEx digit bir karakter mi?
	//isspace			Boşluk karakterlerinden biri mi?
	//ispunct			Noktalama karakterlerinden biri mi?
	//isascii			İlk 128 karakterden biri mi?
	//iscntrl			Kontrol karakterlerinden biri mi? (ASCII tablosunun ilk 32 karakteri kontrol karakterleridir)



// makroyu alt satırdada tanımlama
#include <stdio.h>
#include <stdlib.h>

#define error_check(result)			\
{									\
	if (!result) {					\
		printf("Error!\n");			\
		exit(1);					\
	}								\
}									

//! makroyu bu şekilde parantez içine almak bazı durumlarda hataya yol acar

int main(void)
{
	int test = 0;

	error_check(0);

	if(1)
	error_check(0)//! hataya yol açar ; konulması
	else
	printf("aa");


	return 0;
}

// sorun böyl çözülür
	#define error_check(result)			\
	do  {								\
		if (!result) {					\
			printf("Error!\n");			\
			exit(1);					\
		}								\
	} while (0)



 // anlamına gelir
/*	if (val > 0)
		error_check(status);			/* Burada ';' artık boş deyim olmayacak, do-while deyimini tamamlayan ';' haline gelecek		
	else
		printf("Everything is ok\n");

	Önişmeci makroyu açtığında şu durum olşacaktır:

	if (val > 0)
		do {
			if (!status) {
				printf("Error!\n");
				exit(1);
			}
		} while (0);
	else
		printf("Everything is ok\n");


*/








// include komudu o dosyayı kodun o kısmına yapıştırırı
// yanı define gibi kullanılabilir önemli
#include <stdio.h>
//#include "test.h"
#define SIZE	10
#define square(a)	((a) * (a))


int main(void)
{
	for (int i = 0; i < SIZE; ++i)
		printf("%d\n", i);

	printf("%d\n", square(10));

	return 0;
}

/* test.h */






