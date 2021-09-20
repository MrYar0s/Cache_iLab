#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* test = fopen("test2.dat", "w");
	int number_of_tests = 10000;
	int size_cache = 1000;
	fprintf(test, "%d %d\n", size_cache, number_of_tests);
	for(int i = 0; i < number_of_tests; i++)
	{
		fprintf(test, "%ld ", random());
	}
	return 0;
}