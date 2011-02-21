#include <stdio.h>
#include <time.h>

int substr_count(int num, int search);

int main (int argc, const char * argv[])
{
	int search = 1;
	int total = 500000000;
	int count = 0;
	
	//take the time
	int start = time(NULL);
	
	printf("\nStarting now. Time at start: %d\n\n", start);
	
	for (int i = 1; i <= total; i++)
	{
		count += substr_count(i, search);
	}
	
	printf("The number %d appeared %d times\n", search, count);
	
	int end = time(NULL);
	printf("Completed, took %i seconds\n\n", end - start);
	
	return 0;
}

//yeeaah so im stealing the PHP name...
int substr_count(int num, int search)
{
	int count = 0;

	while (num > 0)
	{
		int a = num % 10;
		num /= 10;
		if (a == search)
		{
			count++;
		}
	}
	return count;
}