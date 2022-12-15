// Importing input output operations file
#include <iostream>
// Importing file class
#include <fstream>
// Importing standard library file
#include <stdlib.h>
// Importing string library file
#include <string>

std::string fname, lname, phone_num;

// Methods
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(std::string);
bool check_numbers(std::string);

// Method 1
// Helper method
void self_exit() {
	system("cls");
	std::cout << "\n\n\n\t\tThank You for using Contact-Saver!\n";
	exit(1);
}

// Method 2
// Helper method
void help() {
	std::cout << "Help Center";
	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");
}

// Method 3
// Helper method
void addContact() {
	std::ofstream phone("number.txt", std::ios::app);
	system("cls");
	std::cout << "\n\n\tEnter First Name : ";
	std::cin >> fname;
	std::cout << "\n\tEnter Last Name : ";
	std::cin >> lname;
	std::cout << "\n\tEnter Phone Number : ";
	std::cin >> phone_num;

	if (check_digits(phone_num) == true) {
		if (check_numbers(phone_num) == true) {
			if (phone.is_open()) {
				phone << fname << " " << lname << " "
					<< phone_num << std::endl;
				std::cout << "\n\tContact saved successfully !";
			}
			else {
				std::cout << "\n\tError in opening record!";
			}
		}
		else {
			std::cout << "\n\tOnly numbers are allowed!";
		}
	}
	else {
		std::cout << "\n\tPhone number should be of 10 digits only.";
	}
	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");
	phone.close();
}

// Method 4
// Helper method
void searchContact() {
	bool found = false;
	std::ifstream myfile("number.txt");
	std::string keyword;
	std::cout << "\n\tEnter Name to search : ";
	std::cin >> keyword;
	while (myfile >> fname >> lname >> phone_num) {
		if (keyword == fname || keyword == lname) {
			system("cls");
			std::cout << "\n\n\n\t\tCONTACT DETAILS";
			std::cout << "\n\nFirst Name : " << fname;
			std::cout << "\nLast Name : " << lname;
			std::cout << "\nPhone Number : " << phone_num;
			found = true;
			break;
		}
	}
	if (found == false)
		std::cout << "\nNo such contact is found!";

	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");
}

// Method 5
// Helper method
bool check_digits(std::string x) {
	if (x.length() == 10)
		return true;
	else
		return false;
}

// Method 6
// Helper method
bool check_numbers(std::string x) {
	bool check = true;

	for (int i = 0; i < x.length(); i++) {
		if (!(int(x[i]) >= 48 && int(x[i]) <= 57)) {
			check = false;
			break;
		}
	}

	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");

	return check;
}

// Method 7
void showContacts() {
	system("cls");
	int count = 0;
	std::ifstream myfile("number.txt");
	while (myfile >> fname >> lname >> phone_num) {
		std::cout << "\n\n\n\t\tCONTACT DETAILS";
		std::cout << "\n\nFirst Name : " << fname;
		std::cout << "\nLast Name : " << lname;
		std::cout << "\nPhone Number : " << phone_num;
		count++;
	}
	if (count == 0)
		std::cout << "\nNo contacts found!";

	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");
}

// Method 8
// Main driver method
int main() {
	int choice;
	system("cls");
	system("color 0A");
	while (1) {
		std::cout << "\n\n\n\t\t\tCONTACT SAVER";
		std::cout << "\n\n\t1. Add Contact\n\t2. Search "
				"Contact\n\t3. Show All Contacts \n\t4. Help\n\t5. Exit\n\t> ";
		std::cin >> choice;

		// Switch case
		switch (choice) {
		case 1:
			addContact();
			break;

		case 2:
			searchContact();
			break;
		
		case 3:
			showContacts();
			break;

		case 4:
			help();
			break;

		case 5:
			self_exit();
			break;

		default:
			std::cout << "\n\n\tInvalid Input!";
		}
	}
	return 0;
}
