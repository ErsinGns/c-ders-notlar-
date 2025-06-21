#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    int* p1 = &x;
    int* p2 = p1;

    printf("%d %d %d", p1, p2, &x);
    
    return 0;
}







