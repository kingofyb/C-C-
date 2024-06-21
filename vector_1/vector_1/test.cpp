#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

// vector就是顺序容器
// template < class T, class Alloc = allocator<T> > class vector; // generic template
// allocator<T> -> 空间配置器(内存池)

namespace std
{
	void test_vector1()
	{
		vector<int> v1;
		vector<int> v2(10, 1);
		vector<int> v3(v2); // 拷贝构造
	}

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		// 第一种遍历方式：下标+[]
		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		// 第二种遍历方式：迭代器
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			(*it)--;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		// 第三种遍历方式：rbegin，反向迭代

		// 第四种遍历方式：rend

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	// 测试vector的默认扩容机制
	void TestVectorExpand()
	{
		size_t sz;
		vector<int> v;
		// 这里不能用resize，要用reserve
		// resize不仅开了空间还加入了100个数据
		// v.resize(100);
		v.reserve(100);

		sz = v.capacity();
		cout << "making v grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			v.push_back(i);
			if (sz != v.capacity())
			{
				sz = v.capacity();
				cout << "capacity changed: " << sz << '\n';
			}
		}
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		cout << v1.max_size() << endl;

		TestVectorExpand();
	}


	// find -> 函数模板
	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			// 在3前面添加30
			v1.insert(pos, 30);
		}
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(10);
		v1.push_back(2);
		v1.push_back(32);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(1);
		v1.push_back(9);

		// sort默认升序
		sort(v1.begin(), v1.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		less<int> ls;

		// 降序
		greater<int> gt;
		// sort(v1.begin(), v1.end(), gt);
		// 也可以直接匿名对象
		sort(v1.begin(), v1.end(), greater<int>());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		// vector<char> v; // 无法替代string
		// string str; // 数据结尾有\0，支持+=，find，比较大小，to_string，<<，>>等等

		vector<string> strV;
		strV.push_back();

	}
}


int main()
{
	std::test_vector5();
	return 0;
}