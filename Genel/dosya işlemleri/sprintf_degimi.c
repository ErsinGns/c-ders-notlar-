#include <stdio.h>


int main(int argc, char const *argv[])
{
    char name[20] = "Ersin";
    char hello[20] = "hello ";
    char sum[40];

    sprintf(sum, "%s%s", hello, name); // pointer olarak aldığı adrese verilen bilgiyi yazar

    printf("%s\n", sum);// hello Ersin

    sprintf(hello + 6, "%s", name);
    printf("%s\n", hello); // hello Ersin

    sprintf(hello, "%s", name);
    printf("%s\n", hello); //Ersin         

    return 0;
}
