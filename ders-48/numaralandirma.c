#include <stdio.h>

// enumaration constant    enumarator

enum Color{ // tanımlanmazsa belekte yer kaplamaz derleme zamanı kodun yerine yazılır uzerine getirirsen değerini gösteriri
    white, red, brown = 44, blue, black = 10, orange = 10
};

//  # defendan farkı 
// definda derleyici görmez  önişlemci görür
// definde scobe kavramı yoktur 


//enumda sucobe kavramı vardır
// enumda tür kavramı vardır
enum traficcolor{
    //! red, 
    green, yellow // sentax hatası nedeni red in yazılması çünki global alanda iki tane aynı isimde tanımlanmıs
};



int main(int argc, char const *argv[])
{

    printf(" %d  %d %d %d %d %d \n", white, red, brown, blue, black, orange);
    printf("%u\n", -1);

    enum {size = 100};
    int a[size];
    printf("%zu\n", sizeof(a));

    unsigned int x = -1; // 0 dan başladığı için 2 ^32 -1 şeklinde yapılır
    printf("%u\n", x);
    
    return 0;
}
