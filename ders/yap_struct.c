
	struct DATE {			/* bildirim, bellekte yer ayrılmaz */
		int day, month, year;
	};

	struct DATE d;		/* tanımlama, bellekte yer ayrılır */


struct PERSON {
		char name[32];
		int no;
	};

	struct PERSON per = {"Ali Serce", 123};		/* geçerli */



struct CITY {
		char name[32];
		int plate;
	};

	struct CITY cities[5];

	struct CITY cities[5] = {{"Ankara", 6}, {"Izmir", 35}, {"Eskisehir", 26}, {"Kutahya", 43}, {"Istanbul", 34}};		/* iyi teknik */




#include <stdio.h>

struct SAMPLE {
	int a;
	int b;
	double c;
};

int main(void)
{
	struct SAMPLE s;
	struct SAMPLE *ps = &s;

	printf("%p\n", ps);				/* 0000002B7395FD70 */
	printf("%p\n", &ps->a);			/* 0000002B7395FD70 */
	printf("%p\n", &ps->b);			/* 0000002B7395FD74 */
	printf("%p\n", &ps->c);			/* 0000002B7395FD78 */

	return 0;
}





	struct SAMPLE {
		int a;
		int b;
		int c;
	};

	void foo(struct SAMPLE *ps)				/* ps = &s */
	{
		printf("%d, %d, %d\n", ps->a, ps->b, ps->c);
	}

	int main(void)
	{
		struct SAMPLE s = {10, 20, 30};

		foo(&s);			/* iyi teknik */

		return 0;
	}



#include <stdio.h>
#include <stdlib.h>

struct PERSON {
	char name[32];
	int no;
};

int main(void)
{
	struct PERSON *per;

	if ((per = (struct PERSON *)malloc(sizeof(struct PERSON))) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per->name, "Ali Serce");
	per->no = 123;

	printf("%s, %d\n", per->name, per->no);

	free(per);

	return 0;
}



#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t;

	t = time(NULL);

	printf("%.0Lf\n", (long double)t);

	return 0;
}


#include <stdio.h>

struct DATE {
	int day, month, year;
} date = {10, 12, 2009}, *pdate = &date;

int main(void)
{
	struct POINT {
		int x, y;
	} pt = {10, 20};

	printf("%d/%d/%d\n", date.day, date.month, date.year);
	printf("%d/%d/%d\n", pdate->day, pdate->month, pdate->year);

	printf("%d, %d\n", pt.x, pt.y);

	return 0;
}


#include <stdio.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};

int main(void)
{
	struct PERSON per = {"Sacit Mutlu", 123, {12, 7, 1978}};

	printf("%s, %d, %d/%d/%d\n", per.name, per.no, per.bdate.day, per.bdate.month, per.bdate.year);

	return 0;
}


#include <stdio.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};


void disp(struct PERSON *pper)
{
	printf("%s, %d, %d/%d/%d\n", pper->name, pper->no, pper->bdate.day, pper->bdate.month, pper->bdate.year);
}

int main(void)
{
	struct PERSON per = {"Sacit Mutlu", 123, {12, 7, 1978}};
	
	disp(&per);

	return 0;
}



#include <stdio.h>

struct DATE {
	int day, month, year;
};

struct PERSON {
	char name[32];
	int no;
	struct DATE bdate;
};

int main(void)
{
	struct PERSON per = {"Sacit Mutlu", .bdate.day = 12, .bdate.month = 7, .bdate.year = 1978, .no = 123};
		
	printf("%s, %d, %d/%d/%d\n", per.name, per.no, per.bdate.day, per.bdate.month, per.bdate.year);

	return 0;
}




// bağlı lısteler
//	Sonuç olarak eğer bir sistemde çok fazla insert, delete işlemi yapılıyor ancak elemana erişim fazla yapılmıyorsa bağlı listeler daha iyi bir seçenek oluşturabilmektedir. 












