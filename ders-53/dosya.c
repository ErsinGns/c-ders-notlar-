#include <stdio.h>

#define NDEBUG // bu yazılmışsa assert makrosuna girmez kodda ekstra yer kaplamasını engelr
#include <assert.h>

//fflush(NUll) açık olan tüm dosyaları flash eder

//feof() bayraktır son karakter okunup (okunmadığında) 1 döner

// fprintf(stdout, "ali"); // ekrana yazar (standart cıkış birimine)
// stdout dan dolayı


//printf("ali");  // ekrana yazma garantisi yok // altakinin gerekmemesinin sebebi tie(bağlanmış) 
//fflush(stdout); // ekran ayazma garantisi getirir

// stderr standart hata akımı stdout dan farkı standart cıkış akımına yazmak zorunda değilsin yönlendirebilirsin
//cmd den programın adı > nereye yazılacağı şeklinde yapabilirsin
// programın adı < girişin neresi olugunu  burdan alır

void func(int p[const]){// int * const p ile aynı anlam c 99 la geldi

}
void foo(int p[static 20]){ // adresi gönderilen dizinin minimum adedi 20 olmalı 20 den az olursa hata veriri 

}


int main(int argc, char const *argv[])
{
    int x = 3;
    assert(x == 0); // hatalı olduğu zaman çalışır koda ektıra maliyeti vardır

    int a[4] = { 0, 1, 2, 3};
    int (*p)[4] = &a;

    return 0;
}


// 1- FREAD/FWRITE
// 	DOSYALARDAN FORMATSIZ OKUMA VE DOSYALARA FORMATSIZ YAZMA YAPILIYOR.
// 	EN ÇOK KULLANILANLARDAN BİRİ GRUP.

// 	A- size_t fread(void *vpbuf,size_t sz, size_t n,FILE *f); 

// 	f = BU HANDLE DAN DATALAR OKUNUR
// 	vpbuf = BURADAKİ DEĞERE YAZILIR
// 	sz = BİR ELEMAN BOYUTU
// 	n = KAÇ ELEMAN OLDUĞU BİLGİSİ.
// 	RETURN DEĞERİ KAÇ DEĞERİ OKUYABİLDİĞİ.Okuyamazsa 0

// 	B- size_t write(const void *vpbuf,size_t sz, size_t n,FILE *f);

// 	vpbuf = BURADAKİ DEĞERDEN DATALAR OKUNUR
// 	f = BU HANDLE A YAZILIR
// 	sz = BİR ELEMAN BOYUTU
// 	n = KAÇ ELEMAN OLDUĞU BİLGİSİ.
// 	RETURN DEĞERİ KAÇ DEĞERİ YAZABİLDİĞİ.Yazamazsa 0

// 	================================================================

// 	2- FPUTS/FGETS
// 	DOSYALARA LİNE YAZMAK VEYA OKUMAK İÇİN KULLANILIR.

// 	A- char* fgets(char *buffer,int n,FILE *f);,

// 	return değeri buradaki adres olan buffer değeridir. Hata olursa NULL pointer döner
// 	\n karakterini line by line gittiği için otomotik koyar.zaten satır sonunda \n var.Bunuda alıyor yani.
// 	f = OKUMA YAPILAN HANDLE
// 	n = KAC ADET OKUMA YAPILACAĞI
// 	buffer = BU OKUMANIN YAZILACAĞI DİZİ.

// 	NOT: ÇOK ÖNEMLİ !!!!!!!
// 	EĞER BUFFER SİZE DAN DAHA KÜÇÜK BİR KARAKTER OKURSA, DATAYI OKUR BUFFERA YAZAR VE SONUNA \n DEĞİL \0 KOYAR.
// 	KISACA, \n KARAKTERİNE KADAR OKURSA BUNUDA ALIR, AMA \n KARAKTERİ YOKSA VE BUFFER DOLDUYSA SONA \0 KOYAR.



// 	B- int fputs(char *buffer,FILE *f);
// 	return değeri başarılı ise non-negative değer. Hata durumunda EOF
// 	buffer = buradaki dizileri alır
// 	f = buradaki handle a line olarak girer.

// 	==========================================================================

// 	3- SPRINTF/FPRINTF - SSCANF/FSCANF

// 	FORMATLI OKUMA YAZMA
// 	BELLEKTEKI BYTELARI, VERIYI IFADE EDEN KARAKTER KODLARINA DÖNÜŞTÜRMEK VE BU KARAKTER KODLARINI
// 	ALMAK YADA GÖNDERMEK.

// 	A- PRINTF
// 	int fprintf(FILE *, const char *,...) ; variadic  ------------> dosyaya yazıyor
// 	int sprintf(char *buf, const char *,...) ; variadic ----------> memoryye yazıyor
// 	int printf(const char *,...) ; variadic ----------------------> Std outputa yazdırıyor

// 	return değer yazdırılan karakter sayısı.
// 	BURASI ASLINDA BİR YAZIYI ELDE ETMEK İÇİN KULANILIYOR.

// 	B- SCANF
// 	int fscanf(FILE *, const char *,...) ; variadic  ------------> file dan aldıklarını değişkenlere yazıyor
// 	int sscanf(char *buf, const char *,...) ; variadic ----------> bir diziden dan aldıklarını değişkenlere yazıyor
// 	int scanf(const char *,...) ; variadic ----------------------> std inputtan aldıklarını değişkenlere atıyor.
	
// 	Geri dönüş değeri başarılı okunan eleman sayısı. 
// 	Eğer okunacak karakter kalmamışsa EOF(-1) döndürür.

// 	veri 1 2 3   ise fscanf %d %d %d   nin geri dönüş değeri 3 tür
// 	veri 1 2 ali   ise fscanf %d %d %d   nin geri dönüş değeri 2 dir
// 	veri 1 veli ali   ise fscanf %d %d %d   nin geri dönüş değeri 1 dir
// 	veri hasan veli ali   ise fscanf %d %d %d   nin geri dönüş değeri 0 dır
// 	file sonu ise geri dönüş değeri EOF

// 	==========================================================================

// 	4- FPUTC/FGETC

// 	A-int fputc(int c,FILE *);

// 	buda dosyaya yazma fonksiyonu.
// 	geri dönüş değeri başarısız ise EOF yani -1, başarılı ise dosyaya yazılan byte ın değeri.
	
// 	B-int fgetc(FILE *);
// 	getchar fonksiyonuna benziyor. getchar standart inputtan alıyordu, bu ise dosyadan karakter alıyor.
// 	Geri dönüş değeri 0 ile 255 aralığıunda olacak.
// 	başarısız olursa int türden EOF yani -1 döndürecek.



// 2. dosyadan okuma yöntemi fscanf ile

int main()
{
	FILE* f = fopen("kayit.txt", "r");
	if (!f)
	{
		fprintf(stderr, "Dosya acilamadi\n");
		return 1;
	}

	char str[100];
	int count = 0;
	while (fscanf(f, "%s", str) != EOF) // fgets ile yaparsak != NULL dememiz lazım.
	{
		printf("%-5d %s\n", count++, str);
		_getch();
	}
	fclose(f);
}





//? DOSYALARDAN FORMATSIZ OKUMA VE FORMATSIZ YAZMA İŞLEMLERİ.
// ---------------------------------------------------------
// UNFORMATTED INPUT OUTPUT OPERATION

// Formatsız yazma demek bir verinin bellekteki bitlerine bakıyor ve bunları dosyaya yazmak demek.

// bellekteki byteları oldukları gibi dosyaya transfer etmek 
// dosyadaki byteları oldukları gibi belleğe transfer etmek
// En önemlileri bunlardiyor hoca.
// Formatsız okuma yazma


// size_t fread(void *vpbuf,size_t sz, size_t n,FILE *f);

// sz = bu kadar bytelık bloklardan
// n = bu kadar tanesini
// f = buradan okuyup
// vpbuf = buraya yazıyor.
// Return değeri başarılı okuma sayısıdır.


// size_t fwrite(const void *vpbuf,size_t sz, size_t n,FILE *f);
// tam tersini yapıyor yukarıdakinin.
// sz = bu kadar bytelık bloklardan
// n = bu kadar tanesini
// vpbuf = buradan okuyup.
// f = bu kısma yazıyor.
// Return değeri yazdığı blok sayısıdır.


//bir dosyaya formatsız olarak ilk n asal sayının yazdırılması
int main()
{
	char filename[100];
	int n;
	printf("dosya adi\n");
	scanf("%s", filename);
	printf("kac asal sayi yazilsin\n");
	scanf("%d", &n);

	printf("%zu bytelik %s dosyasi olusacaktir\n", sizeof(int) * n, filename);

	FILE* f = fopen(filename, "wb");
	if (!f)
	{
		fprintf(stderr,"%s dosyasi olusturulamadi\n",filename);
	}

	int prime_count = 0;
	int x = 2;
	while (prime_count < n)
	{
		if (isprime(x))
		{
			fwrite(&x,sizeof x,1,f);
			prime_count++;
		}
		x++;
	}

	fclose(f);

}


// int fseek(FILE *f, long n, int origin); başarılı olursa 0 döndürür.başarısız olursa nonzero
// f = dosya handle 
// n = ne kadar ileri veya geri alacağını belirtir. ileri için +, geri için - değer.
// origin = konumlandırmanın origin olarak neresi alınarak yapılacağını bildiriyor.
// 	SEEK_SET = 0 => Konumlandırma dosyanın başından itibaren yapılacak
// 	SEEK_CUR = 1 => konumlandırma dosyanın file pointerın son konumuna göre yapılır.
// 	SEEK_END = 2 => konumlandırma dosyanın sonundan itibaren yapılır
		 




// Dosyanın başından ileri gidilebilir ama geri gidilirse UB oluşur.
// fseek(f,100,SEEK_SET) -> FILE PTR dosyanın başından başlayıp 100 offsetine gider
// fseek(f,0,SEEK_SET) -> FILE PTR Dosyanın başına gider.
// fseek(f,-100,SEEK_END) -> sondan 100 tane geri gelir.
// fseek(f,0,SEEK_END) -> FILE PTR ı dosyanın sonuna gönderir. 1 dosyayı append etmek için kullanılabilir.
// fseek(f,10,SEEK_CUR) -> FILE PTR son konumundan 10 ileri
// fseek(f,-10,SEEK_CUR) -> FILE PTR son konumundan 10 geri
// fseek(f,0,SEEK_CUR) -> FILE PTR son konumuna getirilir. BU ÇOK ÖNEMLİ. UB engelleyen senaryolar var burada.





	int main()
{

	FILE* f = fopen("asal1000.dat", "rb");
	if (!f)
	{
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	if (feof(f)) // set edilmemiş çıkacak bu burada
	{
		printf("eof bayragi set edilmis\n");
	}
	else
	{
		printf("eof bayragi set edilmemis\n");
	}

	fseek(f, 0L, SEEK_END); // dikkat

	if (feof(f)) // yine set edilmemiş çıkacak burada çünkü henüz başarısız okuma olmadı.
	{
		printf("eof bayragi set edilmis\n");
	}
	else
	{
		printf("eof bayragi set edilmemis\n");
	}

	//dikkat
	int c = fgetc(f);
	printf("c = %d\n", c);

	if (feof(f)) // yukarıda sonda iken okuma yapılmaya çalışılmış.okuma yapılamamış.EOF FLAG TRUE OLDU
	{
		printf("eof bayragi set edilmis\n"); //buraya girer
	}
	else
	{
		printf("eof bayragi set edilmemis\n");
	}

}