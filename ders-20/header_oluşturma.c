// bir başlık dosyasında ilk yapılması gereken multiple inclusion guard
// bir başlık dosyasından birden fazla kez, aynı bildirimin tanımlanması hata olabiliyor.

// tempbel işi çözüm aşağıda.Derleyici yapıyor.std değil.
// #pragma once . pragma bir önişlemci komutu. std değil. derleyiciyi yazanlara bırakılmış ne yapılacağı
// %100 taşınabilir değil.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    double i = 10/3; // 3.000
    printf("i = %f\n", i);
    i = 10/3.;  //3.33333 
    printf("i = %f\n", i);

    return 0;
}
