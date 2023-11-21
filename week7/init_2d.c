#include <stdio.h>

void printArray(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

void changeArray(int a, int b, int array[][3], int change){
    array[a][b] = change;
}

int main() {
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  printf("Values in array1 by row are:\n");
  printArray(array1);

  int array2[2][3] = {1, 2, 3, 4, 5};
  printf("Values in array2 by row are:\n");
  printArray(array2);


  int array3[2][3] = {{1, 2}, {4}};
  printf("Values in array3 by row are:\n");
  printArray(array3);

  changeArray(1,2,array3,6);
  printf("After change\n");
  printArray(array3);
  
  return 0;
}