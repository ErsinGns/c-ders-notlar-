#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct erg
{
    double d1, d2;  
}erg;

typedef struct intin
{
    int x, y , z;
}intin;


typedef struct nec
{
    int x, y, z;
    struct erg e;
}nec;


struct kal
{
    int a;
    struct lam
    {
        int z;
    }; 
    struct 
    {
        int z;
    }kali, u; 
};


// chec ( l1 l2 l3) atama da sıkıntı çıkara dynamicte sıkıntı yok 
// algoritmanın karmaşıklığı gene önemli (on on^2) gibi
// simd == bir clock saykılda birden fazla işlem yapmayı sağlar ama belekte verinin ardışık olması lazım (bir artırmak gibi)
typedef struct Node// dugum 
{
    struct Node* before; // adresi burayla eslestirilir
}Node;
//  en sık dynamic array kullanılır
//




//alignemnt  == hizalama fazla cıkmasının nedeni
int main(int argc, char const *argv[])
{
    clock_t start = clock();
    for(int i = 0; i < 100; i++)
        printf("a");
    clock_t end = clock();
    printf("\n sonuc : %f\n", (double)(end - start)/ CLOCKS_PER_SEC); // sureyi olcmek icin kullanılır

    printf("erg = %zu\n", sizeof(erg));
    printf("intin = %zu\n", sizeof(intin));
    printf("nec = %zu\n", sizeof(nec)); // fazla cikar nedeni alignemnt

    struct lam l1; // legal

    struct kal k;
    k.kali.z = 5; // legal olması gerek ama hata veriyor
    k.u.z = 4;

    return 0;
}
