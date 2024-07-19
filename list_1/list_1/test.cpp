#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

#include"list.h"

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = lt.begin();
	while (it != lt.end())
	{
		*it *= 2;
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

// list是一个双向链表
// N个数据需要排序，vector + 算法sort list + sort
int main()
{
	wyb::test_list1();
	return 0;
}