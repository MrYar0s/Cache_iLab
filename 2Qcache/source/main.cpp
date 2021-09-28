#include <iostream>
#include <unistd.h>

#include "../include/cache.hpp"

/*void simple_unit_test()
{
	int n = 20;
	size_t m = 20;
	cache_<int> Q2(m);
	for (int i = 1; i <= n; ++i)
	{
		Q2.accesing(i);
	}
	printf("A1in max size = %ld\n", Q2.A1in.max_size);
	printf("A1out max size = %ld\n", Q2.A1out.max_size);
	printf("Am max size = %ld\n", Q2.Am.max_size);
	printf("A1in queue\n");
	Q2.A1in.print();
	printf("A1out queue\n");
	Q2.A1out.print();
	printf("Am queue\n");
	Q2.Am.print();
}*/

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
	fprintf(stderr, "%d\n", hits);
}

int main(int argc, char const *argv[])
{
	input_test();
//	simple_unit_test();
	return 0;
}