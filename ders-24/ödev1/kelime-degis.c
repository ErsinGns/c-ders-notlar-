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

    if(kelime_1_uzunluk == kelime_2_uzunluk){
        for(int j = 0; str[kelime_2_uzunluk + 1]; j++){
            int harf = str[j];
            str[j] = str[kelime_2_uzunluk + 1];
            str[kelime_2_uzunluk + 1] = harf;
            kelime_2_uzunluk++;
        }
    }
    else if(kelime_1_uzunluk > kelime_2_uzunluk){
        int harf;
        for(int j = 0; str[kelime_2_uzunluk + 2]; j++){
            if(str[kelime_2_uzunluk + 2] == '\0'){
                str[j] = ' ';
                str[kelime_2_uzunluk + 2] = '\0';
            }
            else{
                harf = str[j];
                str[j] = str[kelime_2_uzunluk + 2];
                str[kelime_2_uzunluk] = harf;
            }            
            kelime_2_uzunluk++;
        }
    }

    printf("[%s]\n", str);
    return 0;
}