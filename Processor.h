#pragma once
#include"process.h"
class Scheduler;
class Processor
{
public:
	Scheduler* ptr;
	process* run;
	virtual void addprocess(process p) = 0;
	virtual void schedulingalgo() = 0;
	virtual void setSch(Scheduler*);
	Processor();
};

 