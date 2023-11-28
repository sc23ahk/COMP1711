#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;


//function to end the program
void end(int i){
    printf("Error: Invalid file\n");
    exit(i);
}

//function that checks that a line has the date and time
void checkDateTime(char *line){
    if (line[0] == ',' || line[11] == ','){
        end(1);
    }
}

//function that checks that the number of steps are positive
//and that there is a value for steps
void checkSteps(FitnessData *data, int rows){
    for (int i=0; i < rows; i++){
        if (data[i].steps <= 0){
            end(1);
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
        end(1);
    }
    //declarations
    char buffer [10000];
    int rows = 0;
    //loop through the file reading each line and tokenising
    //it before adding it to data
    while (fgets(buffer, 10000, file)!= NULL){
        //check that there exists a date and time
        checkDateTime(buffer);
        FitnessData record = {};
        int tempSteps [10];
        tokeniseRecord(buffer, ',', record.date, record.time, tempSteps);
        record.steps = tempSteps[0];
        data[rows] = record;
        rows++;
    }
    //close file
    fclose(file);
    //check that the steps are formatted correctly
    checkSteps(data, rows);
    //perform an insertion sort on the data sorting it into descending order
    for(int i=1; i <rows; i++){
        FitnessData current = data[i];
        int j=i-1;
        while(j>=0 && data[j].steps < current.steps){
            data[j+1] = data[j];
            j=j-1;
        }
        data[j+1] = current;
    }
    //concatenate .tsv to filename
    strcat(filename, ".tsv");
    //create a new file in write mode
    FILE *file2 = fopen(filename, "w");
    //copy the contents of the sorted data array into the .tsv file
    for (int i=0; i<rows; i++){
        fprintf(file2, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    //close file
    fclose(file2);
    //end program
    end(0);

}