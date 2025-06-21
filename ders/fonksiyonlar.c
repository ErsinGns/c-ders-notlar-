#include <stdio.h>
#include <string.h>


char *mystrcpy2(char *dest, char *source)
{
    char *temp = dest;

    while ((*dest = *source) != '\0') {
        ++source;
        ++dest;
    }

    return temp;
}


char *mystrcpy(char *dest, char *source)
{
    for (size_t i = 0; (dest[i] = source[i]) != '\0'; ++i)
        ;

    return dest;
}

//! zaten adresine kopyalıyoruz neden adresi tekrardan dönüyoruz araştır



char *mystrcat(char *dest, char *source)
{
    size_t i;

    for (i = 0; dest[i] != '\0'; ++i)
        ;
    for (size_t k = 0; (dest[i + k] = source[k]) != '\0'; ++k)
        ;

    return dest;
}


char *mystrchr(char *str, int ch)
{
    while (*str != '\0') {
        if (*str == ch)
            return str;
        ++str;
    }

    return ch == '\0' ? str : NULL;
}

char *mystrrchr(char *str, int ch)
{
    char *result = NULL;

    while (*str != '\0') {
        if (*str == ch)
            result = str;
        ++str;
    }

    return ch == '\0' ? str : result;	
}

int mystrcmp(char *s1, char *s2)
{
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		++s1;
		++s2;
	}
	return *s1 - *s2;
}

char *mystrncpy(char *dest, char *source, size_t n)
{
    size_t i;

    for (i = 0; i < n && source[i] != '\0'; ++i)
        dest[i] = source[i];

    for (; i < n; ++i)
        dest[i] = '\0';

    return dest;
}




int main(int argc, char const *argv[])
{
    char s[] = "ankara";
    char d[19];

    printf("%s\n", strcpy(d, s));// s yi d ye kopyalar ve d nin adresini döndürür

    char k[20];
    char *a;
    a = mystrcpy(k, s);
    printf("%s %s\n", k, a);

    a = mystrcpy(a, s);
    printf("%s %s\n", k, a);


    strcat(d, s);
    puts(d);// ankaraankara şeklinde yazar \n yerine diyer kısmı yapıştırır

    *strchr(s, 'a') = 'x';// o elemana basar ilkini
    puts(s);

    strchr(s, 'k')[2] = 'x'; // iki eleman sonrasına basar
    puts(s);




	char path[] = "/home/kaan/study/test.c";
	char *fname;

	fname = strrchr(path, '/');// en sonuncusunu bulur
	if (fname)
		puts(fname + 1);

// strcmp
//1. büyükse pozitif 2. büyükse negatif eşitse sırı döner

printf("%d \n", strcmp(k, s));


    char ak[] = "yenisehir";
    char bk[] = "konya";
    strncpy(ak, bk, 4);// yerie yazar
    puts(ak); //konysehir 


    strncat(ak, bk, 4); // sonuna istenen kadar ekler \0 koyar
    puts(ak);//konysehirkony


    char as[] = "1234";
    int val;

    val = atoi(as); // stringi inte çeviri
    printf("%d\n", val);
    char ask[] = "123akl432";//123
    char asl[] = "aks2343";// 0

    printf("%d %d \n", atoi(ask), atoi(asl));

    char ss[] = "this is a test yes!";
	char ks[] = "test";
	char *str;

	str = strstr(ss, ks);
	if (str != NULL)
		puts(str);		/* test yes! */ //döner varsa
	else
		printf("cannot find!\n");


    return 0;
}

