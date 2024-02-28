#include"RR.h"
#include"Scheduler.h"
void RR::addprocess(process p)
{
	queue.enqueue(p);
}
void RR::schedulingalgo()
{
	process b(0, 0, 0, 0);
	bool f = true;
	if (run == nullptr)
	{
		f = queue.getfront(b);
		run = &b;
		queue.dequeue(b);
	}
	if (f)
	{
		int z = rand() % (100) + 1;
		if (1 <= z && z <= 15)
		{
			ptr->setBLK(*run);
			run = NULL;

		}
		else if (20 <= z && z <= 30)
		{
			queue.enqueue(*run);
			run = NULL;
		}
		else if (50 <= z && z <= 60)
		{
			ptr->setTRM(*run);
			run = NULL;
		}

	}

}
