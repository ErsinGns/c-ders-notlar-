#include <stdio.h>
#include <string.h>

#define SIZE 100

char* yaz(void){
    return "ersin";
}

void func(char p[5]){// pointer
    printf("%zu", sizeof p); // türün değerini verir pointer sizeofunu döner 5 yazmaz içine ne yazarsan yaz önemi yok
}

int main(int argc, char const *argv[])
{
    "ersin"; // const değiştirilemez statik ömürlü

    const char* p = "ersin"; // böyle tanımla programın sornuna kadar kalır read only
    char str[] = "ersin";  // değiştirilebilir otomotik ömürlü

    printf("%s\n", yaz()); // gönderilen kelimeyi direk yazar çünki statik ömürlü
    
    const char* p1 = "ersin";
    const char* p2 = "ersin";

    p1 == p2; // bilemeyiz derleyiciye bağlı

    "m"; // string literali dizi 2 elamanlı 
    'm'; // karakter sabiti dizi değil belekte yer tutmaz türü int 
    //! 'ersin'; // sentaks hatası 


    //sizeof  ==> öperatör  size_t geri dönüş değeri
    //strlen ==> fonksiyon  size_t geri dönüş değeri 


    //sizof(str + 12) geçerli 
    //strlen(str + 12) hatalı

    printf("%zu\n", sizeof p + 5); // p pointer olduğu için 4 bayt işlem önceliği var
    printf("%zu\n", sizeof (p + 5)); //  tamamı pointer olduğu için 4 bayt işlem önceliği var

    // sizeof un içerisi için kod üretilmez bir değişiklik oluşturmaz

    char kel[10];
    strcat(kel, "ersin"); // tanımsız davranış ub çünki içerisi çöp deger \0 bulamaz

    char* metin = "er"
                  "sin"; // \ kullanırsan aradaki boşluklarıda alır
    printf("%s\n", metin);


    // strcmp fonksiyonundan devam
	// >0 ise birinci yazı büyük
	// <0 ise ikinci yazı büyük
	// == 0 ise ikiside eşit

	// if(strcmp(s1,s2) == 0) girer ise eşit
	// if(!strcmp(s1,s2)) ise yine eşit

	// if(strcmp(s1,s2)) ise farklı
	// if(strcmp(s1,s2) != 0) ise yine farklı

	// if(strcmp(s1,s2) > 0) ise s1 büyük
	// if(strcmp(s1,s2) < 0) ise s2 büyü
    // yüzü büyüklük küçüklük kavramı
	// sadece yazı değil veriyapı karşılaştırmasında da lexicograpohical
	// algoritma kullanılıyor.

	// 1 3 7 40  bu dizi daha büyük
	// 1 3 7

	// 1 5 7 9
	// 1 6		Bu daha büyük


	// 1 200 300 400 600 700
	// 2	bu daha büyük.

	// ali ata bak
	// veli		bu daha büyük.Asci deki yerine göre

	// BU BİR YAZIDIR
	// ali			bu daha büyük.Ascideki karşılığı daha büyük.

	// _!ali < ?ali
    
    // Birde fonksiyonların n li hali var.fonksiyon bildiriminde fazladan n parametresi var.

	// strcpy için strncpy  -> source adresteki yazının ilk n karakterini dest e kopyalar.
	// strcat için strncat  -> source adresteki yazının ilk n karakterini dest in sonuna ekler
	// strcmp için strncmp  -> source adresteki yazının ilk n karakterini dest ile kıyaslar.

	// NOT:
	// strncpy nin yanlış kullanımı çok yaygın.


    // strncat
	// bir yazının sonuna istenilen uzunlukta başka bir yazıyı ekler.
	// Çok güzel mantıklı bir func.


	// char s1[SIZE] = "mustafa";
	// char s2[SIZE] = "1234567890";
	// strncat(s1, s2 , 5); // strncat(s1, s2 +2, 5); yazsaydım. 4 ten sonrasını birleştirecekti.
	// printf("%s", s1);

    // char s1[SIZE] = "handan";
	// char s2[SIZE] = "kayhan";

	// mesela birinin son ücü ile diğerinin ilk içi eşit mi ?
	// indis ile karakter sayısını karıştırma sakın.s1 0. indisten 3 karakter alacak yani han
	// s2 3. indisten 3 karakter alacak yani yine han.

	// if (!strncmp(s1, s2 + 3, 3))
	// 	printf("yazilar esit\n");
	// else
	// 	printf("yazilar esit degil\n");



    // 1. char p[] = "maya";  UB mi
	// 2. char * ptr = "maya";  UB mi


	// 1. char diziye ilk değer verme sentaksının bileşeni.yani buradaki mert yazısı bellekte ayrı bir
	// dizide tutulmayacak.Ayrıca derleyici tarafından oluşturulan bir dizi yok.
	// yani burada p[0] = 'K'; yapılabilir. UB YOK.

	// 2. burada iki ayrı değişken var aslında.Az önce diziyi değiştirmek UB değil dedik ama
	// burada ptr bir string literalini gösterdiği için bu yazıyı(string literalini) değiştirmek UB dir.
	// Ayrıca "maya" yazısı(yani str literali) programın başından sonuna kadar memoryde kalacak.


    // printf("UMUT"); 
	// bu yazının yani str literalini yazmaktaki amaç ekrana umut yazdırmak
	// bu string literali programın başından sonuna kadar bellekte kalacak.
	// Bunu benim 1 kere çağırmam başka bir durum ama bellekte programın başından 
	// sonuna kadar kalıyor bu string literali.
	
	// Static Ömürlü olmasının bizi ilgilendiren kısımları var.
	// normalde otomatik ömürlü değişkenlerin adresini return edemezdik.Bu UB

	// string literalini ise döndürebiliriz.UB oluşturmaz.
	// Çünkü static ömürlü.

	// char * get_month_name(int m)
	// {
	// 	switch(m)
	// 		{
	// 			case 1: return "ocak";
	// 			case 2: return "subat";
	// 			....
	// 			....
	// 			....
	// 			case 12: return "aralik";
			
	// 		}
	// 	return "";
	// }

	// mesela yukarıdaki kodda UB yok.
	// çünkü string literalleri static ömürlü.

	// string literallerinin dezavantajı ise,
	// öyle bir sistemde çalışmış olalımki, static verilere ayrılmış bellek alanı çok kısıtlı olsun.
	// bu durumda sürekli string literali kullanamayız.


	// NOT:
	// string literalleri değiştirilemez.
	// static ömürlüdür.
	// programın başından souna kadar varlığını devam ettirirler.



    //! Unspecified behavior ==> spesifik olmayan davranış derleyiciye bağlı başka derleyicide başka olabilir
    




    return 0;
}