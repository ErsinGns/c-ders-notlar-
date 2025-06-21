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

	while ((ch = getchar()) != 'q') // q girene kadar veri alır
		putchar(ch);

	return 0;



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


