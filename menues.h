#include<iostream>
#include<conio.h>
#include"data_controler.h"

using namespace std;

class menues {
	
	public:	
	void main_menu()
	{
			data_control dc;
			char choice;
			cout<<"\n\t==============> Students Management System <================\n";
			cout<<"\n\n\t ********** Choose Operation You Want To Perform **********\n\n";
			cout<<"\n\n\t 1) Create Record";
			cout<<"\n\n\t 2) Display Record";
			cout<<"\n\n\t 3) Search Record";
			cout<<"\n\n\t 4) Update Record";
			cout<<"\n\n\t 5) Sort Data";
			cout<<"\n\n\t 6) Delete Record";
			cout<<"\n\n\t 7) Exit Program";
			cout<<"\n\n Enter your choice====>";
			choice = getche();
			
			test_choice(choice);
	}
	
	void test_choice(char choice)
	{
		bool exitCondition=true;
		data_control dc;
		switch(choice)
			{
				case '1':
					dc.create_recored();
					break;
				case '2':
					dc.display_database();
					break;
				case '3':
					dc.search();
					break;
				case '4':
					dc.updateRecored();	
					break;
				case '5':
					dc.sortData();
					break;
				case '6':
					dc.delete_record();
					break;
				case '7':
					exitCondition=false;
					system("exit");
					break;
				default:
					system("cls");
					cout<<"\n\n\t=======> Wrong Choice <=======\n\n";
					main_menu();
					break;
			}
			if(exitCondition)
				main_menu();
	}
};
