

enum COLOR{
    Red, Green, Blue // 0 , 1, 2
};

enum COLOR c;


switch (color) {
    case Red:
        ...
    case Green:
        ...
    case Blue:
        ...
}

// buna benzerdir ama bazen daha okunabilir
#define Red			0
#define Green		1
#define Blue		2

/*			Her ne kadar enum sabitleri ile #define sabitleri semantik bakımdan birbirlerine benziyorsa da aralarında önemli bazı farklılıklar da vardır. 
	#define komutu önişlemci modülüne ilişkindir. Dolayısıyla bunların "faaliyet alanı (scope)" biçiminde bir kavramları yoktur. Oysa enum sabitleri 
	derleme modülüne ilişkindir. Bunların faaliyet alanları vardır. enum aynı zamanda bir tür de belirtmektedir. Enum sabitleri gerçek sayı türlerine ilişkin 
	olamazlar. Yalnızca tamsayı değerleri temsil ederler. 
*/

enum { sunday, monday, tuesday, wednesday, thursday, friday, saturday};
enum { January, February, March, April, May, June, July, August, September, October, November, December};

enum COLOR{
    red = 10, green, blue // 10 dan devam eder
};



#include <stdio.h>

int main(void)
{
    int x = 10, y = 20, z = 30;
    int *a[] = {&x, &y, &z};
    int **ppi;


    ppi = a;
    for (int i = 0; i < 3; ++i)
        printf("%d\n", *ppi[i]);

    return 0;
}




#include <stdio.h>
#include <stdlib.h>

void alloc_intarray(int **ppi, size_t size)
{
	if ((*ppi = (int *)malloc(sizeof(int) * size)) == NULL) {
		fprintf(stderr, "cannot allocate array!..\n");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	int *pi;

	alloc_intarray(&pi, 10);

	for (int i = 0; i < 10; ++i)
		pi[i] = i;

	for (int i = 0; i < 10; ++i)
		printf("%d ", pi[i]);
	printf("\n");

	free(pi);

	return 0;
}




// genelde adres geri dönecek şekilde yazılır

int *alloc_intarray(size_t size)
{
	int *pi;

	if ((pi = (int *)malloc(sizeof(int) * size)) == NULL) {
		fprintf(stderr, "cannot allocate array!..\n");
		exit(EXIT_FAILURE);
	}

	return pi;
}

int main(void)
{
	int *pi;

	pi = alloc_intarray(10);

	for (int i = 0; i < 10; ++i)
		pi[i] = i;

	for (int i = 0; i < 10; ++i)
		printf("%d ", pi[i]);
	printf("\n");

	free(pi);

	return 0;
}


char *names[] = {"ali", "veli", "selami"};
void *pv;
char **ppnames;

pv = names;					/* geçerli tür dönüştürmesine gerek yok */
ppnames = pv;				/* C'de geçerli C++'ta geçersiz */
ppnames = (int **)pv;		/* Hem C'de hem de C++'ta geçerli */








