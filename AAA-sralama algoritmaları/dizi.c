#include "dizi.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomize(void)
{
    srand((unsigned)time(NULL));
}


void set_random_array(int* p, int size)
{
    for(int i = 0; i < size; i++)
    {
        p[i] = rand() % 100;
    }
}


void print_array(const int* p, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(i && i %20 == 0)
            printf("\n");

        printf("%3d", p[i]);
    }
}


void print_line(void)
{
    printf("\n--------------------------------------------------------------\n");
}


int only_one(int x)
{
    static int array[100] = { 0 };
    
    if(array[x] == 0){
        array[x] = 1;
        return 1;
    }
    return 0;
}


void only_one_list(int* only_one_array)
{
    int i = 0;
    while (!only_one_array[99])
    {
        int x = rand() % 100;
        int result = only_one(x);
        if(result)
        {
            only_one_array[i++] = x;
        }
    }

}


void sort(int * array, int size)
{
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100 - 1 - i; j++){
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            
        }
    }
}


int main(int argc, char const *argv[])
{
     randomize();
    //random array tanımla
    int array[100];
    set_random_array(array, 100);
    print_array(array, 100);

    // random array sırala
    sort(array, 100);
    print_line();
    print_array(array, 100);

    // her karakterin tek olduğu random array
    print_line();
    int only_one_array[100] = { 0 };
    only_one_list(only_one_array);
    print_array(only_one_array, 100);

    // her karakterin tek olduğu random array doğrulama
    print_line();
    sort(only_one_array, 100);
    print_array(only_one_array, 100);


    return 0;
}

