#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <stdbool.h>

//global variables
FITNESS_DATA data[100000];
char filename [100];
int rows = 0;


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
                //declare the whole data structure
            FITNESS_DATA data[10000];
            //collect filename
            char filename [100];
            char buffer [10000];
            int rows;
            FILE *file;
            FITNESS_DATA record;
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
        case 'a':
        {
            //collect filename
            printf("Insert a name: ");
            scanf("%s", filename);
            //open the file
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Error opening file\n");
                 exit(1);
            }
            //declarations
            char buffer [10000];
            //loop through the file reading each line and tokenising
            //it before adding it to data
            while (fgets(buffer, 10000, file)!= NULL){
                char strSteps[20];
                FITNESS_DATA singleRow = {};
                tokeniseRecord(buffer, ",", singleRow.date, singleRow.time, strSteps);
                singleRow.steps = atoi(strSteps);
                data[rows] = singleRow;
                rows++;
            }
            break;
        }  
        case 'B':
        case 'b':
        {
            printf("Total records: %d\n", rows);
            break;
        }
        case 'C':
        case 'c':
        {
            int lowSteps = 1000000;
            int record;
            for (int i=0; i < rows; i++){
                if (data[i].steps < lowSteps){
                    lowSteps = data[i].steps;
                    record = i;
                }
            }
            printf("Fewest Steps: %s %s\n", data[record].date, data[record].time);
            break;
        }
        case 'D':
        case 'd':
        {
            int highSteps = -1;
            record = 0;
            for (int i=0; i < rows; i++){
                if (data[i].steps > highSteps){
                    highSteps = data[i].steps;
                    record = i;
                }
            }
            printf("Largest Steps: %s %s\n", data[record].date, data[record].time);
            break;
        }
        case 'E':
        case 'e':
        {
            int total = 0;
            for (int i=0; i<rows; i++){
                total = total + data[i].steps;
            }
            int mean = total/rows;
            printf("Mean Step Count: %d\n", mean);
            break;
        }
        case 'F':
        case 'f':
        {
            int period = 0;
            int tempStart = -1;
            int start = -1;
            int end = -1;
            int tempPeriod;
            bool inPeriod = false;
            for (int i=0; i< rows; i++){
                if (data[i].steps > 500){
                    if(!inPeriod){
                        tempStart = i;
                        inPeriod = true;
                    }
                }else if(inPeriod){
                    tempPeriod = i-tempStart;
                    if (tempPeriod > period){
                        start = tempStart;
                        end = i-1;
                        period = tempPeriod;
                    }
                    tempPeriod = 0;
                    inPeriod = false;
                }
            }
            printf("Longest Period Start: %s %s\n", data[start].date, data[start].time);
            printf("Longest Period End: %s %s\n", data[end].date, data[end].time);
            break;
        }
        case 'Q':
        case 'q':
        {
            exit(0);
            break;
        }
    }
    return 0;
}