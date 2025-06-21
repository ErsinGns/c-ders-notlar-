#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double dval = 0;
    printf("dobule = %.60f\n", .1);
    printf("long dobule = %.6lf\n", .1l); // unsigned long double yok  // bu kod negatif olarak sapıtır

    for(int i = 0; i < 10; i++){
        dval += .1;
    }
    printf("%.60lf\n", dval);
    printf("%f\n", dval);

    dval = NAN; //! kendisine bile eşit değil (geşerli bir değer değil)

    if(dval == dval)
        printf("esit");
    else
        printf("esit degil");

    return 0;
}






