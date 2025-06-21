#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 3;
    int *p = &x;
    printf("%p\n", p);
    printf("%p %d %p\n",p, *p++, p); // elamanı verir ve pointerı bir artırır
    printf("%d %p", *p, p);


    return 0;
}
