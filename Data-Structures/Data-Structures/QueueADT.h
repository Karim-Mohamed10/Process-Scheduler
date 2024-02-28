#pragma once
template<class T>
class QueueADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool enqueue(const T& newEntry) = 0;
	virtual bool dequeue(T& FrontEntry) = 0;
	virtual bool getfront(T& FrontEntry) const = 0;
	virtual void Print() = 0;
	virtual ~QueueADT() { }
};
