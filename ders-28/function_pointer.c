#include <stdio.h>

int g = 34; // eğer içerde tanımlansaydı ub olurdu 12 satırdan dolayı
            // stattic diye içerde tanımlansaydı sıkıntı  olmazdı 

int * foo(void){
    return &g;
}


int main(int argc, char const *argv[])
{
    int* ptr = foo(); 


    printf("%d", *ptr);


    return 0;
}