

const int a = 20;
int const a = 20;
// ikiside aynı



const int *pi; // içindeki değer const
int const *pi; // aynı iekilde
// pi değiştirilebilir ama *pi değiştirilemez

int* const pi; // adres const demek
// *pi değiştirilebilir ama pi değiştirilmez

int const* const pi; // ikisisde const
const int* const pi; // ayno


const int a = 10;
int *pi;// const olması gerek const int* pi;

pi = &a;		/* geçersiz! */
*pi = 20;

//! eğer bir şeyi değiştirmeyeceken mutlaka const kullan





#include <stdio.h>

typedef const int *PI;

int main()
{
    int a = 10, b = 20;
    PI pi = &a;

    pi = &b;        /* geçerli, pi'nin gösterdiği yer const */
    printf("%d\n", *pi);
   //! *pi = 20;       /* geçersiz! pi'nin gösterdiği yer const! */

    return 0;
}

/*Gösterici olmayan parametre değişkenlerinin const olmasının okunabilirlik bakımından hiçbir anlamı yoktur. Örneğin:

	void foo(const int a);

	Burada a'nın const olup olmaması fonksiyonu yazanı ilgilendiren kullanını ilgilendirmeyen bir durumdur. Dolayısıyla dış dünyaya faydalı hiçbir bilgi 
	vermemektedir. Parametre değişkenlerinin gösterici olmadıktan sonra const biçimde bildirilmesi iyi bir teknik değildir. */






//volatile 
/*Şimdi volatile anahtar sözcüğünün neyi sağladığını açıklayalım. Biz bir nesneyi volatile anahtar sözcüğü ile tanımlarsak derleyiciye şunları
	söylemiş olmaktayır: "Derleyici, bu nesnenin dışarıdan başka bir el tarafından değiştirilme gibi bir durumu var. Dolayısıyla ben bu nesne dışarıdan
	değiştirildiğinde değişikliği hemen anlamak istiyorum. Ben ne zaman bu nesneyi kullansam sen onu yazmaca çekmiş olsan bile yazmaçtaki halini 
	kullanma. Taze taze onu yeniden bellekten çek ve kullan."
*/

volatile int x;
int volatile x;

/*1) Dışarıdaki bir el benim programındaki bir nesnenin değerini nasıl değiştirebilir? İşte bu başka el bazen bir thread olabileceği gibi bazen de bir 
	"kesme kodu (interrupt handler)" olabilmektedir. 

	2) Derleyicinin bu nesnenin dışarıdan değiştirilebileceğini dikkate alıp bu tür optimizasyonları yapmaması gerekmez mi? Derleyiciler bir nesnenin başka "
	bir el tarafından dışarıdan değiştirileceğini varsaymamaktadır. Bu çok özel bir durumdur. Eğer derleyiciler böyle bir varsayımda bulunup ona kod üretselerdi
	üretilen kodun kalitesi hız bakımından düşük olurdu. Bu özel durumun programcı tarafından dikkate alınması gerekmektedir. 

*/

volatile int flag;
...
flag = 0;
while (flag == 0) {
    ...
}

/*	volatile niteleyicisi nadir biçimde kullanılmaktadır. Eğer çok thread'li uygulamalar ya da birtakım kesme kodlarının oluşturulduğu uygulamalar söz konusu 
	değilse volatile niteleyicisine gereksinim duyulmaz. */

/*	volatile int *pi;					/* kendisi değil, gösterdiği yer volatile olan gösterici 
	int * volatile pi;					/* gösterdiği yer değil kendisi volatile olan gösterici 
	volatile int * volatile pi;			/* hem kendisi hem de gösterdiği yer volatile olan gösterici */




const volatile int *pi;// ve türevleri kullanılabilir










