#pragma once
#include <assert.h>

template<class T>
class Vector
{
	struct Node;
public:
	class iterator
	{
	public:
		iterator(Node* ref) : _data(ref) {}
		iterator operator++() { _data = _data->next; return *this; }
		T& operator* () const { return _data->value; }

		bool operator==(const iterator& another) const { return this->_data == another._data; }
		bool operator!=(const iterator& another) const { return !this->operator==(another); }
	private:
		Node* _data;
	};

	Vector();
	~Vector();

	void push_back(const T&);
	void push_front(const T&);
	T pop_back();
	T pop_front();
	T& operator[](int);
	T& at(int);
	void insert(int, const T&);

	iterator begin();
	iterator end();
	void clear();

	void removeLastNode();
private:
	struct Node
	{
		Node():value(0)
		{
			next = nullptr;
		}
		Node* next;
		T value;
	};
	Node* _head;
	
};

template <class T>
Vector<T>::Vector()
{
	_head = nullptr;
}

template <class T>
Vector<T>::~Vector()
{
}

template <class T>
void Vector<T>::push_back(const T& data)
{
	if (_head == nullptr)
	{
		_head = new Node();
		_head->value = data;
		_head->next = new Node;
		return;
	}

	Node* cpy = _head;
	while (cpy->next != nullptr)
		cpy = cpy->next;

	cpy->value = data;
	cpy->next = new Node;
}

template <class T>
void Vector<T>::push_front(const T&)
{
}

template <class T>
T Vector<T>::pop_back()
{
}

template <class T>
T Vector<T>::pop_front()
{
}

template <class T>
T& Vector<T>::operator[](int)
{
}

template <class T>
T& Vector<T>::at(int i)
{
	Node* copy = _head;
	int counter = 0;
	while(counter !=i && copy->next->next != nullptr)
	{
		
	}
	return NULL;
}

template <class T>
void Vector<T>::insert(int, const T&)
{
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return iterator(this->_head);
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
	if (_head == nullptr)
	{
		return iterator(nullptr);
	}

	Node* cpy = _head;
	while (cpy->next != nullptr) // 
		cpy = cpy->next;

	return iterator(cpy); // 
}

template <class T>
void Vector<T>::clear()
{
	while (_head->next != nullptr)
		removeLastNode();
	assert(_head != nullptr);
	delete _head;
	_head = nullptr;
}

template <class T>
void Vector<T>::removeLastNode()
{
	// Need to :
	// 1. Delete gag
	// 2. Set last Node value to 0
	// o -> o -> ... o -> o(last actual value) -> o(gag) -> null

	// assert(_head == nullptr || _head->next == nullptr);
	if (_head == nullptr || _head->next == nullptr)
		return;

	Node* cpy = _head;
	while (cpy->next->next != nullptr)
		cpy = cpy->next;

	//assert(cpy->next == nullptr);
	if (cpy->next == nullptr)
		return;

	delete cpy->next;
	cpy->next = nullptr;
	cpy->value = 0;
}