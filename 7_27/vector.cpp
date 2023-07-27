#pragma once
#include <assert.h>

// 模拟实现 -- 加深对这个容器理解，不是为了造更好的轮子
namespace bits
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstoage - _start;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, size() * sizeof(T));
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_endofstoage = _start + n;
			}
		}

		//void resize(size_t n, const T& val = T())
		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}

			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstoage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}

			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			if (_finish > _start)
			{
				--_finish;
			}
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		iterator insert(iterator pos, const T& x)
		{
			// 检查参数
			assert(pos >= _start && pos <= _finish);

			// 扩容
			// 扩容以后pos就失效了,需要更新一下
			if (_finish == _endofstoage)
			{
				size_t n = pos - _start;

				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);

				pos = _start + n;
			}

			// 挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstoage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << '\n';

		v.pop_back();
		v.pop_back();
		v.pop_back();

		for (size_t i = 0; i < v.size(); ++i)
		{
			std::cout << v[i] << " ";
		}
		std::cout << '\n';

		for (auto e : v)
		{
			std::cout << e << " ";
		}
		std::cout << '\n';

		// C++中内置类型也可以认为有构造函数 析构函数
		// 这样才能更好支持模板
		// void resize(size_t n, T val = T())
		int i = 0;
		int j = int();
		int k = int(1);
	}

	void test_vector2()
	{
		/*vector<int> v;
		v.resize(10, -1);

		for (auto e : v)
		{
		std::cout << e << " ";
		}
		std::cout << '\n';*/
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(5);

		v.insert(v.begin(), 0);

		for (auto e : v)
		{
			std::cout << e << " ";
		}
		std::cout << '\n';
	}


	void test_vector3()
	{
		// 在所有的偶数的前面插入2
		vector<int> v;
		//v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.insert(it, 20);
				++it;
			}

			++it;
		}

		for (auto e : v)
		{
			std::cout << e << " ";
		}
		std::cout << '\n';
	}
}