// 16 bayta kadar col bay value önemli miktarda maliyet oluşturmaz
#include <stdio.h>
#include <time.h>
#include <locale.h>
int* foo(){
    int x; // hatalı ub static diye tanımlamalısın yoksa çöp değer gönderir
    // static kullan eğer look at table ise kullanmasan belekte durmadan yer ayırır tablo için


    // return &x;
}
 
int main(int argc, char const *argv[])
{
    clock_t start = clock();
    const char *k = setlocale(LC_ALL, "turkish");
    if(!k)
        printf("lokal degistirilemedi");
    else
        printf("locakal ismi : %s \n", k);
    printf("şşşşşşşşççççööööööııııı\n");
    printf("%s\n", "şıçö");
    time_t sec;
    time(&sec);
    struct tm* p = localtime(&sec);

    printf("%d %d %d %d %d:%d:%d\n", p->tm_mday, p->tm_mon, p->tm_year + 1900, p->tm_wday, p->tm_hour, p->tm_min, p->tm_sec);

    printf("%d", p->tm_isdst);// gün işiği tasaruf modu bilgisini verir 0 dan küçükse bilgi tutulmuyor demek 0 sa tasruf modunda değl 0 dan büyükse tasaruf modunda

    struct tm* p1 = gmtime(&sec); // sistemin zamanını verir
    printf("%d %d %d %d %d:%d:%d\n", p1->tm_mday, p1->tm_mon, p1->tm_year + 1900, p1->tm_wday, p1->tm_hour, p1->tm_min, p1->tm_sec);

    time_t tx = 1500000;
    struct tm* tm_p = localtime(&tx);

    const char* p2 = ctime(&tx);// aynı adresi kaplaralar 
    const char* p3 = asctime(tm_p);
    printf("%p %p\n", p2, p3);
    unsigned x = -1;
    printf("en son = %d %u\n" , (unsigned int)-1, x);
    unsigned int i;
    for(i= 0; i < (unsigned) -1; i++);
    printf("%d", i);
    clock_t end = clock();

    printf("gecen sure: %f", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}


//? ATOI

// 	int atoi(const char *p);
// 	alpha to int anlamında.

// 	int main()
// 	{
// 		char str[100];

// 		printf("Bir yazi giriniz\n");
// 		sgets(str);
// 		printf("[%s]\n", str);

// 		int val = atoi(str);
// 		printf("%d\n", val);

// 	}

// 	----------------------------------------------------------------

// 	int main()
// 	{
// 		char str[100];

// 		printf("bir tarih girin gg-aa-yyyy : ");
// 		sgets(str);
// 		printf("[%s]\n", str);

// 		//gün ay yılı ayrıştırmak istiyoruz.
// 		int day = atoi(str);
// 		int mon = atoi(str + 3);
// 		int year = atoi(str + 6);

// 		printf("%02d/%02d/%d", day, mon, year);

// 	}

// 	-------------------------------------------------------------
// 	-------------------------------------------------------------

// 	ATOL , ATOLL, ATOF
// 	atol long döndürür.
// 	atoll long long geri döndürür.
// 	atof double geri döndürür.

// 	int atol(const char *p);
// 	int atoll(const char *p);
// 	int atof(const char *p);


// 	ÖR:
// 	int main()
// 	{
// 		char str[100];

// 		printf("bir sayi girin: \n");
// 		sgets(str);				// 234.1234Ali gir
// 		printf("[%s]\n", str);

// 		int day = atoi(str);
// 		double mon = atof(str);

// 		printf("%d\n", day);
// 		printf("%f\n", mon);
// 	}

//? Buda itoa ile

// 	int main()
// 	{
// 		char str[100];

// 		int x;
// 		printf("bir tamsayi girin : \n");
// 		scanf("%d", &x);		// 47802 güzel bir sayi.
// 		int temp = x;

	// derleyiciler bunu genelde veriyor. _itoa fonksiyonu bunu yapıyor
// 		_itoa(x, str, 10);	
// 		printf("decimal : [%s]\n", str);
// 		_itoa(x, str, 16);	
// 		printf("Hexadecimal : [%s]\n", str);
// 		_itoa(x, str, 2);	
// 		printf("Binary : [%032s]\n", str);
// 		_itoa(x, str, 8);	
// 		printf("Octal : [%s]\n", str);

 		// %032s  = eğer varsa değeri yaz, yoksa yerine 0 yaz.

// 	}

// 3 temel printf var
// 	printf -> formatlı çıkışı konsola yapıyor
// 	sprintf -> çıkışı belleğe yapıyor
// 	fprintf -> çıkışı file a yapıyor.

// 	snprintf

// SSCANF
// 	------

// 	scanf -> değişken setting için std input bufferdan alıyor ihtiyaç duyduğu karakterleri alıyor.
// 	sscanf -> bellekte benim verdiğim adresten alır
// 	fscanf - > dosyadan alır.
