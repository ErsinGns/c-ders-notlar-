#include <stdio.h>

int main(int argc, char const *argv[])
{
    // p[i] == *(p + i)

    // void func(int p[10]) içine değer yazılmasının bir anlamı yok ama sentak hatası değil 
    //func(int p[]) == func(int* p)  gelen değrein pointer olduğunu belirtirler 
    int a[5] = { 0 };
    int* ptr1 = a + 1;
    int* ptr2 = &a[1];
    printf("ptr1 = %p - ptr2 = %p", ptr1, ptr2); // aynı adresi gösterirler
    
    int x = 3; //! hepsi hatalı 
    // &x++;
    // &++x;
    // ++&x;

    int* p = &x; // geçlerli
    *++p;
    *++p = 2;
    *p++;

    // const neyden önce geliyorsa o değiştirilmez

    const int k = 4;
    int* ptr = (int*) &k; //legal ama yanlış
    *ptr = 3; // ub
    





    return 0;
}
