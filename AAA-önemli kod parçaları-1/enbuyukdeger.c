#include <stdio.h>

int max3(int x, int y, int z){
    int max = x;
    if(y > max)
        max = y;
    if(z > max)
        max = z;
    return max;
}


int main(int argc, char const *argv[])
{
    int max = max3(3, 7, 4);
    printf("en buyuk sayi: %d", max);
    unsigned deneme = 25;
        printf("\n%d [%c]", deneme, deneme);

    return 0;
}
