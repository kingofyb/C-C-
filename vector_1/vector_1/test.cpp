#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

// vector����˳������
// template < class T, class Alloc = allocator<T> > class vector; // generic template
// allocator<T> -> �ռ�������(�ڴ��)

namespace std
{
	void test_vector1()
	{
		vector<int> v1;
		vector<int> v2(10, 1);
		vector<int> v3(v2); // ��������
	}

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		// ��һ�ֱ�����ʽ���±�+[]
		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		// �ڶ��ֱ�����ʽ��������
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			(*it)--;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		// �����ֱ�����ʽ��rbegin���������

		// �����ֱ�����ʽ��rend

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	// ����vector��Ĭ�����ݻ���
	void TestVectorExpand()
	{
		size_t sz;
		vector<int> v;
		// ���ﲻ����resize��Ҫ��reserve
		// resize�������˿ռ仹������100������
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


	// find -> ����ģ��
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
			// ��3ǰ�����30
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

		// sortĬ������
		sort(v1.begin(), v1.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		less<int> ls;

		// ����
		greater<int> gt;
		// sort(v1.begin(), v1.end(), gt);
		// Ҳ����ֱ����������
		sort(v1.begin(), v1.end(), greater<int>());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		// vector<char> v; // �޷����string
		// string str; // ���ݽ�β��\0��֧��+=��find���Ƚϴ�С��to_string��<<��>>�ȵ�

		vector<string> strV;
		strV.push_back();

	}
}


int main()
{
	std::test_vector5();
	return 0;
}