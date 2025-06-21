//? Restrict
// --------
// Benim gösterdiğim nesneyi bir başkası gösteremesin demek.C99 da eklendi.
// C++ ta restrict yok.

// kullanımı asteriskten sonra gelir. öncesinde olması sentaks hatası
int * restrict ptr;

// ÖR:
void func(int* px, int* py, int* restrict pz)
{
    	*px += *pz;
	
	// *pz ye eriş ve onu registerda tut
	// *pz ye tekrar erişmek yerine onu registerdaki değeri ile kullan.
	//restrict olmasaydı px, pz yi gösteriyor olabilirdi ve *px değişince *pz de değişirdi.
	// bu değeride get etmek için tekrar memory ye erişmek gerekirdi. restrict ile bunu
	// ortadan kaldırıyoruz. sadece pz bu değeri tutabilir ve erişebilir.
	//bu şekilde compiler optimizasyon yapıyor.

	*py += *pz;
}

// burada px ve py nin pz nin gösterdiği nesneyi gösterme ihtimali yok.bunu sağlıyor.
// bu derleyicinin daha iyi optimizasyon yapmasını sağlıyor.

// eğer 
// px = pz; yapılırsa bu bir UNDEFINED BAHAVIOR


int main()
{
	int x = 10;
	int y = 20;
	int z = 30;

	func(&x, &y, &z); //burası ok

	// ama aşağıdaki gibi çağrılsaydı UB olurdu
	func(&x, &y, &x);
	// pz yi aynı zamanda px te gösteriyor

}


// structures - yapılar				|
// unions - birlikler					|
// enumerations - numaralandırmalar	|



	// if(px == py) // BU KARŞILAŞTIRMA GEÇERSİZ !!!
				// tüm elemanları tek tek kıyaslayabilirdik
			// if(px.mx == py.mx && px.my == py.my && px.mz == py.mz) GEÇERLİ




	// struct Data{
	// 	char x;
	// 	int a;
	// 	char y;
	// };

	// burada toplayınca aslında 6 byte ediyor.
	// ama sizeof ile bakınca 12 değerini veriyor.

	// x ten sonra 3 byte var diyelim. int 4 byte. 3 byte ı bir blokta 1 byte ı diğer blokta 
	// olmasını engellemek için o 3 byte ı kullanmayacak.buna hizalama deniyor.İleride görülecek.
	// verim düşüyor çünkü 3 byte al 1 byte ı al birleştir değere ulaş.maliyetli bir işlem.

// ilk değer verilebilir.

	struct Data {
		int a;
		double b;
	}data = {4,5.4};


// birden fazla değişken tanımlanabilir.
	struct Data {
		int a;
		double b;
	}data1,data2,data3;


// ÇOK ÖNEMLİ !!!!!!!!!!
// 	Mülakat sorusu. 
// 	tag opsiyonel.başta, maddelerde var bu.

// 	struct {
// 		int a,b,c;
// 	}x;     
	  
// 	Bu geçerli bir tanımlama. bir yapı türü oluşturulmuş ve bir nesne tanımlanmış.
// 	buna ilk değerde verilebilirdi
	
	struct {
		int a,b,c;
	}x = {1,2,3};

	// Global bir değişken fakat tür bilgisi dışarı sızdırılmamış demek.
	// Yani yazılım mühendisi kod içinde, bu türden başka bir nesne daha tanımlayamaz.
	// Yani bir tane daha tanımlayamam kod içinde
	
	// Amacı
	// başka koda bu türü kullanma hakkı vermemek için kullanılabilir.


	struct {
		int a, b, c;
	}x,y,z;

	int main()
	{
		x.a = 10, x.b = 20, x.c = 30;
		y = x;
		z = y;
	}

	// Artık bu türden bir t nesnesi daha tanımlayamayız. çünkü türün ismi yok.





