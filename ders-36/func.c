#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void func(void) {
    printf("Hello, world!\n");
}

int main(int argc, char const *argv[]) {
    void (*fun)(void); // İşlev işaretçisi tanımı
    fun = &func; // İşaretçi, func işlevini işaret eder

    printf("fun = %p  *fun = %p  &fun = %p\n", (void*)fun, (void*)*fun, (void*)&fun);
    printf("func = %p &func = %p *func = %p\n", func, &func, *func);
    // func: Bu, func işlevinin kendisini temsil eder, yani func işlevinin başlangıç adresidir. Bu adres, func işlevinin bellekteki konumunu gösterir.
    // &func: Bu, func işaretçisinin adresini temsil eder. Yani, &func ifadesi func işaretçisinin bellek adresini verir.
    // *func: Bu ifade ise func işaretçisinin işaret ettiği işlevin değerini temsil eder. func işaretçisi, func işlevini işaret ettiği için *func ifadesi func işlevinin kendisini ifade eder.


    // İşaretçi kullanarak işlevi çağırma
    fun();

    typedef int (*FPTEST)(int);

    FPTEST fa[] = { &isupper,&islower,&isalpha,&isalnum,&isdigit,&isxdigit,&ispunct,&isspace,&isblank,&isprint,
    &isgraph,&iscntrl };

    const char *p[] = { "isupper","islower","isalpha","isalnum","isdigit","isxdigit","ispunct",
        "isspace","isblank","isprint","isgraph","iscntrl" };

    int ch;
    printf("bir karakter girin :");
    ch = getchar();
    for (size_t i = 0; i < sizeof(fa)/ sizeof(fa[0]); i++)
    {
        if (fa[i](ch))
            printf("%s	OK\n",p[i]);
        else
            printf("%s  Not Ok\n",p[i]);
    }



    return 0;
}
