#pragma once
#include "Processor.h"
#include"process.h"
#include"Data-Structures/Data-Structures/LinkedQueue.h"
#include<string>
class FCFS : public Processor
{
	int Time = 0;
public:
	LinkedQueue<process>queue;
	void addprocess(process p);
	void schedulingalgo();

};