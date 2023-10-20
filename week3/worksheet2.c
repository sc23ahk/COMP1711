#include <stdio.h>
#include <stdbool.h>

float circleArea (float r){
    return r*r*3.147;
}

float volumeSphere(float r){
    return (4*r*r*r*3.147)/3;
}


int str_len(char str[]){
    int count = 0;
    while(str[count] != "\0"){
        count = count + 1;
    }
    return count-1;
}

bool isPrime(int num){
    for(int i=2; i < num; i++){
        if (num%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    float r;
    scanf("%f", &r);
    float area = circleArea(r);
    float volume = volumeSphere(r);
    printf("area = %f\n", area);
    printf("volume = %f\n", volume);
    
    char str [10] = "string";
    int length = str_len(str);
    printf("%d", length);
    
    int num;
    scanf("%d", &num);
    bool is_prime = isPrime(num);
    if (is_prime){
        printf("true\n");
    }else{
        printf("false\n");
    }



    return 0;
}