#pragma once
#include "Node.h"
#include "QueueADT.h"
#include <iostream>
using namespace std;
template <typename T>
class LinkedQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int size;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frontEntry);
	bool getfront(T& frontEntry)  const;
	void Print();
	int getsize();
	~LinkedQueue();
	LinkedQueue(const LinkedQueue<T>& LQ);


};

//------------------------------------------------------------IMPLEMENTAION--------------------------------------------------------//


template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);

	if (isEmpty())
		frontPtr = newNodePtr;
	else
		backPtr->setNext(newNodePtr);

	backPtr = newNodePtr;
	size++;
	return true;
}

template <typename T>
bool LinkedQueue<T>::dequeue(T& frontEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frontEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;
	delete nodeToDeletePtr;
	size--;
	return true;

}

template <typename T>
bool LinkedQueue<T>::getfront(T& frontEntry) const
{
	if (isEmpty())
		return false;

	frontEntry = frontPtr->getItem();
	return true;
}

template<typename T>
inline void LinkedQueue<T>::Print()
{
	Node<T>* p = frontPtr;
	while (p)
	{
		cout << p->getItem() << " ";
		p = p->getNext();
	}
	cout << endl;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	T temp;
	while (dequeue(temp));
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr)
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}
template <typename T>
int LinkedQueue<T>::getsize()
{
	return size;
}