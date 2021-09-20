#include <iostream>
#include <unistd.h>

#include "../include/cache.hpp"

int main(int argc, char const *argv[])
{
	int hits = 0;
	size_t m;
	int n;
	std::cin >> m >> n;
	caches::cache_<int> Q2(m);
	printf("A1in max size = %ld\n", Q2.A1in.max_size);
	printf("A1out max size = %ld\n", Q2.A1out.max_size);
	printf("Am max size = %ld\n", Q2.Am.max_size);
	for(int i = 0; i < n; i++)
	{
		int q;
		std::cin >> q;
		if(Q2.accesing(q))
			hits+=1;
		printf("A1in cur size = %ld\n", Q2.A1in.cur_size);
		printf("A1out cur size = %ld\n", Q2.A1out.cur_size);
		printf("Am cur size = %ld\n", Q2.Am.cur_size);
	}
	fprintf(stderr,"%d\n", hits);
	return 0;
}