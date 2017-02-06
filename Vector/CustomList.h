#pragma once
namespace CustomListComponents
{
	template<class T>
	struct Node
	{
		explicit Node()
		{
			value = 0;
			next = nullptr;
		}
		Node(const T& value)
		{
			this->value = value;
			next = nullptr;
		}
		T value;
		Node* next;
	};

	template<class T>
	class ListIterator
	{
	public:
		explicit ListIterator(const Node<T>* const);
		ListIterator(const ListIterator<T>& toCopy);
		~ListIterator();
		void operator++();
		bool operator==(const ListIterator<T>&) const;
		bool operator!=(const ListIterator<T>&) const;
		bool isNextNull() const;
		void setData(const T&);
		T getData() const;
	private:
		Node<T>* getNext() const;
		Node<T>* _target;
	};

	template <class T>
	ListIterator<T>::ListIterator(const Node<T>* const node)
	{
		this->_target = new Node<T>();
		this->_target->next = node->next;
		this->_target->value = node->value;
	}

	template <class T>
	ListIterator<T>::ListIterator(const ListIterator<T>& toCopy)
	{
		this->_target = new Node<T>();
		this->_target->next = toCopy.getNext();
		this->_target->value = toCopy.getData();
	}

	template <class T>
	ListIterator<T>::~ListIterator()
	{
		delete this->_target;
	}

	template <class T>
	void ListIterator<T>::operator++()
	{
		if (this->_target->next != nullptr)
		{
			this->_target->value = _target->next->value;
			this->_target = _target->next;
		}
		else
			throw std::out_of_range("end iter exception");
	}

	template <class T>
	bool ListIterator<T>::operator==(const ListIterator<T>& another) const
	{
		return (this->_target->value == another.getData() && this->_target->next == another.getNext()) ? true : false;
	}

	template <class T>
	bool ListIterator<T>::operator!=(const ListIterator<T>& another) const
	{
		return !this->operator==(another);
	}

	template <class T>
	bool ListIterator<T>::isNextNull() const
	{
		return (this->_target->next == nullptr) ? true : false;
	}

	template <class T>
	void ListIterator<T>::setData(const T& dt)
	{
		this->_target->value = dt;
	}

	template <class T>
	T ListIterator<T>::getData() const
	{
		return this->_target->value;
	}

	template <class T>
	Node<T>* ListIterator<T>::getNext() const
	{
		return this->_target->next;
	}

	template<class T>
	class CustomList
	{
	public:
		CustomList();
		~CustomList();

		void clear();
		ListIterator<T> begin();
		ListIterator<T> end();

		void add(const T&);
		T remove();
	private:
		Node<T>* getLastNode();


		Node<T>* _listHead;
	};

	template <class T>
	CustomList<T>::CustomList()
	{
		//this->_listHead = nullptr;
		this->_listHead = new Node<T>();
	}

	template <class T>
	CustomList<T>::~CustomList()
	{
		if (this->_listHead->next != nullptr)
			clear();
		delete this->_listHead;
	}

	template <class T>
	void CustomList<T>::clear()
	{
		while (end() != begin())
			remove();
		this->_listHead->next = nullptr;
		this->_listHead->value = 0;
	}

	template <class T>
	ListIterator<T> CustomList<T>::begin()
	{
		return ListIterator<T>(this->_listHead);
	}

	template <class T>
	ListIterator<T> CustomList<T>::end()
	{
		return ListIterator<T>(getLastNode());
	}

	template <class T>
	Node<T>* CustomList<T>::getLastNode()
	{
		if (this->_listHead == nullptr)
		{
			return new Node<T>();
		}
		Node<T>* copy = this->_listHead;
		
		while (copy->next != nullptr)
			copy = copy->next;
		return copy;
	}

	template <class T>
	void CustomList<T>::add(const T& value)
	{
		if (this->_listHead == nullptr)
		{
			this->_listHead = new Node<T>();
			this->_listHead->value = value;
			return;
		}
		Node<T>* last = this->getLastNode();
		last->next = new Node<T>(value);
	}

	template <class T>
	T CustomList<T>::remove()
	{
		if (this->_listHead == nullptr)
		{
			return 0;
		}
		Node<T>* copy = this->_listHead;
		
		while (copy->next->next != nullptr)
			copy = copy->next;
		T result = copy->next->value;

		delete copy->next;
		copy->next = nullptr;
		return result;
	}
}