#pragma once
#include"Scheduler.h"

	Scheduler::Scheduler()
	{
		RDYListCounter = 0;
		timestep = 0;
		TRMcounter = 0;
		
	}
	int Scheduler::getTimestep()
	{
		return timestep;
	}
	void Scheduler::setTRMcounter()
	{
		TRMcounter++;
	}
	int Scheduler::getTRMcounter()
	{
		return TRMcounter;
	}
	int Scheduler::getRDYListCounter()
	{
		return RDYListCounter;
	}
	int Scheduler::getNF()
	{
		return NF;
	}
	int Scheduler::getNS()
	{
		return NS;
	}
	int Scheduler::getNR()
	{
		return NR;
	}
	void Scheduler::setBLK(process y)
	{
		BLKK.enqueue(y);
		BLKc++;
	}
	void Scheduler::removeBLK(process y)
	{
		BLKK.dequeue(y);
		BLKc--;
	}
	void Scheduler::setTRM(process y)
	{
		TRMM.enqueue(y);
		TRMcounter++;
	}
	void Scheduler::removeTRM(process y)
	{
		TRMM.dequeue(y);
		TRMcounter--;
	}
	int Scheduler::getblkc()
	{
		return BLKc;
	}
	void Scheduler::printBLKK()
	{
		BLKK.Print();
	}
	void Scheduler::printTRMM()
	{
		TRMM.Print();
	}
	void Scheduler::LoadFunction()
	{
			ifstream file;
			file.open("inputfile.txt");
			file >> NF >> NS >> NR;
			file >> TS;
			file >> RTF >> MAXW >> STL >> FP;
			file >> M; // to know the total number of processes

			FCFSProcessor = new FCFS[NF]; // processor to be changed later to FCFS cause its array of ptrs
			SJFProcessor = new SJF[NS];  // processor to be changed later to SJF cause its array of ptrs
			RRProcessor = new RR[NR];   // processor to be changed later to RR cause its array of ptrs
			for (int i = 0; i < NF; i++)
			{
				FCFSProcessor[i].setSch(this);
				ProcessorQueue.enqueue(&FCFSProcessor[i]);
			}
			for (int i = 0; i < NS; i++)
			{
				SJFProcessor[i].setSch(this);
				ProcessorQueue.enqueue(&SJFProcessor[i + NF]);
			}
			for (int i = 0; i < NR; i++)
			{
				RRProcessor[i].setSch(this);
				ProcessorQueue.enqueue(&RRProcessor[i + NS + NF]);
			}
			for (int i = 0; i < M; i++)
			{
				process x;
				int a, b, c, d;
				file >> a >> b >> c >> d;
				x.setAT(a);
				x.setPID(b);
				x.setCT(c);
				x.setN(d);
				for (int i = 0; i < d; i++)
				{
					int g, h;
					char s, t, r;
					file >> s >> g >> t >> h >> r;
					x.SetIO(g, h);
				}
				NEWW.enqueue(x);
			}
			file.close();
	}
	LinkedQueue<process> Scheduler::BLKList()
	{
		return BLKK;
	}
	void Scheduler::BLKTORDY(int& d)  //from block state to ready state
	{
		if (d = (NF + NS + NR))
		{
			d = 0;
		}
		int s = rand() % (100 - 1 + 1) + 1;
		if (s < 10)
		{
			process z;
			BLKK.dequeue(z);
			MoveTORDY(d, z);
		}
	}
	void Scheduler::MoveTORDY(int& index, process x)  //from newstate to ready state
	{
		int i = index;   //index->timestep
		if (index = (NF + NS + NR))
		{

			index = 0;
			i = index;
		}
		if (i < NF)
		{
			FCFSProcessor[i].addprocess(x);
			x.setProcessState(RDY);
			RDYListCounter++;
			i++;
		}
		else if (i >= NF && i < (NS + NF))
		{
			SJFProcessor[i - NF].addprocess(x);
			x.setProcessState(RDY);
			RDYListCounter++;
			i++;
		}
		else if (i >= NF + NS && i < (NS + NF + NR))
		{
			RRProcessor[i - NF - NS].addprocess(x);
			x.setProcessState(RDY);
			RDYListCounter++;
			i++;
		}
		index++;
	}



	void Scheduler::SimulatorFunction()
	{
		int indexx =0 ;
		process xg;
		UI uiobj(this);
		LoadFunction();
		int l=0;
		uiobj.askMode();
		while (TRMcounter !=M)
		{
			for (int i = 0; i < NF; i++)
			{
				FCFSProcessor[i].schedulingalgo();
			}
			for (int i = 0; i < NS; i++)
			{
				SJFProcessor[i].schedulingalgo();
			}
			for (int i = 0; i < NR; i++)
			{
				RRProcessor[i].schedulingalgo();
			}
			NEWW.getfront(xg);
			while (xg.getAT() == timestep)  // to change the error later
			{
				MoveTORDY(indexx, xg);
				NEWW.dequeue(xg);
				NEWW.getfront(xg);
				indexx++;
			}
			indexx++;
			if (indexx = (NF + NS + NR))
			{
				indexx = 0;
			}
			timestep++;
			BLKTORDY(indexx);
			l++;
			
			uiobj.Output(BLKK, TRMM, FCFSProcessor, RRProcessor, SJFProcessor);
		}
	}
	
	Scheduler::~Scheduler()
	{}

