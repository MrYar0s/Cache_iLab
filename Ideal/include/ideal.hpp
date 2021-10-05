#ifndef INCLUDE_IDEAL_HPP
#define INCLUDE_IDEAL_HPP

#include <vector>
#include <list>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename T>
struct ideal_
{
	int max_size;
	int cur_size;

	std::vector<T> elem_list_;

	std::list<T> list_;
	using ListIt = typename std::list<T>::iterator;
	std::unordered_map<T, ListIt> hash_;

	ideal_(): max_size(0), cur_size(0) {}
	ideal_(int size): max_size(size), cur_size(0) {}

	void add_data(T key)
	{
		list_.push_front(key);
		hash_[key] = list_.begin();
		cur_size++;
	}

	void remove_data(T key)
	{
		auto x = hash_.find(key);
		list_.erase(x->second);
		hash_.erase(key);
		cur_size--;
	}

	bool search(T key) const
	{
		auto it = hash_.find(key);
		if(it == hash_.end())
			return false;
		else
			return true;
	}

	bool full() const
	{
		if(max_size == cur_size)
			return true;
		return false;
	}

	bool accesing(T key)
	{
		if(search(key))
		{
			return true;
		}
		else
		{
			if(full())
			{
				T deleted = lastused();
				remove_data(deleted);
				add_data(key);
				return false;
			}
			else
			{
				add_data(key);
				return false;
			}
		}
	}

	T lastused()
	{
		int lu_pos = 0;
		int pos = 0;
		T deleted = 0;
		auto list_begin = elem_list_.begin();
		auto list_end = elem_list_.end();
		for (ListIt it = list_.begin(); it != list_.end(); ++it)
		{
			auto result = std::find(list_begin, list_end, *it);
			if(result != elem_list_.end())
			{
				pos = std::distance(list_begin, result);
				if(lu_pos < pos)
				{
					lu_pos = pos;
					deleted = *it;
				}
			}
			else
			{
				deleted = *it;
				break;
			}
		}
		return deleted;
	}
};

#endif //INCLUDE_IDEAL_HPP