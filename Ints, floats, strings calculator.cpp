#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Assignment
{
public:
	string assignmentnametype;
	double assignmentweight;
	vector<int> gradevector;

	void getname() {
		cout << "What is the type of this assignment?" << endl;
		cin >> assignmentnametype;
	}

	void getweight() {
		cout << "What is the weight of " << assignmentnametype << "?" << endl;
		cin >> assignmentweight;
	}

	void printname() {
		cout << assignmentnametype << endl;
	}

	void printweight() {
		cout << "[" << assignmentweight << "]" << endl;
	}

	void printgradelist() {
		cout << "Your grade(s) for " << assignmentnametype << "are: ";
		for (int count = 0; count < gradevector.capacity - 1; count++) {
			cout << gradevector[count];
			if (count < gradevector.capacity - 2) {
				cout << ", ";
			}
		}
	}

	void printaveragegrade() {
		cout << "Your average grade for " << assignmentnametype << " is: " << averagegrade(gradevector) << endl;
	}

	void addtovector() {
		double grade;
		cout << "Enter your grade for this " << assignmentnametype << "." << endl;
		cin >> grade;
		gradevector.push_back(grade);
	}

	double weighttimesgrade(double weight, double grade) {
		double sum;
		sum = weight * grade;
		return sum;
	}

	double averagegrade(vector<int> targetvector) {
		double sum;
		for (int count = 0; count < targetvector.capacity; count++) {
			sum += targetvector[count];
		}
		sum = sum / targetvector.capacity;
		return sum;
	}

	void createvector() {
		int inputnum;
		cout << "Enter 1 to input a new assignment grade." << endl;
		cin >> inputnum;
		if (inputnum = 1) {
			addtovector();
		}
		else {
			printgradelist();
		}
	}
}

int main() {
	string inputstr;
	vector <string> typeassignlist;
	for (count = 0; count < typeassignlist.capacity; count++) {
		cout << "Enter your assignment types: " << endl;
		cin >> inputstr;
		typeassignlist.push_back(inputstr);
		Assignment typeassignlist[count];
		typeassignlist[count].getname;
		typeassignlist[count].printname;
	}
}