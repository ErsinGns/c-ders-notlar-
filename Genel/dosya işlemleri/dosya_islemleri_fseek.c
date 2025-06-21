
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

#include <stdio.h>

	int main()
{

	FILE* f = fopen("metin2.txt", "rb");
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