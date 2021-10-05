#include <iostream>
#include "../include/ideal.hpp"

void input_test()
{
	int hits = 0;
	int m;
	int n;
	std::cin >> m >> n;
	ideal_<int> ideal(m);
	for(int i = 0; i < n; i++)
	{
		int q = 0;
		std::cin >> q;
		ideal.elem_list_.push_back(q);
	}
	for(int i = 0; i < n; i++)
	{
		if(ideal.accesing(ideal.elem_list_[i]))
			hits++;
		ideal.elem_list_[i] = 0;
	}
	std::cerr << "Hits = " << hits << std::endl;
}

int main(int argc, char const *argv[])
{
	input_test();
	return 0;
}