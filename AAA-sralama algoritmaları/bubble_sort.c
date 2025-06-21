#include "dizi.h"

#define SIZE 100



int main(int argc, char const *argv[])
{
    randomize();

    int array[SIZE];
    
    set_random_array(array, SIZE);
    print_array(array, SIZE);

    return 0;
}






