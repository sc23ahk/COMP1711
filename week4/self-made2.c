#include <stdio.h>

int main(){
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "a");
    if (file == NULL){
        perror("");
        return 1;
    }
    int max_numbers = 10, i;
    for (i=1; i<=max_numbers;i++){
        fprintf(file, "%d\n", i*i);
    }
   
   
    fclose(file);
    return 0;
}