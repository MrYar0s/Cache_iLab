#include <iostream>
#include <unistd.h>

#include "../include/cache.hpp"
void input_test()
{
	int hits = 0;
	size_t m;
	int n;
	std::cin >> m >> n;
	cache_<int> Q2(m);
	for(int i = 0; i < n; i++)
	{
		int q;
		std::cin >> q;
		if(Q2.accesing(q))
			hits+=1;
	}
	std::cerr << "Hits = " << hits << std::endl;
}

int main(int argc, char const *argv[])
{
	input_test();
	return 0;
}