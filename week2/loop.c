#include <stdio.h>
int main(){
    int a=5, i=20, temp;
    
    //for loop
    for(i=5; i>0; i--){
        printf("%d\n", i);
    }
    
    //while loop
    while (i<5){
        printf("%d\n", i);
        i=i+1;
    }
    
    //print first 10 odd numbers
    for(i=1; i<20;i+=2){
        printf("%d\n",i);
    }

    //print even numbers in reverse
    while(i>=0){
        printf("%d\n",i);
        i=i-2;
    }
    
    //print the squares of the first 10 natural numbers
    for(i=1;i<11;i++){
        temp = i*i;
        printf("%d\n",temp);
    }
    return 0;
}