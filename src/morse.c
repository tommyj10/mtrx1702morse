#include "morse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 1000

// global variables for the corresponding lists of the morse codes and their translations
char * morse_lookup[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "/"};
char char_lookup[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "};

void morse(char * input)	{
	
	// alphanumeric -> morse
	if (isalnum(input[0]))	{
		
		unsigned int i;
		
		// each element in input
		for (i = 0; i < strlen(input); ++i)	{
			
			unsigned int k;
			k = 0;
			
			// find the exact same value, and print the corresponding morse code
			while (char_lookup[k] != input[i])	{
				
				++k;
			}
			
			printf("%s", morse_lookup[k]);
			
			// only print whitespace if not ultimate element
			if (strlen(input) - 1 != i)	{
				
				printf(" ");
			}
		}
	}
	// morse code
	else	{
		
		char * token;
		char s[] = " ";
		
		// get first morse code
		token = strtok(input, s);
		
		while (NULL != token)	{
			
			unsigned int m;
			m = 0;
			
			// find the corresponding morse code, and print its translation
			while (0 != strcmp(token, morse_lookup[m]))	{
				
				++m;
			}
			
			printf("%c", char_lookup[m]);
			
			// get the next morse code
			token = strtok(NULL, s);
		}
	}
}
