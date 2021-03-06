#pragma once
#ifndef SORTING_H_

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;

#pragma region defines

#ifdef __linux__// Linux
	#define CLEAR system("clear"); // Clear the comand prompt (screen)
	#define SLEEP sleep(1); // Make program pause for one sec
	#define KEYPRESS cout << "Press [Enter] to continue..."; cin.ignore(); // "Press [Enter] key to continue..."
	#define BOLD cout << "\033[1m";// Make text bold
	#define RED cout << "\033[31m";
	#define DEFCOLOR cout << "\033[39m";
#elif _WIN32// Windows
	#include <windows.h>	// Windows features
	#define CLEAR system("cls"); // Clear the comand prompt (screen)
	#define SLEEP Sleep(1000); // Make program pause for one sec
	#define KEYPRESS cout << "Press any key to continue..."; _getch(); // "Press any key to continue..."
	#define BOLD ""
	#define RED cout << "";
	#define DEFCOLOR ""
#endif

#define LINEBREAK cout << endl;// Line break
#define DEBUG false // For debugging
#define CHECKPOINT false // Enables SLEEP

#pragma endregion

#pragma region Text Color
namespace Color
{
	enum Code
	{
		FG_RED = 31,
		FG_GREEN = 32,
		FG_BLUE = 94,
		FG_DEFAULT = 39,
		BG_RED = 41,
		BG_GREEN = 42,
		BG_BLUE = 44,
		BG_DEFAULT = 49
	};
	class Modifier
	{
		Code code;
	public:
		Modifier(Code pCode) : code(pCode) {}
		friend std::ostream&
			operator<<(std::ostream& os, const Modifier& mod)
		{
			return os << "\033[" << mod.code << "m";
		};

	};
}
#pragma endregion

#pragma region SortingClass
// Sorting algorithm class
class Sorting{
	public:
		// Introsort Algorithms
		void introsort(vector<int>&);
		void introsort_Quick(vector<int>&, int, int, int);		
		void insertionSort(vector<int>&);
		int partition(vector<int>&, int, int);		
		int medianOfThree(int, int, int);
};

#pragma endregion

#pragma region GeneralFuncs
// Gets the case file 
string getCaseFile();
// Get input from file
string getFileInput(vector<int>&);
// Swap int values 
void swapValue(vector<int>&, int, int);
// Print sorted array
void printArray(vector<int>, int, string);
#pragma endregion

#endif