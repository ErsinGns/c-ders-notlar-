#include <stdio.h>

int main(int argc, char const *argv[])
{
    static int* p1;
    static int* p2;
    int xa = 3;
    p1 = &xa;
	p2 = &xa;

    printf("p1 = %d p2 = %d\n", *p1, *p2); // her bir null pointer kendine özel
    static int * p ; // null pointer değerini alır
    printf("%d\n", p); 

    //int x = 10;
	// int *ptr = &x;
	// &x -> bu x in adrsidir. 
	// ptr -> bu da x in adresini tutuyor.
	// &ptr -> bu ise ptr ın adresi
	// ama &&x gibi bir kavram yok.
	
	// func(x) call by value
	// func(&x) call by reference

	int x = 10;
	int* ptr = &x;
	int** pptr = &ptr; // pointer to pointer int ptr nin adresini tutar
	
	printf("%d - %d - %d - %d\n", &x, ptr, &ptr, pptr);
	printf("%d - %d - %d\n", pptr, *pptr, **pptr);

	//const correctness const doğruluğu ==> const doğru yerde kullanmak yada kullanmamak
	// func(T *p) => out param
	// (const T*) => in param
	// in-out param





    return 0;
}
