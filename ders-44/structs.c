#include <stdio.h>





int main(int argc, char const *argv[])
{
    system("pause");//Press any key to continue . . . 
    return 0;
}

// NOT: C STANDARTLARINA GÖRE FUNCTION ADRESLERİ ARASINDA TÜR DÖNÜŞÜMÜ YAPMAK
// UNDEFINED BEHAVIOR AMA DEREYİCİLER BUNA İZİN VERİYOR.DOĞRU KOD ÜRETİYOR.
// ÖZELLİKLE CONST VOİD* PARAMETRELERİ SÖZKONUSU OLDUĞUNDA.



// NOT:  BİR STRUCT TÜRÜNÜN ELEMANI KENDİ TÜRÜNDEN OLAMAZ AMA KENDİ ADRESİ TÜRÜNDEN OLUR.
// ÇÜNKÜ ADRES İFADESİNİN SİZEOF DEĞERİ BELLİ.

struct data{
	int a;
	struct data * ptr;
};
// bu olur 
// ama 
struct data x;// olmaz.


// LINKED LIST

// 	En çok kullanılan veri yapısı dinamik diziydi.Bu ondan farklı

// 	singly linked list -> ileri gidilebiliyor.kendinden sonraki veriyi tutan düğümün
// 	adresini tutar ama kendinden öncekini tutamaz.

// 	doubly linked list - > hem ileri hemde geri gidilebiliyor.içerisinde nex ve prev isimli
// 	2 adet pointer var.daha fazla yer kaplar singly ye göre.


// Linked list Dezavantajları / Avantajları
	
// 	1 - Bellek kullanımı
// 	--------------------
// 	100 elemanlı bir int    sizeof(100*int) -> 400byte
// 	ama 
	
// 	100 elemanlı bir int    sizeof(100*int) + (100 * singly list ptr size)  -> 800 byte
// 	+ bir de header size var. çok daha fazla 800 den.
	
// 	Hatta doubly linked list olursa 1200 byte + header size lar -> 1200 den fazla yer kaplar.

// 	2 - Fragmante olmuş bir blokta bağlı listeyi büyütmek daha kolay olabilir.
// 	dinamik dizi olsaydı dizi 1.5 veya 2 katına çıkacağı için daha zor olur.

// 	3 - Dinamik dizide öğeye erişmek constant time.
// 		Bağlı listede 15. ye erişmek için ilk 14 ünü dolaşmak gerekiyor.

// 	4 - Bağlı listede ekleme veya silme işlemi constant time da yapılabilir.
// 		Dinamik dizide ise ortaya bir eleman eklemek için tüm diziyi 
// 		kaydırmak gerekiyor ve bunun içinde copy işlemi yapmak gerekiyor.



//! STRUCT ALNIGMENT PADDING

// 	Bellekte 1 byte a erişme diye birşey yok. işlemci 32 bit ise 32 bitlik veriye yani 4 byte,
// 	64 ise 8 bytelık veriye erişir.

// 	temel erişim birimi işlemcinin kaç bit olduğu bilgisidir.s

// 	daha önce konuşulmuştu.
// 	bir datanın bir kısmı bir bellek alanında, diğer kısmıda diğer bellek alanında olursa bunları birleştirmesi gerekir.
// 	Buda maliyetli bir işlem. BUnun yerine alignment yapıyor.



//? union
//union içindeki sizeof değeri en yüksek olan eleman, union un size ını belirler.

union data {
	int a, b;
	double dval;
	double dx;
	char str[16];
};


//card.h nin içi
#define POKER

#ifdef POKER
	typedef enum {Club,Diamond,Spade,Heart}Suit;
#else
	typedef enum {Club,Diamond,Heart,Spade}Suit;
#endif


typedef enum {Club,Diamond,Spade,Heart}Suit;
//aşağıdaki gibide olabilir.Kart dağıtmada falan kullanılabilir.
typedef enum { two = 2,three = 3,four = 4,five = 5,six = 6,seven = 7,
			   eight = 8,nine = 9,ten = 10,jack = 10,queen = 10,king = 10,ace = 11};



int main()
{
	const char* const asuits[] = {
		[Club] = "Sinek",   // Club bir constant. enumdan 0 değeri ile gelir ve dizinin 0. indisine
		[Diamond] = "Karo", // designated initilaze ile değerler atanır.
		[Heart] = "Kupa",
		[Spade] = "Maca",
	};
}


#include <stdio.h>
typedef enum { white, gray, blue, magenta, brown, red, black,NoOfColors }Color;

int main()
{
	for (Color c = white; c < NoOfColors; ++c)
		printf("%d", c);
}//0123456


