#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;




// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main(){
    //open the file for reading
    char *filename = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    //loop through each line of the file and count each line
    char count_array [100], lines [100];
    int count = 0;
    while (fgets(count_array, 100, file)!= NULL){
        count++;
    }
    //close the file
    fclose(file);
    //output the numebr of lines (records) in the file
    printf("Number of records in file: %d\n", count);
    //open the file again for reading
    FILE *file2 = fopen(filename, "r");
    int i = 0;
    //loop through each line tokenising each line
    while (fgets(lines, 100, file2)){
        char date [12];
        char time [6];
        char steps [15];
        tokeniseRecord(lines, ",", date, time, steps);
        //convert steps to an integer
        int intsteps = atoi(steps);
        //print the first three records of the data
        if (i<3){
            printf("%s/%s/%d\n", date, time, intsteps);
            i++;
        }
    }
    fclose(file2);
    return 0;
}