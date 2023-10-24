#include <stdio.h>

int main(){
    char filename[] = "/data.txt";
    FILE *file = fopen(filename, "a");
    if (file == NULL){
        perror("");
        return 1;
    }
    fprintf(file, "Hello World!\n");
   
   
    fclose(file);
    return 0;
}