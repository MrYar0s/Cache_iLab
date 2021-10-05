#include <unordered_map>
#include <list>
#include <iterator>

const double Kin = 0.2;
const double Kout = 0.25;

template <typename T>
struct queue_
{
	int max_size;
	int cur_size;

	std::list<T> list_;
	using ListIt = typename std::list<T>::iterator;
	std::unordered_map<T, ListIt> hash_;

	queue_() : max_size(), cur_size() {}

	queue_(int size)
	{
		max_size = size;
		cur_size = 0;
	}

	void add_data(T key)
	{
		list_.push_front(key);
		hash_[key] = list_.begin();
		cur_size++;
	}

	void remove_data(T key)
	{
		if(key == list_.back())
		{
			list_.pop_back();
		}
		else
		{
			auto x = hash_.find(key);
			list_.erase(x->second);
		}
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
};

template <typename T>
struct cache_
{
	queue_<T> Am;
	queue_<T> A1in;
	queue_<T> A1out;

	cache_(int size)
	{
		int size_a1out = Kout * size;
		if(!size_a1out)
			size_a1out = 1;
		int size_a1in = Kin * (size - size_a1out);
		if(!size_a1in)
			size_a1in = 1;
		int size_am = size - size_a1out - size_a1in;
		if(size_am <= 0)
			size_am = 1;
		A1in = queue_<T>(size_a1in);
		A1out = queue_<T>(size_a1out);
		Am = queue_<T>(size_am);
	}

	void reclaimfor(T key)
	{
		if(!A1in.full())
		{
			A1in.add_data(key);
			return;
		}
		if(!Am.full())
		{
			Am.add_data(key);
			return;
		}
		if(A1in.full())
		{
			T Ytale = A1in.list_.back();
			A1in.remove_data(Ytale);
			if(A1out.full())
			{
				T Ztale = A1out.list_.back();
				A1out.remove_data(Ztale);
			}
			A1out.add_data(Ytale);
			A1in.add_data(key);
			return;
		}
	}

	bool accesing(T key)
	{
		if(Am.search(key))
		{
			Am.remove_data(key);
			Am.add_data(key);
			return true;
		}
		else if(A1out.search(key))
		{
			reclaimfor(key);
			return true;
		} else if(A1in.search(key))
			return true;
		else
		{
			reclaimfor(key);
			return false;
		}
	}
};