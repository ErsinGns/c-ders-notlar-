#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[] = "Ersin";
    char name2[] = "Gunes";

    printf("%s %s\n", name, name2);
    puts(name);// yazarken new line verir
    puts(name2);
    printf("bay\n");
    // puts(name, name2); //! , değer almaz 

    char name3[] = "Ersin";

    if(name == name3) // yanlışa girer çünki adresleri karşılaştırır değerler için strcmp kullan
        printf("esit");
    else 
        printf("esit degil");

    // ekrandan alma

    char str[100];
    printf("\nismi giriniz: ");
    gets(str);
    printf("isim: %s", str);

    printf("\nismi giriniz: ");
    int ch;
    int idx = 0;
    while ((ch = getchar()) != '\n')
    {
        str[idx++] = (char)ch;
    }
    str[idx] = '\0';
    printf("isim: %s", str);
    
    printf("\nismi giriniz: ");
    scanf("%s", str); // scanf scanset bak 
    printf("isim: %s", str);

    return 0;
}
