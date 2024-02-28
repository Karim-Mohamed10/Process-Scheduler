#pragma once
#include "process.h"
#include "Data-Structures/Data-Structures/LinkedQueue.h"
#include "Data-Structures/Data-Structures/LinkedList.h"
#include "Data-Structures/Data-Structures/priorityQueue.h"
#include "Data-Structures/Data-Structures/PrioQueueADT.h"
#include "FCFS.h"
#include "RR.h"
#include "SJF.h"
#include <iostream>
class Scheduler;
using namespace std;
class UI
{
private:
	Scheduler* Sc;
	int mode = 0;
	bool Printed;
public:
	UI(Scheduler*);
	void askMode();

	int Returnmode();


	void InteractiveMode(LinkedQueue<process>& BLK, LinkedQueue<process> TRM, FCFS*Fp, RR* Rp, SJF* Sp);

	void RUN(LinkedQueue<process>& BLK, LinkedQueue<process>TRM, FCFS* Fp, RR* Rp, SJF* Sp);

	void StepByStepMode(LinkedQueue<process>& BLK, LinkedQueue<process> TRM, FCFS* Fp, RR* Rp, SJF* Sp);


	void SilentMode();

	bool getPrinted() const;

	void Output(LinkedQueue<process>& BLK, LinkedQueue<process>TRM, FCFS* Fp, RR* Rp, SJF* Sp);

};
