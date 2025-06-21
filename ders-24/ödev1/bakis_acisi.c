// Ana, Naci Dede ne dedi Canan'a?
// Para hazır, ama Rıza harap!
// At sahibi gibi hasta!
// tras neden şart?
// en iyi mese bese mi yine?
// kalas yok, kutuk koy, salak!
// A man, a plan, a canal: Panama.
// Madam, I'm Adam!

#include <stdio.h>
#include <ctype.h>


int main(int argc, char const *argv[])
{
    char metin[100];
    printf("bir metin giriniz: ");
    scanf("%[^\n]s", metin);

    
    for(int i = 0; metin[i]; i++){
        for(int j = 0; metin[j]; j++){
            if(!(toupper(metin[i]) > 64 && toupper(metin[i]) < 91)){
                metin[i] = ' ';
            }
        }
    }
    printf("%s\n", metin);
    for(int i = 0; metin[i]; i++){
        for(int j = 0; metin[j]; j++){
            if(j > i){
                if(metin[i] == ' '){
                    if(!(metin[j] == ' ')){
                        metin[i] = metin[j];
                        metin[j] = ' ';
                    }
                }
            }
        }
    }

    printf("%s\n", metin);

    int i = 0;
    for(i; metin[i]; i++){
        if(metin[i] == ' '){
            metin[i] = '\n';
            break;
        }
    }
    i--;
    for(int j = 0; metin[2 * j]; j++){
        if(toupper(metin[j]) == toupper(metin[i])){
            i--;
        }
        else{
            printf("esit degil\n");
            return 1;
        }
    }
    printf("esit");

    return 0;
}

