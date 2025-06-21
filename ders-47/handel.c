#include <stdio.h>
#include <stdalign.h>
#include <stddef.h>
typedef struct data // yazılan sıraya gore belekte yer kaplarlar doğrudan ardısık olmak zorunda degil alignment (64 bit işlemci 64 64 alır bunu sağlamak için ayarlama yapılır)
{
    char z;
    int x;
    char y;
} data;

#define myoffsetof(s, m) ((size_t) & (((s *)0)->m))



// union birlikler

int main(int argc, char const *argv[])
{
    printf("%zu", _Alignof(int));
    printf("%zu", _Alignof(double));
    printf("%zu\n", _Alignof(char));

    printf("%d ", offsetof(data, x)); // kaç sonra x geliyor demek ana adresden ne kadar uzakta
    printf("%d ", offsetof(data, z));
    printf("%d ", offsetof(data, y)); // sizeof tan farklı olmasının  nedeni hizalama

    printf("\n%d ", myoffsetof(data, x));
    printf("%d ", myoffsetof(data, z));
    printf("%d ", myoffsetof(data, y));

    return 0;
}
