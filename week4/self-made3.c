#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[]){
    FILE *file = fopen(filename, mode);
    if (file==NULL){
        perror("File I/O");
        exit(1);
    }
    return file;
}

int main(){
    char filename[] = "data.txt";
    FILE *file = open_file(filename, "r");
    int buffer_size = 100;
    char buffer[buffer_size];
    int count =0;
    while(fgets(buffer, buffer_size, file)){
        printf("%s", buffer);
        count++;
    }
   
    printf("The loop was executed %d times.\n", count);
   
    fclose(file);
    return 0;
}