#include <stdio.h>
#include <shellapi.h>

void foo(void)
{
    printf("foo\n");
}


int main(void)
{
    void (*pf)(void);

    pf = foo;

    pf();       /* pf göstericisinin içerisindeki adreste bulunan fonksiyonu çağır */
    
    return 0;
}



#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int main(void)
{
    int (*pf)(int, int);
    int result;

    pf = add;

    result = pf(20, 10);
    printf("%d\n", result);     /* 30 */

    pf = sub;

    result = pf(20, 10);
    printf("%d\n", result);     /* 10 */

    pf = mul;

    result = pf(20, 10);       /* 2000 */
    printf("%d\n", result);

    pf = div;

    result = pf(20, 10);
    printf("%d\n", result);     /* 2 */
      
    return 0;
}



int main(void)
{
    int (*pfs[4])(int, int) = {add, sub, mul, div};
    int result;

    for (int i = 0; i < 4; ++i) {
        result = pfs[i](20, 10);
        printf("%d\n", result);
    }
      
    return 0;
}

typedef int (*PF)(int, int);

int main(void)
{
    PF pfs[4] = {add, sub, mul, div};
    int result;

    for (int i = 0; i < 4; ++i) {
        result = pfs[i](20, 10);
        printf("%d\n", result);
    }
      
    return 0;
}



#include <stdio.h>
#include <time.h>

void set_alarm(time_t target, void (*pf)(void))
{
    time_t t;

    for (;;) {
        t = time(NULL);
        if (t == target) {
            pf();
            break;
        }
    }
}

void foo(void)
{
    printf("Ok\n");
}

int main(void)
{
    time_t t;

    t = time(NULL) + 10;

    set_alarm(t, foo);

    printf("continues..\n");
      
    return 0;
}


#include <stdio.h>

enum EVENTS {
    FOREACH_PROGRESS, FOREACH_END
};

void for_each(int *pi, size_t size, void (*pf)(int *, int status))
{
    size_t i;

    for (i = 0; i < size - 1; ++i)
        pf(&pi[i], FOREACH_PROGRESS);

    pf(&pi[i], FOREACH_END);
}

void disp(int *pi, int status)
{
    printf("%d", *pi);
        
    putchar(status == FOREACH_PROGRESS ? ' ' : '\n');
}

void square(int *pi)
{
    *pi = *pi * *pi;
}

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    for_each(a, 5, disp);
    for_each (a, 5, square);
    for_each(a, 5, disp);


    return 0;
}




//! atexit 


#include <stdio.h>
#include <stdlib.h>

void foo(void)
{
    printf("foo\n");
}

void bar(void)
{
    printf("bar\n");
}

int main(void)
{
    atexit(foo);
    atexit(bar);

    printf("main ends...\n");

    return 0;
}



int add(int a, int b)
{
    return a + b;
}
void (*pf)(void);

pf = add;						/* geçersiz! */

pf = (void (*)(void))add;		/* geçerli */



void foo(void)
{
    ...
}

void bar(int a)
{
    ...
}

int tar(int a)
{
    ...
}

void (*pf)(void);

pf = foo;		/* geçerli */
pf = bar;		/* geçersiz! */
pf = tar;		/* geçersiz! */

Ancak örneğin:

void (*pf)();

pf = foo;		/* geçerli */
pf = bar;		/* geçerli */
pf = tar;		/* geçersiz! */
