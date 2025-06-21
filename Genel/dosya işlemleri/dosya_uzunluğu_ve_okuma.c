#include <stdio.h>
#include <stdlib.h>

char* read_from_file(char* filename){
    FILE* file = fopen(filename, "r");
    fseek(file, 0, SEEK_END); // dosyanın sonuna gide
    int length = ftell(file); // uzunluğu alır dosyanın neresinde olduğunu döner
    fseek(file, 0, SEEK_SET);
    char* contents = malloc(sizeof(char) * length + 1);
    fread(contents, 1, length, file);
    contents[length] = '\0';
    return contents;
}





int main(int argc, char const *argv[])
{
    char* contents = read_from_file("text.txt");
    
    printf("(%s)", contents);

    return 0;
}
