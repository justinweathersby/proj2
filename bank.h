#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#ifndef BANK_H
#define BANK_H

class goodTeller; //Forward Declaration
class badTeller; //Forward Declaration
class manager;

class bank {
private:
	int score;
	string closed;
	string open;
	string state;
	vector<badTeller> *badTellerVector;
	vector<goodTeller> *goodTellerVector;
	vector<manager> *managerVector;
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
