#include <stdio.h>

int main(){
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror("");
        return 1;
    }
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