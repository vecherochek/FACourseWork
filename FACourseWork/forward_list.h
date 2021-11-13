#pragma once

#include "forward_list_node.h"
#include <ostream>

template <typename T>
class	ForwardList
{
private:
	ListNode<T>* _head;
	ListNode<T>* _tail;
	size_t		_length;

	ListNode<T>* _createNewNode(const T& value);

public:
	class iterator
	{
	private:
		ListNode<T>* _ptr;
	public:
		iterator(): _ptr(nullptr){}
		iterator(ListNode<T>* ptr): _ptr(ptr){}
		iterator(const iterator& iter): _ptr(iter._ptr){}
		~iterator() = default;

		T& operator*()
		{
			return _ptr->_data;
		}
		bool operator==(const iterator& rhs) const
		{
			return this->_ptr == rhs._ptr;
		}
		bool operator!=(const iterator& rhs) const
		{
			return this->_ptr != rhs._ptr;
		}
		iterator& operator=(const iterator& rhs)
		{
			this->_ptr = rhs._ptr; 
			return (*this);
		}
		iterator operator++(int)
		{
			iterator copy = *this; 
			this->_ptr = this->_ptr->_next;
			return copy;
		}
	};

	ForwardList();
	~ForwardList();

	iterator	end() const;
	iterator	begin() const;
	iterator	find(const T& value);
	size_t		size() const;
	bool		empty() const;
	void		clear();
	void		insert(const T& value);
	void		remove(const T& value);
};

template <typename T>
ForwardList<T>::ForwardList()
{
	_head = nullptr;
	_tail = nullptr;
	_length = 0;
}

template <typename T>
ForwardList<T>::~ForwardList()
{
	clear();
}

template <typename T>
typename ForwardList<T>::iterator ForwardList<T>::begin() const
{
	return iterator(_head);
}

template <typename T>
typename ForwardList<T>::iterator ForwardList<T>::end() const
{
	return iterator(nullptr);
}

template <typename T>
typename ForwardList<T>::iterator ForwardList<T>::find(const T& value)
{
	ForwardList<T>::iterator iter;

	iter = begin();
	while (iter != end())
	{
		if (*iter == value)
			return (iter);
		iter++;
	}
	return (end());
}

template <typename T>
ListNode<T>* ForwardList<T>::_createNewNode(const T& value)
{
	ListNode<T>* new_node = nullptr;

	new_node = new ListNode<T>(value);
	if (!new_node)
		return (nullptr);
	return (new_node);
}

template <typename T>
size_t ForwardList<T>::size() const
{
	return (_length);
}

template <typename T>
bool ForwardList<T>::empty() const
{
	return (_head == nullptr);
}

template <typename T>
void ForwardList<T>::clear()
{
	ListNode<T>* temp_ptr;

	if (_head != nullptr)
	{
		while (_head != nullptr)
		{
			temp_ptr = _head;
			_head = _head->_next;
			delete temp_ptr;
		}
		_head = nullptr;
		_tail = nullptr;
		_length = 0;
	}
}

template <typename T>
void ForwardList<T>::insert(const T& value)
{
	ListNode<T>* new_node = nullptr;

	new_node = _createNewNode(value);
	if (new_node != nullptr)
	{
		if (!_head)
			_head = new_node;
		else
			_tail->_next = new_node;
		_tail = new_node;
		_length++;
	}
}

template <typename T>
void ForwardList<T>::remove(const T& value)
{
	ListNode<T>* temp = _head;
	ListNode<T>* prev = nullptr;

	if (temp && temp->_data == value)
	{
		_head = temp->_next;
		delete temp;
	}
	else
	{
		while (temp && temp->_data != value)
		{
			prev = temp;
			temp = temp->_next;
		}
		if (temp)
		{
			prev->_next = temp->_next;
			delete temp;
		}
	}
}