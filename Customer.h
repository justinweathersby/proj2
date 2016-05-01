/*
* Customer.h
* Project 7
* Zack Weathersby
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

class Customer{
    private:
        int customerID;
        int transactionTime;
    public:
        int arrivalTime;
        int tolerateTime;
        Customer();
		Customer(int);
		~Customer();
		void genTransactionTime();
		void genTolerance();
		int getTransactionTime();
		int getTolerance();
		int getCustomerID();
};
#endif