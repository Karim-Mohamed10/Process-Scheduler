#include"Scheduler.h"
#include"SJF.h"
void SJF::addprocess(process p)
{
	queue.smallestenqueue(p, p.getCT());
}
void SJF::schedulingalgo()
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
			queue.smallestenqueue(*run, run->getCT());
			run = NULL;
		}
		else if (50 <= z && z <= 60)
		{
			ptr->setTRM(*run);
			run = NULL;
		}

	}

}