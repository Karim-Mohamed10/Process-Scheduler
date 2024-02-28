#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"Process.h"
#include"Processor.h"
#include"Data-Structures/Data-Structures/LinkedList.h"
#include"Data-Structures/Data-Structures/LinkedQueue.h"
#include"Data-Structures/Data-Structures/ListADT.h"
#include"Data-Structures/Data-Structures/Node.h"
#include"Data-Structures/Data-Structures/PNode.h"
#include"Data-Structures/Data-Structures/PrioQueueADT.h"
#include"Data-Structures/Data-Structures/priorityQueue.h"
#include"Data-Structures/Data-Structures/QueueADT.h"
#include"FCFS.h"
#include"SJF.h"
#include"RR.h"
#include "UI.h"
class Scheduler
{
private:
	int NF, NS, NR; //number of processors
	int TS; //timeslice for RR
	int RTF, MAXW, STL, FP; // will be needed in phase 2
	int M;// number of processors & input file contain M lines
	int BLKc;
	 //Array for each processors


	int timestep, RDYListCounter, TRMcounter;
	LinkedQueue<Processor*> ProcessorQueue;


	FCFS object1;
	SJF object2;
	RR object3;
	//UI ui;
public:
	FCFS* FCFSProcessor;
	SJF* SJFProcessor;
	RR* RRProcessor;
	LinkedQueue<process> NEWW;
	LinkedQueue<process> BLKK; //Block List
	LinkedQueue<process> TRMM; //Terminate List
	Scheduler();
	int getTimestep();
	void setTRMcounter();
	void BLKTORDY(int& d);
	int getTRMcounter();
	int getRDYListCounter();
	int getNF();
	int getNS();
	int getNR();
	void setBLK(process y);
	void removeBLK(process y);
	void setTRM(process y);
	void removeTRM(process y);
	int getblkc();
	void printBLKK();
	void printTRMM();
	void LoadFunction();
	LinkedQueue<process> BLKList();
	void MoveTORDY(int& index, process x); //from newstate to ready state
	void SimulatorFunction();
	~Scheduler();
	
};
