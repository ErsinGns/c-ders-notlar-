#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //void realloc(void* adres, int yeni adres); yer büyütmeye yada küçültmek için kullanılrı
    // adres yeri değişir büyük ihtimalle küçük ihtimal aynı
    //eski ögeleri kopyalar taşırken 
    // başarısız olursa eski veriler free olmaz başarı olursa olur
    // bulunduğu yerde büyütmeye çalışmaz denk gelirse olur yazılan algoritmaya bağlı
   
    // 1 - realloc fiziksel olarak var olan bellek bloğunu büyütecek şekilde yapabilir.
	// yani eski adresi ile yeni adresi aynı olabilir, var olan bloğu uzatabilir.

	// 2 - Yeni bir bellek bloğu allocate etti. eski bellek bloğundakileri 
	// yeniye kopyaladı, eski bloğu free edip yenisini return etti.

	// NOT: Önce 1 i dener olmazsa, sonra 2. yi dener diye birşey yok.
	// Burada bir algoritma var ve o karar veriyor neyi nasıl yapacağına.

	// 3 - Büyütmede başarısız olunması. bu durumda NULL ptr döner ama eldeki
	// bellek bloğunuda geri vermiyor. Büyüteyim derken eldekini kaybettim riski yok.
	// yani geri dönüş değeri ile ilk parametre aynı adres olmayabilir.
    // İki adet bilgi var.
	// 1 - Reallocation takes time ! 
	// Maaliyetli bir işlem yani zaman alıyor demektir bu.
	// mesela 100mb veriyi 10byte büyütmek için muhtemelen başka bir veri bloğu yaratıp dataları yeni yere kopyalayıp
	// eski memory bloğunu free edecek. Maliyeti büyük.

	// sürekli realloc yapmak demek bunu sürekli yapmak demek, ciddi performans problemleri ortaya çıkabilir.

	// 2 - Realocation invalidates pointers!
	// realloc free işlemi yaptığı için, varolan pointerı invalid hale getiriyor.
	// bizde buraya erişme girişiminde bulunursak UB oluşur.

	// Bunu bilinçli olarak biz yapmıyoruz
    // 1- realloc(pd,100) -> pd = NULL ise, bu UB değil.well-defined behavior.
    // reallocun 1. parametresine NULL ptr geçersek bu artık malloc gibi davranır.yani malloc(100) e eşdeğerdir.

    // 2- realloc(pd,n)  -> n = 0 ise UB değil. Implementation Defined. Benim derleyicide free(pd) gibi davranr.

    // burada normalde döngü dışında malloc yazıp, sonra döngü içinde realloc yazmak yerine direkt döngü içinde realloc ile
    // devam edilebilir.bu sayede döngü dışındaki malloca gerek kalmadan realloc ilk seferinde malloc işlevi yapar ve realloc ile
    // diğer turlarda devam eder.döngü dışındaki başka koda bağımlı hale gelmez

    // Öbür türlü eksiltme işlemlerinde ise en son turda free çalışır.azalta azalta 0 a gelir çünkü.
    // Döngü dışındaki başka koda bağımlı hale gelmez.

    // Tipik hatalar

    // 1- Dinamik bellek bloğunu geri vermemek.memory leak
    // 2- Dinamik bellek bloğu free edildi.sonrada bu ptr nin gösteridği nesneye erişilmeye çalışıldı.
    // Dereference etmek. UNDEFINED BEHAVIOR
    // 3- Dİnamik bellek bloğunun adresini başka fonksionlara kopyaladık, free ettik ama diğer kodların 
    // bundan haberleri yokken 
    //     a - invalid pointerı kullandılar. UB
    //     b - onlarda free etti.	UB
    // 4- Dinamik bellek bloğunu realloc ile büyütmeye çalıştık, sanki aynı yerde büyüyecek gibi yazdık kodu,
    // ama dizi başka bir yere taşınınca UB oluştu.
    // 5- Dinamik olmayan bellek bloğunu realloc ile büyütmeye çalışmak UB.

    // Bazı programlarda heapten alınarak kullanmış bir alan olsun, free ile geri versek bile oradaki byte lar
    // orada duruyor olabilir.Bu da güvenlik açığı oluşturabilir. bu memory bloğunun free etmeden önce clear
    // edilmesi(memset(pd,0,size * sizeof(int))) gerekir, sonra free edilir.

    // auto -> C de kullanımdan düşmüş bir keyword. C++ ta kullanılıyor.
	// 		Yerel değişkenler otomatik veya static ömürlü olabilir. auto otomatik ömürlü olduğunu gösteriyor.
	// 		Artık auto ile nitelenmemiş bir bildirim, otomatik olarak tanımlanır. 
			
	// 		int main(){
	// 			int x = 10; int burada static ömürlü olur
	// 			//auto int x = 10; hiçbir fark yok yukarısı ile
	// 		}

	// 		global değişken otomatik ömürlü olamayacağı için global scope ta tanımlanırsa sentaks hatası verir.

	// 		Ayrıca fonksiyonların parametre değişkenleri otomatik ömürlü olduğu için  burada da auto kullanmaya 
	// 		gerek yok.

	// 		int func(auto int x) //auto olsada olur olmasada olur.


	// register -> auto kadar olmasa da kullanımdan düşmüş. spesifik bir mikroişlemci varsa belki kullanılabilir.
	// 			eski kodlarda kullanılıyordu.

	// 			türkçesi yazmaç demek. işlemci üzerinde bununan ve işlemcideki işlemlerin 
	// 			fiilen yapıldığı bellek alanıdır.
				
	// 			32 bit işlemcilerin yazmacı 32 bit, 64 bitin yazmaçları 64 bit.
	// 			Cache ile karıştırmamak lazım.

	// 			Aşağıdaki tanım bir ricadır.Çünkü yerine getirmek compilera bağlıdır.
	// 	  Rica: Derleyici senin içinde uygunsa x i işlemcinin yazmacında tutacak şekilde kod üret.
	// 			register int x = 10;
	// 			rica dememizin sebebi, böyle yazsak bile compiler uygun görmezse bunu registerda tutmayabilir.


	// 	  a - Neden ? işlemcinin işlemi yapması için bu değeri yazmaca alması gerekiyor. Eğer x i yazmaca zaten alırsa
	// 				x i memory den yazmaca tekrar çekmesine gerek kalmayacak. Bu da maaliyet zaten.Bu maliyeti ortadan
	// 				kaldırıyor.

	// 	  b - Neden kullanımdan düştü ? 
	// 		  compiler zaten en iyi optimizasyonu kendi yapıyor. 
	// 		  İnsandan çok çok daha iyi yapıyor. 

	// 		  for(register int i = 0; i < 1000000; i++)
	// 		  {}


    // static -> C de overload edilmiş. Birden fazla anlamı var.
	// 			global scope ta tanımlanırsa eğer private gibi, sadece aynı file dan erişilebilir.
	// 			local scope ta tanımlanırsa bu nesne static ömürlü olur.Programın başından sonuna kadar
	// 			hayatını sürdürür.


    return 0;
}
