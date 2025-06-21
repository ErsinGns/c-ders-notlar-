#include <stdio.h>

#define OFFSETOF(s, m)  ((size_t)& ((s*)0)->m) // 0 yazılmasının nedeni ne kadar ilerisinde olduğunu bulmak için 
//  2 yazarsan 10  100 yazarsan 108 verir

struct data
{
    int x, y;
    double dval;
    char str[10];
};


int main(int argc, char const *argv[])
{
    printf("%zu \n", OFFSETOF(struct data, x));
    printf("%zu \n", OFFSETOF(struct data, y)); 
    printf("%zu \n", OFFSETOF(struct data, dval));
    printf("%zu \n", OFFSETOF(struct data, str));
    printf("%zu \n", OFFSETOF(struct data, str[4]));



    return 0;
}
