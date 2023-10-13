#include <stdio.h>

int main(){
    int a [5], count, i, new[5];
    //populate an array
    for (count=1; count<6; count++){
        a[count] = count;
    }
    /*
    printf("The first and second elements are %d and %d\n", a[0], a[1]);
    printf("Or, via the pointers, %d and %d\n", *a, *(a+1));
    
    char str [6] = "Hello";
    for (i=length, i>=0; i--;){
        printf("%c\n", str[i]);
    }

    */
    //task 1
    int sum = 0;
    for (i=0; i<6; i++){
        sum= sum + a[i];
    }
    printf("%d\n", sum);

    //task 2
    for(i=length; i>=0; i--){
        new[length-i] = a[i];
    }
    for(i=0; i<length; i++){
        printf("%d, ", a[i]);
    }

    //task 3
    int big = -1;
    for (i=0; i< 6; i++){
        if (a[i] > big){
            big = a[i];
        }
    }
    printf("%d\n", big);

    //task 4
    for (i=0; i<length; i++){

    }



    return 0;
}