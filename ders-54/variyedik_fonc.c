#include <stdio.h>
#include <stdarg.h> // ... için

void func(int x, int y, ...) {// ... sonuncu parametre olması gerekiyor en az 3 karakter ister x ve y den dolayı

}

int vmax(int x, ...) { // kaç karakter gönderileceği == x
    va_list args;
    va_start(args, x);// arg listesi oluşturur
    for (size_t i = 0; i < x; i++)
    {
        int deger = va_arg(args, int); // int yerine türü gelecek
    }
        
}

// int dmax(...){// ... son parametresi -1 if le kontrol et cık

// }

void main(int argc, char const *argv[])
{
    
    return 0;
}



int factorial(int x)
{
	return x < 2 ? 1 : x * factorial(x - 1);
}