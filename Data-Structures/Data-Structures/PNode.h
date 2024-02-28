#pragma once
#include "Node.h"

// A node that has a priority

template <typename T>
class PNode :
	public Node<T>
{
private:
	int priority;
	PNode<T>* next;
public:
	PNode();
	PNode(const T&i_Item);
	PNode(const T& iItem, int p, PNode<T>* nextNodePtr = NULL);
	virtual void setNext(PNode<T>* nextNodePtr);
	virtual PNode<T>* getNext() const;
	void setPriority(int r_priority);
	int getPriority();

	
	friend std::ostream& operator<<(std::ostream&, const PNode<T>&);

};

template <typename T>
PNode<T>::PNode()
{
	priority = -1;
	next = NULL;
}

template<typename T>
PNode<T>::PNode(const T& iItem) : Node<T>(iItem)
{
	priority = -1;
	next = NULL;
}

template<typename T>
PNode<T>::PNode(const T& iItem, int p, PNode<T>* nextNodePtr) : Node<T>(iItem)
{
	priority = p;
	next = nextNodePtr;
}

template<typename T>
inline void PNode<T>::setPriority(int ipriority)
{
	priority = ipriority;
}

template <typename T>
inline int PNode<T>::getPriority()
{
	return priority;
}

template<typename T>
inline void PNode<T>::setNext(PNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template<typename T>
inline PNode<T>* PNode<T>::getNext() const
{
	return next;
}