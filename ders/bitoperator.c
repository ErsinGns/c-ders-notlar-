



/*	Bit AND ve OR operatörlerinin "kısa devre (short circuit)" özelliği yoktur. Örneğin:

	a = foo() & bar() & tar();

	Burada her zaman bu üç fonksiyon da çağrılacaktır. (Halbuli mantıksal AND ve OR operatörlerinde bunun bir garantisi yoktur.)

	Aşağıda bit AND operatörü ile mantıksal AND operatörünün kısa devre davranışına ilişkin bir örnek verilmiştir. */


#include <stdio.h>

int foo(void)
{
    printf("foo\n");

    return 0;
}

int bar(void)
{
    printf("bar\n");

    return 0x3F;
}

int tar(void)
{
    printf("tar\n");

    return 0x7A;
}

int main(void)
{
    int result;

    result = foo() & bar() & tar();

    printf("%d\n", result);

    result = foo() && bar() && tar();

    printf("%d\n", result);

    return 0;
}



#include <stdio.h>

int main(void)
{
    int a;

    printf("Bir sayi giriniz:");
    scanf("%d", &a);

    printf(a & 1 ? "tek\n" : "cift\n");

    return 0;
}
#include <stdio.h>

int main(void)
{
    unsigned char a = 0xA2;         /* 1010 0010 */
    unsigned char b = 0x34;         /* 0011 0100 */
    unsigned char c;

    c = a | b;

    printf("%02X\n", c);            /* 1011 0110 = 0xB6 */

    return 0;
}




/*Bit AND operatörü bit OR peratöründen dagh yüksek önceliklidir. Örneğin:

	a = foo() | bar() & tar();

	Burada önce bit AND operatörü yapılır daha sonra bit OR operatörü yapılır. */





if (a & 1 == 0)
    printf("cift\n");
else
    printf("tek\n");

//Burada a & 1 işleminin sonucu 0 iler karşılaştırılmaz.  Önce 1 ile 0 karşılaştırılıp bunun sonucu a ile AND işlemine sokulmaktadır. Halbuki programcı büyük olasılıkla
//a ile 1 değerini AND işlemine sokup sonucun 0 olup olmadığını kontrol etmek istemiştir. Burada paraztez kullanmak gerekir:

if ((a & 1) == 0)
    printf("cift\n");
else
    printf("tek\n");




#include <stdio.h>

int main(void)
{
    unsigned char a = 0x5B;     /* 0101 1011 */
    unsigned char b = 0x7D;     /* 0111 1101 */
    unsigned char c;

    c = a ^ b;                  /* 0010 0110 */

    printf("%02X\n", c);        /* 26 */

    return 0;
}




#include <stdio.h>

int main(void)
{
    unsigned char a = 0x6B;     /* 0110 1101 */
 
    a = a ^ 0x10;

    printf("%02X\n", a);        /* 0111 1011 = 0x7B */
    
    return 0;
}


/*EXOR işlemi geri dönüşümlü bir işlemdir. Yani a ^ b => c ise, c ^ a => b ve C ^ b => a olmaktadır. Örneğin (sembolik olarak):
	
	a = 0110 1101
	b = 1011 0010

	a ^ b = 1101 1111 => c
	c ^ a = 1011 0010 => b
	c ^ b = 0110 1101 => a*/


#include <stdio.h>

int main(void)
{
    unsigned char a = 0x6D;     /* 0110 1101 */
    unsigned char b = 0xB2;     /* 0110 1111 */
    unsigned char c, d, e;

    c = a ^ b;
    printf("%02X\n", c);        /* 1011 1111 = 0xDF */

    d = c ^ a;
    printf("%02X\n", d);        /* 0110 1111 = 0xB2 */

    e = c ^ b;
    printf("%02X\n", e);        /* 0110 1101 = 0x6D */

    return 0;
}



#include <stdio.h>

int main(void)
{
    unsigned char a = 0x6D;     /* 0110 1101 = 0x6D */
    unsigned char b;

    b = a << 1;                 /* 1101 1010 = 0xDA */
    printf("%02X\n", b);        /* 6A */

    b = a >> 1;                 /* 0011 0110 = 0x36 */
    printf("%02X\n", b);        /* 39 */

    return 0;
}


// bir sayıyı n kez sola ötelediğimizde o sayıyı 2 üzeri n ile çarpmış oluruz. 


/*
	1) Eğer sol taraftaki operand işaretsiz bir tamsayı türündense sola öteleme sırasında yukarıda belirtildiği gibi yapılır. Yani tüm bitler bir sola kaydırılır, 
	en soldaki bit yok edilir. Sayı en sağdan 0 ile besleme yapılır. Sağa öteleme sırasında da tüm bitler bir sağa kaydırılır, en sağdaki bit yok edilir. 
	Sayı en soldan 0 ile beslenir. 

	2) Sola öteleme işleminde sol taraftaki operand işaretli bir tamsayı türündense ve pozitifse, sayı 2 ile çarpıldığında çarpımın sonucu hala bu işaretli tamsayı 
	türünün sınırları içerisinde kalıyorsa işlem sonucunda bu iki ile çarpım değeri elde edilir. Eğer işaretli tamsayı negatifse ya da pozitif olduğu halde 
	sayının iki ile çarpılması sonucunda elde edilen değer o işaretli tamsayı türünün sınırları içerisine girmiyorsa "tanımsız davranış (undefined behavior)" söz
	konusudur. Buradan çıkan sonuçlar şunlardır:

	a) Negatif bir tamsayıyı sola ötelemek tanımsız davranışa yol açar. 
	b) Sayı pozitifse ancak sola öteleme sonucunda sayı soldaki operand'ın yükseltilmiş türünün sınırları içerisinde kalmıyorsa (yani bilgi kaybı oluşuyorsa)
	yine tanımsız davranış söz konusudur. 
	c) İşaretsiz tamsayı türlerininin sola ötelenmesinde hiçbir sakınca yoktur. 
	
	3) Sağa öteleme işleminde sol taraftaki operand işartli bir tamsayı türündense ve pozitif ise işlem normal olarak her bitin sağa kaydırılması biçiminde
	yani 2'ye bölme biçiminde yapılır. Ancak sol taraftaki operand işaretli tamsayı türünden ve negatif ise bu durumda işaret bitinin korunup korunmayacağı 
	(yani en soldan 0'la mı 1'le mi besleneceği) derleyicileri yazanların isteğine bırakılmıştır. Buıradan çıkan sonuçlar şunlardır:

	a) İşaretli pozitif bir sayının sağa ötelenmesinde hiçbir sakınca yoktur.
	b) İşaretli begatif bir sayının sağa ötelenmesinde en soldan besleme 1 ya da 0 ile yapılabilir. 1 ile yapılması aslında negatif bir sayının negatif olarak 2'ye 
	bölündüğü anlamına gelir. 0 ile yapılması sayıyı büyük bir pozitif sayı haline getirir. Bu durun derleyicileri yazanların isteğine bırakılmıştır. 
	c) İşaretsiz tamsayı türlerinin sağa ötelenmesinde hiçbir sakınca yoktur.

	Sonuç olarak işaretsiz tamsayılar üzerinde öteleme işlemleri sorunsuz olarak yukarıda anlatıldığı gibi yapılmaktadır. Ancak işaretli sayılar üzerinde öteleme 
	işlemleri yapılırken dikkat edilmelidir. Programcılar genellikle öteleme işlemlerini şişaretsiz tamsayılar üzerinde yaparlar. 

	Yine standartlara göre sola öteleme ya da sağa öteleme işleminde sağ taraftaki operand negatif ise ya da soldaki operand'ın yükseltilmiş türünün 
	bit uzunluğunu aşıyorsa tanımsız davranış söz konusudur. Yani bir sayıyı -1 defa ötelemek istersek derleme aşamsındna geçilir. Ancak programın çalışması 
	sırasında ne olacağı belli değildir. Benzer biçimde biz int türünün 32 bit olduğu bir sistemde unsigned int bir değeri örneğin 40 kere sola ya da sağa ötelersek
	bu durum da tanımsız davranış oluşturur. 
    */



#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t a = 0x12345678;
    int n, result;

    printf("Bit no:");
    scanf("%d", &n);

    result = a >> n & 1;
    printf("%d\n", result);

    return 0;
}


#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t a = 0xAF;
    uint8_t result;

    result = a >> 4 | a << 4;
    printf("%02X\n", result);

    return 0;
}


#include <stdio.h>
#include <stdint.h>

#define LOBYTE(w)   ((w) & 0xFF)
#define HIBYTE(w)   ((w) >> 8 & 0xFF)

int main(void)
{
    uint16_t w = 0x1234;
    uint8_t high, low;

    high = HIBYTE(w);
    low = LOBYTE(w);

    printf("%02X\n", high);
    printf("%02X\n", low);

    return 0;
}


#include <stdio.h>

int main(void)
{
    int a = 0;

    a = ~a;// not

    printf("%d\n", a);      /* -1 */

    return 0;
}


#include <stdio.h>
#include <stdint.h>

void disp_bits32(uint32_t val)
{
    for (int i = 31; i >= 0; --i)
        putchar((val >> i & 1) + '0');
    putchar('\n');
}

int main(void)
{
    uint32_t result;
    int n;

    printf("n: ");
    scanf("%d", &n);

    result = ~(~0u << n);
    disp_bits32(result);

    return 0;
}



#include <stdio.h>
#include <stdint.h>

void disp_bits32(uint32_t val)
{
    for (int i = 31; i >= 0; --i)
        putchar((val >> i & 1) + '0');
    putchar('\n');
}

int main(void)
{
    uint32_t result;
    int n;

    printf("n: ");
    scanf("%d", &n);

    result = ~(~0u >> n);
    disp_bits32(result);

    return 0;
}


/*
	O halde öncelik tablomuzun nihai durumu da aşağıdaki gibidir:

	
	() [] .	->								Soldan-Sağa
	+ - ++ -- !	& *	(tür) sizeof ~			Sağdan-Sola
	* / %									Soldan-Sağa
	+ -										Soldan-Sağa
	<< >>									Soldan-Sağa
	<  > <= >=								Soldan-Sağa
	!= ==									Soldan-Sağa
	&										Soldan-Sağa
	^										Soldan-Sağa
	|										Soldan-Sağa
	&&										Soldan-Sağa
	||										Soldan-Sağa
	?:										Sağdan-Sola
	= *= /= %= += -= <<= >>= &= ^= |=		Sağdan-Sola
	,	
*/


struct SAMPLE {
		double a;
		int b;
		int c: 3;		/* bit alanı elemanı */
		int d: 5;		/* bit alanı elemanı */
	};

/*
Burada yapının a ve b elemanları sırasıyla double ve int türdendir. Ancal c elemanı 3 bitlik bir int nesneyi, d elemanı ise 5 bitlik bir int nesneyi belirtmektedir. 
	n bitlik nesneler ancak yapı elemanları olarak oluşturulabilmektedir. Yapının dışında böyle bir bildirim yapılamaz. 
	*/





	struct TIME {
		int hour;
		int minute;
		int second;
	};

//	Bu yapı muhtemele2 Windows ve UNIX/Linux sistemlerinde 12 byte yer kaplayacaktır. Halbuki aslında zamanının bu bileşenlerinin dörder byte yer kaplamasına 
//	gerek yoktur. Saat bilgisi 5 bit ile, dakika ve saniye bilgileri 6 bit ile temsil edilebilir:

	struct TIME {
		unsigned hour: 5;
		unsigned minute: 6;
		unsigned second: 6;
	};// 4 byte yer kaplar hizalamadan dolayı





















