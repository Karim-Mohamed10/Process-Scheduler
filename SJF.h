#pragma once
#include "Processor.h"
#include"Data-Structures/Data-Structures/priorityQueue.h"
#include"process.h"
class SJF :public Processor
{

	int time = 0;
public:
	PriorityQueue<process>queue;
	void addprocess(process p);
	void schedulingalgo();
};

