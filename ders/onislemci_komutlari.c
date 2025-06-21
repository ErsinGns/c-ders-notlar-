

#include <stdio.h>

int main(void)
{
    #if 1
        printf("Yes\n");
    #elif 2
        printf("ara");
    #else
        printf("No\n");
    #endif

    return 0;
}




#include <stdio.h>

#define MAX 

int main(void)
{
#ifdef MAX  // ifndef tersi
    printf("Yes\n");
#else
    printf("No\n");
#endif

    return 0;
}


// header dosyası


#ifndef SAMPLE_H_
#define SAMPLE_H_

<dosya içeriği>

#endif

// makrolar



#include <stdio.h>

int main(void)
{
    char fname[] = __FILE__;

    printf("%s\n", fname);

    return 0;
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", __LINE__);
    printf("%d\n", __LINE__);

    return 0;
}

int main(void)
{
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);

    return 0;
}


/*
	__cplusplus: Bu makro eğer derleme C'de yapılıyorsa define edilmemiş, C++'ta yapılıyorsa define edilmiş kabul edilmektedir. Dolayısıyla programcılar
	C kodlarının C++ derleyicileri tarafından derlenmesi durumunda iki dilin uymsuzluklarını gidermek için bu makroyu kullanabilirler. Örneğin bazı 
	C'deki özellikler C++'ta geçerli olmayabilmektedir. Bu durumda programcı her ne kadar C dilinde yazıyorsa da C++'ın kabaca C'yi kapsadığı fikriyle
	kodunun C++ derleyici ile derlenmesini de isteyebilir. Örneğin "restrict göstericiler" C99 ile birlikte C'ye eklenmiştir. Ancak C++ bu özelliği 
	desteklememektedir. Bu durumda biz aşağıdaki gibi bir prototipi C++ uyumlu hale getirebiliriz:

	#ifdef __cplusplus
	void foo(void * p);
	#else
	void foo(void * restrict p);
	#endif

	__STDC_VERSION__: Önişlemci bu makroyu gördüğünde  201ymmL biçiminde long bir sabit yerleştirmektedir. Bu sayede biz C'nin hangi versiyonunda çalıştırığımızı
	derleme sırasında anlayabiliriz.*/



// gcc ye özle

	#include <stdio.h>

	int main(void)
	{
	#ifdef __GNUC__
		printf("gcc\n");
	#else
		printf("not gcc\n");
	#endif

		return 0;
	}


// hangi işletim sistemi
#include <stdio.h>
	#include <stdlib.h>

	#if defined(__unix__)
	#include <sys/stat.h>
	#elif defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
	#endif

	#define DIR_NAME       "xxx"

	int main(void)
	{
	#if defined(__unix__)
		if (mkdir(DIR_NAME, 0777) == -1) {
			fprintf(stderr, "cannot create directory!..\n");
			exit(EXIT_FAILURE);
		}
	#elif defined(_WIN32) || defined(_WIN64)
		if (!CreateDirectory(DIR_NAME, NULL)) {
			fprintf(stderr, "cannot create directory!..\n");
			exit(EXIT_FAILURE);
		}
	#else
		#error operating system not supported
	#endif

		return 0;
	}






#ifndef __unix__
		#error operatating system is not UNIX/linux // hatalar için kullanılır
#endif


#ifdef SIZE
		#ifdef COUNT
			...
		#endif
	#endif

	//Ancak defined operatörü sayesinde bu işlem şöyle de yapılabilir:

	#if defined(SIZE) && defined(COUNT)
		....
	#endif

#include <stdio.h>

#define MSG(msg)		puts(#msg)

int main(void)
{
	MSG(this is a test);

	return 0;
}



#include <stdio.h>
	#include <wchar.h>

	#define WSTR(msg)		L##msg

	int main(void)
	{
		wprintf(L"%s\n", WSTR("test"));

		return 0;
	}
	#include <stdio.h>

	#define UNICODE

	#ifdef UNICODE
		#define STR(str)	L##str
	#else
		#define STR(str)		str
	#endif

	#ifdef UNICODE
		#define _tprintf		wprintf
	#else
		#define _tprintf	printf
	#endif

	int main(void)
	{
		_tprintf(STR("%s\n"), STR("this is a test\n"));

		return 0;
	}



#include <stdio.h>

	#define TEST(a, b)		a##b

	int main(void)
	{
		int TEST(x, y);

		xy = 10;
		printf("%d\n", xy);

		return 0;
	}


#include <stdio.h>

	#define PREFIXED_NAME(name)	sys_##name

	int main(void)
	{
		int PREFIXED_NAME(info);

		sys_info = 10;

		printf("%d\n", sys_info);

		return 0;
	}


//inline


/*inline
	static inline (ya da inline static)
	extern inline (ya da inline extern)

	inline anahtar sözcüğü C99'da "fonksiyon belirleyicisi (function specifier)" denilen bir gruba dahil edilmiştir. 

	inline fonksiyon çağrıldığında derleyici koda fonksiyon çağırma kodu (CALL komutu) eklemek yerine doğrudan kodun iç kısmını tıpkı bir makroymuş gibi 
	çağrılma yerine enjekte edebilmektedir. Örneğin:

	inline int square(int a)
	{
		return a * a;
	}

	Burada biz fonksiyonu şöyle çağırmış olalım:

	result = square(1 + 2);

	Derleyici square fonksiyonunu çağırmak yerine fonksiyonun içkodunu çağırma yerine enjekte edebilmektedir:

	result = 3 * 3;


    inline fonksiyonlar normal bir fonksiyon gibi yazılmaktadır. derleyici inline fonksiyonlar üzerinde normal fonksiyonlarda yaptığı bütün kontrolleri 
	yapmaktadır. Ancak bir inline fonksiyon çağrıldığında derleyici onu bir fonksiyon gibi çağırmak yerine bizzat onun iç kodunu çağırma yerine enjekte edebilmektedir. 
	Böylece C99 ve sonrasında artık fonksiyon çağırma işlemini elimine etmek için küçük fonksiyonların makro yerine inline fonksiyon biçiminde yazılması 
	tavsiye edilmektedir. Zaten inline fonksiyonlar makroların yukarıda sıraladığımız olumsuzluklarını gidermek amacıyla dile sokulmuştur. 


	Ancak C'de inline fonksiyonların bazı ayrıntıları vardır. Öncelikle "inline" belirleyicisi "bir emir değil rica" niteliğindedir. Yani biz bir 
	fonksiyonu inline yaptığımız zaman derleyici o fonksiyonu inline olarak açmayabilir. inline fonksiyonların derleyiciler tarafından inline olarak 
	açılmaları zorunlu değildir. Pek çok derleyicide "inline açım (inline expansion)" derleyicinin optimizasyon seçenekleriyle ilişkilendirilmiştir. 
	Yani derleyicilerin optimizasyon seçenekleri açılmazsa genellikle derleyiciler inline açım yapmamaktadır. Microsoft derleyicilerinin inline açım yapması 
	için en azından /O2 optimizasyon seçeneğinin kullanılması gcc ve clang derleyicilerinde de en azından -O2 seçeneğinin kullanılması gerekmektedir. Örneğin:
	
	cl /O2 sample.c					(Microsoft)
	gcc -O2 -o sample sample.c		(gcc)




    	Tabii programcı bu derleyicilerde optimizasyon seçeneklerini açmış olsa bile derleyici yine de inline açımı yapmayabilir. Derleyiciler genellikle inline 
	açım yapmaması durumunda herhangi bir uyarı vermezler. Programcı inline açımın yapılıp yapılmadığını ancak derleyicinin ürettiği kodu inceleyerek anlayabilmektedir. 

	Pekiyi derleyici neden fonksiyonu inline açmak istemeyebilmektedir? Bunun çeşitli nedenleri olabilir. Örneğin:

	- Özyinelemeli fonksiyonların inline açımları mümkün değildir. 
	- İçlerinde karmaşı deyimler olan fonksiyonalar (örneğin iç içe if deyimleri gibi) inline açılamayabilir. 
	- Çalışması uzun zaman alan kodların inline olarak açılması uygun değldir. Örneğin bir fonksiyonun içerisinde 1000000 kere dönen büyük 
	bir döngü olsun. Böyle bir fonksiyonun inline açılmasının bir faydası olmayacağı gibi kodu büyütebilmesi gibi zararları söz konusu olabilmektedir. 
	- Fonksiyonun adresi alınıp kod içerisinde kullanılıyorsa derleyici fonksiyonu inline olarak açmak istemeyebilir. 
	- Fonksiyon çok fazla satırdan oluşuyorsa inline açım kodu ciddi biçimde büyütebilecektir. Derleyiciler bu durumda inline açım yapmak istemeyebilirler.

	Tersten gidersek "basit, birkaç satırlık, uzun döngüler ve karmaşık if deyimleri gibi deyimleri içermeyen" fonksiyonlar inline olarak açılmaya aday fonksiyonlardır. 





	Pekiyi derleyici inline fonksiyonu inline olarak açmazsa ne yapacaktır? İşte bu durumda C99 ve sonrasında fonksiyonun nasıl inline tanımlandığna göre 
	derleyicinin davranışı farklılaşmaktadır. Yukarıda da belirttiğimiz gibi C'de inline fonksiyonlar üç biçimde olabilmektedir:

	inline
	static inline
	extern inline

	C++'ta böyle bir ayrım yoktur. Ancak C'de yukarıdaki üç inline tanımlama farklı anlamlara gelmektedir. 

	Eğer C'de inline fonksiyon static ya da extern anahtar sözcüğü olmadan yalnızca inline anahtar sözcüğü ile tanımlanmışsa bu durumda derleyici fonksiyonu
	inline açarsa sorun olmaz. Ancak derleyici fonksiyonu inline olarak açmazsa fonksiyonun tanımlamasını amaç kod içerisine yerleştirmez. Yani sanki fonksiyon 
	hiç tanımlanmamış gibi işlem yapar. Fakat fonksiyonu CALL makine komutuyla çağırır. İşte bu durumda eğer inline açım yapılamadıysa ve başka bir modülde de 
	aynı isimli bir fonksiyon yoksa muhtemelen build işlemi link aşamasında çağrılan fonksiyonu linker'ın bulamaması biçiminde error ile sonuçlanacaktır. 
	Örneğin:

	 sample.c  

	#include <stdio.h>

	inline int square(int a)
	{
		return a * a;
	}

	int main(void)
	{
		int result;

		result = square(3);

		printf("%d\n", result);

		return 0;
	}

	Burada square fonksiyonu static ya da extern belirleyicisi olmadan yalnızca inline belirleyicisi ile tanımlanmıştır. Eğer fonksiyon inline açılamazsa
	link aşamasında eror olulacaktır. Örneğin biz gcc derleyicisinde fonksiyonu optimizasyon seçeneklerini açmadan aşağıdaki gibi derlemek isteyelim:

	gcc -o sample sample.c

	Bu durumda link aşamasında şöyle bir hata alırız:

	/usr/bin/ld: /tmp/ccWaZ5zm.o: in function `main':
	sample.c:(.text+0x1d): undefined reference to `square'
	collect2: error: ld returned 1 exit status

	Ancak biz programo -O2 seçeneği ile derlersek derleyici inline açım yapacağı için her ne kadar square fonksiyonunu amaç koda yerleştirmeyecekse de 
	programın derlenip çalışmasında muhtemelen bir hata oluşmayacaktır:

	gcc -O2 -o sample sample.c

	yalnızca inline belirleyicisi ile fonksiyonu tanımladığımızda derleyici inline açımı yapsın ya da yapmasın fonksiyon kodunu amaç koda yazmamaktadır. 

	static inline fonksiyonlar eğer derleyici tarafından inline olarak açılmazlarsa static biçimde amaç dosyaya yerleştirilmektedir. Böylece derleyici CALL makine komutu 
	ile bu static fonksiyonu çağırmış olmaktadır. Yani bu durumda derleyici inline fonksiyonu açsa da açmasa da programın derlenip çalışmasında bir sorun oluşmayacaktır. Örneğin:

	static inline int square(int a)
	{
		return a a a;
	}

	Tabii static inline fonksiyonlarda derleyici inline açımı yaparsa aslında fonksiyonu hiç amaç dosyaya yazöayabilir. Ancak inline açımı yapamazsa static
	düzeyde fonksiyonu amaç dosyaya yazacaktır. Tabii fonksiyon static olduğu için fonksiyonun başka bir modülden çağrılması mümkün olmayacaktır. 

	static inline fonksiyonlar C'de en çok kullanılan inline fonksiyonalrdır. Ancak bunların da en önemli dezavantajı birden fazla modülde aynı static inline 
	fonksiyonun kullanılması durumunda eğer inline açım yapılamazsa bu fonksiyonların kodlarının ayrı ayrı bu modüllerde bulunması zorunluluğudur. 

	Normal bir fonksiyon zaten extern biçimdedir. Yani onun tanımlamasının önüne extern getirilip getirilmemesinin bir farkı yoktur. Örneğin:

	extern void foo(void)
	{
		...
	}

	Burada extern belirleyicisi gereksiz kullanılmıştır. Fonksiyonlar zaten default external linkage'a sahiptir. Ancak extern anahtar sözcüğü ile 
	inline anahtar sözcüğü bir arada kullanılırsa bu başka bir anlam ifade etmektedir. extern inline fonksiyonlar derleyici tarafından inline açılsalar da açılmasalar da 
	her zaman object dosyaya extern linkage biçiminde yazılırlar. Örneğin:

	extern inline int square(int a)
	{
		return a * a;
	}

	Burada fonksiyon extern ilnine olarak tanımlanmıştır. Derleyici çağrı sırasında bu fonksiyonu inline olarak açsa da açmasa da kod yine bu fonksiyonu 
	normal external linkage'a sahip bir fonksiyon olarak yazmaktadır. Bu durumun dezavatajı şudur: Biz extern inline fonksiyonu birden fazla modülde kullanırsak 
	ve bu fonksiyon inline açılmazsa fonksiyonun birden fazla extern tanımalası modüllerde bulunur. Bu da link aşamasında soruna yol açar. 
	Özetle üç inline fonksiyon arasındaki farlılıklar şunlardır:

	1) inline: Derleyici inline açım yaparsa sorun olmaz, ancak ayapamazsa CALL makine komutunu yerleştirir. Başka modülde bu fonksiyon yoksa 
	link aşamasında error oluşur. 

	2) static inline: Derleyici inline açım yapsa da yapmasa da sorun oluşmaz. Ancak fonksiyonu inline açamazsa static linkage'a sahip biçimde amaç dosyaya 
	yazar ve fonksiyonu CALL makine komutuyla çağırır.

	3) extern inline: Derleyici inline açım yaparsa sorun olmaz. Açamazsa CALL makine komutunu kullanır. Ancak her zaman derleyici fonksiyonu 
	amaç dosyaya extern linkage'a sahip olacak biçimde yazar. Dolayısıyla birden fazla modülde bu fonksiyon kullanılırsa error oluşur. 

	Burada programcı naısl bir yol izlemeidir? Eğer programcı inline fonksiyon derleyici tarafından inline açılamıyorsa bir sorun oluşmasın istiyorsa
	ya static inline tanımlamasını tercih etmelidir ya da inline tanımlamasını tercih edip ayrıca fonksiyonun static olmayan bir tanımlamasını başka bir modülde 
	bulundurmalıdır. C'de inline fonksiyonlar için en çok tercih edilen biçim "static inline" biçimidir. 

	inline fonksiyonlar her derleme işleminde derleyic tarafındna görülmek zorundadır. Dolayısıyla bu fonksiyonlar kütüphanelere yerleştirilemezler. 
	Birden fazla modülle çalışırken biz inline fonksiyonları ortak bir başlık dosyasına yerleştirebiliriz. Örneğin:

	/* project.h 

	#ifndef PROJECT_H_
	#define PROJECT_H_

	static inline foo()
	{
		...
	}

	#endif

	/* sample.c 

	#include <stdio.h>
	#include "project.h"
	...

	/* mample.c 

	#include <stdio.h>
	#include "project.h"
	...


*/


// restirict

/*   C99 ile birlikte standartlara "restrict" isimli bir tür niteleyicisi daha eklenmiştir. C++ C'yi temel aldığı halde bu restrict niteleyicisini bünyesine katmamıştır. 
    restrict niteleyicisi yalnızca göstericilerle "üst düzey (top level)" biçimde kullanılablir. Yani sıradan bir nesne restrict olamaz. Yalnızca göstericiler restrict olabilir. 
    Göstericilerin gösterdiği yer restrict olamaz yalnızca kendileri restrict olablir. Örneğin:

    restrict int a;				/* geçersiz 
    restrict int *pi;			/* geçersiz! 
    char * restrict pc;			/* geçerli 

    restrict anahtar sözcüğü "pointer aliasing" denilen bir optimizasyonu mümkün hale getirebilmek için düşünülmüştür. Bir göstericinin gösterdiği yere erişim en az
    iki makine komutu ile yapılmaktadır. Örneğin:

    a = *pi;

    Bunun muhtemel makine kaomutları şöyle olacaktır:

    mov reg1, pi
    mov reg2, [reg1]
    mov a, reg2

    Pekiyi bir kod içerisinde *p gibi bir kullanım birden fazla yerde varsa derleyici daha önceden elde ettiği *p değerini opimizasyon amaçlı saklayıp kullanabilir mi?
    Yanıt kullanabilir. Ancak derleyicinin o göstericinin gösterdiği yerdeki nesnenin değişmemiş olduğunu garanti etmesi gerekir. Örneğin:

    for (;;) {
        a = *pi;
        foo();
    }

    Derleyici burada foo fonksiyonun pi'nin gösterdiği yerdeki nesneyi değiştirmiş olabileceğini dikkate almak zorundadır. Dolayısıyla *pi'ye yeniden başvuru yapabilir. 
    Tabii derleyici foo'nun içini görürse ve *pi'nin yerel bir nesneyi gösterdiğini bilirse yani ""bazı koşullar altında"" foo'nun *pi'yi değiştirmeyeceğini anlayabilir. 
    Bu durumda optimizasyon yapabilir. Ancak bu karmaşık bir durumdur. Bazen bunu anlamak çok zor bazen de mümkün olmayabilir. İşte restrict anahtar sözcüğü 
    bu tarz optimizasyonları derleyici yapabilsin diye uydurulmuştur. restrict anahtar sözcüğü derleyiciye şunu demektedir: "Derleyici bu göstericinin gösteridiği 
	yerdeki nesneye ben yalnızca bu gösterici ile erişiyorum. Başka bir fonksiyon ya da başka bir yolla ona erişmeyeceğime söz veriyorum". Böylece restrict 
	göstericilerde derleyici o göstericilerin gösterdiği yerdeki nesnelerin erişiminde optimizasyonlar yapabilmektedir. Pekiyi biz bir göstericiyi restrict yaptığımız halde 
	o göstericinin gösterdiği yere başka bir nesne ya da gösterici yoluyla erişirsek ne olur? Bu durum C'de tanımsız davranışa yol açmaktadır. Çünkü burada 
	restrict ile verilen söz programcı tarafından tutulmamıştır. 

    restrict göstericiler C99'da fonksiyon prototiplerinde de sıkça karşımıza çıkmaktadır. Örneğin:

    char *strcpy(char * restrict dest, const char * restrict source);

    Burada restrict gösterici gördüğümüzde ne anlamalıyız? İşte mademki restrict göstricilerin gösterdiği yere yalnızca o gösterciler yoluyla erişilir o halde
    burada fonksiyona verdiğimiz iki adres çakışık olmamalıdır. Eğer bu iki adres çakışık olursa "tanımsız davranış (undefined behavior)" oluşur. Örneğin:

    void *memcpy(void * restrict s1, const void * restrict s2, size_t n);

    Burada da blokların çakışık olmaması gerekir. Ancak örneğin:

    void *memmove(void *s1, const void *s2, size_t n);

    Burada restrict gösterici kullanılmadığına göre bloklar çakışık olabilir. Şüphesiz göstericinin gösterdiği yerde bir güncelleme yapmayan fonksiyonlarının 
	prototiplerinde restrict gösterici bulundurmanın bir anlamı yoktur. Örneğin:

    int strcmp(const char *s1, const char *s2);

	Bazı işlemcilerde blok kopyalaması yapan makine komutları bulunmaktadır. Örneğin böyle bir işlemci söz konusu olsun. Biz de aşağıdaki gibi 
	bir fonksiyonu yazmış olalım:

	void reverse_copy(void *dest, void *source, size_t n)
	{
		...
	}
	
	Bu fonksiyon ikinci parametresiyle verilen diziyi birinci parametresiyle verilen diziye tersten kopyalacak olsun. Bir işlemci bunu tek bir makine komutuyla 
	önce source'dan n kadar byte kendi içine çekip sonra bunu dest'e kopyalayabilir. Ancak burada bloklar çalıkışıksa fonksiyonun iç kodunun yapma çalıştığı 
	şey bu makine komutuyla yapılamayacaktır. Bu durumda biz derleyiciye bir güvence verebiliriz:

	void reverse_copy(void * restrict dest, void * restrict source, size_t n)
	{
		...
	}
	
	Şimdi artık biz derleyiciye şunu demekteyiz: "Derleyici ben hiçbir zaman source ve dest adreslerinin gösterdiği yerlere başka bitr yolla erişmeyeceğim.
	Dolayısıyla benim adresini geçtiğim diziler çakışık olmayacaktır. Sen bunların çakışık olmayacağı garantisiyle istediğin optimizasyonu yap".

	C++'ta restrict göstericiler olmadığı için eğer kodun C++ uyumu olması isteniyorsa restrict göstericiler kullanılmamalıdır. 
*/








