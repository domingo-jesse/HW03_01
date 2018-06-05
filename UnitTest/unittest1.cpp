#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"
#include <stdexcept> 
#include <iostream>
#include <fstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{
	TEST_CLASS(READINT_TEST)
	{
	public:

		TEST_METHOD(TestCase1) // Test case 1: invalid input
		{
			ifstream ss("..\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);
			cin.rdbuf(orig_cin);
			ss.close();
		}


		TEST_METHOD(TestCase2) //invalid argument
		{
			auto func = []() {
				read_int("Myprompt: ", 5, 1);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3) //returns 3
		{
			istringstream ss("-3\n5\n10\n-2\n3");
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);
			cin.rdbuf(orig_cin);
			ss.clear();

		}

		TEST_METHOD(TestCase4) //For invalid argument
		{

			auto func = []() {
				read_int("My prompt: ", 0, 0);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};



};