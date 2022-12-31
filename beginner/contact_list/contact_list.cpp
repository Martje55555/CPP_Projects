/*********************************************************************
* Contact List System                                                *
*********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

std::string firstName, lastName, phoneNum;

bool checkDigits(std::string);
bool checkNumbers(std::string);

void exit() {
	system("cls");
	std::cout << "\n\n\n\t\tThank You for using Contact-Saver!\n";
	exit(1);
}

void help() {
	system("cls");
	std::cout << "Help Center";
	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");
}

void addContact() {
	std::ofstream phone("number.txt", std::ios::app);
	system("cls");
	std::cout << "\n\n\tEnter First Name : ";
	std::cin >> firstName;
	std::cout << "\n\tEnter Last Name : ";
	std::cin >> lastName;
	std::cout << "\n\tEnter Phone Number : ";
	std::cin >> phoneNum;

	if (checkDigits(phoneNum) == true) {
		if (checkNumbers(phoneNum) == true) {
			if (phone.is_open()) {
				phone << firstName << " " << lastName << " "
					<< phoneNum << std::endl;
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

void searchContact() {
	bool found = false;
	std::ifstream myfile("number.txt");
	std::string keyword;
	std::cout << "\n\tEnter Name to search : ";
	std::cin >> keyword;
	while (myfile >> firstName >> lastName >> phoneNum) {
		if (keyword == firstName || keyword == lastName) {
			system("cls");
			std::cout << "\n\n\n\t\tCONTACT DETAILS";
			std::cout << "\n\nFirst Name : " << firstName;
			std::cout << "\nLast Name : " << lastName;
			std::cout << "\nPhone Number : " << phoneNum;
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

bool checkDigits(std::string x) {
	if (x.length() == 10)
		return true;
	else
		return false;
}

bool checkNumbers(std::string x) {
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

void showContacts() {
	system("cls");
	int count = 0;
	std::ifstream myfile("number.txt");
	while (myfile >> firstName >> lastName >> phoneNum) {
		std::cout << "\n\n\n\t\tCONTACT DETAILS";
		std::cout << "\n\nFirst Name : " << firstName;
		std::cout << "\nLast Name : " << lastName;
		std::cout << "\nPhone Number : " << phoneNum;
		count++;
	}
	if (count == 0)
		std::cout << "\nNo contacts found!";

	std::cout << std::endl << std::endl;
	system("PAUSE");
	system("cls");
}

int main() {
	int choice;
	system("cls");
	system("color 0A");
	while (1) {
		std::cout << "\n\n\n\t\t\tCONTACT SAVER";
		std::cout << "\n\n\t1. Add Contact\n\t2. Search "
				"Contact\n\t3. Show All Contacts \n\t4. Help\n\t5. Exit\n\t> ";
		std::cin >> choice;

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
			exit();
			break;

		default:
			std::cout << "\n\n\tInvalid Input!";
		}
	}
	return 0;
}
