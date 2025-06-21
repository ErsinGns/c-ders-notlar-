#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char const *argv[])
{
    char str[SIZE];
    printf("iki kelime giriniz: ");
    scanf("%[^\n]", str);
    
    int word_sum_length= strlen(str);
    int space = 0;
    int i;
    for(i = 0; i < word_sum_length - 1; i++){
        if(str[i] == ' ' && !space)
            space = i;
        if(space){
            char letter = str[i];
            str[i] = str[i + 1];
            str[i + 1] = letter;
         }
    }

    int word_1_length = space;
    int word_2_length = i - space + 1;

    for(int i = word_1_length; i > 0; i--){
        int position = i;
        for(int j = word_2_length; j > 0; j--){
            char letter = str[position - 1];
            str[position - 1] = str[position];
            str[position] = letter;
            position++;
        }
    }
    printf("[%s]", str);

    return 0;
}