///
//By: Jesse Domingo 
///CS 273 
// HW 03_1
// 6/4/2018
//
#include <iostream>

#include <stdexcept>

#include "readint.h"

using namespace std;

int main()

{

	int low, high;

	do
	{

	cout << "Enter the range of values to read.\n";

	cout << "high: " << endl;

	cin >> high;

	cout << "low: " << endl;

	cin >> low;
	
	try {
		// throws and catches invild arguments that dont make a correct range 
		if (low > high || low == high) {

			throw invalid_argument("Invaild argument");

		}
	}
		catch (invalid_argument& ia) {
			cout << "Invalid argument " << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	
		// loops it until correct input is inserted 
	} while (low > high || low == high);
	
	

	try

	{
		// calls unnpon read int fuction 
		int number = read_int("Please enter a number within the range: ", low, high);

			cout << "You entered " << number << endl;
	
	}

	// if strings are entered catches
	catch (ios_base::failure& ex) {
		cout << "Bad numeric string -- tryagain\n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	}
	// catches other unforseen error 
	catch (...)
	{
		cout << "other error" << endl; 
		cin.clear(); 
		cin.ignore(numeric_limits<int>::max(), '\n');
	}

}