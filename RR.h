#pragma once
#include "Processor.h"
#include"process.h"
#include"Data-Structures/Data-Structures/LinkedQueue.h"
class RR : public Processor
{

	int timeslice;
	int remCT;
	int time = 0;
public:
	LinkedQueue<process>queue;
	void addprocess(process p);

	void schedulingalgo();

		
};