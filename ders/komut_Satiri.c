





/*./sample ali veli selami

	Burada argc parametresine program ismi dahil olmak üzere boşluklarla ayrılmış yazıların sayısı geçirilmektedir. Yani örneğimizde argc 4 değerini alacaktır. 
	argv ise bir göstericiyi gösteren göstericidir. Yani bir gösterici dizisini göstermektedir. İşte bu gösterici dizisi program ismi dahil olmak üzere
	komut satırı argümanlarını gösterir. Her komut satırı argümanın sonunda yine null karakter bulunmaktadır. Standartlar argv dizisinin sonundaki son elemanın 
	NULL adres içereceğini garanti etmektedir. Yukarıdaki çalıştırmada argv dizisinin ieçriği şöyle olacaktır:

	argv ---> [0] ---> ./sample\0
	          [1] ---> ali\0
			  [2] ---> veli\0
			  [3] ---> selami\0
			  [4] NULL
*/


#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", argc);

	for (int i = 0; i < argc; ++i)
		puts(argv[i]);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double total;

    if (argc < 2) {
        fprintf(stderr, "wrong number of arguments!..\n");
        exit(EXIT_FAILURE);
    }

    total = 0;
    for (int i = 1; i < argc; ++i)
        total += atof(argv[i]);

    printf("%f\n", total);
  
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f;
    int ch;

    if (argc != 2) {
        fprintf(stderr, "wronh number of arguments!..\n");
        exit(EXIT_FAILURE);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "cannot open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(f)) != EOF)
        putchar(ch);

    if (ferror(f)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);
  
    return 0;
}







