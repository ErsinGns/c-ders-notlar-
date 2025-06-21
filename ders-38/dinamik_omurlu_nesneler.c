#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    size_t n;
    printf("bir sayi giriniz: ");
    scanf("%d", &n);

    int* pd = (int*)malloc(n * sizeof(int)); // yer ayir intitorment value (0 yazmaz)
    if(!pd){// yer ayıramazsa null döner
        fprintf(stderr, "bellek yetersiz\n");
        exit(EXIT_FAILURE);
    }
    free(pd); // yeri serbest bırakır
    
    int row, col;
	int* pd;
	printf("matrisin satir ve sutun sayilarini girin : \n");
	(void)scanf("%d%d", &row, &col);

	pd = (int*)malloc(row * col * sizeof(int));
	if (!pd)
	{
		printf("Bellek yetersiz \n");
		return 1;
	}

	// tek boyutlu dizi ama 2 boyutlu dizi gibi kullanacak
	for (int i = 0; i < row * col; i++)
	{
			pd[i] = rand() % 10;
	}

	int** pp = (int**)malloc(row * sizeof(int*));
	//control kodu

	for (int i = 0; i < row; i++)
		pp[i] = pd + i * col; // dizin içindeki oluşturulmuş satır adreslerini verdi.

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", pp[i][j]);
		}
		printf("\n");
	}

	free(pd);
	free(pp);



    return 0;
}
