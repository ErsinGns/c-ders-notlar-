#include <stdio.h>


int z = 3;
int* func(void)
{
    int x;
    static int y = 22;

    // return &x; hata verir çünki döndüğünde x in ömrü biter
    return &z; // değeri verir çünki ölmez
    return &y; // değeri verir çünki ölmez
}

int main(int argc, char const *argv[])
{

    int* retu = func();
    printf("deger: %d adres: %d \n", *retu, retu);
    ++*func(); // adres gösterdiği için retu değerini de değiştirir adresler çünki
    printf("deger: %d adres: %d bir fazlasi: %d    %d\n", *retu, retu, ++*func(), *func());
    
    printf("%d %d    %p   %p", *func(), func(), (void*)func(), func());
    // 1 - static ömürlü nesne adresi
    // 	a - global nesne adresi
    // 	b - static yerel nesne adresi
    // 	c - string literalleri (string literaller static ömürlü olan char dizilerdir.)

    // 2 - Client koddan aldığı adresi tekrar geri döndürmesi.Mesela dizi adresi isteyen bir
    // 	pointer fakat fonksiyonun geri dönüş değeri aynı dizinin adresi. o adres zaten hayatta
    // 	fonksiyon çağrısı bittiğinde halen dizi hayatta. Örneği yaptık daha önce yukarıda.

    // 3 - Dinamik ömürlü nesne adresi döndüren fonksiyonlar. Fabrika fonksiyonları.

    // int * -----> const int * a dönüşümü doğru kabul ediyor.Problem yok.
    // const int * -----> int * a dönüşüm C++ sentaks hatası, C de uyarı.


    int x = 10;
    // const int * p = &x;

    // /// code...

    // // p ile x e okuma amaçlı eriştik

    // // int * ptr = p; // c++ sentaks hatası, C de uyarı mesajı.
    //                 // bu tip durumlarda otomatik dönüşüme bırakmadan cast etmemiz
    //                 // daha uygun olur

    // int * ptr = (int *)p;  // burası şimdi oldu
    // *ptr = 12; // UB yok. x const değil ptr const değil.
    

    // 1-	Aşağıdaki kodda hata yok.Legal
	// 	int * ptr = NULL;
	// 	if(ptr == NULL)
	// 		printf("evet dogru\n");  

	// 2-	Eğer iki pointer da NULL pointer ise ikisi birbirine eşittir.
	// 	Kod legal
	// 	int *a = NULL;
	// 	int *b = NULL;
	// 	if(a == b)
	// 		printf("Esittir\n");

	// 3-	Logical yorumlamalarda kullanılır
	// 	Eğer if, ternary op, for, while, && || ... 
	// 	gibi logical yorumlamalara tabi tutulan yerler varsa
	// 	burada NULL pointer 0 dır yani yanlıştır.

	// 	if(ptr != NULL)  yazmak ile if(ptr) yazmak aynı anlamda

	// 	if(ptr == NULL)	 yazmak ile if(!ptr) yazmakta aynı anlamdadır.


    // NULL == 0
    





    return 0;
}
