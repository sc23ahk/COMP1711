#include <stdio.h>

int main(){
    char date[20];
    int i;
    scanf("%s", date);
    char month[3];
    for (i=0; i< 3; i++){
        month[i] = date[i];
    }
    printf("%s\n", month);
}