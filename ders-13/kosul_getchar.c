#include <stdio.h>
#include <conio.h> //standart değil._getch ve _getche icin eklendi

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) !='\n' && c != EOF)  // bufferı boşaltır 
        ;
    
}


int main(int argc, char const *argv[])
{
    fprintf(stderr,"file cannot open\n");

    int x = 1, y = 2, z = 3;
    if(1 == x)
        if(0 == y)
            printf("icteki if calisti\n");
        else
            printf("icteki ifin\n");
    
    z = getchar();// buffer boşalana kadar getcharlara sırasıyla girilen değerleri verir
    printf("z = %c\n", z);
    clear_input_buffer();
    z = getchar(); // getchar karakter alır sayı için 0 dan çıkarman gerek
    printf("z = %c", z);


	// getchar std. new line var echo var
	// _getch std değil new line var echo yok
	// _getche std değil new line yok echo var

    z =_getch(); // ! standar değil
    printf("\nz = %c\n", z);


    return 0;
}



