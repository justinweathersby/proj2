/*
* manager.h
* Project 7
* Zack Weathersby
*/
#include <iostream>
#include "teller.h"
using namespace std;

#ifndef _MANAGER_H_
#define _MANAGER_H_

class manager
{
    private:
        string state;
		string visit;
		string office;
    public:
        manager();
		~manager();
		void setState(string);
		string getState();
		int test;
};
#endif