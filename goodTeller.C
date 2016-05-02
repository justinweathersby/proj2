#include "goodTeller.h"
#include "teller.h"
#include <iostream>
using namespace std;

goodTeller::goodTeller() : teller()
{
	 setState("idle");
	 stateTime = 0;
	 nextBreakTime = 3600;
}

goodTeller::~goodTeller() {}

void goodTeller::setState(string str)
{
	 if(str.compare(busy) != 0 && str.compare(idle) != 0 && str.compare(rest) != 0)
	 	cout << "Invalid state for Teller.  Set to one of the following: busy, idle, or rest." << endl;
	 else
	 	state = str;
}

string goodTeller::getState() { return state; };
