/*
 * badTeller.h
 * Project 7
 * Zack Weathersby
 */
 #include <iostream>
 #include "teller.h"
 using namespace std;
 
 #ifndef _BADTELLER_H_
 #define _BADTELLER_H_

 class badTeller: public teller
 {
     public:
        badTeller();
        ~badTeller();
        void setState(string);
        string getState();
        int stateTime;
        int nextBreakTimeBad;
 };
 #endif