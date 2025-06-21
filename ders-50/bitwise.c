#include <stdio.h>
#include <stdint.h>

// bitfields (bit alanları)
// bitfield members of structures

struct Data
{
    int x : 3; // 3 bitlik yer kaplar
    int y : 6; // 6 bitlik yer kaplar
    unsigned int z : 2;
}; // adresleri kullanılamaz
// bit alanı elemaları adres elemaı olarak kullanılamaz

struct time
{
    unsigned int mday : 5;
    unsigned int mmon : 4;
    unsigned int myear : 7;

    unsigned int mhour : 5;
    unsigned int mmin : 6;
    unsigned int msec : 5; // 6 dersen 8 bayt 5 dersen 4 bayt
};

typedef union
{
    uint32_t uval;
    struct
    {
        unsigned int mday : 5;
        unsigned int mmon : 4;
        unsigned int myear : 7;

        unsigned int mhour : 5;
        unsigned int mmin : 6;
        unsigned int msec : 5; // 6 dersen 8 bayt 5 dersen 4 bayt
    };
} timePoint;

int main(int argc, char const *argv[])
{

    struct Data d = {.z = 2};
    printf("%d", d.z);
    printf("%zu ", sizeof(d)); // katları şeklinde tutulur
    // printf("%zu %zu %zu", sizeof(d.x), sizeof(d.y), sizeof(d));

    struct time t;
    printf("\n%zu\n", sizeof(t));

    timePoint t2;
    printf("%zu\n", sizeof(t2));
    return 0;
}
BİT FİELDS / BİT ALANLARI
--------------------------


typedef struct {
	//Yapının x isimli elemanı 4 bitlik alanda tutulacak demek.
	unsigned int x : 4;
}Data;


int main()
{

	Data mydata;
	mydata.x = 5; // derleyici burada x i 4 bitlik bir alanda tutacak. Bunu bitsel operatör kullanarak yapmıyoruz.
					// compiler bizim için yapıyor.Çok zahmetli oluyor zaten bitsel operatörlerle.
					//birde compiler her zaman daha iyi kod yazıyor zaten.Optimizasyon ....

	Data* p = &mydata;
	p->x = 4;

}

------------------------------------

Yapının elemanları birden fazla olabilir. genelde böyle zaten.
bitfield elemanlarla olmayan elemanlar aynı yerde olabilir.


typedef struct {
	int a,b;
	double d;
	unsigned int x : 4;
	unsigned int y : 3;
	unsigned int z : 2;
	unsigned int t : 5;
}Data;

