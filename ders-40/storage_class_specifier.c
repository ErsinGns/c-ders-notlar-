// deprecation ===> bir ögenin ilerde kaldırılacağı anlamına gelir
//legacy code ==> eski kod miras kod bugün yazılsa öyle yazılmazdı
//code base ===> geçmişten gelen kodların tamamı kod havuzu



#include <stdio.h>
#include <stdbool.h>


	// Storage Class Specifiers
	// ------------------------
	// auto
	// register
	// static
	// extern


	// Type Modifiers
	// --------------
	// const
	// volatile
	// restrict


// ilk kez çağırılma
void func(void)
	{
		static bool first_call_flag = true; // memory de kalır ve aşağıda false a girince artık false yani ilk kez çağrılmamış demektir.
		if (first_call_flag)				// bir sonraki çağırmada girmez if e.ilk kez de çağrılmadığını anlar.
		{
			printf("ilk kez cagrildi\n");
			first_call_flag = false;
		}

		printf("Diger islemler\n");
	}

// random char
int get_random_char(void)
{
	int c;
	while (!isalnum(c = rand() % 128))
		;
	return c;
}


// Eğer fonksiyon içerisinde otomotik ömürlü değişkenler varsa bunların her seferinde ilk değer ile hayata getirme maliyeti var.

void func(void)
{
	int primes[] = {2,3 } ;

}

// function her çağrıldığında dizi yeniden hayata gelecek. yani stackte ki alana bunların yazılması gerekiyor.
// bu maliyetten kaçmak için static ile nitelenebilir.


void func(void)
{
	static int primes[] = {2,3 } ;

}

// function içerisindeki lookup table olarak kullanılan dziler static ömürlü olursa maliyet kısılır.
// automatic ömürlü olursa her function call da ilk değer verme maliyeti oluşur.





//? Linkage
// -------
// Eğer bir isim aynı projeyi oluşturan birden fazla kaynak dosyada kullanıldığında, aynı varlığa işaret ediyorsa
// böyle isimlerin bağlantı kategorisi external linkage dır.

// Eğer bir isim aynı projeyi oluşturan birden fazla kaynak dosyada kullanıldığında, farklı varlığa işaret ediyorsa
// böyle isimlerin bağlantı kategorisi internal linkage dır.

// Eğer bir isim kendi kaynak dosyasında bile kullanılamıyorsa no linkage denir. Bunlar local nesnelerdir.


// DIŞ BAĞLANTI / EXTERNAL
// -----------------------
// Hiçbir şey yapmaya gerek yok.
// default olarak dış bağlantı.

int x = 10; // dış bağlantıya ait

void foo(int x) // dış bağlantıya ait
{ }


// İÇ BAĞLANTI / INTERNAL
// ----------------------

// İç bağlantıya almak için tanımda static keyword kullanılacak

static y = 56; // iç bağlantıya ait
static void foo(void) // iç bağlantıya ait
{ }

//derleyici sen bunun için yer ayırma.
//Bunun projeyi oluşturan başka bir dosyada global değişken olduğunu bil.
extern int x;


// ali.h						ali.c
extern int x;				int x = 10;
extern int a[];				int a[20] = {0};
//içine 20 yazmasakta olur

extern void(func)(int);		void func(int x)  // fonksiyonlar sözkonusu olduğunda extern koysakta,
							{}					// koymasakta extern kabul ediliyor.



// EĞER erişim istemezsek.
// Sadece kod file a yani .c uzantılı file a static ile bildirim yapılır

// ali.h						ali.c
// bildirim yok				static int g = 20;
// Bildirim yok				static void func(void)
// 							{ }


// Soru?
// statici koymasak ama başlıkta da gerek yok diye bildirim yapmasak olmaz mı?
// olmuyor.Linker time da hata alırız.AYNI İSİMLİ GLOBAL DEĞİŞKEN VEYA FONKSİYON KULLANILIRSA HATA OLUR.
// YADA UNDEFİNED BAHAVİOR.

// ÖRNEK ÜZERİNDE BAKALIM

// nutility.c içinde print_array var

// ben main içinde void print_array(...) benzer birşey tanımlayıp çalıştırsam
// linker time da hata alırız veya UB oluşur.
// ÇÜNKÜ DIŞ BAĞLANTIYA AİT İSİMLER TEK OLMALI.!!!!!!!!!!!!!!!!


// FONKSİYONU ASLA STATIC İLE HEADER FİLE DA BİLDİRME !!!
// HİÇBİR ANLAMI YOK.YANLIŞ. HEADER FİLE DA STATİC İLE BİLDİRİM VEYA TANIMLAMA YAPMA.

// KURAL
// DIŞARIYA AÇIKSA EXTERN İLE HEADER FİLE A BİLDİRİM YAP
// DIŞARIYA AÇIK DEĞİLSE CODE FİLE DA STATİC İLE BİLDİR.

// burada bir sorun oluşuyor.
// global namespace pollution problem
// global isim alanı kirlenmesi problemi.

// dış bağlantıya açık isimler özelleştiriliyor.önüne bir ek veya bir alt tire falan konuluyor.


// ÖRNEK:

// nutility.c
const int primes[] = {0,2,3,5,7 }; // rakamla eşlemek için başa 0 koydu

// nutility.h 
extern const int primes[];


//? VOLATILE
// --------

// değişkenler 2 farklı yapıda oluyor.
// program dışı kaynakları tarafından değiştirilen nesneler.
// mesela bir kod var ve dışarıdan bir aygıtın bu bellek alanını set edebileceğini biliyoruz.
// burada volatile kullanılır.

// dış kaynaklar tarafından değiştirilebilen varlıklar,
// memory mapped file olabilir.
// birtakım cihazların registerları olabilir.
// interruptlarla ilgili olabilir ...

// bu tip örnekler ile ilgili derleyicinin optimizasyon problemi var.

// DİKKAT!!!!
// Aşağıda compiler g yi registerlara alır.registerlara almasının sebebi, memory den erişim maliyeti
// registerlardan erişime göre çok fazla.g nin de değişmediğini görünce her seferinde registerlardan
// veriyi işleme sokar.çünkü daha maliyetsiz.
// AMA
// Dış dünyadan başka bir cihaz, g nin değerini değiştirirse bunu anlayamadan tekrar cpu registerdan
// değeri okuyup işlemlere soktuğu zaman hata ile karşılaşma şansımız çok yüksek.
// Aşağıda bunun örneği var

// int g = 20;

// int main()
// {
// 	if(g == 20)
// 	{
		
// 	}
// }

// (NOT: g++; olsaydı değiştiğini anlayacaktı. ama değişmemiş zannedip buna göre optimizasyon yapıyor.
// volatile ile bu optimizasyonu iptal ediyoruz.yine memory den her durumda değeri çekiyor.)

// Bunu engellemek için volatile keyword kullanılır.
// volatile her seferinde veriyi memory den oku demektir.
// Değiştirilirse de oradan okuduğunda anlayacak.
// Burada bir optimizasyon yapmaktan kaçacak compiler.

// yani volatile ile nitelenen değişken her zaman memory den okunacak, registerdan değil.
// Optimizasyonu iptal ediyor.


// NOT!!!!!! DÖKÜMANTASYONDAN ALDIM				    |
// Volatile değişkeni,volatile olmayan bir lvalue değişken ile	    |
// read/write yapmak UNDEFINED BAHAVIOR.				    |
// 								    |
// volatile int n = 1; // object of volatile-qualified type	    |
// int* p = (int*)&n;						    |
// int val = *p; // undefined behavior.				    |
			


//! auto int g = 3; //sentax hatası
int main(int argc, char const *argv[])
{
    //auto == değişekenin otomotik olduğunu söyler
    auto int x = 3; // int x = 3; aynı anlam defolt olarak gelir

    //register == işlemcinin yazmaçında tutmasını rica eder tutmaya bilir l123
    // derleyici optimize ettiği için artık kullanılmasına gerek yok

    //static == yerel değişkende kullanılırsa hayatı programının sonuna kadar
    static int k = 3; // programın sonuna kadar k kalır
     //1.12 bak önemli bir kod var
     //static fonksyonda çağrı yapıyor ama string değişmiyor
    // global alanda isim vereceksen önune dosyanın adınıda yaz ki diğer doysalarada vereceğen isimin farklı varyasynlarını kullanasın


    //extern ===> başka bir doysayda tanımlanmış yer ayırmaz ayrıyeten
    /// tanımlayan modüle .h a extern int a; demelisin

    // static ==> değişkenin sadece bildirilen kaynak dosyaya özel kılar
    // global alanda tanımlanan için diyer dosyalar da aynı isimden değişkenler oluşturabilir ama değişkenler farklı adreslere sahip olur
    // fonksyon eğer o dosyaya sadece ait olsun istiyorsan static kullan



volatile int x = 123;


	volatile int *ptr = &x;
	*ptr;		// bu her çağırıldığında memory den tekrar okur değerini.Registerdan değil. 

	// Eğer
	int * volatile ptr; // dersek bu seferde ptr ye her eriştiğimde optimizs. yapmayacak. Memoryden okuyacak.

	
	volatile int * volatile ptr = &x; // dersek *ptr ve ptr volatile oldu.

    return 0;
}

