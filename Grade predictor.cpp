#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double homeworksum;
double homeworkpercent;
int numhomework;
double hwt;

double midtermsum;
double midtermpercent;
int nummidterm;
double mtt;

double finalssum;
double finalpercent;
int numfinals;
double ftt;

double gradenum;


void findhw() {
	int assigngrade;

	cout << "What is the percentage weight of homework? Eg: if 44 percent, type 44" << endl;
	cin >> homeworkpercent;
	homeworkpercent = (homeworkpercent / 100);

	cout << "How many homework assignments do you have?" << endl;
	cin >> numhomework;

	for (int count = 0; count < numhomework; count++) {
		cout << "Enter your homework grade." << endl;
		cin >> assigngrade;
		homeworksum = homeworksum + assigngrade;
	}

	hwt = ((homeworksum / numhomework) *homeworkpercent);
}

void findmid() {
	int assigngrade;

	cout << "What is the percentage weight of midterm? Eg: if 44 percent, type 44" << endl;
	cin >> midtermpercent;
	midtermpercent = (midtermpercent / 100);

	cout << "How many midterm assignments do you have?" << endl;
	cin >> nummidterm;

	for (int count = 0; count < nummidterm; count++) {
		cout << "Enter your midterm grades." << endl;
		cin >> assigngrade;
		midtermsum = midtermsum + assigngrade;
	}

	mtt = ((midtermsum / nummidterm) *midtermpercent);
}

void findfinal() {
	int assigngrade;

	cout << "What is the percentage weight of final? Eg: if 44 percent, type 44." << endl;
	cin >> finalpercent;
	finalpercent = (finalpercent/100);

	cout << "How many final assignments do you have?" << endl;
	cin >> numfinals;

	for (int count = 0; count < numfinals; count++) {
		cout << "Enter your final grades." << endl;
		cin >> assigngrade;
		finalssum = finalssum + assigngrade;
	}

	ftt = ((finalssum / numfinals) *finalpercent);
}

double avggrade(double midtermnum, double finalnum, double projectnum)
{
	int gradeavg;
	gradeavg = (midtermnum + finalnum + projectnum);
	return gradeavg;
}


char grade(double x)
{
	char grade = ' ';
	if (x >= 90)
	{
		grade = 'A';
	}
	else if (x >= 80)
	{
		grade = 'B';
	}
	else if (x >= 70)
	{
		grade = 'C';
	}
	else
	{
		grade = 'D';
	}

	return grade;
}

int main() {
	findhw();
	findmid();
	findfinal();
	gradenum = avggrade(hwt, mtt, ftt);
	cout << "Your grade is: " << grade(gradenum) << endl;
}


