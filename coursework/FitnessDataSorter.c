#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    //declare the whole data structure
    FitnessData data[10000];
    //collect filename
    char filename [100];
    printf("Enter filename: ");
    scanf("%s", filename);
    //open the file
    FILE *file = fopen(filename, "r");
    //check that file opened correctly
    if (file == NULL)
    {
        printf("Error: invalid file\n");
        exit(1);
    }
    //declarations
    char buffer [10000];
    int rows = 0;
    //loop through the file reading each line and tokenising
    //it before adding it to data
    while (fgets(buffer, 10000, file)!= NULL){
        FitnessData record = {};
        tokeniseRecord(buffer, ',', record.date, record.time, record.steps);
        data[rows] = record;
        rows++;
    }
    
}