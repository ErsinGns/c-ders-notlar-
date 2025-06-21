
// çalışması için üste tanımlanmalı
#define NDEBUG // yazılmışsa assert makrosuna girmez
#include <assert.h> 

int main(int argc, char const *argv[])
{
    int x = 4;
    assert(x == 32);// hatalıysa girer


    return 0;
}


