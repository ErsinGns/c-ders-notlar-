 #include <stdio.h>


int foo(int x){
    return x *x;
}
int bar(int x){
    return 2 * x;
}

void fi(void){printf("merhaba");}


void fo(void(*fp)(void))
{
    fp();
    printf(" dunya");
}

 int main(int argc, char const *argv[])
 {
    int x, y, a;
    // int donen = scanf("%d%d%d", &x, &y, &a);
    // printf("donene= %d", donen);

    // printf("donene= %d\n", scanf("%d%d%d", &x, &y, &a));
    // printf("a= %d\n", a);

    int (*pfoo)(int) = &foo;

    printf("%d\n", pfoo(4));
    
    pfoo = bar;

    printf("%d\n", pfoo(4));

    fo(fi);

    //foo(fi()); // değeri atar
    //foo(fi); adrei atar

    // memset -> bellek bloğuna tamsayı yazar
	// memcpy -> belle bloğuna kopyalama yapar
	// memmove -> overlapped bloklar arasında kopyalama yapar
	// memchr -> belirli bir bellek bloğunda byte arar
	// memcmp -> belirli bir bellek bloğunda kıyaslama yapar.
    

    // int x;
	// my_memset(&x, 0, sizeof x);
	// printf("x = %d\n",x); // Her bir belle bloğuna 0000 0000 0000 0000 0000 0000 0000 0000 yazar

	// my_memset(&x, 255, sizeof x); // 1111 1111 1111 1111 1111 1111 1111 1111 -> -1 dir.
	// printf("x = %d\n",x);

	// my_memset(&x, 1, sizeof x); // 0000 0001 0000 0001 0000 0001 0000 0001 yazar.
	// printf("x = %d", x);
	
	// Güvenlik Amaçlı genelde kullanılan bellek bloğu sıfırlanıyor.
	// Daha sonradan bu bloktaki verilere erişilemesin diye.


    // void func(func)
	// {
	// 	printf("cagrildi\n");
	// }

	// int main()
	// {
	// 	func(); // (&func)(); şeklinde de çağrılır.function to ptr conversion olduğu için gerek yok.
	// }

	// Function to Pointer Conversion
	// Bir function ismi bir ifade içerisinde kullanılınca 
	// derleyici function ismini implicit olarak ilgili functionun adresine dönüştürür.
	// func ----> &func
	// func() ----> (&func)()  aynı ifade bunlar.





    return 0;
 }

