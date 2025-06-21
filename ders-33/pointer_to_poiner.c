#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    int* ptr = &x;
    int** p = &ptr;
    char kelime[100];
    printf("basarili alinan veri adedi: %d\nkelime : %s\n ", scanf("%[^\n]s", kelime), kelime);

    printf("&x = %p\n", &x);
    printf("ptr = %p\n", ptr);
    printf("&ptr = %p\n", &ptr); // pointer to pointer 
    printf("p = %p\n", p); // pointer to pointer 


    void* vprt = &x; // her türden değer atanabilri pointer olduğu sürece
    // pointer olarak kullanılamaz 
    // eşitlik sınzmada, null olup olmadığına bakmada

    // atama yapılabiir
    int* k = vprt;
    printf("%d\n", *k);


    // puts("\"ayhan\""); ->  "ayhan" yazdırır.
	// puts("\\ayhan\\"); ->  \ayhan\ yazdırır.

	// path bilgisi girerkende çift \ kullanılmalı.
	// "c:\\umut\\umut.txt"




    return 0;
}
