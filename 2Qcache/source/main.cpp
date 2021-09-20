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
	for(int i = 0; i < n; i++)
	{
		int q;
		std::cin >> q;
		if(Q2.accesing(q))
			hits+=1;
	}
	fprintf(stderr,"%d\n", hits);
	return 0;
}