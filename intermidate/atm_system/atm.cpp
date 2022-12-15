
	#include <iostream>
	#include <iomanip>
	#include <time.h>
	#include <fstream>
	#include <conio.h>
	#include <stdlib.h>
    #include <string>
	#include<process.h>
	#include<dos.h>
	
	class Bank { /** abstract base class **/ };

	class ATMAccountHolders {
	    std::string accountHolders;
	    std::string accountHoldersAddress, branch;
	    int accountNumber;
	    double startBalance;
	    double accountBalance;
	    double accountInterest;
	    double amount;
	    int count;

	    public:
	    void deposit();
	    void withdraw();
        void details();
	    void payBills();
	    void accountExit();
	    void interest();

	    ATMAccountHolders() {
            accountNumber = 5678;
            accountHolders = "Johhy Dre";
            accountHoldersAddress = "Eastway, House no.36";
            startBalance = 60000.00;
            accountBalance = 60000.00;
            branch  = "Pkr";
            amount = 20000;
	    }
	};

    void ATMAccountHolders::interest() {
        system("cls");

        std::cout <<"\n\xB2\xB2\xB2\xB2\\xB2\xB2\xB2\xB2\ATM ACCOUNT INTEREST PAYMENT\xB2\xB2\xB2\xB2\\xB2\xB2\xB2\xB2\\n\n";
        std::cout <<"\tThe Interest is calculate over the last SIX months on the average account balance\n";
        std::cout <<"\n\t\tInterest Rate payable is 10% per annum." << std::endl;
        std::cout <<"\t\tView the accumulated interest? Press 1 for Yes OR 0 for NO.\n\n";

        std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT INTEREST PAYMENT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

        std::cout <<"\n\nThe Names of the Account Holders are :" << accountHolders << "\n\n";
        std::cout <<"\tThe Account Holders' address is :" << accountHoldersAddress << "\n\n";
        std::cout <<"\tThe Branch location is :" << branch << "\n\n";
        std::cout <<"\tAccount number :" << accountNumber << "\n\n";
        std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout << "\tStarting account balance :$" << startBalance << "\n\n";
        std::cout << "\tPresent available balance :$" << accountBalance << "\n\n";
        accountInterest=accountBalance + (accountBalance*1.050);
        std::cout << "\tPresent available balance + interest for 6 months :$" << accountInterest << "\n\n";
        std::cout <<"Press any key to Return to the Main Menu\n\n";
        system("PAUSE");
    }

	//==================================================================================================
    void ATMAccountHolders::deposit() {
        system("cls");
        std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT DEPOSIT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

        std::cout << "\n\nThe Names of the Account Holders are :"<<accountHolders <<"\n\n";
        std::cout << "\tThe Account Holders' address is :"<<accountHoldersAddress << "\n\n";
        std::cout << "\tThe Branch location is :"<<branch << "\n\n";
        std::cout << "\tAccount number :" << accountNumber <<"\n\n";
        std::cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout << "\tStarting account balance :$" << startBalance << "\n\n";
        std::cout << "\tPresent available balance :$" << accountBalance <<"\n\n";
        std::cout << "\tEnter the Amount to be Deposited $";

        double newAmount;
        std::cin >> newAmount;
        accountBalance=accountBalance+newAmount ;
        std::cout << "\n\tYour new available Balanced Amount is $" << accountBalance << std::endl ;
        std::cout << "\n\t\t\tThank You!\n\n" << std::endl;
        std::cout << "Press any key to Return to the Main Menu\n\n";
        system("PAUSE");
    };
	//==================================================================================================
    void ATMAccountHolders::withdraw() { //Withdrawal Transactions
        system("cls");
        std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT WTHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

        std::cout << "\n\nThe Names of the Account Holders are :"<<accountHolders<<"\n\n";
        std::cout << "\tThe Account Holders' address is :"<<accountHoldersAddress<<"\n\n";
        std::cout << "\tThe Branch location is :"<<branch<<"\n\n";
        std::cout << "\tAccount number :"<<accountNumber<<"\n\n";
        std::cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout <<"\tStarting account balance :$"<<startBalance<<"\n\n";
        std::cout <<"\tPresent available balance :$"<<accountBalance<<"\n\n";
        std::cout <<"\tEnter the Amount to be Withdrawn $";

        double newAmount;
        std::cin>>newAmount;

        if(newAmount>accountBalance||newAmount>accountBalance-2000)
        {
            system("cls");
            std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT WITHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            std::cout <<"\n\nThe Names of the Account Holders are :"<<accountHolders<<"\n\n";
            std::cout <<"\tThe Account Holders' address is :"<<accountHoldersAddress<<"\n\n";
            std::cout <<"\tThe Branch location is :"<<branch<<"\n\n";
            std::cout <<"\tAccount number :"<<accountNumber<<"\n\n";
            std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            std::cout <<"\n\tInsufficient Available Balance in your account.\n\n"<<std::endl;
            std::cout <<"\t\t\tSorry !!\n"<<std::endl;
            system("PAUSE");
        }
        else
        {
            double b;
            accountBalance=accountBalance-newAmount;
            system("cls");

            std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT WTHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            std::cout <<"\n\nThe Names of the Account Holders are :"<<accountHolders<<"\n\n";
            std::cout <<"\tThe Account Holders' address is :"<<accountHoldersAddress<<"\n\n";
            std::cout <<"\tThe Branch location is :"<<branch<<"\n\n";
            std::cout <<"\tAccount number :"<<accountNumber<<"\n\n";
            std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            std::cout <<"Your new available Balanced Amount is $"<<accountBalance<<std::endl ;
            std::cout <<"Press any key to Return to the Main Menu\n\n";
            system("PAUSE");
        }

    };

    void ATMAccountHolders::payBills() {
        system("cls");

        std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM BILLS PAYMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";

        std::cout <<"\n\nThe Names of the Account Holders are :"<<accountHolders<<"\n\n";
        std::cout <<"\tThe Account Holders' address is :"<<accountHoldersAddress<<"\n\n";
        std::cout <<"\tThe Branch location is :"<<branch<<"\n\n";
        std::cout <<"\tAccount number :"<<accountNumber<<"\n\n";
        std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout <<"Pay Electric Company electricity bill of $2000.00 now?\n\n";
        std::cout <<"\t\tPress 1 for Yes OR Press 0 for No\n\n";

        int r;

        std::cin>>r;
        if(r==1)
        {
            accountBalance=accountBalance-2000;
            system("cls");

            std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM BILLS PAYMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
            std::cout <<"\n\tYour electricity bill of $2000.00 has been paid.\n\n";
            std::cout <<"\tYour account new Available Balanced Amount is $"<<accountBalance<<std::endl ;
            std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            std::cout <<"Press any key to Return to the Main Menu\n\n";
        }
        if(r==0)
        {
            std::cout <<"\n===========================ATM BILLS PAYMENT SYSTEM==========================\n\n";
            std::cout <<"\n\n\tExiting Bill Payment System. Thank you!.\n\n";
            std::cout <<"====================++THANK YOU++============================\n\n";
        }

        system("PAUSE");
    };

	//==================================================================================================
	void ATMAccountHolders::details() {
        system("cls");

        std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT DETAILS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout <<"\n\nThe Names of the Account Holders are :"<<accountHolders<<"\n\n";
        std::cout <<"\tThe Account Holders' address is :"<<accountHoldersAddress<<"\n\n";
        std::cout <<"\tThe Branch location is :"<<branch<<"\n\n";
        std::cout <<"\tAccount number :"<<accountNumber<<"\n\n";
        std::cout <<"\tPresent Balance: " << accountBalance<<"\n\n";
        std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        std::cout <<"Press any key to Return to the Main Menu\n\n";
        system("PAUSE");
    };

	//==================================================================================================
    void ATMAccountHolders::accountExit() {
        system("cls");
        std::cout <<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
        std::cout <<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ ATM ACCOUNT EXIT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
        std::cout <<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
        system("PAUSE");
        exit(1);
    };

int main() {
    system("cls");
    int e;
    ATMAccountHolders p;

    std::cout <<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ WELCOME TO ATM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    std::cout <<"\t\t\t--------------------\n"<<std::endl;
    //Prompt to show today's date
    std::cout << "\t\tCurrent date : ";
    //Show date and time function
    time_t now;
    time(&now);

    printf("%s\n", ctime(&now));;
    //Give space for the function of date and time
    std::cout <<"\t\t\t--------------------\n"<<std::endl;
    std::cout <<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
//==================================================================================================

    std::cout <<"\tPress 1 and Then Press Enter to Access Your Account Via Pin Number\n\n";
    std::cout <<"\t\t\t\t\t or \n\n";
    std::cout <<"\tPress 0 and press Enter to get Help.\n\n";

    int access;
    std::cin >> access;
    switch(access)
    {
        case 1://pin to access account
            system("cls");
            int i, pin;

            std::cout <<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ATM ACCOUNT ACCESS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
            std::cout <<"\n\nEnter Your Acc Pin Access Number! [Only one attempt is allowed]\n\n" << std::endl;
            std::cout <<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
            std::cin >> pin;

            system("cls");


            if(pin==12345) {
                system("cls");
                do {
                    system("cls");

                    std::cout << std::endl << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Main Menu Screen \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" << std::endl << std::endl;
                    std::cout << "\t\tEnter [1] To  Deposit Cash" << std::endl;
                    std::cout << "\t\tEnter [2] To Withdraw Cash" << std::endl;
                    std::cout << "\t\tEnter [3] To Balance Inquiry" << std::endl;
                    std::cout << "\t\tEnter [4] To Pay Bills" << std::endl;
                    std::cout << "\t\tEnter [5] to Pay Account Interest" << std::endl;
                    std::cout << "\t\tEnter [0] to Exit ATM" << std::endl << std::endl;
                    std::cout << "\tPLEASE ENTER A SELECTION AND PRESS RETURN KEY: \n\n";
                    std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

                    std::cin>>e;
                    switch(e) {
                        case 1:
                            p.deposit();
                            break;
                        case 2:
                            p.withdraw();
                            break;
                        case 3:
                            p.details();
                            break;
                        case 4:
                            p.payBills();
                            break;
                        case 5:
                            p.interest();
                            break;
                        case 0:
                            p.accountExit();
                            break;
                        default:
                            std::cout <<"Please Enter the Correct Number Choice"<<std::endl;
                    }
                } while(e!=0);

                break;
            }
            else {
                system("cls");

                std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb THANK YOU \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                std::cout <<"\nYou had made your attempt which failed!!! No More attempts allowed!! Sorry!!\n\n";
                std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                system("PAUSE");
                exit (1);
            }
    //==================================================================================================
        case 0://pin to access account
            system("cls");
            
            std::cout <<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT STATUS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            std::cout <<"\tYou must have the correct pin number to access this acount. See your\n\n";
            std::cout <<"\t  bank representative for assistance during bank opening hours\n\n";
            std::cout <<"\t\tThanks for, your choice today!!\n\n";
            std::cout <<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            
            system("PAUSE");
            exit(1);
            break;
    }
    system("PAUSE");
    return 0;
};
