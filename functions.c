#include "functions.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>

float getFloat(void)
{
	//get a float from user
	while (1 == 1)
	{
		//get line of text, returning FLT_MAX(MAX INTEGER VALUE) 
		//for exponent on failure
		char* line = getInput();
		if(line == NULL)
		{
           return FLT_MAX;
		}
   
        //return a float 
        char c;
        float f;
        if(sscanf(line, " %f %c", &f, &c) == 1)
        {
        	free(line);
        	return f;
        }
        else
        {
        	free(line);
        	printf("Retry ");
        }

	}
}

char* getInput(void)
{
     char* buffer = NULL;

     unsigned int capacity = 0;
     unsigned int num = 0;

     int character;

     while((character = getchar()) != '\n')
     {
     	if(num + 1 > capacity)
     	{
     		if(capacity == 0)
     		{
     			capacity = 32;
     		}
     		else if (capacity <= (UINT_MAX / 2))
     		{
     			capacity *= 2;
     		}
     		else
     		{
     			free(buffer);
     			return NULL;
     		}

     		//Re-allocate memory for bigger capacity
     		char* increased = realloc(buffer, capacity * sizeof(char));
     		if(increased == NULL)
     		{
     			free(buffer);
     			return NULL;
     		}

     		//Assign new alloc to the buffer
     		buffer = increased;
     	}
     	buffer[num++] = character;
     }

     if(num == 0)
     {
     	return NULL;
     }

     char* condensed = malloc((num+1) * sizeof(char));
   
   //copy the chars in the buffer string into condensed string
     //according to the num of bytes
    strncpy(condensed, buffer, num);
    free(buffer);

    //termination here
    condensed[num] = '\0';
    return condensed;
}