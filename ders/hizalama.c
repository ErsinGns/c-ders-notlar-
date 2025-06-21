

#include <stdio.h>

struct SAMPLE {
    char a;
    int b;
    char c;
    int d;
};

int main(void)
{
    struct SAMPLE s;

    printf("%zd\n", sizeof s);			/* 16 */// hizalamadan dolayı

    return 0;
}
/*
	a---
	bbbb
	c---
	dddd
*/

//! sırası önemli 
/*	
    ab--
	cccc
	dddd
*/

#include <stdio.h>

struct SAMPLE {
    char a;
    char b;
    int c;
    int d;
};

int main(void)
{
    struct SAMPLE s;

    printf("%zd\n", sizeof s);		/* 12 */

    return 0;
}




#include <stdio.h>

#pragma pack(1) // hizalamayı purogramcı bu şekilde ayarlayabilir

struct SAMPLE {
    char a;
    int b;
    char c;
    int d;
};

int main(void)
{
    struct SAMPLE s;

    printf("%zd\n", sizeof s);		/* 10 */

    return 0;
}








