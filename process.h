#pragma once

#include<iostream>
using namespace std;
enum state 
{ NEW,RDY, BLK, RUN,TRM,ORPH };
class process
{
private:
	int PID; // each process has unique ID
	int AT;  // ArrivalTime
	int TT;  //calculated TerminationTime -> when process finishes execution
	int CT;  //CPU Time -> time needed to run the process continually
	int TRT; // TurnARoundDuration -> total time process spends in the system from arrival to termination
	int WT;  // waiting time -> time spent without execution
	int N;   // number of time the process requests I/O
	state processstate;
	int** IO;  //array for IO
	int IOindex;
public:
	process(int id, int at, int tt, int ct)
	{
		IOindex = 0;
		setPID(id);
		setAT(at);
		setTT(tt);
		setCT(ct);
		setTRT();
		setWT();
		processstate = NEW;
		IO = new int*[N];
		for (int i = 0; i < N; i++)
		{
			IO[i] = new int[2];
		}
	}
	

	process() { processstate = NEW; IOindex = 0; }
	void SetIO(int a,int b)
	{
		IO[IOindex][0] = a;
		IO[IOindex][1] = b;
		IOindex++;
	}

	void setProcessState(state x)
	{
		processstate = x;
	}
	state GetProcessState()
	{
		return processstate;
	}

	void setPID(int a)
	{
		PID=a;
	}
	void setAT(int b)
	{
		AT=b;
	}
	void setTT(int c)
	{
		TT=c;
	}
	void setCT(int d)
	{
		 CT=d;
	}
	void setTRT()
	{
		 TRT=getTT() - getAT();
	}
	void setWT()
	{
		WT= getTRT() - getCT();
	}
	void setN(int e)
	{
		IOindex = 0;
		N = e;
		IO = new int* [N];
		for (int i = 0; i < N; i++)
		{
			IO[i] = new int[2];
		}
	}
	int getPID() const
	{
		return PID;
	}
	int getAT() const
	{
		return AT;
	}
	int getTT() const
	{
		return TT;
	}
	int getCT() const
	{
		return CT;
	}
	int getTRT() const
	{
		return TT-AT;
	}
	int getWT() const
	{
		return TRT-CT;
	}
	int getN() const
	{
		return N;
	}
	~process()
	{	}
	friend ostream& operator<<(ostream& os, const process& p)
	{
		os << p.getPID();
		return os;
	}
};