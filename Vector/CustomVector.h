#pragma once
#include <assert.h>
#include <iterator>

template<class T>
class Vector
{
	struct Node;
public:
	class iterator : public std::iterator<std::forward_iterator_tag, T>
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

	T& operator[](int) const;
	T& at(int) const;
	void insert(int, const T&);
	int size() const;

	iterator begin() const;
	iterator end() const;
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
int Vector<T>::size() const
{
	if (this->_head == nullptr || this->_head->next == nullptr)
		return 0;

	int count = 0;
	iterator bgn = this->begin();
	while (bgn != this->end()) { ++bgn; count++; }
	return count;
}

template <class T>
Vector<T>::Vector()
{
	_head = nullptr;
}

template <class T>
Vector<T>::~Vector()
{
	this->clear();
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
	if (_head == nullptr)
	{
		_head = new Node();
		_head->value = value;
		_head->next = new Node;
		return;
	}
	Node* newHead = new Node;
	newHead->value = value;
	newHead->next = _head;
	_head = newHead;
}

template <class T>
T Vector<T>::pop_back()
{
	return removeLastNode();
}

template <class T>
T Vector<T>::pop_front()
{
	assert(this->size() > 0);
	T toReturn = _head->value;
	if (this->size() == 1)
	{
		this->clear();
		return toReturn;
	}
	Node* newHead = _head->next;
	delete _head; _head->next = nullptr;
	_head = newHead;
	return toReturn;
}


template <class T>
T& Vector<T>::operator[](int i) const throw (std::out_of_range)
{
	int counter = 0;
	auto iter = this->begin();
	while (iter != this->end() && i != counter)
	{
		++iter;
		counter++;
	}

	if (i != counter || iter == this->end())
		throw std::out_of_range("Element is out of bounds of vector");

	return *iter;
}

template <class T>
T& Vector<T>::at(int i) const
{
	int counter = 0;
	auto iter = this->begin();
	while (iter != this->end() && i != counter)
	{
		++iter;
		counter++;
	}

	assert(i == counter && iter != this->end());
	return *iter;
}

template <class T>
void Vector<T>::insert(int pos, const T& val)
{
	assert(pos >= 0);
	int size = this->size();
	if (pos >= size - 1)
	{
		this->push_back(val);
		return;
	}
	if (pos == 0)
	{
		this->push_front(val);
		return;
	}
	int cnt = 0;
	Node* newHead = _head;
	while (newHead->next != nullptr && cnt != pos)
	{
		newHead = newHead->next;
		cnt++;
	}

	Node* toInsert = new Node;
	toInsert->next = newHead->next;
	toInsert->value = val;
	newHead->next = toInsert;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin() const
{
	if (_head == nullptr || _head->next != nullptr)
		return iterator(this->_head);
	return iterator(nullptr);
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() const
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