/*
 * teller.h
 * Project 7
 * Zack Weathersby
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef _TELLER_H_
#define _TELLER_H_

class teller{
    public:
        virtual void setState(string) = 0;
        virtual string getState() = 0;
        
    protected:
        teller();
        ~teller();	
        string state;
        string idle;
        string rest;
        string busy;
};
#endif