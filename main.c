#include <stdio.h>
#include <time.h>

int test(int total);

int main (int argc, const char * argv[])
{
	//take the time
	int start = time(NULL);
	
	int debug, min, max, inc;
	
	printf("\nEnable debug mode? ");
	scanf("%d", &debug);
	
	printf("\nWhat value should we start at? ");
	scanf("%d", &min);
	
	printf("What value should we finish at? ");
	scanf("%d", &max);
	
	printf("What value should we increment by? ");
	scanf("%d", &inc);
	
	printf("\nStarting now. Time at start: %d\n\n", start);
	
	int matches = 0;
	
	for (int total = min; total <= max; total += inc)
	{
		if (debug)
		{
			printf("%d\n", total);
		}
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