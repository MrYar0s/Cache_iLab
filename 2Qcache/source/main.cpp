#include <iostream>
#include <unistd.h>

#include "../include/cache.hpp"

int main(int argc, char const *argv[])
{
	int hits = 0;
	size_t m;
	int n;
	std::cin >> m >> n;
	cache_<int> Q2(m);
	printf("A1in max_size = %ld\n", Q2.A1in.max_size);
	printf("A1out max_size = %ld\n", Q2.A1out.max_size);
	printf("Am max_size = %ld\n", Q2.Am.max_size);
	for(int i = 0; i < n; i++)
	{
		int q;
		std::cin >> q;
		if(Q2.accesing(q))
			hits+=1;
	}
	fprintf(stderr, "%d\n", hits);
	return 0;
}