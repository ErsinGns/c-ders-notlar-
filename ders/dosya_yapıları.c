
/*
    /a/b/c.text			UNIX/Linux ve macOS sistemlerinde (ancak Windows sistemleri de destekliyor)
	\a\b\c.text			Windows sistemlerinde, ancak UNIX/Linux ve macOS sistemleri desteklemiyor
*/


// 	FILE *fopen(const char *path, const char *mode);



/*
	Açış Modu						Anlamı
	---------						------
	"r"								Olan dosyayı açar, yalnızca okuma yapılabilir.
	"r+"							Olan dosyayı açar, hem okuma hem de yazma yapılabilir.
	"w"								Dosya yoksa yaratır ve açar, dosya varsa içini sıfırlar (truncate eder) ve açar, yalnızca yazma yapılabilir.
	"w+"							Dosya yoksa yaratır ve açar, dosya varsa içini sıfırlar (truncate eder) ve açar, hem okuma hem de yazma yapılabilir.
	"a"								Dosya varsa olanı açar, yoksa yaratır ve açar, yalnızca yazma yapılabilir. Her yazılan sona eklenir.
									(Dosyanın sonunun dışında başka bir yerine yazma yapılamaz)
	"a+"							Dosya varsa olanı açar, yoksa yaratır ve açar, hem okuma hem yazma yapılabilir. Her yazılan sona eklenir. 
									Ancak herhangi bir yerden okuma yapılabilir.
*/




#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    printf("Ok\n");

    return 0;
}

int fclose(FILE *f);



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    printf("Ok\n");

    fclose(f);

    return 0;
}



FILE *f1, *f2;

if ((f1 = fopen("test.txt", "r") == NULL) {
    fprintf(stderr, "cannot open file!..\n");
    exit(EXIT_FAILURE);
}
if ((f2 = fopen("test.txt", "r") == NULL) {
    fprintf(stderr, "cannot open file!..\n");
    exit(EXIT_FAILURE);
}


// int fgetc(FILE *f); bir bayt alır ve istenen değişkene atar 


/*

	fgetc temelde iki nedenden dolayı başarısız olabilir: 

	1) Dosya göstericisi EOF durumundadır ve bu nedenle okuma yapılamamıştır.
	2) Disk ilgili ciddi ve patolojik bir problem oluşmuştur. 
    */



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    int ch;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(f)) != EOF)
        putchar(ch);

    fclose(f);

    return 0;
}


//Son yapılan işlemin nedne başarısız olduğunu veren iki standart C fonksiyonu bulundurulmuştur: ferror ve feof. Fonksiyonların prototipleri 
	//şöyledir:

	int ferror(FILE *f);
	int feof(FILE *f);


/*ferror fonksiyonu son yapılan işlem IO hatasından dolayı başarısz olmuşsa sıfır dışı bir değere, IO hatasındna dolayı başarısz olmamışsa 0 değerine
	geri dönmektedir. feof fonksiyonu ise son yapılan işlem EOF durumundan dolayı başarısz olmuşsa sıfır dışı bir değere, EOF durumundan dolayı başarısız
	olmamışsa 0 değerine geri dönmektedir. Bu iki fonksiyon tipik olarak bir başarısızlık sonrasında başarısızlığın nedenini sorgulamak için kullanılmaktadır.
	Bir başarısızlık söz konusu olmadığı durumda bu fonksiyonlar 0 değerine geri döner. Özellikle feof fonksiyonunun işlevi yanlış anlaşılmaktadır. Örneğin:

	012345
	xxxxx

	Burada dosya gösteicisi 4'üncü offset'te olsun. Biz de fgetc fonksiyonu ile dosyadan 1 byte okumuş olalım. Burada biz feof fonksiyonu ile durumu sorgulamaya 
	çalışsak feof 0 değerini verecektir. Halbuki dosya göstericisi EOF durumundadır. Çünkü feof ve ferror "son yapılan işlemin başarısızlığının nedenini"
	tespit etmekte kullanılır. Son yapılan işlem başarısız değilse bu fonksiyonlar 0 ile geri döner. feof fonksiyonundaki yanlış anlaşılma şudur: 
	Yeni öğrenen kişiler sanki feof fonksiyonunun o andaki dosya göstericisinin konumuna göre durum tespiti yaptığını sanmaktadır. Halbuki feof 
	"son yapılan işlemin başarısızlığının nedeninin EOF nedeni ile mi olduğuna" bakmaktadır. Başka bir deyişle ferror ve feof ancak başarısızlık durumunda 
	anlamlı bir biçimde kullanılabilmektedir. */


//Yeni öğrenenlerin sık yaptığı bir hata şudur:

	while (!feof(f)) {
		ch = fgetc(f);
		putchar(ch);
	}
/*
	Burada programcı EOF'a gelinmediği sürece işlem yapmak istemiştir. Ancak bu kod parçası kusurludur. Dosyanın son byte'ının fgetc tarafından 
	okunduğunu varsayalım. Bu durumda putchar son byte'ı yazdıracaktır. Ancak feof hale sıfır değerini verecektir (çünkü son işlem başarısız olmamıştır).
	Bu durumda döngü yinelenecek fgetc bu sefer EOF'tan dolayı başarısız olacak putchar EOF değerini (-1 değeirni) yazdırmaya çalışacaktır. 
	Halbuki döngünün şöyle oluşturulması gerekir:
*/
	while ((ch = fgetc(f)) != EOF)
		puthcar(ch);

	//Tabii aşağıdaki gibi bir döngü de oluşturulabilir:

	for (;;) {
		ch = fgetc(f);
		if (feof(f))
			break;
		putchar(ch);
	}


	while ((ch = fgetc(f)) != EOF)
		puthcar(ch);

	if (ferror(f)) {
		fprintf(stderr, "Unexpected IO error!..n");
		exit(EXIT_FAILURE);
	}

//	Tabii aynı kontrol aşağıdaki gibi de yapılabilrdi. Ancak bunu tavsiye etmiyoruz:

	while ((ch = fgetc(f)) != EOF)
		puthcar(ch);

	if (!feof(f)) {
		fprintf(stderr, "Unexpected IO error!..n");
		exit(EXIT_FAILURE);
	}



//fputc isimli standart C fonksiyonu dosya göstericisinin gösterdiği yere bir byte yazmak için kullanılmaktadır. Fonksiyonun prototipi şöyledir:

	int fputc(int ch, FILE *f);


/*
	Fonksiyonun birinci parametresi yazılacak byte'ı belirtir. Bu parametre int türden olmasına karşın buradaki sayının en düşün anlamlı byte değeri 
	dosyaya yazılmaktadıır. Fonksiyonun ikinci parametresi yazılacak dosyaya ilişkin dosya bilgi göstericisini belirtir. Fonksiyon başarı durumunda 
	yazılan byte değerine başarısızlık duruymunda EOF değerine geri döner. Başarısızlığın nedeni IO hatası olabilir. (Tabii fonksiyon EOF'tan dolayı başarısz olmaz. 
	Çünkü EOF durumunda dosyaya yazma yapılırsa zaten bu durum dosyaya ekleme anlamına gelmektedir.) Fonksiyonb başarısız olduğunda ferrror bayrağı set edilir. 
	Dolayısıyla ferror fonksiyonu da sıfır dışı bir değere geri döner. 

	Yazma sırasında IO hatasının muhtemel nedenlerinden bazıları şunlar olabilmektedir:

	- Diskin bozuk olması
	- Çıkarılabilir (removable) bir diskin (örneğin flash bellekler) o anda çıkartılması
	- Diskin tamamen dolu olması
	- İşletim sistemlerinde dosyaya yazılabilecek maksimum byte sayısı sınırlı olabilmektedir. Bu sınır aşılmış olabilir.

	Aşağıdaki örnekte char türdne bir dizinin içerisindeki tüm byte'ler null karakter görülene kadar dosyaya yazılmıştır.*/




#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    char s[] = "ankara";

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; s[i] != '\0'; ++i)
        if (fputc(s[i], f) == EOF) {
            fprintf(stderr, "Unexpected IO error!..\n");
            exit(EXIT_FAILURE);
        }

    fclose(f);

    return 0;
}



/*1) Dosya text modda açılmışsa dosyaya '\n' karakteri yazılmak istendiğinde UNIX/Linux ve macOS sistemlerinde dosyaya yalnızca bir byte'lık
	LF (0A) karakteri basılır. Ancak Windows sistemlerinde CR/LF (OD/0A) biçiminde iki karakter yazdırılır. Ancak dosya binary modda açılmışsa artık yazısal bir 
	anlam dikkate alınmayacağı için '\n' karakteri sistem ne olursa olsun LF (0A) byte'ı olarak yazıdırlacktır. Yani text modda '\n' karakterinin 
	dosyaya yazılması ilgili işletim sistemine göre o işletim sistemindeki tanıma göre yapılmaktadır. Ancak binary modda böyle bir durum
	söz konusu değildir. Bu durumda biz bir dosyayı Windows sistemlerinde "text" modda açarsak o dosyaya '\n' karakterini yazdığımızda aslında
	dosyaya \r\n karakterleri birlikte yazıdırılacaktır. Ancak binary modda dosyayı açarsak '\n' karakteri içimn yine '\n' karakteri basılacaktır. 
	Tabii UNIX/Linux ve macOS sistemlerinde bu anlamda "text mod" ile "binary mod" arasında bir farklılık söz konusu olmayacaktır. Ancak taşınabilirlik 
	için programcının yazısal içeriğe sahip olmayan dosyaları binary modda açması gerekir.

	2) Dosya text modda açılmışsa Windows sistemlerinde dosya göstericisi CR/LF çiftinin başını gösterir durumdaysa dosyadan bir karakter okunmak 
	istendiğinde her iki karakter de okunur. Ancak okumanın sonucu olarak LF (\n) karakteri verilir. Yani Windows'ta text modda LF ('\n') için CR/LF karakterleri
	yazdırıldığı için okunurken de ters işlem yapılmaktadır. Bu iki karakterin her ikisi de okunup sanki LF ('\n') karakteri okunmuş gibi davranılmaktadır. 
	Tabii UNIX/Linux ve macOS sistemlerinde dosya text modda açılmışsa dosya göstericisi CR/LF çifitini gösterdiğinde dosyadan bir byte okunacağı 
	zaman CR (\r) karakteri verilecektir. Sonra yine bir byte okunacağı zaman bu kez LF (\n) karakteri verilecektir. Windows'ta dosya binary modda açılmışsa 
	ve dosya göstericisi CR/LF çiftini gösteriyorsa dosyadan bir karakter okunduğunda CR karakteri okunur. Çünkü binary modda yazısal bir anlam uygulanmamaktadır.
	UNIX/Linux ve macOS sistemlerinde de okuma işleminde yine binary mod ya da text modda bir şey değişmemektedir. 

	O halde açış modu için şu tavsiyelerde bulunulabilir: Eğer bir dosyayı yazısal amaçlı açacaksanız text modda açmalısınız. Ancak yazısal olmayan bir dosya
	üzerinde işlem yapacaksanız dosyayı binary modda açmalısınız. 
	*/



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fputc('a', f);
    fputc('\n', f);
    fputc('b', f);

    fclose(f);

    return 0;
}






	int fprintf(FILE *f, const char *format, ...);
	int printf(const char *format, ...);



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i)
        fprintf(f, "Number: %d\n", i);

    fclose(f);

    return 0;
}

	fprintf(stdout, "this is a tes\n"); // ekrana yazar stdout dan dolayı


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    int a, b;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%d%d", &a, &b);

    printf("a = %d, b = %d\n", a, b);

    fclose(f);

    return 0;
}



	int fseek(FILE *f, long int offset, int whence);// istenilen yere bir şey yazömak için



/*	Fonksiyonun birinci parametresi dosya göstericisi konumlandırılacak dosyanın bilgi göstericisini almaktadır. İkinci parametre konumlandırma offset'ini
	belirtmektedir. Fonksiyonun ikinci parametresi konumlandırma offset'ini belirtmektedir. Üçücüncü parametre ise konumlandırmanın nerereye göre 
	yapılacağını başka bir deyişle konumlandırma orijinini belirtmektedir. Bu üçüncü parametre yalnızca 0, 1 ya da 2 değerini alabilir. 
	Diğer değerler geçirsizdir. 0 değeri konumlandırmanın dosyanın başından itibaren yapılacağı anlamına gelmektedir. Bu durumda ikinci parametrenin >= 0 
	olması gerekir. 1 değeri konumlandırmanın o anda dosya göstericisinin gösterdiği yerden itibaren yapılacağı anlamına gelmektedir. Bu duurmda ikinci
	parametre pozitif, negatif ya da 0 olabilir. Pozitif değer "bulunulan yerden n ileriye", negatif değer "bulunulan yerden n geriye" konumlandırma anlamına gelir. 
	Örneğin:

	fseek(f, -1, 1);

	Burada dosya göstericisi her neredeyse bir geriye konumlandırılmıştır. Örneğin:

	fseek(f, 10, 0);

	Burada dosya göstericisi 10'uncu offset'e konumlandırılmıştır. Üçüncü parametrenin 2 olması konumlandırmanın EOF pozisyonundan itibaren yapılacağı
	anlamına gelmektedir. Bu durumda ikinci parametrenin <= 0 olması gerekir. Örneğin:

	fseek(f, 0, 2);

	Burada konumlandırma EOF pozisyonuna yapılmaktadır. Örneğin:

	fseek(f, -1, 2);

	Burada konumlandırma dosyanın son byte'ına yapılmaktadır. Üçücnü parametre okunabilirliği artırmak için <stdio.h> içerisinde aşağıdaki 
	üç sembolik sabitle de define edilmiştir:

	#define SEEK_SET		0
	#define SEEK_CUR		1
	#define SEEK_END		2

	Örneğin:

	fseek(f, 10, SEEK_SET);
	fseek(f, 0, SEEK_END);

	fseek fonksiyonuna olmayan bir offset'i parametre oalrak geçrirsek ya da üçüncü parametreyi uygunsuz bir biçimde girersek fseek başarısız olabilir. 
	fseek başarı durumunda 0 değerine, başarısızlık durumunda sıfır dışı herhangi bir değere geri dönmektedir. Ancak programcılar genel olarak 
	fonksiyonun başarısını kontrol etmezler.
*/




#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "r+")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fseek(f, 0, SEEK_END);

    fprintf(f, "this is a test...\n");


    fclose(f);

    return 0;
}





#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    long size;
    
    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);// dosya uzunluğun verir
    printf("%ld\n", size);

    fclose(f);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    char buf[4096];
    
    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, 4096, f) != NULL)
        printf("%s", buf);

    fclose(f);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    char buf[3];
    
    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, 3, f) != NULL)
        printf("%s", buf);

    fclose(f);

    return 0;
}



#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[10];
    char *str;

    if (fgets(buf, 10, stdin) != NULL) {
        if ((str = strchr(buf, '\n')) != NULL)
            *str = '\0';
        puts(buf);
    }
    
    return 0;
}


size_t fread(void *ptr, size_t size, size_t n, FILE *f);
	size_t fwrite(const void *ptr, size_t size, size_t n, FILE *f);
// genelde binary dosyalarda kullanılır





#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10];

    if ((f = fopen("test.dat", "w+b")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    if (fwrite(a, sizeof(int), 10, f) != 10) {
        fprintf(stderr, "cannot write file!..\n");
        exit(EXIT_FAILURE);
    }

    rewind(f);

    if (fread(b, sizeof(int), 10, f) != 10) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", b[i]);
    printf("\n");

    fclose(f);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH        1024
#define BUFFER_SIZE     1024

int main(void)
{
    FILE *fs, *fd;
    char spath[1024], dpath[1024], *str;
    size_t result;
    char buf[BUFFER_SIZE];

    printf("Source file path: ");
    fgets(spath, 1024, stdin);
    if ((str = strchr(spath, '\n')) != NULL)
        *str = '\0';
    else {
        fprintf(stderr, "path too long...\n");
        exit(EXIT_FAILURE);
    }

    printf("Target file path: ");
    fgets(dpath, 1024, stdin);
    if ((str = strchr(dpath, '\n')) != NULL)
        *str = '\0';
    else {
        fprintf(stderr, "path too long...\n");
        exit(EXIT_FAILURE);
    }

    if ((fs = fopen(spath, "rb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    if ((fd = fopen(dpath, "wb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while ((result = fread(buf, 1, BUFFER_SIZE, fs)) > 0)
        if (fwrite(buf, 1, result, fd) != result) {
            fprintf(stderr, "cannot write file!...\n");
            exit(EXIT_FAILURE);
        }

    if (ferror(fs)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    printf("file successfully copied...\n");

    fclose(fs);
    fclose(fd);
    
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON {
    char name[64];
    int no;
};

int main(void)
{
    FILE *f;
    struct PERSON per;
    char *str;
    
    if ((f = fopen("test.dat", "wb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("Adi soyadi:");
        fgets(per.name, 64, stdin);
        if ((str = strchr(per.name, '\n')) != NULL)
            *str = '\0';
        if (!strcmp(per.name, "quit"))
            break;
        printf("No:");
        scanf("%d", &per.no);
        while (getchar() != '\n')
            ;
        if (fwrite(&per, sizeof(struct PERSON), 1, f) != 1) {
            fprintf(stderr, "cannot write file!..\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(f);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct PERSON {
    char name[64];
    int no;
};

int main(void)
{
    FILE *f;
    struct PERSON per;
 
    if ((f = fopen("test.dat", "rb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&per, sizeof(struct PERSON), 1, f) == 1) 
        printf("%s, %d\n", per.name, per.no);
  
    if (ferror(f)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);

    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON {
    char name[64];
    int no;
};

int main(void)
{
    FILE *f;
    struct PERSON per;
    char *str;
    char name[64];

    printf("Aranacak kisinin adi soyadini giriniz:");
    fgets(name, 64, stdin);
    if ((str = strchr(name, '\n')) != NULL)
        *str = '\0';

    if ((f = fopen("test.dat", "rb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&per, sizeof(struct PERSON), 1, f) == 1) 
        if (!strcmp(per.name, name)) {
            printf("record found : %s, %d\n", per.name, per.no);
            break;
        }
       
    if (feof(f))
        printf("record not found!..\n");

    if (ferror(f)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);

    return 0;
}





#include <stdio.h>

	int main(void)
	{
		double val;

		for (;;) {
			if (scanf("%lf", &val) == EOF)
				break;
            
			printf("%f\n", val * val);
		}

			return 0;
		}
	
// windows ctrl z linux ctrl d çıkmak için eof etkisi yaratır

//stdout ve stderr defold durumda ekrandır 

//           hata için
// > hatayı ekrana yazar
// 2> normalı ekrana yazar



/*#include <stdio.h>

	int main(void)
	{
		printf("stdout\n");
		fprintf(stderr, "stderr\n");

		return 0;
	}

	Şimdi programı şöyle çalıştırmış olalım:

	./sample > x.txt

	Burada ekranda yalnızca "stderr" yazısını göreceğiz. Çünkü > semboli yalnızca stdout dosyasını yönlnedirmektedir. Eğer stderr dosyası yönlendirilmek 
	istenirse bu durumda 2> sembolünün kullanılması gerekir. Örneğin:

	./sample 2> x.txt

	Burada da ekran yalnızca "stdout" yazısını göreceğiz. Çünkü biz bu örnekte yalnızca stderr dosyasını yönlendirmiş olduk. İşte programcıo eğer 
	hata mesajlarını stderr dosyasına yazarsa kullanıcı programın normal mesajlarıyla hata mesajlarını birbirinden ayırabilir. Örneğin:

	find / -name "sample.c"

	Bu komut kökten itibaren her dizinde "sample.c" dosyasını aramaktadır. Ancak yekisiz dizinlerle karşılaştığında stderr dosyasına hata mesajları yazmaktadır. 
	İşin başında stdout ile stderr ekrana yönlendirildiği için programın normal mesajları ile hata mesajları birlikte ekranda görünecektir. Karışık bir 
	görüntü oluşacaktır. Halbuki biz bu programı çalıştırırken stderr dosyasını başka bir dosyay yönlendirirsek kafamızın karışmasını engellemiş oluruz. 
	Örneğin:

	find / -name "sample.c" 2> err.txt

	Artık programın hata mesajları ekrana değil "err.txt" dosyasına yazdırılacaktır. İşte kullanıcıya bu ayırma olanağını vermek için hata mesajlarının 
	stderr dosyasına yazdırılması gerekmektedir. Linux sistemlerinde /dev/null isimli özel bir dosya vardır. Bu dosyaya yazılan her şey atılmaktadır. 
	Dolayısıyla yönlendirme bu dosyaya yapılırsa hata mesajlarından tamamen kurtulabiliriz. Örneğin:

	find / -name "sample.c" 2> /dev/null
*/


