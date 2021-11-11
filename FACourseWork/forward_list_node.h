#pragma once

template <typename T>
class ListNode
{
	template <typename U> friend class ForwardList;

private:
	T	_data;
	ListNode* _next;

public:
	ListNode(const T& value);
	~ListNode() = default;
};

template <typename T>
ListNode<T>::ListNode(const T& value)
{
	this->_data = value;
	this->_next = nullptr;
}

