#include <stdio.h>
// structure member(S)

struct data // bir tür
{
    int x, y;
    double dval;
    char str[20];
};
typedef struct
{
    int yas;
}ogr;


int main(int argc, char const *argv[])
{
    struct data mydata; // bu şekilde kullanılır
    // . dot operator kendisne bulasır
    // -> arrow operator adresini ister


    mydata.x = 2;

    ogr o1;
    o1.yas = 21;
    ogr *o2;
    o2->yas = 3;
    
    printf("%d\n", o1.yas);
    printf("%d", o2->yas);

    return 0;
}
