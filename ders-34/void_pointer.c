#include <stdio.h>

void swap(void* a, void* b, size_t size) // genel swap için kullanılabilir
{
    char* p1 = (char*)a;
    char* p2 = (char*)b;

    while (size--)
    {
        char temp = *p1;
        *p1++ = *p2;
        *p2++ = temp;
    }

}

// int* donus(dönecek olan, girdi) // ilk return olacak olan yazılır genelde

int main(int argc, char const *argv[])
{
    int a = 2; 
    int b =5;
    printf("a = %d b = %d\n", a, b);

    swap(&a, &b, sizeof(a));

    printf("a = %d b = %d\n", a, b);



    // p = &y;
    // *p = 300;

    // --------------

    // int * const p = &x;  olsaydı.
    // Bu const pointerdır. yani p const. P değişmeyecek demek
    // *p = 45; geçerli
    // p = &y; sentaks hatası.


    // const int * p = &x;
	// 	BUna da Pointer to const int deniyor.
	// 	const olan nesne *p demek bu. P const değil.
	// 	Hem pointer to const int denince, pointer const int i gösteriyor 
	// 	anlıyoruz biz zaten. Ayrıca daha kolayı, 
	// 	tanımda const tan sonra *p geliyor(int i saymazsak), bu durumda 
	// 	*p işlemi const demek :) iki türlü anlaşılabilir. 2. olan daha kolay.
		 
	// 	 p = &y; sorunsuz
	// 	 *p = 90; hata


    // Expression			Data Type			Value Category
	// -------------------------------------------------------
	// 	x					int					L
	// 	-----------------------------------------
	// 	&x					int *				R
	// 	-----------------------------------------
	// 	p					int *				L
	// 	-----------------------------------------
	// 	*p					int					L
	// 	-----------------------------------------
	// 	&p					int **				R
	// 	-----------------------------------------
	// 	ptr					int **				L
	// 	-----------------------------------------
	// 	*ptr				int *				L
	// 	-----------------------------------------
	// 	**ptr				int					L
	// 	-----------------------------------------
	// 	&ptr				int ***				R
	// 	-----------------------------------------



    // void func(void); parametresi yok
	// void func(); parametreleri hakkında bilgi verilmemiş.
    // int * , int türden bir değişkenin adresini tutabilir.
	// void * pointerlar ise istediğim türden nesnenin adresini tutar.
	// varlık sebebi  bu.



    
	// int x = 10;
	// void *vp = &x;
	// int *iptr;

	// iptr = vp; // burada tür dönüşümü var. void * türünden int * türüne implicit dönüşüm var.
				// burası yanlış değil.
				// C++ ta ise doğrudan sentaks hatası.
				// C++ ta legal olması iiçin  iptr = (int *)vp; yapmak gerekiyor.

    // C de ise iki farklı tavır var.
	// 1. kod legal.implicit dönüşüm ile işlem yaptırılır.
	// 2. C++ ta da derlenmesi için iptr = (int *)vp; yazmak.

    

    return 0;
}


