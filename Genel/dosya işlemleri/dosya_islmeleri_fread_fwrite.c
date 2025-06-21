#include <stdio.h>
#include <stdlib.h>
// formatsız okuma ve yazma işleminde kullanılır

// size_t fread(void *vpbuf,size_t sz, size_t n,FILE *f); 

// 	f = BU HANDLE DAN DATALAR OKUNUR
// 	vpbuf = BURADAKİ DEĞERE YAZILIR
// 	sz = BİR ELEMAN BOYUTU
// 	n = KAÇ ELEMAN OLDUĞU BİLGİSİ.
// 	RETURN DEĞERİ KAÇ DEĞERİ OKUYABİLDİĞİ.Okuyamazsa 0

// 	size_t write(const void *vpbuf,size_t sz, size_t n,FILE *f);

// 	vpbuf = BURADAKİ DEĞERDEN DATALAR OKUNUR
// 	f = BU HANDLE A YAZILIR
// 	sz = BİR ELEMAN BOYUTU
// 	n = KAÇ ELEMAN OLDUĞU BİLGİSİ.
// 	RETURN DEĞERİ KAÇ DEĞERİ YAZABİLDİĞİ.Yazamazsa 0

int main(int argc, char const *argv[])
{  
    FILE* f = fopen("metin.bin", "rb");

    if(f == NULL){
        fprintf(stderr, "dosya acilamadi.");
        return 1;
    }
    char buffer[100];

    size_t bytes_read = fread(buffer, sizeof(char), 50, f); // sonuna gelince daha fazla okumaz 

    for(size_t i = 0; i < bytes_read; i++){
        printf("%c", buffer[i]);
    }

    fclose(f);

    FILE* file = fopen("metin.bin", "wb");
    

    size_t items_witten = fwrite(buffer, sizeof(char), 18, file); // eğer fazla değer yazdırırsan random değer yazar

    printf("yazilan miktar = %zu\n", items_witten);
    

    fclose(file);

    FILE* k = fopen("metin.bin", "r");

    char c;
    while ((c = fgetc(k)) != EOF)
    {
        putchar(c);
    }
    


    return 0;
}
