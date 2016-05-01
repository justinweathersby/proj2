/*
* Customer.C
* Project 7
* Zack Weathersby
*/
#include "Customer.h"

Customer::Customer()
{
    arrivalTime = 60;
    genTransactionTime();
    genTolerance();
}
Customer::Customer(int x)
{
    customerID = x;
	arrivalTime = 60;
	genTransactionTime();
	genTolerance();
}

Customer::~Customer(){}

void Customer::genTolerance()
{
       	tolerateTime = 299 + (rand() % 299 + 1);
}

void Customer::genTransactionTime()
{
      	transactionTime = 599 + (rand() % 599 + 1);
}

int Customer::getTransactionTime()
{
	return transactionTime;
}

int Customer::getTolerance()
{
	return tolerateTime;
}

int Customer::getCustomerID()
{
	return customerID;
}