#include <unordered_map>
#include <list>
#include <iterator>

#define Kin 0
#define Kout 0.1

template <typename T, typename data_t=int>
struct queue_
{
	size_t max_size;
	size_t cur_size;

	std::list<T> list_;
	std::unordered_map<data_t, T*> hash_;

	queue_()
	{
		max_size = 0;
		cur_size = 0;
	}

	queue_(size_t size)
	{
		max_size = size;
		cur_size = 0;
		for(size_t i = 0; i < max_size; i++)
			list_.push_back(T());
	}
	void add_data(T data)
	{
		list_.push_front(data);
		hash_.insert({data, &data});

		T* del = &list_.back();
		hash_.erase(*del);
		list_.pop_back();

		cur_size++;
	}
	void remove_data(T data)
	{
		hash_.erase(data);
		list_.remove(data);
		list_.push_back(T());
		cur_size--;
	}
	bool search(T data)
	{
		typename std::unordered_map<data_t,T*>::iterator it = hash_.find(data);
		if(it == hash_.end())
			return false;
		else
			return true;
	}
};

template <typename T>
struct cache_
{
	queue_<T> Am;
	queue_<T> A1in;
	queue_<T> A1out;
		cache_(size_t size): Am(), A1in(), A1out()
	{
		size_t size_a1out = Kout * size;
		if(!size_a1out)
			size_a1out = 1;
		size_t size_a1in = Kin * (size - size_a1out);
		if(!size_a1in)
			size_a1in = 1;
		int size_am = size - size_a1out - size_a1in;
		if(size_am <= 0)
			size_am = 1;
		A1in = queue_<T>(size_a1in);
		A1out = queue_<T>(size_a1out);
		Am = queue_<T>((size_t)size_am);
	}
	void reclaimfor(T data)
	{
		if(A1in.cur_size < A1in.max_size)
		{
			A1in.add_data(data);
		} else if(Am.cur_size < Am.max_size)
		{
			Am.add_data(data);
		} else if(A1in.cur_size == A1in.max_size)
		{
			T Ytale = A1in.list_.back();
			A1in.remove_data(Ytale);
			if(A1out.cur_size == A1out.max_size)
			{
				T Ztale = A1out.list_.back();
				A1out.remove_data(Ztale);
			}
			A1out.add_data(Ytale);
			A1in.add_data(data);
		} else
		{
			T Ytale = Am.list_.back();
			Am.remove_data(Ytale);
			Am.add_data(data);
		}
	}
	bool accesing(T data)
	{
		if(Am.search(data))
		{
			Am.remove_data(data);
			Am.add_data(data);
			return true;
		}
		else if(A1out.search(data))
		{
			reclaimfor(data);
			return true;
		} else if(A1in.search(data))
			return true;
		else
		{
			reclaimfor(data);
			return false;
		}
	}
};