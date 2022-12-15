// C++ program to illustrate bookshop
// management system using File Handling
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Bookshop Class
class Bookshop {
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void del_book();
};

// Function to display the menus
void Bookshop::control_panel()
{
	system("cls");
	std::cout << "\n\n\t\t\t\tCONTROL PANEL";
	std::cout << "\n\n1. ADD BOOK";
	std::cout << "\n2. DISPLAY BOOKS";
	std::cout << "\n3. CHECK PARTICULAR BOOK";
	std::cout << "\n4. UPDATE BOOK";
	std::cout << "\n5. DELETE BOOK";
	std::cout << "\n6. EXIT";
}

// Function to add book
void Bookshop::add_book()
{
	system("cls");
	std::fstream file;
	int no_copy;
	std::string b_name, a_name, b_id;
	std::cout << "\n\n\t\t\t\tADD BOOKS";
	std::cout << "\n\nBook ID : ";
	std::cin >> b_id;
	std::cout << "\nBook Name : ";
	std::cin >> b_name;
	std::cout << "\nAuthor Name : ";
	std::cin >> a_name;
	std::cout << "\nNo. of Books : ";
	std::cin >> no_copy;
	while (!std::cin) {
		std::cout << "\nNo. of Books (integer only!)";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> no_copy;
	}

	// Open file in append or
	// output mode
	file.open("D:// book.txt",
			std::ios::out | std::ios::app);
	file << " " << b_id << " "
		<< b_name << " " << a_name
		<< " " << no_copy << "\n";
	file.close();
}

// Function to display book
void Bookshop::show_book()
{
	system("cls");
	std::fstream file;
	int no_copy;
	std::string b_name, b_id, a_name;
	std::cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("D:// book.txt", std::ios::in);
	if (!file)
		std::cout << "\n\nFile Opening Error!";
	else {

		std::cout << "\n\n\nBook ID\t\tBook"
			<< "\t\tAuthor\t\tNo. of "
				"Books\n\n";
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) {

			std::cout << " " << b_id
				<< "\t\t" << b_name
				<< "\t\t" << a_name
				<< "\t\t" << no_copy
				<< "\n\n";
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}

		system("pause");

		// Close the file
		file.close();
	}
}

// Function to check the book
void Bookshop::check_book()
{
	system("cls");
	std::fstream file;
	int no_copy, count = 0;
	std::string b_id, b_name, a_name, targetId;

	std::cout << "\n\n\t\t\t\tCheck "
		<< "Particular Book";

	// Open the file in input mode
	file.open("D:// book.txt", std::ios::in);
	if (!file)
		std::cout << "\n\nFile Opening Error!";
	else {
		std::cout << "\n\nBook ID : ";
		std::cin >> targetId;
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		while (!file.eof()) {

			if (targetId == b_id) {
				system("cls");
				std::cout << "\n\n\t\t\t\t"
					<< "Check Particular Book";
				std::cout << "\n\nBook ID : "
					<< b_id;
				std::cout << "\nName : "
					<< b_name;
				std::cout << "\nAuthor : "
					<< a_name;
				std::cout << "\nNo. of Books : "
					<< no_copy;
				std::cout << std::endl
					<< std::endl;
				count++;
				break;
			}
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			std::cout << "\n\nBook ID Not" << " Found...\n";
		system("pause");
		file.close();
	}
}

// Function to update the book
void Bookshop::update_book()
{
	system("cls");
	std::fstream file, file1;
	int no_copy, no_co, count = 0;
	std::string b_name, b_na, a_name;
	std::string a_na, b_idd, b_id;

	std::cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D:// book1.txt",
			std::ios::app | std::ios::out);
	file.open("D:// book.txt", std::ios::in);

	if (!file)
		std::cout << "\n\nFile Opening Error!";
	else {

		std::cout << "\n\nBook ID : ";
		std::cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) {
			if (b_id == b_idd) {
				system("cls");
				std::cout << "\t\t\t\t"
					<< "Update Book Record";
				std::cout << "\n\nNew Book Name : ";
				std::cin >> b_na;
				std::cout << "\nAuthor Name : ";
				std::cin >> a_na;
				std::cout << "\nNo. of Books : ";
				std::cin >> no_co;
				file1 << " " << b_id << " "
					<< b_na << " "
					<< a_na << " " << no_co
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			std::cout << "\n\nBook ID"
				<< " Not Found...";
	}
	std::cout << std::endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

// Function to delete book
void Bookshop::del_book()
{
	system("cls");
	std::fstream file, file1;
	int no_copy, count = 0;
	std::string b_id, b_idd, b_name, a_name;
	std::cout << "\n\n\t\t\t\tDelete a Book";

	// Append file in output mode
	file1.open("D:// book1.txt",
			std::ios::app | std::ios::out);
	file.open("D:// book.txt",
			std::ios::in);

	if (!file)
		std::cout << "\n\nFile Opening Error...";
	else {

		std::cout << "\n\nBook ID : ";
		std::cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;
		while (!file.eof()) {

			if (b_id == b_idd) {

				system("cls");
				std::cout << "\n\n\t\t\t\t"
					<< "Delete a Book";
				std::cout << "\n\nBook is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			std::cout << "\n\nBook ID "
				<< "Not Found...\n";
	}
	system("pause");

	// Close the file
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

// Function for book shop record
void bookShopRecord()
{
	int choice;
	char x;
	Bookshop b;

	while (1) {

		b.control_panel();
		std::cout << "\n\nEnter your choice : ";
		std::cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_book();
				std::cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				std::cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_book();
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;

		case 5:
			b.del_book();
			break;

		case 6:
			exit(0);
			break;

		default:
			std::cout << "\n\nINVALID CHOICE\n";
		}
	}
}

// Driver Code
int main()
{
	// Function Call
	bookShopRecord();
	return 0;
}
