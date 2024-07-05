#pragma once
#include<assert.h>

namespace wyb
{
	template<class T>
	class vector
	{

	public:
		typedef T* iterator;
		typedef const T* const_iterator;

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

		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}

		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		// ��ͳд�� - ���
		// v2(v1) - v1������v2
		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.size()]; // v����v1�ı�������v.capacity()Ҳ����
		//	memcpy(_start, v._start, sizeof(T) * v.size());
		//	_finish = _start + v.size();
		//	_end_of_storage = _start + v.size();

		//}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last) // ��������������ҿ�
			{
				push_back(*first);
				++first;
			}
		}

		vector()
		{}


		// Ҳ��������д
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _end_of_storage(nullptr)
		//{
		//	reserve(v.size());
		//	for (const auto& e : v)
		//	{
		//		push_back(e);
		//	}
		//}
		

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}


		// ������ôд
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _end_of_storage(nullptr)
		//{
		//	vector<T> tmp(v.begin(), v.end());
		//	swap(tmp);
		//}
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}

			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}


		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}*/

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}


		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + size();
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back() // βɾ
		{
			assert(_finish > _start);
			--_finish;
		}

		iterator insert(iterator& pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			// Ų������
			iterator end = _finish - 1;

			while (end >= pos)
			{
				*(end - 1) = *end;
				--end;
			}

			*pos = x;

			++_finish;

			return pos;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		// stl �涨erase����ɾ��λ����һ��λ�õ�����
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;

			//if (size() < capacity() / 2)
			//{
			//	// ���� -- ��ʱ�任�ռ�
			//	// ����Ч�ʵͣ�������Ч�ʸ�
			//	// ���ݺ��������ʧЧ
			//}

			return pos;
		}

		// ���ۣ�
		// insert/erase posλ�ã���Ҫֱ�ӷ���pos��һ��Ҫ���¡�
		// ֱ�ӷ��ʣ����ܻ���ָ��ֳ������ϵĽ�����������ν�ĵ�����ʧЧ
		// ��ΪposʧЧ����Ҫ����

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};

	void Func(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << endl;
			++it; // ֻ�ܶ������޸�
		}
	}

	void test_vector1()
	{
		//double d = 2.2;
		//const int& i = d;

		//vector<string> v;
		//v.push_back("xxxxx");

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto p = find(v.begin(), v.end(), 3);
		if (p != v.end())
		{
			v.insert(p, 30);
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(4);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v1(v);
		v[0] *= 10;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}