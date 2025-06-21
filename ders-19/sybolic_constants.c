// Predefined symbolic constants
// __LINE__	kodun hangi satırda oluduğunu verir
// __FILE__	file adını
// __DATE__	tarih
// __TIME__	saati verir.
// __func__   c99 da geldi. Bu tip daha macro var. fonksiyonun adını verir.
// __STDC__	eğer derleyicinin eklentileri kapalıysa bu macro tanımlı kabul ediliyor.



//  file scope : global isim alanında tanımlanan isimlerin kapsamı.
// 	block scope : block içinde tanımlanmış ismin o blockta kullanılmasıi.
// 	func. prorotype : func bildiriminde kullanılan değişken isimlerinin alanı. Sadece parantez içindeki alandaki isim o daisim yazılırsa yani x. void func(int x).
// 	function scope : bir label tanımlanır ve yukarıdan da aşağısından da bu label kullanılabilir.labellar ayrı scope olduğu için
// 	fonksiyon içindeki diğer isimlerle çakışmaz.

//          #line	-> bu kod üreten komutlarda kullanılır.__LINE__ macrosunun değerini değiştiriyor.
// 			#line 1000 dersem printf("%d",__LINE__) bu değeri 1000 verir.
// 			#line 1000 "umut.c"   printf("%s %d",__FILE__,__LINE__)  -> 1000 ve umut yazar. çok özel kullanım senaryosu var.


// #error -> programın derlenmesini önişlemci aşamasında durduruyor.


	//      #pragma once -> multip inc. guard sağlıyor.
	// 		#pragma pack(1) -> alignment sağlıyor.
	// 		#pragma warning (disable: 4706)   4706 nolu uyarı mesajını verme demek bu.