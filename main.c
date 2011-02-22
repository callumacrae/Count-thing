#include <stdio.h>
#include <time.h>

int test(int total);

int main (int argc, const char * argv[])
{
	//take the time
	int start = time(NULL);
	
	printf("\nStarting now. Time at start: %d\n\n", start);
	
	int matches = 0;
	
	for (int total = 1; total < 1000000; total++)
	{
		matches += test(total);
	}
	
	int end = time(NULL);
	printf("\nCompleted, took %i seconds. Found %d total matches\n\n", end - start, matches);
	
	return 0;
}

int test(int total)
{
	int count, matches = 0;

	for (int search = 0; search < 10; search++)
	{
		int substart = time(NULL);
		
		count = 0;
		for (int i = 1; i <= total; i++)
		{
			int num = i;
			while (num > 0)
			{
				int a = num % 10;
				num /= 10;
				if (a == search)
				{
					count++;
				}
			}
		}
		
		if (count == total)
		{
			int end = time(NULL);
			printf("MATCH: The number %d appears in %d that amount of times (%d seconds).\n", search, count, end - substart);
			matches++;
		}
	}
	
	return matches;
}