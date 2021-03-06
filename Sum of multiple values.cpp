/*
[Program-1] Write a program that accepts exactly ten (10) integer numbers from the user.
When the user is done inputting these numbers, the program prints back:
(i) the sum of the 10 numbers,
(ii) the minimum value from the 10 numbers,
(iii) the maximum value from the 10 numbers.

[Program-2] Write a program that accepts an indefinite set of numbers until the user enters “-1”.
In other words, the program keeps accepting new values until the user provides a “-1”
(your program accepts all values, and discards the “-1”).
When done, the program prints back to the user:
(i) the sum of all numbers entered,
(ii) the minimum value seen across all numbers,
(iii) the maximum value across all numbers (except -1).
*/

#include "pch.h"
#include <iostream>

using namespace std;

int sum;
int maxval;
int minval;
int inputval;

int minvalchecker(int oldval, int newval);
int maxvalchecker(int oldval, int newval);
void program1();
void program2();
void playagain();

int main()
{
	playagain();
}

int minvalchecker(int oldval, int newval) {
	if (oldval > newval) {
		return newval;
	}
	else {
		return oldval;
	}
}

int maxvalchecker(int oldval, int newval) {
	if (oldval < newval) {
		return newval;
	}
	else {
		return oldval;
	}
}

void program1(int totalcount) {
	sum = 0;

	cout << endl << "This is Program-1." << endl;
	cout << "This program will accept exactly " << totalcount << " integer numbers from the user." << endl;
	cout << "Please enter your " << totalcount << " integers numbers now." << endl;

	for (int count = 0; count < totalcount; count++) {
		
		cin >> inputval; // Takes input

		sum = sum + inputval; // sum adds.
		

		if (count == 0) {
			maxval = inputval;
			
			minval = inputval;
			
		}
		minval = minvalchecker(minval, inputval);

		maxval = maxvalchecker(maxval, inputval);
	}

	cout << endl << "You have entered " << totalcount << " number of integers." << endl;
	cout << "The sum of your integers are " << sum << "." << endl;
	cout << "The minimum value that you entered is: " << minval << "." << endl;
	cout << "The maximum value that you entered is: " << maxval << "." << endl;
	cout << "Thank you for running Program-1." << endl;
	playagain();
}


void program2() {
	sum = 0;
	int totalcount = 0;

	cout << endl << "This is Program-2." << endl;
	cout << "This program accepts an indefinite set of numbers until the user enters “-1”." << endl;
	cout << "Please enter your integers numbers now." << endl;
	while (inputval != -1) {
		cin >> inputval; // Takes input

		if (inputval == -1) {
			break; //Beats the whole -1 from sum and stuff. Just get out of here directly)
		}

		if (totalcount == 0) {
			maxval = inputval; //firstval

			minval = inputval; //firstval
		
		}

		sum = sum + inputval; // sum adds.
		minval = minvalchecker(minval, inputval);		
		maxval = maxvalchecker(maxval, inputval);
	
		totalcount++; //reset.
	}
	cout << endl << "You have entered: " << inputval << ", here are your results." << endl;
	cout << "You have entered " << totalcount << " number of integers." << endl;
	cout << "The sum of your integers are " << sum << "." << endl;
	cout << "The minimum value that you entered is: " << minval << "." << endl;
	cout << "The maximum value that you entered is: " << maxval << "." << endl;
	cout << "Thank you for running Program-2." << endl;
	playagain();

}

void playagain() {
	cout << endl << "Enter 1 to access Program-1." << endl;
	cout << "Enter 2 to access Program-2." << endl;
	cout << "Enter 3 to access Program-1 with an amount of numbers set by you." << endl;
	cout << "Enter any other number to exit" << endl;

	cin >> inputval;
	if (inputval == 1) {
		program1(10);
	}
	else if (inputval == 2) {
		program2();
	}
	else if (inputval == 3) {
		cout << "Thank you for trying this function." << endl;
		cout << "Please enter the amount of integers you wish to enter for Program-1" << endl;

		cin >> inputval;

		if (inputval == 0) {
			cout << "0, really? Fine." << endl;
		}

		program1(inputval);
	}
	else {
		cout << "Thank you for using this program." << endl;
		cout << "Created by Ruidong Liu." << endl;
		cout << "Goodbye and have a good day." << endl;
	}

}
