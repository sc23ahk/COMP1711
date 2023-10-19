#include <stdio.h>

int main(){
    /*
    //task 1
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number >0){
        printf("Number is positive\n");
    }else if (number == 0){
        printf("Number is equal to zero\n");
    }else{
        printf("Number is negative\n");
    }

    //task 2
    int div;
    printf("Enter a number: ");
    scanf("%d", &div);
    if (div%4 ==0 && div%5==0){
        printf("%d is divisable by both 4 and 5\n", div);
    }else{
        printf("%d is not divisable by both 4 and 5\n", div);
    }

    //task 3
    int mark;
    printf("Enter grade: ");
    scanf("%d", &mark);
    if (mark <50 && mark >=0){
        printf("%d is a fail\n", mark);
    } else if (mark >=50 && mark <70){
        printf("%d is a pass\n", mark);
    } else if (mark >= 70 && mark <=100){
        printf("%d is a distinction \n", mark);
    }else {
        printf("Invalid answer\n");
    }

    //task 4
    int temp;
    printf("Enter temp: ");
    scanf("%d", &temp);
    if (temp >= -10 && temp <=40){
        printf("Valid\n");
    }else{
        printf("Invalid\n");
    }
    
    //task 5
    int choice;
    printf("Choose : ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Option 1\n");
            break;
        case 2:
            printf("Option 2\n");
            break;
        case 3:
            printf("Option 3\n");
            break;
        case 4:
            printf("Option 4\n");
            break;
        case 5:
            printf("Option 5\n");
            break;
        default:
            printf("Error not an option\n");
    }
    */

    //task 6
    int num;
    do{
        printf("Input a number: ");
        scanf("%d", &num);
        if (num >= 0 && num <= 100){
            printf("%d is a valid number\n", num);
        }else if (num != -1){
            printf("%d is not a valid number\n", num);
        }
    } while (num != -1);
    printf("Exited loop\n");


    return 0;
}