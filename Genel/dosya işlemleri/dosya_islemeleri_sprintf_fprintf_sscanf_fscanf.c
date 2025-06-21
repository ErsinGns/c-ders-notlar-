#include <stdio.h>


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

int main(int argc, char const *argv[])
{
    //sprintf

    char buffer[100];
    int age = 25;
    double height = 175.3;
    
    sprintf(buffer, "yas: %d, boy: %.1f cm", age, height);//sitringe yazar
    printf("%s\n", buffer);

    //fprintf

    FILE* f = fopen("metin2.txt", "w");
    if(f == NULL){
        perror("dosya acilamadi.");
    }
    fprintf(f, "yas: %d, boy: %.1f cm\n", age, height);// dosyaya yazar
    fclose(f);

    char buffer1[] = "35 214";

    sscanf(buffer1, "%d %lf", &age, &height); // string parcalar 
    printf("yas: %d boy = %.1f\n", age, height);

    FILE* k = fopen("metin2.txt", "r");
    if(k == NULL){
        perror("dosya acilamadi.");
    }
    
    fscanf(k, "%d %lf", &age, &height);
    printf("yas = %d boy %.1f\n", age, height); // dosyadan okur burda dosya yanlış olduğu için değer atamadı dosya doğru formatlanmış olmalı
    fclose(k);

    return 0;
}
