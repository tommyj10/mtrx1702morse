#include <stdio.h>
#include <string.h>
#include <ctype.h>

int fatalError(char * input)	{
	
	// error
	int error;
	error = 0;
	
	unsigned int i;
	
	// alphanumeric, so check if morse code exists
	if (isalnum(input[0]))	{
		
		for (i = 1; i < strlen(input); ++i)	{
			
			// only '.', '-', '/' are allowed, only checking if both codes exist
			if ('.' == input[i] || '-' == input[i] || '/' == input[i])	{
				
				++error;
			}
		}
	}
	// morse code, so check if alphanumeric components exist
	else	{
		
		for (i = 1; i < strlen(input); ++i)	{
			
			if (isalnum(input[i]))	{
				
				++error;
			}
		}
	}
	
	return error;
}
