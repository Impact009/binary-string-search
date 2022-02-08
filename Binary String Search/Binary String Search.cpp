// Binary String Search.cpp : Defines the entry point for the console application.
// This program is a driver for testing the binarySearch function.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Function prototypes
void selectionSort(string [], int);
int binarySearch(const string [], int, string);

int main()
{
	// Define local variables.
	char reply = 'n';

	// Program information.
	cout << "Binary String Search by David Truong (impact009.com)\n\n"

		 << "This program is a driver for the binarySearch function that searches an array\n"
		 << "of strings. It requires a name in \"last name, first name\" format.\n\n"

	// Ask the user if he or she wants to enter informaion.
		 << "Would you like to test the binarySearch function? (y/n) ";
	cin  >> reply;

	if (reply == 'y' || reply == 'Y')
	{
		do
		{
			// An array with names.
		    const int NUM_NAMES = 20;
			string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
									   "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
									   "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
									   "Looney, Joe", "Wolfe, Bill", "James, Jean",
									   "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
									   "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
									   "Pike, Gordon", "Holland, Beth"};

			int result;  // Holds the search result.
			string name; // Holds a name to search.

			// Clear the screen for output.
			system("cls");

			// Get a name to search.
			cin.ignore();
			cout << "Enter the name you wish to search for (Last Name, First Name): ";
			getline(cin, name);
			cout << endl;

			// Sort the values.
			selectionSort(names, NUM_NAMES);

			// Search for the name.
			result = binarySearch(names, NUM_NAMES, name);

			// Display the results of the search.
			if (result == -1)
				cout << "That name does not exist within the array.";
			else
				// Otherwise, result contains the subscript of the specified name within the array.
				cout << "That name is found at element "  << result << " within the array.";

			// Does the user want to do this again?
			cout << "\n\nWould you like to repeat this program? (y/n) ";
			cin  >> reply;
		} while (reply == 'y' || reply == 'Y');
	}
	cout << "\nHave a great day!\n\n";
	return 0;
}

void selectionSort(string array[], int size)
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

int binarySearch(const string array[], int numElems, string value)
{
	int first = 0,			 // First array element.
		last = numElems - 1, // Last array element.
		middle,				 // Midpoint of the search.
		position = -1;		 // Position of the search value.
	bool found = false;		 // Flag.

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate the midpoint.
		
		if(array[middle] == value)	 // If the value is found at the middle.
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value ) // If the value is in the lower half.
			last = middle - 1;
		else
			first = middle + 1;			 // If the value is in the upper half.
	}
	return position;
}