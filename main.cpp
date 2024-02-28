#include <iostream>
#include<iostream>
#include "UI.h"
#include "Scheduler.h"
using namespace std;


int main() {

    /*Scheduler S;
    S.SimulatorFunction ();*/
    process* a = new process(100, 3, 4, 5);
    process* b = new process(6, 3, 4, 5);
    LinkedQueue<process*> Q;
    Q.enqueue(a);
    Q.enqueue(b);
    Q.Print();


}