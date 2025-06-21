#include <stdio.h>

struct Data; // legal
typedef struct Data Data; // legal

Data foo(Data*);

extern int x; // başka dosyada tanımlanmış demek

extern struct nec gnec;

struct nec;
struct nec* boo(void);

struct org
{
    int x, y;
    struct org* porg; // legal date strctur da kullanılıyor önemli
};






int main(int argc, char const *argv[])
{
    //! Data d1; // hatalı

    struct nec * ptr = boo();// legal
    //! sizeof(*ptr); // hatalı
    // void türü incomplik tipe türünde 
    

    return 0;
}
