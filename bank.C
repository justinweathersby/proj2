#include "bank.h"
#include "goodTeller.h"
#include "badTeller.h"
#include "manager.h"
#include "Customer.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <queue>
using namespace std;


class Compare {
public:
	bool operator()(const Customer i, const Customer j)
	{
		int customer1 = i.arrivalTime;
		int customer2 = j.arrivalTime;
		return customer1 > customer2;

	}
};


priority_queue<Customer, vector<Customer>, Compare> custQue;


bank::bank() {
	srand(time(0));
	open = "open";
	closed = "closed";
	score = 0;
	clock = 0;
	numGTB = 0;
	numBTB = 0;
	custHBGT = 0;
	custHBBT = 0;
	custHBM = 0;
	custLeft = 0;
	totalCusts = 0;

	managerVector = new vector<manager>(1);
	goodTellerVector = new vector<goodTeller>(5);
	badTellerVector = new vector<badTeller>(10);
}
bank::~bank() { };

string bank::getState() { return state; };

int bank::getScore() { return score; };

void bank::decScore() {
	score = score - 10;
};
void bank::incScore() {
	score = score + 10;
}
void bank::setState(string x)
{
	if (x.compare(open) == 0)
		state = open;
	if (x.compare(closed) == 0)
		state = closed;
	if (x.compare(open) != 0 && x.compare(closed) != 0)
		cout << "Invalid state of operation" << endl;
};



void bank::makeCust(int x)
{
	Customer cust(x);
	cust.arrivalTime = cust.arrivalTime + clock;
	cust.tolerateTime = cust.tolerateTime + clock;
	custQue.push(cust);
	totalCusts++;
}
void bank::startWork() {
	if (!custQue.empty())
	{
		Customer a = custQue.top();
		if (a.tolerateTime == clock)
		{
			custQue.pop();
			decScore();
			custLeft++;
			cout << "Customer has grown impatient and left the bank." << endl;
		}
	}
	for (size_t i = 0; i < goodTellerVector->size(); i++)
	{
		if (goodTellerVector->at(i).stateTime == clock)
			goodTellerVector->at(i).setState("idle");
		if (goodTellerVector->at(i).getState().compare("idle") == 0)
		{
			if (!custQue.empty())
			{
				cout << "Customer is waiting" << endl;
				Customer b = custQue.top();
				goodTellerVector->at(i).setState("busy");
				cout << "Good teller is with a customer. " << endl;
				int transactionClock = b.getTransactionTime();
				cout << "Transaction time was " << transactionClock << "s. \n" << endl;
				goodTellerVector->at(i).stateTime = clock + transactionClock;
				incScore();
				custQue.pop();
				custHBGT++;
			}
		}
		if (custQue.empty() && (clock % goodTellerVector->at(i).nextBreakTime == 0))
		{
			goodTellerVector->at(i).setState("rest");
			goodTellerVector->at(i).stateTime += 300;
			numGTB++;
		}
	}
	for (size_t j = 0; j < badTellerVector->size(); j++)
	{
		if (badTellerVector->at(j).stateTime == clock)
			badTellerVector->at(j).setState("idle");
		if (badTellerVector->at(j).getState().compare("idle") == 0)
		{
			if (!custQue.empty())
			{
				Customer c = custQue.top();
				badTellerVector->at(j).setState("busy");
				cout << "Customer in line." << endl;
				cout << "Bad teller is with a customer. " << endl;

				int transactionClockBad = (c.getTransactionTime()) * 2;
				cout << "Transaction time was " << transactionClockBad << "s. \n" << endl;
				badTellerVector->at(j).stateTime = transactionClockBad + clock;
				incScore();
				custQue.pop();
				custHBBT++;
			}
			if (custQue.empty() && managerVector->at(0).getState().compare("office") == 0)
			{
				int t = rand() % 10 + 1;
				if (t < 6)
				{
					badTellerVector->at(j).setState("rest");
					badTellerVector->at(j).stateTime += 600;
					numBTB++;
				}
				else {
					badTellerVector->at(j).setState("idle");
					badTellerVector->at(j).stateTime += 30;
				}
			}
			if (custQue.empty() && (clock % badTellerVector->at(j).nextBreakTimeBad == 0))
			{
				badTellerVector->at(j).setState("rest");
				badTellerVector->at(j).stateTime += 600;
				numBTB++;
			}
		}
	}
	for (size_t m = 0; m < managerVector->size(); m++)
	{
		if (clock % 3600 == 0)
		{
			managerVector->at(m).setState("visit");
			cout << "Manager is at the teller: " << endl;
			if (!custQue.empty())
			{
				Customer c = custQue.top();
				custQue.pop();
				incScore();
				cout << "Manager is with a customer... " << endl;
				cout << "Manager's transaction clock with customer was " << c.getTransactionTime() << endl;
				custHBM++;
				managerVector->at(m).setState("office");
			}
			else
				managerVector->at(m).setState("office");
		}
	}
};
void bank::run()
{
	cout << " Starting Bank Simulation...... " << endl;
	while (clock < 28800)
	{
		setState(open);
		int randCustTime = 59 + (rand() % 59 + 1);
		if (clock % randCustTime == 0)
			makeCust(clock);
		startWork();
		clock++;
	}
	setState(closed);
	if (!custQue.empty() && (getState().compare(closed) == 0))
	{
		int custLB = 0;
		while (!custQue.empty())
		{
			custQue.pop();
			decScore();
			custLB++;
		}
		cout << custLB << "Customers were forced to leave without being served because the bank is closing" << endl;
		custLeft = custLeft + custLB;
	}
}
