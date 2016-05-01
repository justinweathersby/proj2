/*
* manager.C
* Project 7
* Zack Weathersby
*/
#include "manager.h"
#include <iostream>

manager::manager()
{
	office = "office";
	visit = "visit";
	setState(office);
}

manager::~manager(){}

void manager::setState(string str)
{
	if(str.compare(visit) == 0){ state = visit; };
	if(str.compare(office) == 0){ state = office; };
	if(str.compare(visit) != 0 && str.compare(office) != 0)
	    cout << "Invalid state for manager." << endl;
}

string manager::getState() { return state; };