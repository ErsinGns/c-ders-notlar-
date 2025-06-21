
#include <stdio.h>

int main(void)
{
	int a[3][2];

	a[0][0] = 10;
	a[0][1] = 20;
	a[1][0] = 30;
	a[1][1] = 40;
	a[2][0] = 50;
	a[2][1] = 60;

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", a[i][k]);
		printf("\n");
	}

	return 0;
}


#include <stdio.h>

int main(void)
{
	int a[3][2] = {{10, 20}, {30, 40}, {50, 60}};

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", a[i][k]);
		printf("\n");
	}

	return 0;
}


int a[5] = {1, 2, 3, 4, 5};
	int (*pai)[5];
	int *pi;

	pai = &a;
	
	(*pai)[1] = 10;		/* dizinin 1'inci indisli elemanı güncelleniyor */


#include <stdio.h>

int main(void)
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int(*pai)[2];

	pai = a;

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}

	return 0;
}



#include <stdio.h>

void disp_matrix(const int(*pai)[2], int size)
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};

	disp_matrix(a, 3);

	return 0;
}


#include <stdio.h>

void disp_matrix(const void *pmatrix, size_t rowsize, size_t colsize)
{
	const int *pi = (const int *)pmatrix;

	for (size_t i = 0; i < rowsize; ++i) {
		for (size_t k = 0; k < colsize; ++k) 
			printf("%d ", pi[colsize * i + k]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int b[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

	disp_matrix(a, 3, 2);
	disp_matrix(b, 4, 3);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void disp_matrix(int **pmatrix, size_t rowsize, size_t colsize)
{
	const int *pi = (const int *)pmatrix;

	for (size_t i = 0; i < rowsize; ++i) {
		for (size_t k = 0; k < colsize; ++k) 
			printf("%d ", pi[colsize * i + k]);
		printf("\n");
	}
}

int main(void)
{
	int (*pai)[2];

	if ((pai = (int(*)[2]) malloc(sizeof(int) * 3 * 2)) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 3; ++i) 
		for (int k = 0; k < 2; ++k)
			pai[i][k] = i + k;
		

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}

	free(pai);
	
	return 0;
}

