// Include all the necessary libraries.
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

int main() {
	// Considering the max length of data entered (name) to
	// be 15.
	char data[15];
	int n = 0, option = 0, count_n = 0;
	// This is the initial mark allotted to a subject.
	std::string empty = "00";
	std::string proctor = "";
	// Name of the file in which DB is stored.
	std::ifstream f("Example.txt");
	std::string line;

	// The following for loop counts the total number of
	// lines in the file.
	for (int i = 0; std::getline(f, line); ++i) {
		count_n++;
	}

	while (option != 6) {
		// This prints out all the available options in the
		// DB
		std::cout << "\nAvailable operations: \n1. Add New "
				"Students\n2."
			<< "Student Login\n3. Faculty Login\n4. "
				"Proctor Login\n5. Admin View\n"
			<< "6. Exit\nEnter option: ";
		std::cin >> option;

		if (option == 1) {
			std::cout << "Enter the number of students: ";
			std::cin >> n;

			count_n = count_n + n;

			for (int i = 0; i < n; i++) {
				std::ofstream outfile;
				outfile.open("Example.txt", std::ios::app);
				// The entire data of a single student is
				// stored line-by-line.
				std::cout << "Enter your registration number: ";
				std::cin >> data;
				outfile << data << "\t";

				std::cout << "Enter your name: ";
				std::cin >> data;
				int len = strlen(data);

				while (len < 15) {
					data[len] = ' ';
					len = len + 1;
				}
				outfile << data << "\t";
				// Inserting empty data initially into the
				// file
				outfile << empty << "\t";
				outfile << empty << "\t";

				std::cout << "Enter your proctor ID: ";
				std::cin >> proctor;

				outfile << proctor << std::endl;
			}
		}

		else if (option == 2) {
			char regno[9];
			std::cout << "Enter your registration number: ";
			std::cin >> regno;
			std::ifstream infile;
			int check = 0;
			infile.open("Example.txt", std::ios::in);

			// This loop prints out the data according to
			// the registration number specified.
			while (infile >> data) {
				if (strcmp(data, regno) == 0) {
					std::cout
						<< "\nRegistration Number: " << data
						<< std::endl;
					infile >> data;
					std::cout << "Name: " << data << std::endl;

					infile >> data;
					std::cout << "CSE1001 mark: " << data
						<< std::endl;

					infile >> data;
					std::cout << "CSE1002 mark: " << data
						<< std::endl;

					infile >> data;
					std::cout << "Proctor ID: " << data << std::endl;

					infile.close();
					check = 1;
				}
			}

			if (check == 0) {
				std::cout << "No such registration number found!"
					<< std::endl;
			}
		}

		// This loop is used to view and add marks to the
		// database of a student.
		else if (option == 3) {
			char subcode[7];
			std::cout << "Enter your subject code: ";
			std::cin >> subcode;
			std::string code1 = "CSE1001", code2 = "CSE1002",
				mark = "";
			std::ifstream infile;
			int check = 0;

			std::cout << "\nAvailable operations: \n1. Add data "
					"about marks\n"
				<< "2. View data\nEnter option: ";
			std::cin >> option;

			if (option == 1) {
				std::cout
					<< "Warning! You would need to add mark"
					<< "details for all the students!"
					<< std::endl;
				for (int i = 0; i < count_n; i++) {
					std::fstream file("Example.txt");

					// The seek in file has been done
					// according to the length
					// of the data being inserted. It needs
					// to adjusted accordingly for different
					// lengths of data.

					if (strcmp(subcode, code1.c_str())
						== 0) {
						file.seekp(26 + 37 * i,
								std::ios_base::beg);
						std::cout << "Enter the mark of student#"
							<< (i + 1) << " : ";
						std::cin >> mark;
						file.write(mark.c_str(), 2);
					}

					if (strcmp(subcode, code2.c_str())
						== 0) {
						file.seekp(29 + 37 * i,
								std::ios_base::beg);
						std::cout << "Enter the mark of student#"
							<< (i + 1) << " : ";
						std::cin >> mark;
						file.write(mark.c_str(), 2);
					}
				}
			}

			// This loop is used to view marks of a student.
			// The extra infile commands have been used to
			// get a specific mark only since the data has
			// been separated by a tabspace.

			else if (option == 2) {
				infile.open("Example.txt", std::ios::in);
				if (strcmp(subcode, code1.c_str()) == 0) {
					std::cout << "Registration number - Marks\n"
						<< std::endl;
					while (infile >> data) {
						std::cout << data;
						infile >> data;
						infile >> data;
						std::cout << " - " << data << std::endl;
						infile >> data;
						infile >> data;
						check = 1;
					}
				}

				infile.close();
				infile.open("Example.txt", std::ios::in);

				if (strcmp(subcode, code2.c_str()) == 0) {
					std::cout << "Registration number - Marks\n"
						<< std::endl;
					while (infile >> data) {
						std::cout << data;
						infile >> data;
						infile >> data;
						infile >> data;
						std::cout << " - " << data << std::endl;
						infile >> data;
						check = 1;
					}
				}
			}

			infile.close();

			if (check == 0) {
				std::cout << "No such subject code found!"
					<< std::endl;
			}
		}

		// This loop displays all the details of students
		// under the same proctor ID.

		else if (option == 4) {
			char procid[7];
			std::cout << "Enter your proctor ID: ";
			std::cin >> procid;
			int check = 0;
			char temp1[100], temp2[100], temp3[100];
			char temp4[100], id[100];
			std::ifstream infile;
			infile.open("Example.txt", std::ios::in);

			while (infile >> temp1) {
				infile >> temp2;
				infile >> temp3;
				infile >> temp4;
				infile >> id;

				if (strcmp(id, procid) == 0) {
					std::cout << "\nRegistration Number: "
						<< temp1 << std::endl;
					std::cout << "Name: " << temp2 << std::endl;
					std::cout << "CSE1001 Mark: " << temp3
						<< std::endl;
					std::cout << "CSE1002 Mark: " << temp4
						<< std::endl;
					check = 1;
				}
			}

			if (check == 0) {
				std::cout << "No such proctor ID found!" << std::endl;
			}
		}

		// This loop acts as an admin view to see all the
		// data in the file.

		else if (option == 5) {
			char password[25];
			std::cout << "Enter the admin password: ";
			std::cin >> password;

			// This variable value can be changed according
			// to your requirement of the administrator
			// password.

			std::string admin_pass = "admin";

			if (strcmp(password, admin_pass.c_str()) == 0) {
				std::cout << "Reg No.	 "
						"\tName\tCSE1001\tCSE1002\tProctor "
						"ID"
					<< std::endl;
				std::ifstream infile;
				infile.open("Example.txt", std::ios::in);
				char data[20];

				while (infile >> data) {
					std::cout << data << "\t";
					infile >> data;
					std::cout << data << "\t";
					infile >> data;
					std::cout << data << "\t";
					infile >> data;
					std::cout << data << "\t";
					infile >> data;
					std::cout << data << std::endl;
				}
			}
		}
	}
}
