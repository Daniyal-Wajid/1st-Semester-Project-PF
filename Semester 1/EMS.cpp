#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct employee{
	string name;
	int id;
	string department;
	int age,salary;
	string phone;
};

void add_employee();

void single_employee();

void list_employee();

void update_employee();

void delete_employee();

int check_id(int chk);

int main(){
	system("cls");
	int choice;
	cout<<" => Press 1. ADD EMPLOYEE \n";
	cout<<" => Press 2. SINGLE EMPLOYEE DETAILS \n";
	cout<<" => Press 3. LIST OF EMPLOYEE'S \n";
	cout<<" => Press 4. UPDATE EMPLOYEE DATA \n";
	cout<<" => Press 5. DELETE EMPLOYEE DATA \n";
	cout<<" => Press 0. EXIT PROGRAM \n";
loop1:
	cout<<"\n ENTER KEY TO CONTINUE : ";
	cin>>choice;
	switch(choice){
		case 1:
			add_employee();
			break;
		case 2:
			single_employee();
			break;
		case 3:
			list_employee();
			break;
		case 4:
			update_employee();
			break;	
		case 5:
			delete_employee();
			break;
		case 0:
			cout<<" PROGRAM END.";
			break;
		default :
			cout<<" YOU ENTER WRONG CHOICE.\n\n";
			goto loop1;		
	}
}

void add_employee(){
	system("cls");
	employee add;
	int check,length=0;
	
					// ***** SAVE DATA TO (ADD) IN EMPLOYEE STRUCT *****
		
	cin.ignore();

loop1:		
	cout<<" ENTER NAME : ";
	getline(cin,add.name);
	
	// ***** GET LENGTH OF STRING & CHECK ITS ALL CHARACTER OR NOT *****
	
	length=add.name.length();
	cout<<length;
		for(int i=0;i<length;i++)
		{
			if(add.name[i]>='0' && add.name[i]<='9')
			{	
				cout<<" YOU ENTER WRONG NAME. \n";
				goto loop1;
			}
		}
	
loop2:
	
	cout<<" ENTER ID : ";
	cin>>add.id;
	
	// CALL FUNCTION TO CHK ID IS AVAILABLE OR NOT
	
	check=check_id(add.id);		
		if(check==1)
		{
			cout<<" ID IS REGISTERED, TRY AGAIN \n";
			goto loop2;
		}
	
	cout<<" ENTER DEPARTMENT : ";
	cin.ignore();
	getline(cin,add.department);
	cout<<" ENTER AGE : ";
	cin>>add.age;
	cout<<" ENTER SALARY : ";
	cin>>add.salary;
	
	cin.ignore();
loop3:
	
	cout<<" ENTER  PHONE NO. : ";
	getline(cin,add.phone);
	
	// ***** GET LENGTH OF STRING & CHECK ITS ALL DIGITS OR NOT *****
	
	length=add.phone.length();
		for(int j=0;j<length;j++)
		{
			if((add.phone[j]>='a'&& add.phone[j]<='z') || (add.phone[j]>='A'&& add.phone[j]<='Z'))
			{	
				cout<<" YOU ENTER WRONG PHONE NO.\n";
				goto loop3;
			}
		}
	
				// ***** SAVE DATA OF EMPLOYEE TO FILE *****
	
	ofstream write;
	write.open("employee.txt",ios::app);	//append mode
	
	write<<add.name<<endl;	
	write<<add.id<<endl;	
	write<<add.department<<endl;	
	write<<add.age<<endl;	
	write<<add.salary<<endl;	
	write<<add.phone<<endl;	
	
	write.close();
	cout<<"\n DATA ENTER SUCCESSFULLY. \n\n";
	system("pause");	
	main();
}

void single_employee(){
	system("cls");
	employee view;
	ifstream read;
	read.open("employee.txt",ios::in); //read mode
	
	// ***** READ DATA OF EMPLOYEE FROM FILE & SAVE DATA TO (VIEW) IN EMPLOYEE STRUCT *****
	
	getline(read,view.name);	
	read>>view.id;
	read.get();	
	getline(read,view.department);	
	read>>view.age;	
	read>>view.salary;
	read.get();	
	getline(read,view.phone);
	
	// ***** DATA PRESENT IN FILE OR NOT / FILE IS PRESENT OR NOT *****
	
	if(view.name!="\0" && view.id!=0)	
	{	
		int id;
		cout<<" ENTER ID TO SEARCH : ";
		cin>>id; 
		
		// ***** READ DATA AT THE END OF FILE *****
		
		while(read.eof()==0)
		{
	
		// ***** SEARCH FOR SPECIFIC EMPLOYEE DATA *****
	
			if(view.id==id && view.name!="\0")
			{
				cout<<"\n NAME       : ";
				cout<<view.name<<endl;
				cout<<" ID         : ";
				cout<<view.id<<endl;
				cout<<" DEPARTMENT : ";
				cout<<view.department<<endl;
				cout<<" AGE        : ";
				cout<<view.age<<endl;	
				cout<<" SALARY     : ";
				cout<<view.salary<<endl;
				cout<<" PHONE      : ";
				cout<<view.phone<<"\n"<<endl;
				break;
			}
			
			else 
			{
				
			// ***** AGAIN READ IF SPECIFIC DATA ID IS NOT FOUND *****
			
				getline(read,view.name);
				read>>view.id;
				read.get();
				getline(read,view.department);
				read>>view.age;
				read>>view.salary;
				read.get();
				getline(read,view.phone);
		
			// ***** ID NOT FOUND IN THAT FILE *****	
		
				if(view.id!=id && view.name=="\0")
					{
						cout<<" ID NOT FOUND.\n\n";
						break;
					}
			}
		}
		
		read.close();
		system("pause");
		main();
	}	
	
	// ***** IF DATA IS NOT PRESENT IN THAT FILE *****
	
	else
	{	
		read.close();
		cout<<" NO DATA FOUND IN FILE TO SHOW SINGLE DATA.\n\n";
		system("pause");
		main();
	}
}

void list_employee(){
	
	system("cls");
	employee list;
	ifstream read;
	read.open("employee.txt",ios::in);
	
	// ***** READ DATA OF EMPLOYEE FROM FILE & SAVE DATA TO (LIST) IN EMPLOYEE STRUCT *****
	
	getline(read,list.name);	
	read>>list.id;
	read.get();	
	getline(read,list.department);	
	read>>list.age;	
	read>>list.salary;
	read.get();	
	getline(read,list.phone);
	
	// ***** DATA PRESENT IN FILE OR NOT / FILE IS PRESENT OR NOT *****
	
	if(list.name!="\0" && list.id!=0)	
	{
		// ***** READ DATA AT THE END OF FILE *****
	
		while(read.eof()==0)
		{
			// ***** IF DATA IS PRESENT IN FILE SHOW ALL DATA *****
			
			if(list.name!="\0" )
			{
				cout<<"\n NAME       : ";
				cout<<list.name<<endl;
				cout<<" ID         : ";
				cout<<list.id<<endl;
				cout<<" DEPARTMENT : ";
				cout<<list.department<<endl;
				cout<<" AGE        : ";
				cout<<list.age<<endl;	
				cout<<" SALARY     : ";
				cout<<list.salary<<endl;
				cout<<" PHONE      : ";
				cout<<list.phone;
				cout<<"\n\n-----------------------------------------\n";
			}
			
			// ***** IF DATA NOT PRESENT IN FILE *****
			
			else
			{
				cout<<" DATA NOT FOUND.\n\n";
				break;
			}
				
			// ***** AGAIN READ DATA FROM FILE *****
			
			getline(read,list.name);
			read>>list.id;
			read.get();
			getline(read,list.department);
			read>>list.age;
			read>>list.salary;
			read.get();
			getline(read,list.phone);
	
		}
		
		read.close();
		system("pause");
		main();
	}

	// ***** IF FILE IS NOT PRESENT *****

	else
		{	
			read.close();
			cout<<" NO DATA FOUND IN FILE SHOW LIST.\n\n";
			system("pause");
			main();
		}
}

void update_employee(){
	
	system("cls");
	employee newdata;
	employee olddata;
	
	ifstream read;
	read.open("employee.txt",ios::in);
	
	// ***** READ ALL DATA FROM FILE & STORE IN NEW FILE FILE *****
	
	getline(read,olddata.name);	
	read>>olddata.id;
	read.get();	
	getline(read,olddata.department);	
	read>>olddata.age;	
	read>>olddata.salary;
	read.get();	
	getline(read,olddata.phone);
	
	// ***** CHECK DATA PRESENT IN FILE OR NOT / FILE IS PRESENT OR NOT *****
	
	if(olddata.name!="\0" && olddata.id!=0)	
	{	
		int id,check,length;
				
		cout<<" ENTER ID TO UPDATE : ";
		cin>>id;
		
		// ***** CKECK ID IS PRESENT OR NOT *****
		
		check=check_id(id);			// CALL CHECK_ID FUNCTION & ITS VALUE SAVE IN CHECK 
	
		if(check==1)
		{
			ofstream newfile;
			newfile.open("newdata.txt",ios::app);
			
			while(read.eof()==0)
			{ 
				/* ***** IF ENTERED ( ID ) IS NOT EQUAL IT COPY ALL DATA 
							ACCEPT THAT ( ID ) TO BE UPDATED *****  */
							
				if(id != olddata.id)
				{
					newfile<<olddata.name<<endl;	
					newfile<<olddata.id<<endl;	
					newfile<<olddata.department<<endl;	
					newfile<<olddata.age<<endl;	
					newfile<<olddata.salary<<endl;	
					newfile<<olddata.phone<<endl;
				}
				
				/* ***** NEW DATA IS ENTER IN FILE THAT IS TAKKEN 
								BELOW ***** */
				else 
				{	
			
					cin.ignore();
			loop4:
					cout<<" ENTER NAME : ";
					getline(cin,newdata.name);
					
			// ***** GET LENGTH OF STRING & CHECK ITS ALL CHARACTER OR NOT *****
					
					length=newdata.name.length();
						for(int i=0;i<length;i++)
						{
							if(newdata.name[i]>='0'&& newdata.name[i]<='9')
							{	
								cout<<" YOU ENTER WRONG NAME. \n";
								goto loop4;
							}
						}
						
					newdata.id=id;
					cout<<" ENTER DEPARTMENT : ";
					getline(cin,newdata.department);
					cout<<" ENTER AGE : ";
					cin>>newdata.age;
					cout<<" ENTER SALARY : ";
					cin>>newdata.salary;
					cin.ignore();
					
			loop5:					
					cout<<" ENTER  PHONE NO. : ";
					getline(cin,newdata.phone);
			
				// ***** GET LENGTH OF STRING & CHECK ITS ALL DIGIT OR NOT *****

					length=newdata.phone.length();
						for(int j=0;j<length;j++)
						{
							if(newdata.phone[j]>='a'&& newdata.phone[j]<='z')
							{	
								cout<<" YOU ENTER WRONG PHONE NO. \n";
								goto loop5;
							}
						}
					
					// ***** NEW DATA IS ENTER IN FILE *****
					 
					newfile<<newdata.name<<endl;	
					newfile<<newdata.id<<endl;	
					newfile<<newdata.department<<endl;	
					newfile<<newdata.age<<endl;	
					newfile<<newdata.salary<<endl;	
					newfile<<newdata.phone<<endl;
					
					cout<<"\n DATA IS UPDATED.\n\n";
				}
				
			// ***** READ DATA FROM FILE THAT IS TO BE COPIED IN NEW FILE *****
				
			getline(read,olddata.name);	
			read>>olddata.id;
			read.get();	
			getline(read,olddata.department);	
			read>>olddata.age;	
			read>>olddata.salary;
			read.get();	
			getline(read,olddata.phone);
			
		}
			read.close();
			newfile.close();
			remove("employee.txt");
			rename("newdata.txt","employee.txt");
			system("pause");
			main();
		}
		
		// ***** IF ID NOT FOUND IN FILE *****
		
		else
		{	
			read.close();
			cout<<" ID NOT FOUND.\n\n";
			system("pause");
			main();
		}	
	}
	
	// ***** IF FILE NOT PRESENT *****
	
	else
	{	
		read.close();
		cout<<" NO DATA FOUND IN FILE TO UPDATE.\n\n";
		system("pause");
		main();
	}
}

void delete_employee(){
	
	system("cls");
	employee del;

	ifstream read;
	read.open("employee.txt",ios::in);
	
	getline(read,del.name);	
	read>>del.id;
	read.get();	
	getline(read,del.department);	
	read>>del.age;	
	read>>del.salary;
	read.get();	
	getline(read,del.phone);
		
	// ***** DATA PRESENT IN FILE OR NOT / FILE IS PRESENT OR NOT *****
		
	if(del.name!="\0" && del.id!=0)
	{
		int id,check;
		cout<<" Enter ID You Want To Delete : ";
		cin>>id;
		
			// ***** CKECK ID IS PRESENT OR NOT *****
		
		check=check_id(id);			// CALL CHECK_ID FUNCTION & ITS VALUE SAVE IN CHECK 
				
		if(check==1)
		{
			ofstream newfile;
			newfile.open("newdata.txt",ios::app);
		
			while(read.eof()==0)
			{	
			
			//***** COPY ALL DATA EXCEPT THAT ID IS ENTERED *****
			
				if(id != del.id)
				{
					newfile<<del.name<<endl;	
					newfile<<del.id<<endl;	
					newfile<<del.department<<endl;	
					newfile<<del.age<<endl;	
					newfile<<del.salary<<endl;	
					newfile<<del.phone<<endl;
				}
				
			//***** AGAIN READ DATA IN FILE TO COPY ***** 
				
				getline(read,del.name);	
				read>>del.id;
				read.get();	
				getline(read,del.department);	
				read>>del.age;	
				read>>del.salary;
				read.get();	
				getline(read,del.phone);
			}
			
			read.close();
			newfile.close();
			cout<<" DATA IS DELETED.\n\n";
			remove("employee.txt");
			rename("newdata.txt","employee.txt");
			system("pause");
			main();
		}
		
		// ***** IF ID IS NOT PRESENT IN FILE *****
		
		else
		{	
			read.close();
			cout<<" ID NOT FOUND.\n\n";
			system("pause");
			main();
		}
	}
	
	// ***** IF FILE IS NOT PRESENT *****
	
	else
	{
		read.close();
		cout<<" NO DATA FOUND IN FILE TO DELETE.\n\n";
		system("pause");
		main();
	}
}

int check_id(int chk){
	
	employee obj;
	
	ifstream read;
	read.open("employee.txt",ios::in);
	
	// ***** READ DATA OF EMPLOYEE FROM FILE & SAVE DATA TO (obj) IN EMPLOYEE STRUCT *****
	
	getline(read,obj.name);	
	read>>obj.id;
	read.get();	
	getline(read,obj.department);	
	read>>obj.age;	
	read>>obj.salary;
	read.get();	
	getline(read,obj.phone);
	
	//***** IF FILE EXIST IT WILL OPEN OTHERWISE NOT *****
	if(read.is_open())
	{
	
	// ***** READ DATA AT THE END OF FILE *****
	
		while(read.eof()==0)
		{
			
		// ***** SEARCH FOR SPECIFIC ( ID ) TO CHECK ID IS AVAILABLE OR NOT *****
			
			if(obj.id==chk)
			{	
				read.close();
				return 1;		// ***** IT WILL RETURN YES ( FOUND ) *****
			}
			
		// ***** AGAIN READ DATA *****
			
			getline(read,obj.name);
			read>>obj.id;
			read.get();
			getline(read,obj.department);
			read>>obj.age;
			read>>obj.salary;
			read.get();
			getline(read,obj.phone);
		}
		
	return 0;			// ***** IT WILL RETURN NO ( FOUND ) *****
	read.close();	
}

  //***** IF FILE NOT EXIST *****

	else
		{
			read.close();
			return 0;
		}
}
