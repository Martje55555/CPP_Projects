#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>

int k=7,r=0,flag=0;
COORD coord = {0, 0};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct date {
    int mm,dd,yy;
};

std::ofstream fout;
std::ifstream fin;

class Item {
    int itemno;
    char name[25];
    date d;
public:
    void add()
    {
        std::cout<<"\n\n\tItem No: ";
        std::cin>>itemno;
        std::cout<<"\n\n\tName of the item: ";
        std::cin>>name;
        std::cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        std::cin>>d.mm>>d.dd>>d.yy;
    }
    void show()
    {
        std::cout<<"\n\tItem No: ";
        std::cout<<itemno;
        std::cout<<"\n\n\tName of the item: ";
        std::cout<<name;
        std::cout<<"\n\n\tDate : ";
        std::cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
    void report()
    {
        gotoxy(3,k);
        std::cout<<itemno;
        gotoxy(13,k);
        puts(name);
    }
    int retItemNo()
    {
        return(itemno);
    }

};

class Amount: public Item
{
    float price,qty,tax,gross,dis,netamt;
public:
    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float retnetamt() {
        return(netamt);
    }
} amt;

void Amount::add() {
    Item::add();
    std::cout<<"\n\n\tPrice: ";
    std::cin>>price;
    std::cout<<"\n\n\tQuantity: ";
    std::cin>>qty;
    std::cout<<"\n\n\tTax percent: ";
    std::cin>>tax;
    std::cout<<"\n\n\tDiscount percent: ";
    std::cin>>dis;
    calculate();
    fout.write((char *)&amt,sizeof(amt));
    fout.close();
}
void Amount::calculate() {
    gross=price+(price*(tax/100));
    netamt=qty*(gross-(gross*(dis/100)));
}
void Amount::show() {
    fin.open("itemstore.dat",std::ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    Item::show();
    std::cout<<"\n\n\tNet amount: ";
    std::cout<<netamt;
    fin.close();
}

void Amount::report() {
    Item::report();
    gotoxy(23,k);
    std::cout<<price;
    gotoxy(33,k);
    std::cout<<qty;
    gotoxy(44,k);
    std::cout<<tax;
    gotoxy(52,k);
    std::cout<<dis;
    gotoxy(64,k);
    std::cout<<netamt;
    k=k+1;
    if(k==50)
    {
        gotoxy(25,50);
        std::cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        std::cout<<" ITEM DETAILS ";
        gotoxy(3,5);
        std::cout<<"NUMBER";
        gotoxy(13,5);
        std::cout<<"NAME";
        gotoxy(23,5);
        std::cout<<"PRICE";
        gotoxy(33,5);
        std::cout<<"QUANTITY";
        gotoxy(44,5);
        std::cout<<"TAX";
        gotoxy(52,5);
        std::cout<<"DEDUCTION";
        gotoxy(64,5);
        std::cout<<"NET AMOUNT";
    }
}

void Amount::pay() {
    show();
    std::cout<<"\n\n\n\t\t*********************************************";
    std::cout<<"\n\t\t                 DETAILS                  ";
    std::cout<<"\n\t\t*********************************************";
    std::cout<<"\n\n\t\tPRICE                     :"<< price;
    std::cout<<"\n\n\t\tQUANTITY                  :"<< qty;
    std::cout<<"\n\t\tTAX PERCENTAGE              :"<< tax;
    std::cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<< dis;
    std::cout<<"\n\n\n\t\tNET AMOUNT              :Rs."<< netamt;
    std::cout<<"\n\t\t*********************************************";
}

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout << std::setprecision(2);
    std::fstream tmp("temp.dat", std::ios::binary | std::ios::out);
menu:
    system("cls");
    gotoxy(25,2);
    std::cout<<"Super Market Billing ";
    gotoxy(25,3);
    std::cout << "===========================\n\n";
    std::cout << "\n\t\t1.Bill Report\n\n";
    std::cout << "\t\t2.Add/Remove/Edit Item\n\n";
    std::cout << "\t\t3.Show Item Details\n\n";
    std::cout << "\t\t4.Exit\n\n";
    std::cout << "\t\tPlease Enter Required Option: ";
    int ch,ff;
    float gtotal;
    std::cin>>ch;
    switch(ch) {
    case 1:
ss:
        system("cls");
        gotoxy(25,2);
        std::cout<<"Bill Details";
        gotoxy(25,3);
        std::cout<<"================\n\n";
        std::cout<<"\n\t\t1.All Items\n\n";
        std::cout<<"\t\t2.Back to Main menu\n\n";
        std::cout<<"\t\tPlease Enter Required Option: ";
        int cho;
        std::cin>>cho;
        if(cho==1)
        {
            system("cls");
            gotoxy(30,3);
            std::cout<<" BILL DETAILS ";
            gotoxy(3,5);
            std::cout<<"ITEM NO";
            gotoxy(13,5);
            std::cout<<"NAME";
            gotoxy(23,5);
            std::cout<<"PRICE";
            gotoxy(33,5);
            std::cout<<"QUANTITY";
            gotoxy(44,5);
            std::cout<<"TAX %";
            gotoxy(52,5);
            std::cout<<"DISCOUNT %";
            gotoxy(64,5);
            std::cout<<"NET AMOUNT";
            fin.open("itemstore.dat",std::ios::binary);
            if(!fin)
            {
                std::cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            gtotal=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    amt.report();
                    gtotal+=amt.retnetamt();
                    ff=0;
                }
                if(ff!=0) gtotal=0;
            }
            gotoxy(17,k);
            std::cout<<"\n\n\n\t\t\tGrand Total="<<gtotal;
            getch();
            fin.close();
        }
        if(cho==2)
        {
            goto menu;
        }
        goto ss;
    case 2:
db:
        system("cls");
        gotoxy(25,2);
        std::cout<<"Bill Editor";
        gotoxy(25,3);
        std::cout<<"=================\n\n";
        std::cout<<"\n\t\t1.Add Item Details\n\n";
        std::cout<<"\t\t2.Edit Item Details\n\n";
        std::cout<<"\t\t3.Delete Item Details\n\n";
        std::cout<<"\t\t4.Back to Main Menu ";
        int apc;
        std::cin>>apc;
        switch(apc)
        {
        case 1:
            fout.open("itemstore.dat",std::ios::binary | std::ios::app);
            amt.add();
            std::cout<<"\n\t\tItem Added Successfully!";
            getch();
            goto db;

        case 2:
            int ino;
            flag=0;
            std::cout<<"\n\n\tEnter Item Number to be Edited :";
            std::cin>>ino;
            fin.open("itemstore.dat", std::ios::binary);
            fout.open("itemstore.dat", std::ios::binary | std::ios::app);
            if(!fin)
            {
                std::cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            r=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    int x=amt.Item::retItemNo();
                    if(x==ino)
                    {
                        flag=1;
                        fout.seekp(r*sizeof(amt));
                        system("cls");
                        std::cout<<"\n\t\tCurrent Details are\n";
                        amt.show();
                        std::cout<<"\n\n\t\tEnter New Details\n";
                        amt.add();
                        std::cout<<"\n\t\tItem Details editted";
                    }
                }
                r++;
            }
            if(flag==0)
            {
                std::cout<<"\n\t\tItem No does not exist...Please Retry!";
                getch();
                goto db;
            }
            fin.close();
            getch();
            goto db;

        case 3:
            flag=0;
            std::cout<<"\n\n\tEnter Item Number to be deleted :";
            std::cin>>ino;
            fin.open("itemstore.dat", std::ios::binary);
            if(!fin)
            {
                std::cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            while(fin.read((char*)&amt, sizeof(amt)))
            {
                int x=amt.Item::retItemNo();
                if(x!=ino)
                    tmp.write((char*)&amt,sizeof(amt));
                else
                {
                    flag=1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("itemstore.dat", std::ios::trunc | std::ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat", std::ios::binary | std::ios::in);
            if(!tmp)
            {
                std::cout<<"Error in File";
                goto db;
            }
            while(tmp.read((char*)&amt,sizeof(amt)))
                fout.write((char*)&amt,sizeof(amt));
            tmp.close();
            fout.close();
            if(flag==1)
                std::cout<<"\n\t\tItem Succesfully Deleted";
            else if (flag==0)
                std::cout<<"\n\t\tItem does not Exist! Please Retry";
            getch();
            goto db;
        case 4:
            goto menu;
        default:
            std::cout<<"\n\n\t\tWrong Choice!!! Retry";
            getch();
            goto db;
        }
    case 3:
        system("cls");
        flag=0;
        int ino;
        std::cout<<"\n\n\t\tEnter Item Number :";
        std::cin>>ino;
        fin.open("itemstore.dat", std::ios::binary);
        if(!fin)
        {
            std::cout<<"\n\nFile Not Found...\nProgram Terminated!";
            goto menu;
        }
        fin.seekg(0);
        while(fin.read((char*)&amt,sizeof(amt)))
        {
            int x=amt.Item::retItemNo();
            if(x==ino)
            {
                amt.pay();
                flag=1;
                break;
            }
        }
        if(flag==0)
            std::cout<<"\n\t\tItem does not exist....Please Retry!";
        getch();
        fin.close();
        goto menu;
    case 4:
        system("cls");
        gotoxy(20,20);
        std::cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
        char yn;
        std::cin>>yn;
        if((yn=='Y')||(yn=='y'))
        {
            gotoxy(12,20);
            system("cls");
            std::cout<<"************************** THANKS **************************************";
            getch();
            exit(0);
        }
        else if((yn=='N')||(yn=='n'))
            goto menu;
        else
        {
            goto menu;
        }
    default:
        std::cout<<"\n\n\t\tWrong Choice....Please Retry!";
        getch();
        goto menu;
    }
    return 0;
}
