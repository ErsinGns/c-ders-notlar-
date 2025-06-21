#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int x = 3; // değişken bir daha değişmiyecekse değişmemesi gerekiyorsa constla tanımla
    const int* const ptr; // hiç bir şey değişmiyor
    // char k = "selam"; hata verir 1 karakter alır
    // printf("%s", k);
    char *p = "selam";
    printf("%s - %s -- %d - %d", p, p + 1, p, p + 1); // ilginç bak sonra

    // bir adresle bir tamsayı toplanabilir.
	// bir tamsayı ile bir adres toplanabilir.
	// bir adresten bir tamsayı çıkartılabilir.
	// bir tamsayıdan bir adres ÇIKARTILAMAZ !!!
	// bir adresten başka bir adres çıkartılabilir. değeri işaretli tamsayıdır.
	// bir adres ile başka bir adres TOPLANAMAZ !!!
    // sonuc şlaretli bir tam sayıdır yapılabilen işlmelerin  ptrdiff_t

    // &a[4] = a + 4 = &4[a]  aynı şey
    //prt[-22] sentaks hatası değil ub
    // a[i] = *(a + i)

    // print_array de pointer olarak gönderilen nesne kesinlikle const keyword ü ile nitelenmeli.
    // Yapılmazsa büyük hata olur. Mülakatlarda çok dikkat ediyorlar.

	//fonc(hedef, kaynak) standart bunu kullanır fonksyona gönderirken

    //void func(int *p); // aynı anlamda ama bu daha fazla kullanılıyor
    //void func(int p[]);

    



    return 0;
}
