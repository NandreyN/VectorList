#pragma once
#include <assert.h>
#include <queue>

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


private:
	struct Node
	{
		Node() :value(0)
		{
			next = nullptr;
		}
		Node* next;
		T value;
	};
	Node* _head;
	T removeLastNode();
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
void Vector<T>::push_front(const T& value)
{
	std::queue<T> queue;
	auto iter = this->begin();
	while(iter != this->end())
	{
		queue.push(*iter);
		++iter;
	}

	this->clear();
	this->push_back(value);
	while (queue.size() != 0)
	{
		T k = (T)queue.front();
		queue.pop();
		this->push_back(k);
	}
}

template <class T>
T Vector<T>::pop_back()
{
	return removeLastNode();
}

template <class T>
T Vector<T>::pop_front()
{

}

template <class T>
T& Vector<T>::operator[](int i) throw (std::out_of_range)
{
	int counter = 0;
	auto iter = this->begin();
	while (iter != this->end() && i != counter)
	{
		++iter;
		counter++;
	}

	if (i != counter || iter == this->end())
		throw std::out_of_range("Elemt is out of bounds of vector");

	return *iter;
}

template <class T>
T& Vector<T>::at(int i)
{
	int counter = 0;
	auto iter = this->begin();
	while(iter != this->end() && i != counter)
	{
		++iter;
		counter++;
	}
	
	assert(i == counter && iter != this->end());
	return *iter;
}

template <class T>
void Vector<T>::insert(int, const T&)
{
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	if (_head->next != nullptr)
		return iterator(this->_head);
	return iterator(nullptr);
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
T Vector<T>::removeLastNode()
{
	// Need to :
	// 1. Delete gag
	// 2. Set last Node value to 0
	// o -> o -> ... o -> o(last actual value) -> o(gag) -> null

	// assert(_head == nullptr || _head->next == nullptr);
	if (_head == nullptr || _head->next == nullptr)
		return NULL;

	Node* cpy = _head;
	while (cpy->next->next != nullptr)
		cpy = cpy->next;

	//assert(cpy->next == nullptr);
	if (cpy->next == nullptr)
		return NULL;

	delete cpy->next;
	cpy->next = nullptr;

	T valueCopy = cpy->value;
	cpy->value = 0;

	return valueCopy;
}