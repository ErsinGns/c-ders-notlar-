#include <stdio.h>

#define SIZE  1000

int main(int argc, char const *argv[])
{
    char str[SIZE];
    printf("iki kelime girin: ");
    scanf("%[^\n]", str);
    printf("[%s]\n", str);
    
    int kelime_1_uzunluk = 0;
    int kelime_2_uzunluk = 0;
    int i;
    for(i = 0; str[i]; i++){
        if(str[i] == ' '){
            kelime_1_uzunluk = i;

        }
    }
    kelime_2_uzunluk = i - kelime_1_uzunluk - 1;
    printf("%d %d\n", kelime_1_uzunluk, kelime_2_uzunluk);

    for(int j = kelime_1_uzunluk; str[j + 1]; j++){
        int harf = str[j];
        str[j] = str[j + 1];
        str[j + 1] = harf;
    }
    printf("[%s]\n", str);

    for(int i = kelime_1_uzunluk; i > 0; i--){
        int k = i;
        for(int j = kelime_2_uzunluk + 1; j > 0; j--){
            int harf = str[k - 1];
            str[k - 1] = str[k];
            str[k] = harf;
            k++;
        }

    }
    
   
    printf("[%s]\n", str);
    

    return 0;
}