#pragma once
template < typename T>
class Node
{
private:
	T item; // A data item
	Node<T>* next; // Pointer to next node
public:
	Node();
	Node(const T& iItem);
	Node(const T& iItem, Node<T>* nextNodePtr);
	void setItem(const T& iItem);
	virtual void setNext(Node<T>* nextNodePtr);
	T getItem() const;
	virtual Node<T>* getNext() const;
	friend std::ostream& operator<<(std::ostream&, const Node<T>&);
}; // end Node


template < typename T>
Node<T>::Node()
{
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& iItem)
{
	item = iItem;
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& iItem, Node<T>* nextNodePtr)
{
	item = iItem;
	next = nextNodePtr;
}
template < typename T>
void Node<T>::setItem(const T& iItem)
{
	item = iItem;
}

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T Node<T>::getItem() const
{
	return item;
}

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}