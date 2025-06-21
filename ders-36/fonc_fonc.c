#include <stdio.h>

//ileri

#define MAX 10

typedef void (*FPT)(void);


FPT gfa[MAX];
int gcount = 0;

void reg_func(FPT f)
{
    if (gcount == MAX)
        return;
    gfa[gcount++] = f;
}

void faa(void)
{
    for(int i = 0; i < gcount; i++)
    {
        printf("%d", i);
        gfa[i]();
    }
        
}


void f1(void){printf("f1 cagirldi\n");}
void f2(void){printf("f2 cagirldi\n");}
void f3(void){printf("f3 cagirldi\n");}
void f4(void){printf("f4 cagirldi\n");}


// orta
typedef void (*FOOHANDLER)(void);

static void ilk(void)
{
    printf("ilk calisti\n");
}

FOOHANDLER gf = ilk;

void cagir(void)
{
    gf();
}

FOOHANDLER set_fonc(FOOHANDLER f)
{
    FOOHANDLER ret = gf;
    gf = f;
    return ret;
}


void iki(void)
{
    printf("iki calisti\n");
}





// kolay 

typedef int (*FPTR)(int);
int bar(int x)
{
    return x * x;
}

FPTR foo(void)
{
    return bar;
}


int main(int argc, char const *argv[])
{
    //kolay
    int x = foo()(12);
    printf("x = %d\n", x);


    // orta
    cagir();
    FOOHANDLER f = set_fonc(&iki);
    cagir();
    set_fonc(f);
    cagir();

    //ileri
    reg_func(f1);
    reg_func(f2);
    reg_func(f3);
    reg_func(f4);

    faa();


    return 0;
}

