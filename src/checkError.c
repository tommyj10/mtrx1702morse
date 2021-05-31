#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkError(char * input)	{
	
	// list of morse codes
	char * morse_lookup[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "/"};
	
	// no errors initially
	int error;
	error = 0;
	
	// go through if input is morse code, not necessary to check input if alphanumeric values
	if (!isalnum(input[0]))	{
		
		char * token;
		char s[2] = " ";
		
		// get first input
		token = strtok(input, s);
		
		while (NULL != token)	{
			
			int checkTrue;
			checkTrue = 0;
			
			unsigned int j;
			// check for all morse codes
			for (j = 0; j < 37; ++j)	{
				
				if (0 == strcmp(morse_lookup[j], token))	{
					
					// true
					++checkTrue;
				}
			}
			
			// input incompatible with morse code
			if (0 == checkTrue)	{
				
				++error;
			}
			
			// move to next morse code
			token = strtok(NULL, s);
		}
	}
	
	return error;
}
