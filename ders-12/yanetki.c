#include <stdio.h>


int main(int argc, char const *argv[])
{
    char kar = '0';
    // char h = "a"; //! hata verir string olduğu için 2 karakterdir aslında 
    printf("%c %d\n", kar, kar);
    int say = kar - '0';
    printf("%d\n", (int)say);

    int x = 5;

    if(x++ > 5) //! yan etkiden dolayı elseye girer gerçekleşmdeiği için
        printf("dogru %d", x);
    else 
        printf("yanlis %d", x);    

    return 0;
}
