/*
 * bank.h
 * Project 7
 * Zack Weathersby
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Customer.h"
using namespace std;

#ifndef BANK_H
#define BANK_H

class bank {
    private:
        int score;
        string closed;
        string open;
        string state;
    public:
        bank();
        ~bank();
        int clock;
        int numGTB;
        int numBTB;
        int custHBGT;
        int custHBBT;
        int custHBM;
        int custLeft;
        int totalCusts;
        int getScore();
        string getState();
        void run();
        void startWork();
        void makeCust(int);
        void decScore();
        void incScore();
        void setState(string str);
        
};
#endif