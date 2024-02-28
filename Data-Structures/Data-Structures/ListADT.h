#pragma once
template<typename T>
class listADT
{
public:
	virtual void PrintList() = 0;
	virtual void ReadList() = 0;
	virtual void InsertEnd(const T&) = 0;
	virtual	void InsertBeginning(const T&) = 0;
	virtual void DeleteAll() = 0;
	virtual bool DeleteNode(const T&) = 0;
	virtual T& traverselist(const T&) = 0;
	virtual ~listADT() { }
};
