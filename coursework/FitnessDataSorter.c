#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

void end(){
    printf("Error: Invalid file\n");
    exit(1);
}

void checkDateTime(char *line){
    if (line[0] == ',' || line[11] == ','){
        end();
    }
}

void checkSteps(FitnessData *data, int rows){
    for (int i=0; i < rows; i++){
        if (data[i].steps <= 0){
            end();
        }
    }
}

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
        end();
    }
    //declarations
    char buffer [10000];
    int rows = 0;
    //loop through the file reading each line and tokenising
    //it before adding it to data
    while (fgets(buffer, 10000, file)!= NULL){
        checkDateTime(buffer);
        FitnessData record = {};
        int tempSteps [10];
        tokeniseRecord(buffer, ',', record.date, record.time, tempSteps);
        record.steps = tempSteps[0];
        data[rows] = record;
        rows++;
    }
    checkSteps(data, rows);
    for(int i=1; i <rows; i++){
        int current = data[i].time;
        int j=i-1;
        while(j>=0 && data[j].time > current){
            data[j+1].time = data[j].time;
            j=j-1;
        }
        data[j+1].time = current;
    }
    for(int i=0; i< rows; i++){
        printf("%s/%s/%d\n", data[rows].date, data[rows].time, data[rows].steps);
    }
    
    
}