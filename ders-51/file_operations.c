// https://docs.fileformat.com   bu linke bak
#include <stdio.h>

// fclose da kontrol edilebilir ifin içine girerse kapatılamamış demektir

// formatsız giriş fonksiyonu fgetc(file *) EOF(-1) demek dosyanın sonuna geldiğini söyler end of file
// dosya kapatılmasa veri kaybı olabilir


//wb daha az yer kaplar nedeni 14 w dersen 1 4 diye yazar wb dersen 14 diye yazar


// r dersen 26 karaketeini eof algilar rb de algılamaz
int main(int argc, char const *argv[])
{
    FILE *f = fopen("./file_operations.c", "r");// .c yazmasan difold .txt dir
    if (f == NULL)
    {
        fprintf(stderr, "dosya acilamadi\n");
    }
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }
    fclose(f);
    char name[100] = "Ersin"; // var olan yazıyı siler ve yerine altakini yazar
    sprintf(name, " naber%s", " nasislsin?");
    printf("\n(%s)\n", name);

    char temp_filename[L_tmpnam];
    tmpnam(temp_filename);
    printf("%s\n",temp_filename);
    for(int i = 0; i < 90; i++){
        tmpnam(temp_filename);
        printf("%s\n",temp_filename);
    }

    // fcloseall(); standart değil açık olan tüm dosyaları kapatır geri dönüş değeri kapatılan dosya sayısı


if (argc != 2)
	{
		fprintf(stderr, "kullanim hsay - dosya ismi\n");
		return 1;
	}

	FILE* f = fopen(argv[1],"r");
	if (!f)
	{
		fprintf(stderr, "%s dosya acilma hatasi", argv[1]);
		return 2;
	}

	int count[26] = {0};
	int c;

	while ((c = fgetc(f)) != EOF)
	{
		if (isalpha(c))
		{
			count[toupper(c) - 'A']++;
		}
	}

	fclose(f);

	for (size_t i = 0; i < 26; ++i)
	{
		printf("%c ==> %d adet\n", i + 'A', count[i]);
	}

    return 0;
}
// atoi stringi inte çevirir

// unique file name generator == olmayan dosya ismi üretir 
//char *tmpanm(char* filename);

// AŞIRI ÖNEMLİ !!!!!!!!!!!!!!!!!!!!!!!!!!!
// WINDOWSTA DOSYAYI TEXT MODUNDA YAZMA AMAÇLI AÇARSAK
// DOSYAYA NEWLINE KARAKTERINI YAZDIĞIMIZDA DOSYAYA 1 BYTE YERINE 2 BYTE YAZILIR \13 \10 YAZILIR.
// FGETC ILE OKUNDUĞUNDA DAHA KÖTÜ, SADECE \10 LAR GÖRÜLECEK
// AMA BUNU DAHA SONRA BINARY MODE ILE R MODDA AÇARSAK \13 \10 LARIN IKISINIDE GÖRÜRÜZ.


// DOSYAYI BINARY MODUNDA YAZMA AMAÇLI AÇARSAK
// DOSYAYA NEWLINE KARAKTERINI YAZDIĞIMIZDA DOSYAYA 1 BYTE YAZILR \10 YAZILIR.
// ÖRNEĞİ VAR AŞAĞIDA
// BİRDE 26 nolu byte konusu var ctrl-z yani

// ------------------------------------------------------------------------------------------------------

// 2 byte yazmasının sebebi tarihsel
// daktiloda satırbaşı 2 harekette yapılıyormuş,
// birincisi aşağı iniyor ikincisi satırın başına alıyor.	
// biri carriage return diğeri newline character.




//! ÇOOK ÖNEMLİ !!!!!!!!!!!!!

// ESKIDEN DOSYA SONUNU BELIRTEN TAMSAYI DEĞERI VARDI VE BU GELENEK DEVAM EDIYOR.
// BU CTRL-Z KARAKTERI. VE ASCI KODU 26 DIR.

// DOSYA TEXT MODDA AÇILIRSA, BINARY DOSYADAKI BYTELARDAN BIRI 26 ISE, OKUMA YAPAN FONKSIYON BUNU DOSYA SONU OLARAK GÖRECEK
// VE OKUMA IŞLEMI SONLANACAK.




// FPRINTF
// int fprintf(FILE *, const char *,...) ; variadic  ------------> dosyaya yazıyor
// int sprintf(char *buf, const char *,...) ; variadic ----------> memoryye yazıyor
// int printf(const char *,...) ; variadic ----------------------> Std outputa yazdırıyor

// SSCANF
// int fscanf(FILE *, const char *,...) ; variadic  ------------> file dan aldıklarını değişkenlere yazıyor
// int sscanf(char *buf, const char *,...) ; variadic ----------> bir diziden dan aldıklarını değişkenlere yazıyor
// int scanf(const char *,...) ; variadic ----------------------> std inputtan aldıklarını değişkenlere atıyor.







