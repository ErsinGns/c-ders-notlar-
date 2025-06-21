

union SAMPLE {
    int a;
    long b;
    double c;
};

union SAMPLE s;

/*Burada s "union SAMPLE" türündendir. Bir birlğin elemanlarına yine nokta operatörü ile erişilir. Örneğin s.a, s.b ve s.c gibi. Birlikler türünden 
	göstericiler olabilir. Yine gösterici ile birlik elemanlarına -> operatörü ile erişilebilir. Örneğin:

	union SAMPLE s;
	union SAMPLE *ps;

	ps = &s;
*/

typedef union tagSAMPLE {
    int a;
    long b;
    double c;
} SAMPLE;




	//Bir birlik nesnesine ilkdeğer verilebilir. Ancak birliğin yalnızca ilk elemanına değer verilebilir. Örneğin:

	union SAMPLE {
		int a;
		long b;
		double c;
	};

	union SAMPLE s = {1, 2, 3};		/* geçersiz! */
	union SAMPLE k = {1};			/* geçerli, değer a elemanına verilmiş */


	union SAMPLE s = {.c = 1};			/* geçerli! */
	union SAMPLE k = {.b = 1, 2};		/* geçersiz! */


//Bir grup bilgiden yalnızca birine gereksinim duyulduğu durumlar seyrektir. Örneğin bir kişinin iletişim bilgisi "telefon numarası" ya da "posta adresi"
//ya da "TC kimlik numarası" olabilir. Bu bilgilerin hepsinin bulunmasına gerek olmayabilir. Bunlardan yalnızca birinin bulunması yeterli olabilir. Örneğin:

struct PERSON {
    char name[64];
    int no;
    union {
        char telno[11];
        char tcid[12];
        char email[64];
    } cinfo;
};

struct PERSON per;



/*
	Burada per nesnesinin cinfo elemanı bir birliktir. Bu birliğin elemanları çakışık yerleştirilecektir. Çünkü buradaki bilgilerden yalnızca birinin
	buunması yeterlidir. Pekiyi biz per nesnesi içerisindeki cinfo nesnesinin hangi elemanın dolu olduğunu nasıl anlayabiliriz? Genellikle bir birliğin hangi 
	elemanının kullanılıyor olduğunu anlamanın pratik bir yolu yoktur. O zaman bu bilgiyi de yapının içerisinde tutmal gerekir:
*/
enum {CINFO_TELNO, CINFO_TCID, CINFO_EMAIL};

struct PERSON {
    char name[64];
    int no;
    int cinfo_flag;
    union {
        char telno[11];
        char tcid[12];
        char email[64];
    } cinfo;
};

struct PERSON per = {"Ali Serce", 123, CINFO_EMAIL, {.email = "aslank@csystem.org"}};



/*	Parçalardan bütünü oluşturmak ve bütünü parçalara ayrımak için de birlikler kullanılabilmektedir. Aşağıdaki birliğe dikkat ediniz:

	#include <stdint.h>

	union DWORD {
		uint32_t dword;
		uint8_t bytes[4];
	};

	union DWORD dw;

	Burada DWORD isimli birliğin iki elemanı vardır: dword ve bytes. Bunlar çakışık bir biçimde yerleştirilecektir. O halde biz dw.dword elemanına 4 byte 
	yerleştirdiğimizde bunların parçalarını dw.bytes[0], dw.bytes[1], dw.bytes[2] ve dw.bytes[3] elemanlarından alabiliriz. Tabii işlemcinin little endian 
	ya da big endian olup olmadığına göre parçaların sırası da değişebilecektir. 

	Aşağıdaki örnekte biz birliğin dword elemanına 4 byte'lık bir bilgi yerleştirip onları tek tek birliğin bytes elemanından elde ettik. Sonra da bu işlemin 
	tersini yaptık.*/


#include <stdio.h>
#include <stdint.h>

union DWORD {
	uint32_t dword;
	uint8_t bytes[4];
};

int main(void)
{
	union DWORD dw;

	dw.dword = 0x12345678;

	printf("%02x %02X %02X %02X\n", dw.bytes[0], dw.bytes[1], dw.bytes[2], dw.bytes[3]);	/* 78 56 34 12 */

	for (int i = 0; i < 4; ++i)
		printf("%02X ", dw.bytes[i]);
	printf("\n");

	dw.bytes[0] = 0x10;
	dw.bytes[1] = 0x20;
	dw.bytes[2] = 0x30;
	dw.bytes[3] = 0x40;

	printf("%08lX\n", (unsigned long)dw.dword);		/* 40302010 */

    return 0;
}



#include <stdio.h>
#include <stdint.h>

struct BYTES {
	uint8_t b0;
	uint8_t b1;
	uint8_t b2;
	uint8_t b3;
};

union DWORD {
	uint32_t dword;
	struct BYTES bytes;
};

int main(void)
{
	union DWORD dw;

	dw.dword = 0x12345678;

	printf("%02x %02X %02X %02X\n", dw.bytes.b0, dw.bytes.b1, dw.bytes.b2, dw.bytes.b3);	/* 78 56 34 12 */

	dw.bytes.b0 = 0x10;
	dw.bytes.b1 = 0x20;
	dw.bytes.b2 = 0x30;
	dw.bytes.b3 = 0x40;

	printf("%08lx\n", (unsigned long)dw.dword);		/* 40302010 */
	
    return 0;
}


#include <stdio.h>

struct DATE {
    int day, month, year;
};

void disp_date(struct DATE *pdate)
{
    printf("%02d/%02d/%04d\n", pdate->day, pdate->month, pdate->year);
}

int main(void)
{
    struct DATE d;

    disp_date(&(struct DATE) { 10, 12, 2020 });

    d = (struct DATE){21, 12, 2008};
    disp_date(&d);

    return 0;
}


#include <stdio.h>

int main(void)
{
    int *pi;

    pi = (int[]){10, 20, 30};

    *pi = 100;       /* geçerli */

    for (int i = 0; i < 3; ++i)
        printf("%d\n", pi[i]);
    printf("\n");
    
    return 0;
}

/*~	(Bit NOT)
	&	(bit AND) 
	^	(Bit EXOR)
	|	(bit OR)
	<<	(Sola öteleme)
	>>	(Sağa öteleme)
	
	Bit operatörlerinin öncelik tablosundaki konumları şöyledir:

	() [] .	->						Soldan-Sağa
	+ - ++ -- !	& *	(tür) sizeof ~	Sağdan-Sola
	* / %							Soldan-Sağa
	+ -								Soldan-Sağa
	<< >>							Soldan-Sağa
	<  > <= >=						Soldan-Sağa
	!= ==							Soldan-Sağa
	&								Soldan-Sağa
	^								Soldan-Sağa
	|								Soldan-Sağa
	&&								Soldan-Sağa
	||								Soldan-Sağa
	?:								Sağdan-Sola
	=, +=, /=, *=,...				Sağdan-Sola
	,								Soldan-Sağa	 */




#include <stdio.h>

int main(void)
{
    unsigned char a = 0x3F;     /* 0011 1111 */

    a = a & 0xEF;
    printf("%02X\n", a);        /* 0010 1111 = 0x2F */

    return 0;
}




