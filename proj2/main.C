/* Main
 * Project 2
 * Zack Weathersby
 */
#include <iostream>
#include <stdlib.h>
#include "xArray.h"
#include "xArray.C"

using namespace std;

int main() {
	int n; //array size
	
	cout << "Please setup the first array: " << endl;
	ReadInput();

	cout << A[n] << end;
	/* cin >> n;
	
	int * A = new int[n]; //dynamically allocated array with n values
	char a = A;

	for(int i=0; i<n; i++)
	{
		//cin >> A[i];
		getLine(cin, A);
	}
	
	cout << A[n];
	*/

	cout << "Now the second array: " << endl;
	ReadInput();

	cout << "The dot product of the two arrays is " << DotProduct(a,b,n) << endl;
}
