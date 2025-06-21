#include <stdio.h>
#include <stdlib.h>
int a[20];
int (*foo(void))[20]
{ //  anın adresini döndürmek için
    return &a;
}


struct data
{
    int x;
    int dizi[5];
};
struct foka
{
    int x;
};

struct DAta
{
    int a, b;
} g;           // global değişken olarak tanımlama
struct DAta g; // aynısı

typedef struct 
{
    int a;
}*DATA;// legal kütüphanelaerde çok kullanılır

struct kale
{
    int x;
    struct kale* p;
};


int main(int argc, char const *argv[])
{
    struct data dx;
    struct data dy;
    dx = dy; // legal  ama maliyetli belek kopyalama yapar
    struct foka fx;
    // dx = fx; // yanlış

    DATA p = (DATA)malloc(sizeof(*p)); //legal çünkü sizeof için işlem kodu üretilmez

    return 0;
}


// time_t = calender time tutar
// 	struct tm = ayrıştırılmış zaman bilgisi tutar
// 	clock_t = iki time point arasındaki geçen süreyi tutan tür.

// 	clock_t clock(void); 
// 	bu fonksiyon mainin çağrılması ile clock fonksiyonunun çağrılması arasıda geçen süre.
// 	türü saniye değil. tick count türünde.
// 	bunu SANİYE türüne çevirmek için CLOCKS_PER_SEC macrosuna bölmek gerekiyor.
