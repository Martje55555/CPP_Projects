/*********************************************************************
* Student Report System                                              *
*********************************************************************/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

class Student {
    int id;
    char name[50];
    int eng_marks, math_marks, sci_marks, lang2_marks, cs_marks;
    double average;
    char grade;

    public:
        void getData();
        void showData() const;
        void calculate();
        int returnIdNumber() const;
};

void Student::calculate() {
    average = (eng_marks+math_marks+sci_marks+lang2_marks+cs_marks) / 5.0;

    if(average>=90)
        grade='A';
    else if(average>=75)
        grade='B';
    else if(average>=50)
        grade='C';
    else
        grade='F';
}

void Student::getData() {
    std::cout<<"\nEnter student's ID number: ";
    std::cin>>id;

    std::cout<<"\n\nEnter student name: ";
    std::cin.ignore();
    std::cin.getline(name,50);

    std::cout<<"\nAll marks should be out of 100";
    std::cout<<"\nEnter marks in English: ";
    std::cin>>eng_marks;

    std::cout<<"\nEnter marks in Math:  ";
    std::cin>>math_marks;

    std::cout<<"\nEnter marks in Science:  ";
    std::cin>>sci_marks;

    std::cout<<"\nEnter marks in 2nd language:  ";
    std::cin>>lang2_marks;

    std::cout<<"\nEnter marks in Computer science:  ";
    std::cin>>cs_marks;
    calculate();
}

void Student::showData() const {
    std::cout<<"\nRoll number of student : " << id;
    std::cout<<"\nName of student : " << name;
    std::cout<<"\nEnglish : " << eng_marks;
    std::cout<<"\nMaths : " << math_marks;
    std::cout<<"\nScience : " << sci_marks;
    std::cout<<"\nLanguage2 : " << lang2_marks;
    std::cout<<"\nComputer Science : " << cs_marks;
    std::cout << std::setprecision(2);
    std::cout<<"\nAverage Marks :" << std::fixed << average;
    std::cout<<"\nGrade of student is : " << grade;
}

int  Student::returnIdNumber() const {
    return id;
}

void createStudent();
void displayStudent(int);
void displayAll();
void deleteStudent(int);
void updateStudent(int);

int main() {
    char ch;
    std::cout<<std::setprecision(2);

    do {
        char ch;
        int num;
        system("cls");
        std::cout<<"\n\n\n\tMENU";
        std::cout<<"\n\n\t1.Create student record";
        std::cout<<"\n\n\t2. Search student record";
        std::cout<<"\n\n\t3. Display all students records ";
        std::cout<<"\n\n\t4.Delete student record";
        std::cout<<"\n\n\t5.Modify student record";
        std::cout<<"\n\n\t6.Exit";
        std::cout<<"\n\nWhat is your Choice (1/2/3/4/5/6) ";
        std::cin>>ch;
        system("cls");
        switch(ch) {
            case '1':
                createStudent(); break;
            case '2':
                std::cout<<"\n\n\tEnter their ID number "; 
                std::cin>>num;
                displayStudent(num);
                break;
            case '3':
                displayAll();
                break;
            case '4':
                std::cout<<"\n\n\tEnter their ID number: "; 
                std::cin>>num;
                deleteStudent(num);break;
            case '5':
                std::cout<<"\n\n\tEnter their ID number ";
                std::cin>>num;
                updateStudent(num);break;
            case '6':
                std::cout<<"Exiting, Thank you!\n";
                exit(0);
        }
    } while(ch!='6');
    return 0;
}

void createStudent() {
    Student student;
    std::ofstream oFile;
    oFile.open("student.dat",std::ios::binary|std::ios::app);
    student.getData();
    oFile.write(reinterpret_cast<char *> (&student), sizeof(Student));
    oFile.close();
    std::cout<<"\n\nStudent record Has Been Created ";
    std::cin.ignore();
    std::cin.get();
}

void displayAll() {
    Student student;
    std::ifstream inFile;
    inFile.open("student.dat",std::ios::binary);
    if(!inFile) {
        std::cout<<"File could not be opened !! Press any Key to exit";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    while(inFile.read(reinterpret_cast<char *> (&student), sizeof(Student))) {
        student.showData();
        std::cout<<"\n\n====================================\n";
    }
    inFile.close();
    std::cin.ignore();
    std::cin.get();
}

void displayStudent(int n) {
    Student student;
    std::ifstream iFile;
    iFile.open("student.dat",std::ios::binary);

    if(!iFile) {
        std::cout<<"File could not be opened... Press any Key to exit";
        std::cin.ignore();
        std::cin.get();
        return;
    }

    bool flag=false;
    while(iFile.read(reinterpret_cast<char *> (&student), sizeof(Student))) {
        if(student.returnIdNumber()==n) {
            student.showData();
            flag=true;
        }
    }

    iFile.close();
    if(flag==false) std::cout<<"\n\nrecord does not exist";
    std::cin.ignore();
    std::cin.get();
}

void updateStudent(int n) {
    bool found = false;
    Student student;
    std::fstream fl;
    fl.open("student.dat",std::ios::binary|std::ios::in|std::ios::out);
    if(!fl) {
        std::cout<<"File could not be opened. Press any Key to exit...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    while(!fl.eof() && found==false) {
        fl.read(reinterpret_cast<char *> (&student), sizeof(Student));
        if(student.returnIdNumber()==n) {
            student.showData();
            std::cout<<"\nEnter new student details:"<<std::endl;
            student.getData();
            int pos=(-1)*static_cast<int>(sizeof(student));
            fl.seekp(pos,std::ios::cur);
            fl.write(reinterpret_cast<char *> (&student), sizeof(Student));
            std::cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    fl.close();
    if(found==false)
    std::cout<<"\n\n Record Not Found ";
    std::cin.ignore();
    std::cin.get();
}

void deleteStudent(int n) {
    Student student;
    std::ifstream iFile;
    iFile.open("student.dat",std::ios::binary);
    if(!iFile) {
        std::cout<<"File could not be opened... Press any Key to exit...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::ofstream oFile;
    oFile.open("Temp.dat",std::ios::out);
    iFile.seekg(0,std::ios::beg);
    while(iFile.read(reinterpret_cast<char *> (&student), sizeof(Student))) {
        if(student.returnIdNumber()!=n)
            oFile.write(reinterpret_cast<char *> (&student), sizeof(Student));
    }
    oFile.close();
    iFile.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    std::cout<<"\n\n\tRecord Deleted ..";
    std::cin.ignore();
    std::cin.get();
}