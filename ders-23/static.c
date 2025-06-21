#include <stdio.h>

void yaz(){
    static int x = 0;
    printf("%d ", x++);
}

int main(int argc, char const *argv[])
{
    int k = 100;
    while (k--) 
        yaz();

    printf("\n%zu\n", sizeof 'A');  // char int olarak tutuluyor.
	printf("%zu\n", sizeof 'A' + 5);
	printf("%zu\n", sizeof ('A' + 5));
    int x = 10;
	printf("%zu\n", sizeof(x++)); // sequence point gitti.sizeof operatörünün operandı olan ifade için 
	printf("%d\n", x);	// işlem kodu üretilmez değer değişmez
    

    return 0;
}
