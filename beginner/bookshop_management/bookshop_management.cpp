/*********************************************************************
* Book Management                                                    *
*********************************************************************/
// fix error where if book name has a space, it takes the next characters as the author.
#include <fstream>
#include <iostream>
#include <string>

class Bookshop {
public:
	void printMenu();
	void addBook();
	void showBook();
	void checkBook();
	void updateBook();
	void deleteBook();
};

void Bookshop::printMenu() {
	system("cls");
	std::cout << "\n\n\t\t\t\t\tMENU";
	std::cout << "\n\n\t\t\t1. ADD BOOK";
	std::cout << "\n\t\t\t2. DISPLAY BOOKS";
	std::cout << "\n\t\t\t3. CHECK PARTICULAR BOOK";
	std::cout << "\n\t\t\t4. UPDATE BOOK";
	std::cout << "\n\t\t\t5. DELETE BOOK";
	std::cout << "\n\t\t\t6. EXIT";
}

void Bookshop::addBook() {
	system("cls");
	std::fstream file;
	int copyNum;
	std::string bookName, authorName, bookId;
	std::cout << "\n\n\t\t\t\tADD BOOKS";
	std::cout << "\n\nBook ID : ";
	std::cin >> bookId;
	std::cout << "\nBook Name : ";
	std::cin >> bookName;
	std::cout << "\nAuthor Name : ";
	std::cin >> authorName;
	std::cout << "\nNo. of Books : ";
	std::cin >> copyNum;
	while (!std::cin) {
		std::cout << "\nNo. of Books (integer only!)";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> copyNum;
	}

	// Open file in append or output mode
	file.open("D:// book.txt",
			std::ios::out | std::ios::app);
	file << " " << bookId << " "
		<< bookName << " " << authorName
		<< " " << copyNum << "\n";
	file.close();
}

void Bookshop::showBook() {
	system("cls");
	std::fstream file;
	int copyNum;
	std::string bookName, bookId, authorName;
	std::cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("D:// book.txt", std::ios::in);
	if (!file)
		std::cout << "\n\nFile Opening Error!";
	else {
		std::cout << "\n\n\nBook ID\t\tBook"
			<< "\t\tAuthor\t\tNo. of "
				"Books\n\n";
		file >> bookId >> bookName;
		file >> authorName >> copyNum;

		while (!file.eof()) {

			std::cout << " " << bookId
				<< "\t\t" << bookName
				<< "\t\t" << authorName
				<< "\t\t" << copyNum
				<< "\n\n";
			file >> bookId >> bookName;
			file >> authorName >> copyNum;
		}

		system("pause");

		file.close();
	}
}

void Bookshop::checkBook() {
	system("cls");
	std::fstream file;
	int copyNum, count = 0;
	std::string bookId, bookName, authorName, targetId;

	std::cout << "\n\n\t\t\t\tCheck "
		<< "Particular Book";

	// Open the file in input mode
	file.open("D:// book.txt", std::ios::in);
	if (!file)
		std::cout << "\n\nFile Opening Error!";
	else {
		std::cout << "\n\nBook ID : ";
		std::cin >> targetId;
		file >> bookId >> bookName;
		file >> authorName >> copyNum;

		while (!file.eof()) {

			if (targetId == bookId) {
				system("cls");
				std::cout << "\n\n\t\t\t\t"
					<< "Check Particular Book";
				std::cout << "\n\nBook ID : "
					<< bookId;
				std::cout << "\nName : "
					<< bookName;
				std::cout << "\nAuthor : "
					<< authorName;
				std::cout << "\nNo. of Books : "
					<< copyNum;
				std::cout << std::endl
					<< std::endl;
				count++;
				break;
			}
			file >> bookId >> bookName;
			file >> authorName >> copyNum;
		}
		if (count == 0)
			std::cout << "\n\nBook ID Not" << " Found...\n";
		system("pause");
		file.close();
	}
}

void Bookshop::updateBook() {
	system("cls");
	std::fstream file, file1;
	int copyNum, newCopyNum, count = 0;
	std::string bookName, newBookName;
	std::string authorName, newAuthorName;
	std::string bookId, newBookId;

	std::cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D:// book1.txt",
			std::ios::app | std::ios::out);
	file.open("D:// book.txt", std::ios::in);

	if (!file)
		std::cout << "\n\nFile Opening Error!";
	else {

		std::cout << "\n\nBook ID : ";
		std::cin >> bookId;
		file >> newBookId >> bookName;
		file >> authorName >> copyNum;

		while (!file.eof()) {
			if (bookId == newBookId) {
				system("cls");
				std::cout << "\t\t\t\t"
					<< "Update Book Record";
				std::cout << "\n\nNew Book Name : ";
				std::cin >> newBookName;
				std::cout << "\nAuthor Name : ";
				std::cin >> newAuthorName;
				std::cout << "\nNo. of Books : ";
				std::cin >> newCopyNum;
				file1 << " " << bookId << " "
					<< newBookName << " "
					<< newAuthorName << " " << newCopyNum
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << newBookId
					<< " " << bookName
					<< " " << authorName
					<< " " << copyNum
					<< "\n\n";
			file >> newBookId >> newBookName;
			file >> authorName >> copyNum;
		}
		if (count == 0)
			std::cout << "\n\nBook ID"
				<< " Not Found...";
	}
	std::cout << std::endl;
	system("pause");

	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

void Bookshop::deleteBook()
{
	system("cls");
	std::fstream file, file1;
	int copyNum, count = 0;
	std::string bookId, inputId, bookName, authorName;
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
		std::cin >> bookId;
		file >> inputId >> bookName;
		file >> authorName >> copyNum;
		while (!file.eof()) {

			if (bookId == inputId) {

				system("cls");
				std::cout << "\n\n\t\t\t\t"
					<< "Delete a Book";
				std::cout << "\n\nBook is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << inputId
					<< " " << bookName
					<< " " << authorName
					<< " " << copyNum
					<< "\n\n";
			file >> inputId >> bookName;
			file >> authorName >> copyNum;
		}
		if (count == 0)
			std::cout << "\n\nBook ID "
				<< "Not Found...\n";
	}
	system("pause");

	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

void bookShopRecord() {
	int choice;
	char x;
	Bookshop bookShop1;

	while (1) {
		bookShop1.printMenu();
		std::cout << "\n\n\t\t\tEnter your choice : ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			do {
				bookShop1.addBook();
				std::cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				std::cin >> x;
			} while (x == 'y');
			break;
		case 2:
			bookShop1.showBook();
			break;
		case 3:
			bookShop1.checkBook();
			break;
		case 4:
			bookShop1.updateBook();
			break;
		case 5:
			bookShop1.deleteBook();
			break;
		case 6:
			exit(0);
			break;
		default:
			std::cout << "\n\nINVALID CHOICE\n";
		}
	}
}

int main() {
	bookShopRecord();
	return 0;
}
