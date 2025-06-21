#include <stdio.h>
// 	A-int fputc(int c,FILE *);

// 	buda dosyaya yazma fonksiyonu.
// 	geri dönüş değeri başarısız ise EOF yani -1, başarılı ise dosyaya yazılan byte ın değeri.
	
// 	B-int fgetc(FILE *);
// 	getchar fonksiyonuna benziyor. getchar standart inputtan alıyordu, bu ise dosyadan karakter alıyor.
// 	Geri dönüş değeri 0 ile 255 aralığıunda olacak.
// 	başarısız olursa int türden EOF yani -1 döndürecek.


int main(int argc, char const *argv[])
{
    FILE* file = fopen("metin2.txt", "w");
    if(file == NULL){
        perror("dosya acilamadi.");
        return 1;
    }

    char text[] = "kus neden ucar.\n";
    for(int i = 0; text[i] != '\0'; i++){
        if(fputc(text[i], file) == EOF){
            perror("yazma hatası.");
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    FILE* f = fopen("metin2.txt", "r");
    if(f == NULL){
        perror("dosya acilamadi.");
        return 1;
    }
    
    char c;

    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }
    fclose(f);



    return 0;
}
