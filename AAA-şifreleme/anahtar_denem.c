#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE    100

void print_array(int* array, int size)
{
    for(int i = 0; i < size; i++){
        if(i && i % 20 == 0)
            printf("\n");
        printf("%3d", array[i]);
        
    }
}

int main(int argc, char const *argv[])
{
    srand(1);
    printf("%d\n", time(0));
    int array1[SIZE];
    for(int i = 0; i < SIZE; i++){
        array1[i] = rand()%100;
    }
    print_array(array1, SIZE);


    return 0;
}