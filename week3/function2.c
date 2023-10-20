#include <stdio.h>

float sum (float a, float b);

int main(){
    int y = 2;
    float z = sum (5, y); // calling our new function
    printf("The sum of 5 and %d is %f\n", y, z);
}


float sum (int a, int b){
    float answer;
    answer = a + b;
    return answer;
    //return a + b;
}