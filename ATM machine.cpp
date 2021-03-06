/* 
Assignment 7.cpp : This file contains the 'main' function. Program execution begins and ends there.

Your next assignment is to simulate the actions of a realistic ATM machine. You must create a new “class” called ATM machine, and be able to create a variable (object) of this type in your main() function. Using this object,  perform all the following functions:

Initializes a bank account to $1000 (Hint: use the constructor)

Supports a function to make a deposit. Deposits can be cash or check. Cash deposits can be any arbitrary value less than $100, while check deposits are limitless.

Supports a function to withdraw cash. The maximum withdrawal amount is $200, and withdrawal amounts must always be a multiple of 20.

Supports a simple function check balance, which prints the current account balance on screen.

L.R.
*/

#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class ATM {
public:
	ATM(int initial_balance) {balance = initial_balance; }
		
	void deposite( string type, int amount) { 
		if (type == "cash"&& amount <= 100) { 
		balance += amount; 
		} 

		if (type == "check") {
		balance += amount; 
		} 
	}
	
	void withdraw(int amount) { 
		if (amount <= 200 && amount % 20 == 0) { 
			balance -= amount; 
		} 
		else {
			cout << "Can't withdraw that much." << endl;
		}
	}
	void check_balance() { 
		cout << "Current balance: " << balance << endl; 
	}
private:
	int balance;
}; 
int main() {
	ATM a(1000);
	
	while(true){
		cout << endl;
		int x;
		cout << "Enter 1 to deposit." << endl;
		cout << "Enter 2 to withdraw." << endl;
		cout << "Enter 3 to check balance" << endl;
		cout << "Enter 0 to exit" << endl;
		cin >> x;

		if (x == 1) {
			int amount;
			string x;
			cout << "Would you like to deposit via cash or check?" << endl;
			cout << "Enter cash for a cash deposit or enter check for a check deposit." << endl;
			cin >> x;

			cout << "How much would you like to deposit?" << endl;
			cin >> amount;
			a.deposite(x, amount);
		}
		
		else if (x == 2) {
			int amount;
			cout << "How much would you like to withdraw?" << endl;
			cin >> amount;
			a.withdraw(amount);
		}

		else if (x == 3) {
			a.check_balance();
		}

		else if (x == 0) {
			cout << "Thank you for running this program." << endl;
			cout << "Have a good day." << endl;
			break;
		}

		else {
			cout << "Please enter either 1,2,3 or 0." << endl;
		}
	}
	
	
	
}
