#include <stdio.h>
#include <math.h>
#include "functions.h"
#include <float.h>

//Methods to get X, Y, and PrintAnswer

float getX(float a, float b, float c);
float getY(float a, float b, float c);
void PrintAnswer(float x, float y);

int main(int argc, char *argv[])
{
	float a, b, c;
	char Input;

	if(argc == 4)
	{
		//Check all floats
		if(sscanf(argv[1], "%f", &a) != 1 || sscanf(argv[2], "f", &b) != 1 || sscanf(argv[3], "%f", &c) != 1)
		{
			printf("Please enter a number! \n");
			return 1;
		}

		//get answers (X & Y)
		float x = getX(a, b, c);
		float y = getY(a, b, c);

		PrintAnswer(x, y);
	}
	else if (argc == 1)
	{
		while (1)
		{
			//get input from user
			printf("Enter a number for A: ");
			a = getFloat();
			printf("Enter a number for B: ");
			b = getFloat();
			printf("Enter a number for C: ");
			c = getFloat();

			//get answers (X & Y)
			float x = getX(a, b, c);
			float y = getY(a, b, c);

			PrintAnswer(x, y);

			//"Continue or stop program case"
			printf("Do you want to Continue? (y/n)\n");
			while(1)
			{
				Input == getchar();
				if(Input != 'y' || Input != 'n')
					continue;
				else if (Input == 'y')
					break;
				else
					return;
			}
		}
	}
	else
	{
		printf("Please enter the correct input to be solved!\n");

	}
}

	/*Methods BELOW*/
	float getX(float a, float b, float c)
	{
		float x = (-b+sqrtf((b*b)-4*a*c))/(2*a);
		if( x != x)
		{
			return FLT_MAX;
		}
		return x;
	}

	
	float getY(float a, float b, float c)
	{
		float y = (-b-sqrtf((b*b)-4*a*c))/(2*a);
		if( y != y)
		{
			return FLT_MAX;
		}
		return y;
	}

	void PrintAnswer(float x, float y)
	{
		if (x == FLT_MAX || y == FLT_MAX)
		{
			printf("The following input could not be calculated,please try again!\n");
        }
        else
        {
        	printf("Answer calculated: %g or %g\n", x, y);
        }
	}
