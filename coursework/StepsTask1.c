#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    return file;
}



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
    int i;
    char *filename = "FitnessData_2023.csv";
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int count = 1;
    FITNESS_DATA old_temp [0];

    do
    {
        FITNESS_DATA new_temp [count];
        //sizeof() function from 
        //https://www.w3resource.com/c-programming-exercises/c-snippets/determine-size-of-structure-and-why-structure-size-is-different-in-c.php
        for(i=0;i< sizeof(old_count); i++){
            new_temp[i] = old_temp[i];
        }
        tokeniseRecord(line_buffer, ",", new_temp[count].date, new_temp[count].time, new_temp[count].steps);
        count = count + 1;
        FITNESS_DATA old_temp [count];
        for(i=0;i< sizeof(new_count); i++){
            old_temp[i] = new_temp[i];
        }
    }while (fgets(line_buffer, buffer_size, file) != NULL);

    fclose(file);
    return 0;
    



}