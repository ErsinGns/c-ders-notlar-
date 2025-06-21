
typedef int A[4];

typedef void F(void);

F foo;// aynı anlamda
void foo(void);

int main(int argc, char const *argv[])
{
    int a[4];
    A a; // aynı anlamda





    return 0;
}


typedef struct {
    int a;
    double b;
} SAMPLE;

//iksinin farkı üsteki türün ismi altaki değişkenin
struct {
    int a;
    double b;
} SAMPLE;