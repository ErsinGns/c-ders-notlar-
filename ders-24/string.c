#include <stdio.h>


int main(int argc, char const *argv[])
{
    // NUll terminated byte stream. yazıların tutulma şekli C de böyle.
    int x = 0;
    int y = '\0';
    int z = '0';
    //char t = "0"; //nedense warning veriyor 
    const char t[] = "0"; // doğru yazım bu
    printf("0 = %d  /0 = %d '0' = %d\n", x, y, z);

	// char a[SIZE]; -> burada yazının sonundaki null character görmeden yazı uzunluğunu bilme şansı yok
    // s[i] != '\0' burada s[i] != 0  olsada farketmez. aynı şey.

    //static tanımlama name ulaşılabilirliği dışında global alanda tanımlamayla aynı şey
    char isim[] = "ersin";
    printf("boyut = %d\n", sizeof(isim));

    // diziye ilk değer verme santaksiyla değer verilerse değer atanmayan indexlere 0 yazılır

    int len = printf("%s", isim); //printfin geri dönüş değeri ekrana yazılan karakter sayısıdır
    printf("\nisim uzunlugu = %d", len);
    




    return 0;
}