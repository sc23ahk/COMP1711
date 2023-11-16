#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "FitnessDataStruct.h"

// Define an appropriate struct
struct {
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
    //Display all of the options
    printf("A:Import a file");
    printf("B:Display the total number of records");
    printf("C:Display the date and time of the day with the fewest steps");
    printf("D:Display the date and time of the day with the most steps");
    printf("E:Display the mean step count");
    printf("F:Display the highest streak of days with over 500 steps");
    printf("Q:Exit");

    // get the next character typed in and store in the 'choice'
    char choice = getchar();

    // this gets rid of the newline character which the user will enter
    // as otherwise this will stay in the stdin and be read next time
    while (getchar() != '\n');

    switch(choice){
        case 'A':
        case 'a': ;
            //declare the whole data structure
            FITNESS_DATA data[10000];
            //collect filename
            char filename [100];
            printf("Insert a name: ");
            scanf("%s", filename);
            //open the file
            FILE *file = fopen(filename, "r");
            //check that file opened correctly
            if (file == NULL)
            {
                printf("Error: could not open file\n");
                exit(1);
            }
            //declarations
            char buffer [10000];
            int rows = 0;
            //loop through the file reading each line and tokenising
            //it before adding it to data
            while (fgets(buffer, 10000, file)!= NULL){
                char strSteps[20];
                FITNESS_DATA record = {};
                tokeniseRecord(buffer, ",", record.date, record.time, strSteps);
                record.steps = atoi(strSteps);
                data[rows] = record;
                rows++;
            }
            //close the file
            fclose(file);
        /*    
        switch 'B':
        switch 'b':
            int size = sizeof(data);
            printf("%d", size);
        */
            
    }
    return 0;
}