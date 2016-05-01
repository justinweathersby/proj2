/*
 * Main.C
 * Project 7
 * Zack Weathersby
 */
#include <iostream>
#include "teller.h"
#include "manager.h"
#include "bank.h"
#include "Customer.h"
#include "goodTeller.h"
#include "badTeller.h"
using namespace std;


int main() {
    bank a;
    a.run();
    
    cout << endl << "Simulation is complete. Report to follow..." << endl << endl;
    cout << "Number of customers that entered the bank: " << a.totalCusts << endl;
    cout << "Number of customers that were served: " << (a.custHBGT + a.custHBBT +
        a.custHBM)<< endl;
    cout << "Number of customers served by good tellers: " << a.custHBGT << endl;
    cout << "Number of customers served by bad tellers: " << a.custHBBT << endl;
    cout << "Number of customers served by the manager: " << a.custHBM << endl;
    cout << "Number of customers forced to leave before being served: " << a.custLeft << endl;
    cout << "Number of good teller breaks: " << a.numGTB << endl;
    cout << "Number of bad teller breaks: " << a.numBTB << endl;
    cout << "Bank score was " << a.getScore() << endl;
    return 0;
    
}