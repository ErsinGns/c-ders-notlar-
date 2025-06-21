#include <stdio.h>

//komut satırı argümanları

//argument count == argc sayi
//argv  adres
int main(int argc, char const *argv[])
{
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    



    return 0;
}
//  .\comand_line_arguments.exe ali veli kalem can
//  .\comand_line_arguments.exe "ali veli" kalem can  ali veli tek pointerda tutulur



// main(int argc,char **argv)
// {
// }

// argc -> komut satırını kullanırken yazdığım argüman sayısı + komutun sayısı(1) (copy ali veli   --> argc 3 oldu mesela)
// argv -> gönderilen stringlerin adresleri(char * ptr[] gibi, bunu fonksiyona gönderirken char **p diye göndermek yaygın)
// bu ikisi keyword değil.sadece isim.Genelde bu isimler veriliyor.

// argc ===> Argument Count
// argv ===> Argument Vector
