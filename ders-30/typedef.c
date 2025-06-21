#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int world; // tür eş isimi
typedef int* iptr;
#define uptr  int*
typedef int arr[10]; // == int x[10];



// time_t time(time_t* p);
int main(int argc, char const *argv[])
{
    //pointer dizisi
    int s, y;
    int* a[10] = {&s, &y}; //geri kalan null pointer
    int* ptr = NULL; // == dangling pointer bir kütüphane tanımlanmazsa hatalı NULL u bulamaz 
    // NULL anahtar sözcük değildir 
    // Alias -> takma ad
    // type alias -> tür takma adı veya tür eş ismi
    time_t xa = 1;
    time(&xa);
    // printf("%d-", xa);
    // srand((unsigned)time(0));
    // printf("%d", rand()%100);
    srand((unsigned) 3); // kendimiz dal oluşturmak istersek bu şekilde tanımlıyoruz
    printf("%d", rand()% 100);
    
    // time(&xa);
    // printf("%d", xa);

    // #include <stdbool.h>
    // bool x = true; hata vermez. üstteki include edilen library yi silersek hata verir.
    // bir macro tanımlanmş.içine bakarsam


    world x = 3; // == int x = 3;  
    iptr u = &x;   // == int* y = &x;
    iptr k, l; // == int* k , int* l;
    uptr c, t ; //!  == int* c, int t; ikincisi pointer değil 


    FILE* f = fopen("typedef.c", "r");
    if(f == NULL)
    {
        printf("dosya acilamadi.");
        return 1;
    }
    printf("dosya acildi");

    /*
    strlen uzunluk
    strchar karakter arama baştan
    strrchr karakter arama sondan
    strstr   yazı arar
    strpbrk  
    strspn
    strcspn

    strcpy yazı kopyalar
    strcat yazı sonuna yazı ekler
    strcmp karşılaştırma
    strcpy kopyalar
    strncat yazı ekler
    strncmp karşılaştırır

    strerror
    strtokk
    */


    return 0;
}