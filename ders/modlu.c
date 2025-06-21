



int g_x;			/* external linkage, yani başka modüllerden kullanılabilir */
static int g_y;		/* internal linkage, başka bir modüllerden kullanılamaz */

void foo(void)		/* foo external linkage'a sahip, başka modüllerden kullanılabilir */ 
{
    /* ... */
}

static void bar(void)		/* bar internal linkage'a sahip başka modüllerden kullanılamaz */
{
    /* ... */
}




extern int g_x; // g_x başka dosyada demek derleyici bunun için yer ayırmaz
// ilk değer verilirse extern bildirimini bir anlamı kalmaz

int main(void)
{
    g_x = 10;
    printf("%d\n", g_x);

    return 0;
}



#include <stdio.h>

void foo(void)
{
    static int i = 10; // blok bitiğinde yok edilmez

    ++i;

    printf("%d\n", i);
}

int main(void)
{
    foo();		/* 11 */
    foo();		/* 12 */
    foo();		/* 13 */

    return 0;
}




