#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
int main() {
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
            printf("Total records: %d\n", rows);
            int lowSteps = 1000000;
            int record;
            for (int i=0; i < rows; i++){
                if (data[i].steps < lowSteps){
                    lowSteps = data[i].steps;
                    record = i;
                }
            }
            printf("Fewest Steps: %s %s\n", data[record].date, data[record].time);
            int highSteps = -1;
            record = 0;
            for (int i=0; i < rows; i++){
                if (data[i].steps > highSteps){
                    highSteps = data[i].steps;
                    record = i;
                }
            }
            printf("Largest Steps: %s %s\n", data[record].date, data[record].time);
            int total = 0;
            for (int i=0; i<rows; i++){
                total = total + data[i].steps;
            }
            int mean = total/rows;
            printf("Mean Step Count: %d\n", mean);
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
    return 0;
    



}