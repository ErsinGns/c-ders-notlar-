

int8_t
uint8_t
int16_t
uint16_t
int32_t
uint32_t
int64_t
uint64_t




#include <stdio.h>
#include <stdint.h>

int main(void)
{
    intmax_t a = 12345678;// en büyük işaretli int türü demek
    uintmax_t; // işaretsizi

    printf("%jd\n", a);

    return 0;
}	



/*C'de bildirimde kullanılabilecek dört yer belirleyicisi anahtar sözcük vardır:

	auto
	register
	extern
	static

	İki de tür niteliyici anahtar sözcük vardır:

	const
	volatile

	Bir bildirimde iki yer belirleyicisi bir arada kullanılmaz. Ama iki tür niteleyicisi bir arada kullanılabilir. Örneğin:

	static extern int a;				 geçersiz! 
	static const volatile b = 10;		 geçerli 
	extern auto int c;					geçersiz! 
    
*/







