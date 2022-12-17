#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>

struct id
{
    std::string name;
    std::string no;
    int gpa;
};

struct node
{
    id data;
    node *next;
    node *back;
};

class SDB
{
private:
    node *first, *last, *new_node;
    long int type;
    int counter;
    int flag = 0;

public:
    SDB()
    {
        first = last = NULL;
        int counter = 1;
    }

    int construct(long int i, std::string n, std::string x, long double y)
    {
        if (first == NULL)
        {
            type = i;
            new_node = new node;
            new_node->data.name = n;
            new_node->data.no = x;
            new_node->data.gpa = y;
            new_node->next = NULL;
            new_node->back = NULL;
            first = new_node;
            last = new_node;
            counter++;
            return 1;
        }
        else
        {
            std::cout << "  You used create option previously \n ";
            return 0;
        }
    }

    int insertElement(std::string n, std::string x, long double y)
    {

        new_node = new node;
        new_node->data.name = n;
        new_node->data.no = x;
        new_node->data.gpa = y;

        if (first != NULL)
        {

            switch (type)
            {
            case 1:

                if (first->data.name[0] >= n[0])
                {
                    first->back = new_node;
                    new_node->next = first;
                    new_node->back = NULL;
                    first = new_node;
                    counter++;
                    return 1;
                }

                else if (last->data.name[0] <= n[0])
                {
                    last->next = new_node;
                    new_node->next = NULL;
                    new_node->back = last;
                    last = new_node;
                    counter++;
                    return 1;
                }
                else
                {
                    node *current = first;
                    node *cur_next = current->next;

                    for (; cur_next->next != NULL;)
                    {
                        current = current->next;
                        cur_next = cur_next->next;

                        if (cur_next->data.name[0] >= n[0])
                            break;
                    }

                    cur_next->back = new_node;
                    new_node->next = cur_next;
                    new_node->back = current;
                    current->next = new_node;
                    counter++;
                    return 1;
                }
                break;

            case 2:

                if (first->data.no >= x)
                {
                    first->back = new_node;
                    new_node->next = first;
                    new_node->back = NULL;
                    first = new_node;
                    counter++;
                    return 1;
                }

                else if (last->data.no <= x)
                {
                    last->next = new_node;
                    new_node->next = NULL;
                    new_node->back = last;
                    last = new_node;
                    counter++;
                    return 1;
                }
                else
                {
                    node *current = first;
                    node *cur_next = current->next;

                    for (; cur_next->next != NULL;)
                    {
                        current = current->next;
                        cur_next = cur_next->next;

                        if (cur_next->data.no >= x)
                            break;
                    }

                    cur_next->back = new_node;
                    new_node->next = cur_next;
                    new_node->back = current;
                    current->next = new_node;
                    counter++;
                    return 1;
                }
                break;
            }
        }
        else
        {
            std::cout << " Please use  create option first \n";
            return 0;
        }
    }

    int deleteElement(std::string x)
    {
        if (first != NULL)
        {
            node *del_first = first;
            node *del_last = last;
            node *del_next = del_first->next;
            node *del_back = last->back;

            if (first->data.no == x)
            {
                first = del_next;
                delete (del_first);
                counter--;
                return 1;
            }

            else if (last->data.no == x)
            {
                last = del_back;
                last->next = NULL;
                delete (del_last);
                counter--;
                return 1;
            }
            else
            {

                for (; del_first->next != NULL;)
                {
                    del_first = del_first->next;
                    del_back = del_first->back;
                    del_next = del_first->next;

                    if (x == del_first->data.no)
                    {
                        del_next->back = del_first->back;
                        del_back->next = del_first->next;
                        delete (del_first);
                        flag = 1;
                        counter--;
                        return 1;
                    }
                }
            }

            if (flag == 0)
            {
                std::cout << "Wrong ID \n";
                return 3;
            }
        }
        else
        {
            std::cout << "Empty database !!\n";
            return 0;
        }
    }

    void print(void)
    {
        std::cout << "   Name\t\tID\tGPA\n\n";
        node *pri_ele = first;

        for (; pri_ele != NULL;)
        {
            std::cout << pri_ele->data.name << "\t" << pri_ele->data.no << "\t" << pri_ele->data.gpa << std::endl;
            pri_ele = pri_ele->next;
        }
    }

    int saveFile(void)
    {
        node *save = first;
        int fs = 0;
        std::ofstream fout("save.txt");

        if (!fout.is_open()) // failed to open file
        {
            std::cout << "Could not open the file "
                      << "save.txt" << std::endl;
            return 0;
        }
        fout << " Name\t\tID\tGPA\n\n";

        for (; save != NULL;)
        {
            fout << save->data.name << "\t" << save->data.no << "\t" << save->data.gpa << std::endl;
            save = save->next;
            fs = 1;
        }
        fout.close();
        if (fs == 0)
        {
            std::cout << "Empty database !! \n";
            return 0;
        }
        else
        {
            std::cout << "Done \n";
            return 1;
        }
    }

    int searchElement(std::string x)
    {
        node *sch = first;
        int f = 0;

        if (first == NULL)
        {
            std::cout << "Empty Database \n";
            return 0;
        }
        else
        {
            while (sch != NULL)
            {
                if (sch->data.no == x)
                {
                    std::cout << sch->data.name << "\t" << sch->data.no << "\t" << sch->data.gpa << std::endl;
                    f = 1;
                    return 1;
                    break;
                }
                sch = sch->next;
            }
            if (f == 0)
            {
                std::cout << "Wrong ID \n";
                return 3;
            }
        }
    }

    void help(void)
    {
        system("CLS");
        std::cout << "This program considered as simple database of students in collage , you can make it ordered by name or by ID , there are some functions help you to create a database : \n"
                  << "Crate Function : \n"
                  << "You must use this is function at first to create database ,in this function you must enter type of order ( name or ID ) , if you want to insert another data you can use insert function \n"
                  << "Insert/Delete/Search Functions :\n"
                  << "In this function you can insert/delete/search on any number of data , you must use this functions after using create function \n"
                  << "Save Function :\n"
                  << "You can save data in file after you finish your work ,be attention the folder of program must contain (save.text)\n "
                  << "Thanks for reading \n";
    }
};

void show(void);
int checkNum(int x = 0);
int menu();

int main()
{
    show();
    SDB obj;
    long int type, test, num_cases;
    long int num_insert, num_del, num_search, check_insert, check_del, check_search;
    long double gpa;
    std::string name, id;

    test = 1;

    std::cout << "  Enter your choice: \n";
    num_cases = checkNum(3);

    while (test == 1)
    {
        switch (num_cases)
        {
        case 1:
            system("CLS");
            std::cout << "You chose 1 to create a database, Please enter the Name, ID and GPA of the student\n";

            getline(std::cin, name);
            while (name[0] < 65 || name[0] > 122)
            {
                std::cout << "  Wrong input !\n";
                getline(std::cin, name);
            }

            getline(std::cin, id);

            while (!(std::cin >> gpa) || gpa > 4)
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << " Wrong input !\n";
            }
            while (std::cin.get() != '\n')
                continue;

            std::cout << "  What type of database arrangement you want ? \n "
                      << " 1-Name     2-ID \n";
            type = checkNum(2);

            obj.construct(type, name, id, gpa);

            num_cases = menu();

            break;

        case 2:
            system("CLS");
            std::cout << "  You chose 2 to insert data , Please enter number of students you want to save . \n";

            check_insert = 1;
            num_insert = checkNum(0);

            for (int j = 1; j <= num_insert; j++)
            {
                if (check_insert == 1)
                {
                    std::cout << " Please enter name of student , Please enter the Name, ID and GPA of the student\n";
                    getline(std::cin, name);

                    while (name[0] < 65 || name[0] > 122)
                    {
                        std::cout << "  Wrong Name ! \n";
                        getline(std::cin, name);
                    }

                    getline(std::cin, id);

                    while (!(std::cin >> gpa) || gpa > 4)
                    {
                        std::cin.clear();
                        while (std::cin.get() != '\n')
                            continue;
                        std::cout << " Wrong input !\n";
                    }
                    while (std::cin.get() != '\n')
                        continue;

                    check_insert = obj.insertElement(name, id, gpa);
                }
            }
            num_cases = menu();

            break;

        case 3:
            system("CLS");
            std::cout << "You chose 3 to delete data, Please enter number of students you want to delete  \n";

            check_del = 1;
            num_del = checkNum(0);

            for (int k = 1; k <= num_del; k++)
            {
                if (check_del != 0)
                {

                    std::cout << "Please enter ID of student \n";
                    getline(std::cin, id);
                    check_del = obj.deleteElement(id);
                    if (check_del == 3)
                        k--;
                }
            }

            num_cases = menu();

            break;

        case 4:
            system("CLS");
            std::cout << "You chose 4 to search on data,Please enter number of students you want to search on \n";
            check_search = 1;
            num_search = checkNum();

            for (int l = 1; l <= num_search; l++)
            {
                if (check_search != 0)
                {
                    std::cout << " Please enter ID of student \n";
                    getline(std::cin, id);
                    check_search = obj.searchElement(id);
                    if (check_search == 3)
                        l--;
                }
            }

            num_cases = menu();
            break;

        case 5:
            system("CLS");
            obj.print();
            num_cases = menu();
            break;

        case 6:
            system("CLS");
            int save_cheak;
            save_cheak = obj.saveFile();
            num_cases = menu();

            break;

        case 7:

            obj.help();
            num_cases = menu();
            break;

        case 8:

            exit(EXIT_SUCCESS);
            break;

        default:

            std::cout << "Wrong input ! \n";
            std::cout << "Enter your choice: \n";
            num_cases = checkNum(3);
            break;
        }
    }

    return 0;
}

int checkNum(int x)
{
    int num;

    switch (x)
    {

        case 1:
        case 2:

            while (!(std::cin >> num) || num > 2)
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << " Wrong input !\n";
            }
            while (std::cin.get() != '\n')
                continue;
            break;
        case 3:
            while (!(std::cin >> num) || num > 8)
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << " Wrong input !\n";
            }
            while (std::cin.get() != '\n')
                continue;
            break;

        default:

            while (!(std::cin >> num))
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << " Wrong input !\n";
            }
            while (std::cin.get() != '\n')
                continue;
            break;
    }

    return num;
}
int login();
void show(void)
{
    login();

    std::cout << "\n\t      ------WELCOME TO DATABASE MANAGEMENT SYSTEM------                           \n\n";

    std::cout << "********************************************************************************\n"
              << "********************************************************************************\n"
              << "***  1- Create Database                                                      ***\n"
              << "***  2- Insert Data                                                          ***\n"
              << "***  3- Delete Data                                                          ***\n"
              << "***  4- Search on Data                                                       ***\n"
              << "***  5- Print Data                                                           ***\n"
              << "***  6- Save                                                                 ***\n"
              << "***  7- Help                                                                 ***\n"
              << "***  8- Exit                                                                 ***\n"
              << "********************************************************************************\n"
              << "********************************************************************************\n";
}

int menu()
{
    int num_cases;
    std::cout << "  Do you want to do another operation?\n "
              << " 1- Yes   2-No \n";

    int t = checkNum(1);

    if (t == 1)
    {
        system("cls");
        show();
        std::cout << "Enter your choice: \n";
        num_cases = checkNum(3);
        return num_cases;
    }
    else
        return 8;
}

int login()
{
    std::string pass = "";
    char ch;
    std::cout << "\n\n\n\n\t\t\t\t     Database Management System";
    std::cout << "\n\n\n\n\n\n\n\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13)
    { // character 13 is enter
        pass.push_back(ch);
        std::cout << '*';
        ch = _getch();
    }
    if (pass == "pass")
    {
        std::cout << "\n\n\t\t\t\t\tAccess Granted \n";
    }
    else
    {
        std::cout << "\n\n\t\t\t\t\tAccess Aborted...Press Any Key To Try Again\n";
        ch = _getch();
        system("CLS");
        login();
    }
    system("PAUSE");
    system("CLS");
    return 1;
}
