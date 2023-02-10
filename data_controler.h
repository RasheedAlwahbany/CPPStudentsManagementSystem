#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

class data_control
{
	public:
		
		struct students_information
		{
			string id,first_name,last_name,level;
			int score1,score2,score3,score4,total;
		};
	void create_recored()
	{
		system("cls");
		ofstream write_data("database.db",ios::app);
		students_information add_new;
		
		cout<<"\n\n\t\t\t=======> Enter New Student's information'<========="<<endl;
		cout<<"\n\n\t\tStudent's ID ====> ";
		cin>>add_new.id;
		cout<<"\n\n\t\tStudent's First Name ====> ";
		cin>>add_new.first_name;
		cout<<"\n\n\t\tStudent's Last Name ====>";
		cin>>add_new.last_name;
		cout<<"\n\n\t\tStudent's level ====>";
		cin>>add_new.level;
		cout<<"\n\n\t\t\t====> Student's Scores <===="<<endl;
		cout<<"\n\n\t\tStudent's First Score ====>";
		cin>>add_new.score1;
		cout<<"\n\n\t\tStudent's second Score ====>";
		cin>>add_new.score2;
		cout<<"\n\n\t\tStudent's third Score ====>";
		cin>>add_new.score3;
		cout<<"\n\n\t\tStudent's fourth Score ====>";
		cin>>add_new.score4;
		
		int total=0;
		add_new.total = add_new.score1+add_new.score2+add_new.score3+add_new.score4;
		
		write_data <<add_new.id<<" "<<add_new.first_name<<" "<<add_new.last_name
		<<" "<<add_new.level<<" "<<add_new.score1<<" "<<add_new.score2
		<<" "<<add_new.score3<<" "<<add_new.score4<<" "<<add_new.total<<endl;
	}
	
	int file_rows_counter()
	{
		string id,first_name,last_name,level;
		int score1,score2,score3,score4,total=0;
		double average;
		
		ifstream read_data("database.db",ios::in);
		int size=0;
		while(read_data>>id>>first_name>>last_name>>level>>score1>>score2>>score3>>score4>>total)
		{
			++size;
		}	
		return size;
	}
	
	void display_database()
	{
		string id,first_name,last_name,level;
		int score1,score2,score3,score4,total;
		double average;
		ifstream read_data("database.db",ios::in);
		
		cout<<"\n\n\n"<<"Id"<<"\t|\t"<<"First_Name"<<"\t|\t"<<"Last_Name"<<"\t|\t"<<"Level"
			<<"\t|\t"<<"Score1"<<"\t|\t"<<"score2"<<"\t|\t"<<"score3"<<"\t|\t"<<"score4"
			<<"\t|\t"<<"Total"<<endl;
		while(read_data>>id>>first_name>>last_name>>level>>score1>>score2>>score3>>score4>>total)
		{
			cout<<id<<setw(8)<<"|"<<setw(15)<<first_name<<setw(8)<<"|"<<setw(8)<<last_name<<setw(8)<<"|"<<setw(8)<<level
				<<setw(8)<<"|"<<setw(8)<<score1<<setw(13)<<"|"<<setw(8)<<score2<<setw(8)<<"|"<<setw(8)<<score3<<setw(8)<<"|"<<setw(8)<<score4
				<<setw(8)<<"|"<<setw(8)<<total<<endl;
		}
	}
	void delete_record()
	{	
	ifstream read_data("database.db",ios::app);
		
		int index = file_rows_counter();
		students_information query[index];
		
		string search_id;
		
		cout<<"\n\n\tPlease Be careful and chose the id you want to delete ===> ";
		cin>>search_id;
		
		for(int t=0;t<index;t++)
		{
		read_data>>query[t].id>>query[t].first_name>>query[t].last_name>>query[t].level
		>>query[t].score1>>query[t].score2>>query[t].score3>>query[t].score4>>query[t].total;
		}
		
		for(int i=0;i<index;i++)
			{
				if(search_id==query[i].id)
				{
		
				cout<<"\n\tRecord found has the following information";
				cout<<"\n\t\tStudent's ID ====> "<<query[i].id;
				
				cout<<"\n\t\tStudent's First Name ====> "<<query[i].first_name;
				
				cout<<"\n\t\tStudent's Last Name ====> "<<query[i].last_name;
			
				cout<<"\n\t\tStudent's level ====> "<<query[i].level;
			
				
				cout<<"\n\t\t\t====> Student's Scores <===="<<endl;
				
				cout<<"\n\t\tStudent's First Score ====> "<<query[i].score1;
			
				cout<<"\n\t\tStudent's second Score ====> "<<query[i].score2;
			
				cout<<"\n\t\tStudent's third Score ====> "<<query[i].score3;
				
				cout<<"\n\t\tStudent's fourth Score ====> "<<query[i].score4;
				
				cout<<"\n\t\tStudent's total ====>"<<query[i].total;
				
				char test='n';
				cout<<"\n\n\t Are you sure you want to delete this recored y/n ====> ";
				cin>>test;
				
				if(test=='y')
					{
						--index;
						for(int s=i;s<index;s++)
							{
								
								query[s]=query[s+1];
						}
						
						//	ofstream clear("database.db",ios::out);
							ofstream write_data("database.db",ios::out);
							for(int tp=0;tp<index;tp++)
								write_data<<query[tp].id<<" "<<query[tp].first_name<<" "<<query[tp].last_name<<" "<<query[tp].level<<" "
											<<query[tp].score1<<" "<<query[tp].score2<<" "<<query[tp].score3<<" "<<query[tp].score4<<" "<<query[tp].total<<endl;
					}
			}
			}	
	}
	void search()
	{
		ifstream read_data("database.db",ios::in);
		int index = file_rows_counter();
		students_information query[index];
		string search_id;
		
		cout<<"\n\n\tEnter Student Id you want to search for ===> ";
		cin>>search_id;
		
		for(int t=0;t<index;t++)
		{
				read_data>>query[t].id>>query[t].first_name>>query[t].last_name>>query[t].level
				>>query[t].score1>>query[t].score2>>query[t].score3>>query[t].score4>>query[t].total;
		}
		
		for(int i=0;i<index;i++)
			{
				if(search_id==query[i].id)
				{
					cout<<"\n\tRecord found has the following information";
					cout<<"\n\t\tStudent's ID ====> "<<query[i].id;
					cout<<"\n\t\tStudent's First Name ====> "<<query[i].first_name;
					cout<<"\n\t\tStudent's Last Name ====> "<<query[i].last_name;
					cout<<"\n\t\tStudent's level ====> "<<query[i].level;
					cout<<"\n\t\t\t====> Student's Scores <===="<<endl;
					cout<<"\n\t\tStudent's First Score ====> "<<query[i].score1;
					cout<<"\n\t\tStudent's second Score ====> "<<query[i].score2;
					cout<<"\n\t\tStudent's third Score ====> "<<query[i].score3;
					cout<<"\n\t\tStudent's fourth Score ====> "<<query[i].score4;
					cout<<"\n\t\tStudent's Total score ====>"<<query[i].total;		
			}
		}	
	}
	
	void updateRecored()
	{
		system("cls");
		
		int index = file_rows_counter();
		students_information query[index];
		string search_id;
		int attribute;
		
		ifstream read_data("database.db",ios::in);
		
		for(int t=0;t<index;t++)
		{
				read_data>>query[t].id>>query[t].first_name>>query[t].last_name>>query[t].level
				>>query[t].score1>>query[t].score2>>query[t].score3>>query[t].score4>>query[t].total;
		}	
		cout<<"\n\n\t\t ** Editing Menu **";
		cout<<"\n\t\t1 - Student ID  ";
		cout<<"\n\t\t2 - Student First Name ";
		cout<<"\n\t\t3 - Student Last Name ";
		cout<<"\n\t\t4 - Student level  ";
		cout<<"\n\n\t\t\t====> Student Scores <===="<<endl;
		cout<<"\n\t\t5 - Student First Score ";
		cout<<"\n\t\t6 - Student second Score ";
		cout<<"\n\t\t7 - Student third Score ";
		cout<<"\n\t\t9 - Student fourth Score ";
		cout<<"\n\n\tEnter the number of attribute you want to Edit ====> ";
		cin>>attribute;
		
		if(attribute>=1&&attribute<=8)
		{
			cout<<"\n\n\t\tEnter student's Id that you want to edit ====> ";
			cin>>search_id;
			
			for(int i=0;i<index;i++)
			{
				if(search_id==query[i].id)
					switch(attribute)
					{
						case 1:
							cout<<"\n\n\t\t Enter New Id for the student ====>";
							cin>>query[i].id;
							break;
						case 2 :
							cout<<"\n\n\t\t Enter New First Name for the student ====>";
							cin>>query[i].first_name;
							break;
						case 3 :
							cout<<"\n\n\t\t Enter New Last Name for the student ====>";
							cin>>query[i].last_name;
							break;
						case 4 :
							cout<<"\n\n\t\t Enter New Level for the student ====>";
							cin>>query[i].level;
							break;
						case 5 :
							cout<<"\n\n\t\t Enter New first score  ====>";
							cin>>query[i].score1;
							break;
						case 6 :
							cout<<"\n\n\t\t Enter New second score ====>";
							cin>>query[i].score2;
							break;
						case 7 :
							cout<<"\n\n\t\t Enter New third score ====>";
							cin>>query[i].score3;
							break;
						case 8 :
							cout<<"\n\n\t\t Enter New fourth score ====>";
							cin>>query[i].score4;
							break;
						default:
							cout<<"\n\n\t\t Wrong choice rechose ====>";
						//	updateRecored();
							break;
					}
					
				//	total = add_new.score1+add_new.score2+add_new.score3+add_new.score4;
					ofstream write_data("database.db",ios::out);
						for(int tp=0;tp<index;tp++)
							write_data<<query[tp].id<<" "<<query[tp].first_name<<" "<<query[tp].last_name<<" "<<query[tp].level<<" "
							<<query[tp].score1<<" "<<query[tp].score2<<" "<<query[tp].score3<<" "<<query[tp].score4<<" "<<query[tp].total<<endl;	
			}
			
		}
		else
		{
			cout<<"\n\n\t\t*** Wrong Choice chose again ***";
	}
}
	
	void sortData()
	{
		int index = file_rows_counter();
		students_information query[index];
		
		ifstream read_data("database.db",ios::in);
		
		students_information temp;
		
		for(int t=0;t<index;t++)
		{
			read_data>>query[t].id>>query[t].first_name>>query[t].last_name>>query[t].level
			>>query[t].score1>>query[t].score2>>query[t].score3>>query[t].score4>>query[t].total;
		}
		
		for(int t=0;t<index;t++)
		{
			for(int g=0;g<index-1;g++)
			if(query[t].total>query[g].total)
				{
					temp=query[t];
					query[t]=query[g];
					query[g]=temp;
				}
		}
		ofstream write_data("database.db",ios::out);
			for(int tp=0;tp<index;tp++)
				write_data<<query[tp].id<<" "<<query[tp].first_name<<" "<<query[tp].last_name<<" "<<query[tp].level<<" "
				<<query[tp].score1<<" "<<query[tp].score2<<" "<<query[tp].score3<<" "<<query[tp].score4<<" "<<query[tp].total<<endl;
				
		}
};
