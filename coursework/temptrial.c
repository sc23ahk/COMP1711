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
            data[rows] = {"", "", 0}
            printf("%d\n", rows);
            //close the file
            fclose(file);
            int count =0;
            FITNESS_DATA empty = {"","",0};
            while(data[0] != empty){
                count++;
            }
            //int size = sizeof(data) / sizeof(data[0]);
            printf("%d\n", count);
    return 0;
    



}