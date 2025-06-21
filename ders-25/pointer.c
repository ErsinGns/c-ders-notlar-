#include <stdio.h>

int main(int argc, char const *argv[])
{
    int  x = 3;
    int* p = &x;
    p = &x;
    printf("x = %d &x = %d *p = %d p = %d &p = %d\n", x, &x, *p, p ,&p);

    int a[5] = { 0 };
    int * ptr ;
    ptr = a;
    printf("&a[0] = %p\n", &a[0]); // hepsi bir birinin aynısı
    printf("a     = %p\n", a);
    printf("a     = %p\n", ptr);
 
    // int *a, *b, *c; != int* a, b, c; 
    


    return 0;
}
