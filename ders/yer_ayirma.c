
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getname(void)
{
    char name[1024];
    char *str;

    printf("Adi soyadi:");
    scanf("%s", name);

    if ((str = (char *)malloc(strlen(name) + 1)) == NULL)
        return NULL;

    strcpy(str, name);

    return str;   
}



int main(void)
{
    /*
    int *pi;
    int size;

    printf("Dizi ununlugu:");
    scanf("%d", &size);

    pi = (int *)malloc(size * sizeof(int));
    if (pi == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        printf("%d. elemani giriniz:", i + 1);
        scanf("%d", &pi[i]);
    }

    for (int i = 0; i < size; ++i)
        printf("%d ", pi[i]);
    printf("\n");



    char *str;

    if ((str = (char *)malloc(100)) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    printf("Bir yazi giriniz:");
    //gets(str);

    puts(str);
    free(str); // alanı serbest bırakır


*/

 char *name;

    name = getname(); //? önemli
    puts(name);

    free(name);


    return 0;
}
     



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;

    if ((pi = (int *)calloc(10, sizeof(int))) == NULL) { // malloctan farklı olarak 0 yazar
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mycalloc(size_t nelems, size_t size)
{
    void *ptr;

    if ((ptr = malloc(nelems * size)) == NULL)
        return NULL;

    return memset(ptr, 0, nelems * size);
}

int main(void)
{
    int *pi;

    if ((pi = (int *)mycalloc(10, sizeof(int))) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);


/*

	for (n = 0;; ++n) {
		//...
		if ((pnew = realloc(pi, (n + 1) * sizeof(int))) == NULL) {
			fprintf(stderr,i "cannot realloc memory!..\n);
			break;
		}
		pi = pnew;
		//...
	}

*/
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int val;
    int *pi, *pnew;
    int n;

    pi = NULL;
    for (n = 0;; ++n) {
        printf("Bir deger giriniz:");
        scanf("%d", &val);
        if (val == 0)
            break;
        if ((pnew = (int *)realloc(pi, (n + 1) * sizeof(int))) == NULL) {// pi daha önceki adresin başlangıç adresi
            fprintf(stderr, "cannot realloc memory!..\n");
            break;
        }
        pi = pnew;
        pi[n] = val;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}
   

#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE      10

int main(void)
{
    int val;
    int *pi, *pnew;
    int n;

    pi = NULL;
    for (n = 0;; ++n) {
        printf("Bir deger giriniz:");
        scanf("%d", &val);
        if (val == 0)
            break;
        if (n % CHUNK_SIZE == 0) {
            if ((pnew = (int *)realloc(pi, (n + CHUNK_SIZE) * sizeof(int))) == NULL) {
                fprintf(stderr, "cannot realloc memory!..\n");
                break;
            }
            pi = pnew;
        }
        pi[n] = val;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

#define DEF_CAPACITY        4

int main(void)
{
    int val;
    int *pi, *pnew;
    size_t size, capacity;

    size = 0;
    capacity = DEF_CAPACITY;

    if ((pi = (int *)malloc(DEF_CAPACITY * sizeof(int))) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    
    for (;;) {
        printf("Bir deger giriniz:");
        scanf("%d", &val);
        if (val == 0)
            break;
        if (size == capacity) {
            if ((pnew = (int *)realloc(pi, (capacity * 2) * sizeof(int))) == NULL) {
                fprintf(stderr, "cannot reallocate memory!..\n");
                break;
            }
            pi = pnew;
            capacity *= 2;
        }
        pi[size] = val;
        ++size;  
    }

    for (int i = 0; i < size; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}
                          
// yapı bildirimleri hizalamaya uğrarlay eski unuix sistemlerde saniyenin 2 şerli gitmesi
