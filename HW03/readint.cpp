///
//By: Jesse Domingo 
///CS 273 
// HW 03_1
// 6/4/2018
//



#include "readint.h"
#include <stdexcept>
#include<iostream>

using namespace std;

int read_int(const std::string &prompt, int low, int high)
{

	cin.exceptions(ios_base::failbit | ios::badbit);
	int num = 0;
	while (true)
	{
		// gets user input 
		try {
		
			cout << prompt;
			cin >> num;
			// throws and cathces if out of range 
			if (num < low || num > high)
			{
				throw range_error("Number is out of Range");
			}
			else
				return num;

		}
		// catches if string input 
		catch (ios_base::failure& ex) {
			cout << "Bad numeric string -- tryagain\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		//catches range error
		catch (range_error  &re) {
			cout << re.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		//catches unforseen other errors 
		catch (...)
		{
			cout << "Opps somthing went wrong" << endl; 
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}
}

