#include "Processor.h"

void Processor::setSch(Scheduler* sch)
{
	ptr = sch;
}

Processor::Processor()
{
	run = NULL;
	ptr = NULL;
}
