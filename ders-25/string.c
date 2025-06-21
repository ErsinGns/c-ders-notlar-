#include <stdio.h>


//Aşağısı unreachable code
	int foo(int a)
	{
		if(a == 1)
			return 10;
		else
			return 100;
	
		return 1000;  // hiçbir zaman ulaşamayacak						
	}  

int main(int argc, char const *argv[])
{
    char isim[] = "ersin";
    char yedek[100];
    int i = 0;
    while (yedek [i] = isim[i])
        i++;
    printf("(%s)", yedek);  


    
    
    return 0;
}
