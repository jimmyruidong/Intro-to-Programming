#include "pch.h"
#include <iostream>
using namespace std;

void printGreeting();
void divideNumbers(float x, float y);
void factorial(int num);
void fibonacci(int N);

int main()
{
	int input;

	cout << "Enter 1 to print greeting." << endl;
	cout << "Enter 2 to use the divide numbers function." << endl;
	cout << "Enter 3 to use factorial function." << endl;
	cout << "Enter 4 to print fibonnacci numbers." << endl;
	cout << "Enter 0 to exit" << endl;

	cin >> input;
	if (input == 1) {
		printGreeting();
	}
	else if (input == 2) {
		float x;
		float y;

		cout << "Enter x and y" << endl;
		
		cin >> x;
		cin >> y;
		divideNumbers(x,y);
	}
	else if (input == 3) {
		int num;
		cout << "Enter int for factorial." << endl;
		cin >> num;
		factorial(num);
	}
	else if (input == 4) {
		int N;
		cout << "Enter int for fibonnaci seq." << endl;
		cin >> N;
		fibonacci(N);
	}
	else if (input == 0) {
		return 0;
	}
}

void printGreeting() {
	cout << "Hope you're having a good day." << endl;
}

void divideNumbers(float x, float y) {
	if (y == 0) {
		cout << "Cannot perform function" << endl;
	}
	else {
		cout << x << " divided by " << y << " is equal to: " << (x / y) << endl;
	}
}

void factorial(int num) {
	int sum = num;
	for (int count = (num - 1); count > 0; count--) {
		sum = sum * count;
	}
	if (num < 0) {
		cout << "0" << endl;
	}
	else{ 
		cout << "The factorial of " << num << " is: " << sum << endl; 
	}
	
}

void fibonacci(int N) {
	int fib1 = 0;
	int fib2 = 1;
	int fib3;
	cout << "The sequence is: " << endl;
	for (int count = 0; count <= N; count++) {
			if (count <= 1)
				fib3 = count;
			else
			{
				fib3 = fib1 + fib2;
				fib1 = fib2;
				fib2 = fib3;
			}
			cout << fib3 << endl;
		}
}