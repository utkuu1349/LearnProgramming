#include <stdio.h>

int main (void) 
{
	int age;
	
	printf("Please enter your age\n");
	scanf("%d", &age);
	if (age < 18)
	{
		printf("You can't drink legally.\n");
	}
	else if (age == 18)
	{
		printf("Congratulaions you are an adult now!\n");
	}
	else
	{
		printf("I hope you are enjoying your adult life.\n");
	}
	return 0;
}
