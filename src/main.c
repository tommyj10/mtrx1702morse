#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "morse.h"

#define BUFFERSIZE 1000

int fatalError(char * input);
int checkError(char * input);

int main(void)	{
	
	printf("Welcome to the Morse translator.\n");
	printf("Enter input: ");
	
	char input[BUFFERSIZE];
	
	fgets(input, BUFFERSIZE, stdin);
	
	// get rid of the newline element of the input
	input[strlen(input) - 1] = '\0';
	
	// upper case
	unsigned int i;
	for (i = 0; i < strlen(input); ++i)	{
		
		input[i] = toupper(input[i]);
	}
	
	// hold the input because, while using checkError function, the input reduces to the last element if in morse code
	char * holdInput;
	holdInput = (char *) malloc(BUFFERSIZE * sizeof(char));
	strcpy(holdInput, input);
	
	int invalidInput, doubleInput;
	invalidInput = checkError(input);
	doubleInput = fatalError(input);
	
	if (0 != doubleInput)	{
		
		// both morse and alphanumeric
		printf("Invalid input!\n");
		return 7;
	}
	else if (0 != invalidInput)	{
		
		// not appropriate morse code
		printf("Invalid Morse code!\n");
		return 10;
	}
	else	{
		
		// we know that the initial input is flawless, so now translate
		morse(holdInput);
	}
	
	printf("\n");
	
	free(holdInput);
	
	return 0;
}
