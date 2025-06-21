#include <stdio.h>


int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 20;

    int z = x || y++;

    printf("%d\n", x);
    printf("%d\n", y); // değişmemesinin nedeni kısa devre olması
    printf("%d\n", z);



    return 0;
}