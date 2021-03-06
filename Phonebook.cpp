/*
Your assignment for this week is to create a realistic phone book application in C++ which makes use of classes,
functions, and file-operations.

Create a ContactsBook application that allows the user to create, search and display their contacts. 
Your program must store all contact information on a file. 
Contact details can include attributes like First name, Last name, Phone, Email etc., 
Your program must allow the user to: 
(i) create and store new contact information, 
(ii) search for a contact using details such as name/phone-number, 
(iii) display all your contacts on the terminal.

Assignment requirements: 
(1) create a Class called ContactsBook, 
(2) use functions() to perform the required actions, and 
(2) store contact details on a physical file using ifstream/ofstream objects.


Check+ or more: Implement a function that allows a user to search-and-delete a contact.*/

#include "pch.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class Contact
{
public:
	Contact(string firstname, string lastname, string number, string email) {
		this->firstname = firstname;
		this->lastname = lastname;
		this->number = number;
		this->email = email;
	}

	string serialize() {
		return firstname + " " + lastname + " " + number + " " + email;
	}

	bool matches(string query) {
		return (query == firstname || query == lastname || query == number || query == email);
	}

	void printinfo() {
		cout << "First name: " << firstname << endl;
		cout << "Last name: " << lastname << endl;
		cout << "Contact number: " << number << endl;
		cout << "Email Address: " << email << endl << endl;
	}
private:
	string firstname;
	string lastname;
	string number;
	string email;
};

class ContactsBook
{
public:
	ContactsBook() {
		this->contacts = vector<Contact>();
		getContactsfromFile("contacts.txt");
	} 

	void addContacttoBook(Contact c) {
		contacts.push_back(c);
	}

	void putContactsInFile(string fileName) {
		ofstream file(fileName.c_str());
		for (int i = 0; i < contacts.size(); i++) {
			file << contacts[i].serialize() << endl;
		}
	}

	void putLatestContactInFile(string fileName) {
		ofstream file(fileName.c_str());
		int x = 0;
		x = contacts.size() - 1;
		file << contacts[x].serialize() << endl;
	}

	void searchContact() {
		string query;
		cout << "Search for something" << endl;
		cin >> query;
		for (int i = 0; i < contacts.size(); i++) {
			if (contacts[i].matches(query))
				contacts[i].printinfo();
		}
	}

	void display() {
		for (int i = 0; i < contacts.size(); i++) {
			contacts[i].printinfo();
		}
		cout << "All contacts have been displayed" << endl;
	}

	void createContact() {
		string firstname;
		string lastname;
		string number;
		string email;
		cout << "Enter the first name of your contact" << endl;
		cin >> firstname;
		cout << "Enter the last name of your contact" << endl;
		cin >> lastname;
		cout << "Enter the number of your contact" << endl;
		cin >> number;
		cout << "Enter the email of your contact" << endl;
		cin >> email;

		addContacttoBook(Contact(firstname, lastname, number, email));
		cout << "Contact created and added to book" << endl;
	}

private:
	vector<Contact> contacts;

	Contact deserialize(string line) {
		istringstream iss(line);
		string firstname;
		string lastname;
		string number;
		string email;
		iss >> firstname;
		iss >> lastname;
		iss >> number;
		iss >> email;
		return Contact(firstname, lastname, number, email);
	}

	void getContactsfromFile(string fileName) {
		ifstream file(fileName.c_str());
		if (file) {
			for (string line; getline(file, line);) {
				contacts.push_back(deserialize(line));
			}
		}
	}
};

void menu(ContactsBook name);

int main()
{
	ContactsBook contactstrial = ContactsBook();

	menu(contactstrial);
	
	cout << "Thank you for running this program." << endl;
}

void menu(ContactsBook contactstrial) {
	int inputnum;

	while (true) {
		cout << "Enter 1 to create a new contact" << endl;
		cout << "Enter 2 to search for a contact" << endl;
		cout << "Enter 3 to display all contacts" << endl;
		cout << "Enter 0 to exit program" << endl;
		cin >> inputnum;

		if (inputnum == 1) {
			contactstrial.createContact();
			contactstrial.putContactsInFile("contacts.txt");
			
		}
		else if (inputnum == 2) {
			contactstrial.searchContact();
		}
		else if (inputnum == 3) {
			contactstrial.display();
		}
		else if (inputnum == 0) {
			break;
		}
		else {
			cout << "Please enter the corrent input." << endl;
		}
	}
	
	

}
