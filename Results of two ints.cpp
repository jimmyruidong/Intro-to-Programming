#include "pch.h"
#include <iostream>

using namespace std;

float num1;
float num2;
float sum;
int choice; 
int endchoice;

int getfirst() {
	cout << "Enter your first number" << endl;
	cin >> num1;
	cout << "Your first number is: " num1 << endl << endl;
}

int getsecond() {
	cout << "Enter your second number" << endl;
	cin >> num2;
	cout << "Your second number is: " num2 << endl << endl;
}
int add() {
	sum = a + b;
	cout << "Here is the sum of your first and second number: " << sum << endl;
}

int difference() {
	if (a > b) {
		sum = a - b;
	}
	else {
		sum = b - a;
	}
	cout << "Here is the difference between your first and second number: " << sum << endl;
}

int multiply() {
	sum = a * b;
	cout << "Here is the product of your first and second number: " << sum << endl;
}

int divide() {
	sum = a / b;
	cout << "Here is your first number divided by your second number: " << sum << endl;
}

int mathchoice() {
	cout << "What would you like to do with these numbers?" << endl;
	cout << "Enter 1 to add your first and second numbers together" << endl;
	cout << "Enter 2 to find the difference between your first and second number" << endl;
	cout << "Enter 3 to multiply your first number by your second number" << endl;
	cout << "Enter 4 to divide your first number by your second number" << endl;
	cin >> choice;
	if (choice = 1) {
		add;
	else if (choice = 2) {
		difference;
	}
	else if (choice = 3)
		multiply;
	}
	else if (choice = 4) {
		divide;
	}
	else {
		cout << "You entered: " << choice << ", this is not a number between 1-4" << endl;
		cout << "Please key in a number between 1-4!" << endl;
	}
}

int tryagain() {
	cout << "Would you like to try again?" << endl;
	cout << "Enter '1' to try again with the same numbers." << endl;
	cout << "Enter '2' to try again with different numbers." << endl;
	cout << "Enter any other number to exit" << endl;
	cin >> endchoice;

	if (endchoice = 1) {
		mathchoice();
		tryagain();
	}
	else if (endchoice = 2) {
		main();
	}
	else {
		cout << "Thank you and goodbye." << endl;
		cout << "Created by Ruidong Liu" << endl;
		system("Pause");
}

int main() {
	getfirst;
	getsecond;
	mathchoice;
	tryagain;
}
