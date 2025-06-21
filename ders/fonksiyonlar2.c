#include <stdio.h>
#include <string.h>
#include <stddef.h>

void *mymemcpy(void *dest, void *source, size_t n)
{
    char *pcdest = (char *)dest;		/* C'de dönüştürme gerekmez, C++'ta gerekir */
    char *pcsource = (char *)source;	/* C'de dönüştürme gerekmez, C++'ta gerekir */

    for (size_t i = 0; i < n; ++i)
        pcdest[i] = pcsource[i];

    return dest;
}





int main(int argc, char const *argv[])
{   
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int b[10];
    
    memcpy(b, a, 40);// kaç bayt kopyalanacağı
    for(int i = 0; i < 10; i++)
        printf("%d ", b[i]);


    char s[] = "ankara";
	char d[100];

	memcpy(d, s, strlen(s) + 1);
	puts(d);


    int c[10];
    memmove(c + 1, a, 9*4);// baştaki elemanı sona getirme 
    c[0]=b[9];
    for(int i = 0; i < 10; i++)
        printf("%d ", c[i]);

    printf("\n%d  %d   %d\n", memcmp(a, b, 40), memcmp(a, c, 40), memcmp(c, a, 40));// eşitse 0 ilki büyükse + ikincisi büyükse - değer döner

    //! 32 bitte göstericiler 4 byte
    //! 64 bit sistemlerde göstericiler 8 byte olurlar 
    //! geriye uyumuluk için bazen 64 bit 4 byte olabilir


    //! sizeof operatörü calıitırılabilir kod üretmez sizeof(x++) değeri artmaz

    char *str;
    str = "ankara";
    printf("%s \n", str);
    

    char ks[100];
    strcpy(ks, "ankara");
    puts(ks);

    //! str[2] = 's'; const olduğu için değiştirilemez
    puts(str);
    ks[3] = 's';// değiştirilebilir
    puts(ks);



    //geniş karakterler 
    wchar_t; // ile gösterilirler  işaretsizdir
    // typedef bildirimidir nicrosoft derleyicisinde 2byte lık unsigned short tur
    //gcc de 4 byte lık unsigned int tir
    //<stddef.h> dosyasının içindedir


    wchar_t ch;
    ch = L'ş'; // başındaki L geniş karakter demektedir
    printf("ch = %llu\n", (unsigned long long)ch); //351 

    wchar_t *sch;
    sch = "ağrı üşöİ"; //! başına L koyunca tek a yazıyor böyle hepsini
    printf("%s\n", sch);  

    //char16_t sad[] = u"ağrı";//16 bitlik
    //char32_t kas[] = U"ağrı";//32 bitlik 
    
    char sdks[] = u8"ağri";// uicode utf-8 


    char *names[] = {"ali", "veli", "selami", "suleyman", "fatih", "ayse", NULL};
    // null adresi gözünce durması için eklenmiştir
	for (int i = 0; names[i] != NULL; ++i)
		puts(names[i]);


    int aq = 10, bq = 20;
    char format[] = "a = %d, b = %d\n";
    int result;

	result = printf(format, aq, bq); // geri dönüş değeri ekrana basılan karakter sayırı
    printf("%d\n", result);     /* 15 */   



	char buf[1024];
	result = sprintf(buf, "a = %d, b = %d", aq, bq);// printf ten farklı olarak ilk parametreye yazar sonuna\0 koyar
	
	printf("buf = %s, result = %d\n", buf, result);


	sprintf(buf + result, "-this is a test-"); // sonuna yazmak istiyorsan bu şekilde yap
	printf("buf = %s, result = %d\n", buf, result);


    //? randomaz 
    //stdlib.h fonksyonundadır
    // RAND_MAX  microsofa 32767 dir gcc de 2147438647 dir  maximum rand gelebilefcek değre


    // srand(time(NULL)) for içince tanımlanması mantıksız çünki program calıştığında zaman bir kez alınır
    
    // result = (double)rand() / RAND_MAX; 0 1 arasında rasgele sayı üretmek için kullanılır
    //! rasgele sayı  üretimini kalıtesi ne kadar uzun süre sonra kendini tekrar ediyor ona bakılarak anlaşılır
    // bir girdi alınır ona işlem uygulanır(karesinin ortasındaki değer gibi) ve sonra rasgele bir sayı elde edilir bu işlem tekrardan bu sayıya uygulanır












    return 0;
}
