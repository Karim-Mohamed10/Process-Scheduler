#pragma once
#include "process.h"
#include "Scheduler.h"
#include "Data-Structures/Data-Structures/LinkedQueue.h"
#include "Data-Structures/Data-Structures/LinkedList.h"
#include "Data-Structures/Data-Structures/priorityQueue.h"
#include "Data-Structures/Data-Structures/PrioQueueADT.h"

#include <iostream>
#include<chrono>
#include<thread>

UI::UI(Scheduler* sch)
{
	Sc = sch;
	
}

void UI::askMode()
{
	cout << "Enter the mode you want to run in" << endl;
	cout << "Enter 1 for Interactive mode" << endl;
	cout << "Enter 2 for Step-by-Step mode" << endl;
	cout << "Enter 3 for Silent mode" << endl;
	cout << "Enter 4 for Exit" << endl;
	cin >> mode;

}
int UI::Returnmode()
{
	return mode;
}
void UI::Output(LinkedQueue<process>& BLK, LinkedQueue<process>TRM, FCFS* Fp, RR* Rp, SJF* Sp)
{

	switch (Returnmode())
	{
	case 1:
		InteractiveMode(Sc->BLKK, Sc->TRMM, Sc->FCFSProcessor, Sc->RRProcessor, Sc->SJFProcessor);
		break;
	case 2:
		StepByStepMode(Sc->BLKK, Sc->TRMM, Sc->FCFSProcessor, Sc->RRProcessor, Sc->SJFProcessor);
		break;
	case 3:
		SilentMode();
		break;
	case 4:
		exit(0);
	default:
		break;
	}
}


void UI:: RUN(LinkedQueue<process> &BLK, LinkedQueue<process>TRM, FCFS* Fp, RR* Rp, SJF* Sp)
{
	Sc->NEWW.Print();
	cout << "Current Timestep:";
	cout << Sc->getTimestep() << endl;
	cout << "--------------------  RDY Processes  --------------------" << endl;
	for (int i = 0; i < Sc->getNF(); i++)
	{
		FCFS F = Fp[i];
		cout << "Processor " << i + 1 << "[FCFS]: " << Sc->FCFSProcessor->queue.getsize() << "RDY:";
		F.queue.Print();
	}
	for (int i = 0; i < Sc->getNS(); i++)
	{
		SJF S = Sp[i];
		cout << "Processor " << i + 1 << "[SJF]: " << S.queue.getsize() << "RDY:";

		S.queue.Print();
	}
	for (int i = 0; i < Sc->getNR(); i++)
	{
		RR R = Rp[i];
		cout << "Processor " << i + 1 << "[RR]: " << R.queue.getsize() << "RDY:";

		R.queue.Print();
	}
	cout << "--------------------  BLK Processes  --------------------" << endl;
	cout <<  "BLK:";
	Sc->BLKK.Print();
	cout << "--------------------  RUN Processes  --------------------" << endl;

	cout << "--------------------  TRM Processes  --------------------" << endl;
	cout << Sc->getTRMcounter() << "TRM:";
	Sc->printTRMM();

	
}
void UI::InteractiveMode(LinkedQueue<process>& BLK, LinkedQueue<process>TRM, FCFS* Fp, RR* Rp, SJF* Sp)
{
	RUN(Sc->BLKK, Sc->TRMM, Sc->FCFSProcessor, Sc->RRProcessor, Sc->SJFProcessor);

	getchar();
}
void UI::StepByStepMode(LinkedQueue<process>& BLK, LinkedQueue<process>TRM, FCFS* Fp, RR* Rp, SJF* Sp)
{
	RUN(Sc->BLKK, Sc->TRMM, Sc->FCFSProcessor, Sc->RRProcessor, Sc->SJFProcessor);
	std::cout.flush();
	this_thread::sleep_for(chrono::milliseconds(1000));

}
void UI::SilentMode()
{

	if (!Printed) {
		std::cout << "Silent Mode" << endl;
		std::cout << "Simulation Starts..." << endl;
		std::cout << "Simulation ends, Output file created" << endl;
		Printed = true;
	}


}
bool UI::getPrinted() const
{
	return Printed;
}

