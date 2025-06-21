#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char str[100];

    printf("Bir metin giriniz: ");
    scanf("%[^\n]s", str);

    int length = 0;
    for(int i = 0; str[i]; i++){
        if(isalpha(str[i]))
            str[length++] = str[i];
    }    
    str[length] = '\0';

    int palindron = 1;
    for(int i = 0;i < length / 2; i++){
        if(toupper(str[i]) != toupper(str[length - 1 - i])){
            palindron = 0;
            break;
        }
    }

    if(palindron)
        printf("palindrom.");
    else
        printf("palindrom degil.");
    
    return 0;
}