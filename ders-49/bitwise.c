//~ bitwise not     değişkenin kendi değerini değiştirmez // yan etkisi yok
// << bitwise left shift operators  >> bitwise right shift operators // yan etkisi yok
//& bitwise and
// ^ bitwise exclusive or(exor) 1 1 0 | 0 0 0 | 1 0 1 | 0 1 0 !!x != !! y
// | bitwise or
// <<= >>= &= ^= |=
// yan etkileri yoktur

//! 3 yerine negatif veya bit sayısına eşit yada fazla olamaz
// x << 3  3 birim sola kaydırır sağa 3 tane 0 yazar
// x >> 3  3 birim sağa kaydırır sola 
                             // unsigned sa veya pozitifse 0 yazılır 
                             // signed ve negatifse derleyiciye göre değişir ama her zaman aynı

// x++ & y //! tanımsız davranış

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y;
    printf("iki sayi giriniz:");
    scanf("%d%d", &x, &y);

    printf("x = %d y = %d\n", x, y);

    x ^= y, y ^= x, x ^= y;

    printf("x = %d y = %d\n", x, y);

    return 0;
}
// 49 3.17 cok zekiyce
// look up table 128 karakter indeks karakteri degeri is buyuk harf mi sayı mı vs tutuyor

// BİTSEL OPERATÖRLER
// ------------------------------------------------------------------
// 2	~ ---> bitsel değil operatörü
// ------------------------------------------------------------------
// 5	>> << ---> bitsel sağa/sola kaldırma operatörü.right left shift 
// ------------------------------------------------------------------
// 8   &  ---> bitsel ve
// ------------------------------------------------------------------
// 9   ^ ---> bitsel xor 
// ------------------------------------------------------------------
// 10  | ---> bitwise or
// ------------------------------------------------------------------
// 14  <<= >>= &= |= ^=  ---> işlemli atama operatörleri 
// ------------------------------------------------------------------


// BU OPERATÖRLER TAMSAYI OPERATÖRLERİDİR.
// OPERANDLARI TAMSAYI OLMALI. BİRDE MOD(%) OPERATÖRÜ VAR BÖYLE.
// REEL SAYI SENTAKS HATASIDIR.


// >> ---> bitsel sağa kaldırma operatörü
// << ---> bitsel sola kaldırma operatörü
// Bunların yan etkileri yok.

// ÇOK ÖNEMLİ!!!

// 1 - BİTSEL SOLA KAYDIRMA OPERATÖRÜNÜN SAĞ OPERANDININ, NEGATİF OLMASI DURUMU TANIMSIZ DAVRANIŞTIR.
// 	X << Y  BURADA Y < 0 İSE UNDEFINED BEHAVIOR

// 2 - BİTSEL SOLA KAYDIRMA OPERATÖRÜNÜN SAĞ OPERANDININ TAMSAYI DEĞERİ, SOL OPERANDIN BİT SAYISINDAN BÜYÜK VE EŞİT İSE UNDEFINED BEHAV.
// 	BU DURUM BİTSEL SAĞA KAYDIRMADA DA AYNI.
// 	X << Y 
// 	X İN BİT SAYISI 32 OLSUN, BU DURUMDA Y [0-31] ARALIĞINDA OLMAK ZORUNDA. 32 VEYA DAHA ÇOK UNDEFINED BEHAVIOR
	
// 3 - BİTSEL SOLA KAYDIRMADA (FEEDİNG) SOL OPERANDIN TÜRÜNDEN BAĞIMSIZ OLARAK 0 DIR.

// NOT: 
// 	int x = 25;
// 	printf("%d\n", x);
// 	printf("%d\n", x<<1); // bu ifade x in 2 ile çarpımını elde eder.
// 	printf("%d\n", x<<2); // bu ifade x in 4 ile çarpımını elde eder.

// 4 - BİTSEL SAĞA KAYDIRMADA (FEDDİNG) SOL OPERANDIN TÜRÜNE BAĞLI OLARAK DEĞİŞEBİLİR.
// 	A - UNSİGNED TAMSAYI TÜRLERİ İÇİN SAĞA KAYDIRMADA SOLDAN 0 LAR İLE FEEDİNG YAPILIR
// 		int main()
// 		{
// 			unsigned int x = 2324;
// 			bitprint(x);
// 			bitprint(x >> 3); // sağa kaydırmada, soldan 0 lar gelir çünkü tür unsigned tamsayı türden.
// 		}
		
// 	B - SİGNED TAMSAYI TÜRLERİNDE(İŞARETLİLERDE) 
// 			B.1 - SAYININ KENDISI POZİTİF DEĞER İSE HERZAMAN BESLEME 0 İLE YAPILIR.
// 			(SİGNED TÜRLERDE SAYININ SIFIR OLMASI , 0.... DEMEK. YANİ 0 İLE BAŞLIYOR DEMEK)

// 			B.2 - SAYI NEGATİF DEĞER İSE BESLEME IMPLEMENTATION DEFINED.
// 				  COMPİLERA BAĞLI OLARAK FEEDİNG 0 VEYA 1 İLE YAPILIR.ÖRNEKTEN SONRA DEVAM EDİYOR.
// 				  (SİGNED TÜRLERDE SAYININ NEGATİF OLMASI, 1.... DEMEK. YANİ 1 İLE BAŞLIYOR DEMEK)

// X & ~(1 < n)	yan etkisi yok
// X &= ~(1 < n)	burada yan etki var


int main()
{
	int x,y;

	printf("iki tamsayi gir:");
	(void)scanf("%d%d", &x,&y); // 10 20 gir birde 10 -20 gir

	if ((x ^ y) < 0)
		printf("zit isaretli\n");
	else
		printf("ayni isaretli\n");

}


