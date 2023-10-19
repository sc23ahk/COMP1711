#include <stdio.h>

int main(){
    float temperature;
    float threshold = 15;
    printf("What's the temperature today? ");
    scanf("%f", &temperature);
    if (temperature > threshold)
        printf("No need for a jacket.\n");
    else if (temperature < threshold && temperature >= 10)
        printf("Good weather for a jacket.\n");
    else
        printf("Good weather for a coat.\n");


    return 0;
}