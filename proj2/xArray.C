/* xArray.C
 * Project 2
 * Zack Weathersby
 */
#include <iostream>
#include <stdlib.h>
#include "xArray.h"
using namespace std;

int* ReadInput() {
	int N;
	cin >> N; //array size
	int * A = new int[N]; //dynamically allocated array with N values

	for(int i=0; i <= N; i++)
	{
		cin >> A[i];
	}
};

int DotProduct(int* a, int* b, int length) {
	int sum = 0;

	for(int i = 0; i <= length; i++)
	{
		int x = a[i] * b[i]; //multiply array slot with each other
		sum += x; //set new sum
	}
};