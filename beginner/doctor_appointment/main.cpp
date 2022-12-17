#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

int bookAppointment() {
    system("cls");
    std::cout<<"\n ----- Book Your Appointment ---- \n";	
    std::cout<<"\n ----- Availbale slots ---- \n";	 

    //check if record already exist..
    std::ifstream read;
    read.open("appointment.dat");
    
    int hoursbook = 8;
    
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
     
    if(read)
    {     
		std::string line;
		char key = 'A';
		int i = 9;
			
		while(std::getline(read, line)) {
			char temp = line[0];
			int index = (temp - 65);
			arr[index]=1;  
			recordFound = 1;
		}
		if(recordFound == 1)
		{
			std::cout<<"\n Appointment Summary by hours:";
			char key = 'A';
			int hours = 9;
			for(int i = 0; i<=12; i++)
			{
				if(i == 0){
					if(arr[i] == 0) 
						std::cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
					else
						std::cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
				}
				else
				{								           	
					if(arr[i] == 0) 
						std::cout<<"\n "<<key<<"->"<<hours<<" - Available";
					else
						std::cout<<"\n "<<key<<"->"<<hours<<" - Booked";
				}
				hours++;
				key++;
			}
		}
		read.close();
    }

	if(recordFound == 0){
		std::cout<<"\n Appointment Available for following hours :";
		char key = 'A';
		for(int i = 9; i<=21; i++)
		{
			if(i==9)
				std::cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
			else
				std::cout<<"\n "<<key<<" -> "<<i<<" - Available";
			key++;
		}
	}
   
   char choice;
   std::cout<<"\n\n Input your choice : ";
   std::cin>>choice;
   
   if( !(choice >= 'A' && choice <='Z')) {
		std::cout <<"\n Error : Invalid Selection";
		std::cout <<"\n Please selction correct value from menu A- Z";
		std::cout <<"\n Press any key to continue";
		getchar();getchar();
		system("cls");
		bookAppointment();
   }
   
   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0) 
   		isBooked = 0;
      
   if(isBooked == 1) {
		std::cout<<"\n Error : Appointment is already booked for this Hour";
		std::cout<<"\n Please select different time !!";
		std::cout<<"\n Press any key to continue!!";
		getchar();getchar();
		system("cls");
		bookAppointment();
   }
   
   std::string name;
   std::cout<<"\n Enter your first name:";
   std::cin>>name;  
   
   std::ofstream out;
   out.open("appointment.dat", std::ios::app);
	
   if(out) {
	   	out<<choice<<":"<<name.c_str()<<"\n";
	   	out.close();
	  	std::cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
    }
    else {
		std::cout<<"\n Error while saving booking";
    }

    std::cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}

int existingAppointment()
{
    system("cls");
    std::cout<<"\n ----- Appointments Summary ---- \n";	
    //check if record already exist..
   	std::ifstream read;
    read.open("appointment.dat");
    
    int hoursbook = 8;
    
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     int recordFound =0; 
     
    if(read)
    {     
		std::string line;
		char key = 'A';
		int i = 9;
			
		while(std::getline(read, line)) {
			char temp = line[0];
			int index = (temp - 65);
			arr[index]=1;  
			recordFound = 1;
		}
			if(recordFound == 1)
			{
				std::cout<<"\n Appointment Summary by hours:";
				char key = 'A';
				int hours = 9;
				for(int i = 0; i<=12; i++)
				{
					if(arr[i] == 0) 
						std::cout<<"\n "<<key<<"->"<<hours<<" - Available";
					else
						std::cout<<"\n "<<key<<"->"<<hours<<" - Booked";
					hours++;
					key++;
				}
				
			}
		read.close();
    }
    else
    {
		char key = 'A';
		for(int i = 9; i<=21; i++)
		{
			if(i==9)
				std::cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
			else
				std::cout<<"\n "<<key<<" -> "<<i<<" - Available";
			key++;
		}
    }
    
    std::cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;	 
}

int main(int argc, char** argv) {
	while(1) {
		system("cls");
		std::cout<<"\t\t\tDoctor Appointment System\n";
		std::cout<<"----------------------------------------\n\n";
		
		std::cout<<"1. Book Appointment\n";
		std::cout<<"2. Check Existing Appointment\n";
		std::cout<<"0. Exit\n";
		int choice;
		
		std::cout<<"\n Enter you choice: ";
		std::cin>>choice;
		
		switch(choice)
		{
			case 1:
				bookAppointment();
				break;
			case 2:
				existingAppointment();
				break;
			case 0: 
		        while(1)
		        {
				 	system("cls");
		        	std::cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char ex;
		        	std::cin>>ex;
		        	if(ex == 'y' || ex == 'Y')
		        		exit(0);
		        	else if(ex == 'n' || ex == 'N')
                     	break;
                     else {
                     	std::cout<<"\n Invalid choice !!!";
                     	getchar();
                     }
             	 }	break;
                 	 
            default: std::cout<<"\n Invalid choice. Enter again ";
                     getchar();
                 	
		}   		        

	}
	return 0;
}   