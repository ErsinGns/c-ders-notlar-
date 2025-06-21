#include <stdio.h>



int main(int argc, char const *argv[])
{
    
    FILE* file = fopen("metin.txt", "r"); // uzantı koymasan kendiliğinden txt algılar
    if(NULL == file) // her zaman kontrol et
    {
        fprintf(stderr, "dosya acilamadi.\n");
        return 1;
    }

    char name[L_tmpnam];
    tmpnam(name); //! the use of `tmpnam' is dangerous, better use `mkstemp'
    printf("name = %s  size = %d", name, L_tmpnam); //eşsiz bir isim ve 20
    // linuxta dosyayı temp klasörünün altında oluşturur

    FILE *crp = fopen(name, "wb"); // bit olarak yazar

    char c; // burada tanımlanmalı yoksa hata verir
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c); // karakter karakter yazar
        putc(c, crp);
    }
    if(rename(name, "a")){// yeni isim verir
            fprintf(stderr, "dosya ismi değiştirilemedi."); // burda ekrana yazar stderr çıkış yeri ayarlardan değiştirilirse oraya yazar
            fprintf(stdout, "ekrana hata yazma"); // ekrana yazar (standart çıkış biimine)
            return 5;
        }
    if(remove("a")){// siler
        fprintf(stderr, "dosya silinemedi.");
        return 5;
    }
    

   fclose(file); // dosyayı kapatır

    //? eşsiz dosya ismi üretme

   





    return 0;
}
