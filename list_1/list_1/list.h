#pragma once
namespace wyb
{
	template<class T>
	class list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T> iterator;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}

		//*it it.operator*()
		T& operator*()
		{
			return _node->_data;
		}

		// ++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}
	};



	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:

		typedef __list_iterator<T> iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		// ¹¹Ôìº¯Êý
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			// _head         tail newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		
	private:
		Node* _head;

	};

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
			*it *= 2;
			++it;
		}
		cout << endl;
	}
}