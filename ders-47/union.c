#include <stdio.h>
#include <stdint.h>

union nec
{
    int x, y;
    double k, l;
    char str[16];
};

struct snec
{
    int x, y;
    double k, l;
    char str[16];
};

typedef union kel
{
    int k, y;
} kel;

struct point
{
    uint16_t x;
    uint16_t y;
};

union Data
{
    uint32_t uval;
    struct point p;
};

typedef struct 
{
    int no;
    char name[20];
    char surname[20];
    int gender;
    union 
    {
        struct 
        {
            int div;
            int status;
            char place[16];
        };
        char maiden_name[24];
    };
    
}Employee;


typedef union // verinin baytina erişimi sağlar
{
    struct 
    {
        uint16_t lowbytes;
        uint16_t hightbytes;
    };
    uint32_t uval;
    uint8_t bytes[4];
    
}Data;


int main(int argc, char const *argv[])
{
    union nec n1;
    kel k1;
    struct snec s1;

    printf("%zu   %zu \n", sizeof(n1), sizeof(s1));//  union bütün belek adresleri aynı (değişkenleri aynı adreste)
    printf("%p %p %p %p %p", &n1, &n1.x, &n1.k, n1.str, &n1.str[5]); // aynı adressteler

    // bir veriryi farklı iki şekilde temsili için kullanılır
    union Data mydata;
    mydata.p.x = 56;
    mydata.p.y = 45;
    mydata.uval;

    printf("\n%zu ", sizeof(Employee));


    return 0;
}
