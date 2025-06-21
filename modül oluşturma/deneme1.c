#include "denem1.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void random(void){
    printf("random calisti\n");
    srand((unsigned)(time(0)));
}
int  unike(int x){
    printf(".");
    static int array[100] = { 0 };
    if(!array[x]){
        array[x] = 1;
        return 1;
    }
    return 0;

}

void random_array(int* array, int size){
    printf("randdom_array calisti\n");
    int i = 0;
    while (!(array[size - 1]))
    {
        printf("-");
        int x = rand() % size;
        if(unike(x)){
            array[i++] = x;    
        }
    }
    printf("biti");
}

void print_array(int* array, int size){
    printf("print array calisti\n");
    for(int i = 0; i < size; i++){
        if(i && !(i % 20))
            printf("\n");
        printf("%d ", array[i]);
    }
}
