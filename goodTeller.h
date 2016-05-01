/*
* goodTeller.h
* Project 7
* Zack Weathersby
*/
#include <iostream>
#include "teller.h"
using namespace std;

#ifndef GOODTELLER_H
#define GOODTELLER_H

class goodTeller: public teller
{
    public:
		goodTeller();
		~goodTeller();
		void setState(string);
		string getState();
		int stateTime;
		int nextBreakTime;
};
#endif