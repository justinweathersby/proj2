/*
 * badTeller.C
 * Project 7
 * Zack Weathersby
 */
 #include "badTeller.h"
 #include <iostream>
 
 using namespace std;
 
 badTeller::badTeller()
 {
     setState(idle);
     stateTime = 0;
     nextBreakTimeBad = 600;
 }
 badTeller::~badTeller(){};
 
 string badTeller::getState() {return state;}
 
 void badTeller::setState(string str)
 {
     if(str.compare(busy) != 0 && str.compare(idle) !=0 && str.compare(rest) !=0)
        cout << " Incorrect state. Must be a valid state (Busy, Idle, or Rest) " << endl;
     else
        state = str;
 }
 