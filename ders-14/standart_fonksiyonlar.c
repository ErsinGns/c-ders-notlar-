#include <stdio.h>
#include <ctype.h> // bunun içerisinde


int main(int argc, char const *argv[])
{
    int x = 3, a, b;
    // güzel örnek
	// x > 10 ? a : b = 0;    // C de sentaks hatası C++ ta değil
	// C de yazmanın yolu aşağıda
	*(x > 10 ? &a : &b) = 44;
    printf("%d", b);

    // int isupper(int ch) nonzero değer true olur
	// int islower(int ch) nonzero değer true olur
	// int isalpha(int ch) nonzero değer true olur
	// int isdigit(int ch) nonzero değer true olur
	// int isalnum(int ch) nonzero değer true olur
	// int isxdigit(int ch) nonzero değer true olur (0123456789ABCDEFabcdef) hex sayı sisteminde basamak gösteren karakterden biri mi
	// int ispunct(int ch) nonzero değer true olur görüntüsü var ama harf yada rakam değil.
	// int isspace(int ch) nonzero değer true olur space tuşu yatay duset tab \f \n \r bunlar bosluk charlar
	// int isblank(int ch) nonzero değer true olur bosluk karakter ve tab karakterler blank chardır
	// int isprint(int ch) nonzero değer true olur görüntüsü olan tüm charlar
	// int isgraph(int ch) nonzero değer true olur görüntüsü olan tüm charlar(aynısı) sadece  ' ' char yok.
	// int iscntrl(int ch) nonzero değer true olur görüntüsü olmayan özel amaçlı kullanılan karakterler. ascide 0-31 olanlar birde 127 nolular kontrol karakterleri.
	

    printf("bir karakter giriniz \n");
	int ch = getchar();

	if (islower(ch))
		printf("islower ok\n");
	else
		printf("islower not ok\n");
	
	if (isupper(ch))
		printf("isupper ok\n");
	else
		printf("isupper not ok\n");
	
	if (isdigit(ch))
		printf("isdigit ok\n");
	else
		printf("isdigit not ok\n");

	if (isalpha(ch))
		printf("isalpha ok\n");
	else
		printf("isalpha not ok\n");
	if (isalnum(ch))
		printf("isalnum ok\n");
	else
		printf("isalnum not ok\n");
	if (isxdigit(ch))
		printf("isxdigit ok\n");
	else
		printf("isxdigit not ok\n");
	if (ispunct(ch))
		printf("ispunct ok\n");
	else
		printf("ispunct not ok\n");

	if (isspace(ch))
		printf("isspace ok\n");
	else
		printf("isspace not ok\n");

	if (isblank(ch))
		printf("isblank ok\n");
	else
		printf("isblank not ok\n");

	if (isprint(ch))
		printf("isprint ok\n");
	else
		printf("isprint not ok\n");
	if (iscntrl(ch))
		printf("iscntrl ok\n");
	else
		printf("iscntrl not ok\n");

        printf("ispunct\n");
	for (int i = 0; i <= 127; i++) 
	{
		if (ispunct(i))
			putchar(i);
	}


	printf("\n\n");
	printf("isxdigit\n");
	for (int i = 0; i <= 127; i++)
	{
		if (isxdigit(i))
			putchar(i);
	}

	printf("\n\n");
	printf("isgraph\n");
	for (int i = 0; i <= 127; i++)
	{
		if (isgraph(i))
			putchar(i);
	}
	
	printf("\n\n");
	printf("isspace\n");
	for (int i = 0; i <= 127; i++)
	{
		if (isspace(i)) //bosluk oldugundan printf ile kod numaralarını yazdırmak mantıklı
			//putchar(i);
			printf("%d ", i);
	}

	printf("\n\n");
	printf("iscntrl\n");
	for (int i = 0; i <= 127; i++)
	{
		if (iscntrl(i)) //bosluk oldugundan printf ile kod numaralarını yazdırmak mantıklı
			//putchar(i);
			printf("%d ", i);
	}
    return 0;
}
