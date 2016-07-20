

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>


void pass()
{
	clrscr();
	char a[20],b[]="Mittal";
	cout<<"  Enter Current User Password  "<<endl;
	for(int i=0;i<20;i++)
	{
		a[i]=getch();
		if(a[i]==13)
			break;
		else if(a[i]==8 && i>=2)
		{
			i-=2;
			cout<<"\b";
		}
		else if(a[i]==8 && i==1)
		{
			i--;cout<<"\b";
		}
		else
			cout<<"*";
	}
	a[i]='\0';
	if(strcmp(a,b)!=0)
	{
		cout<<endl<<"  ACCESS DENIED "<<endl;
		for(int j=0;j<5;j++)
		{
			sound(300);
			delay(500);
			nosound();
			delay(500);
		}
		exit(5);
	}
	else
	{
		cout<<endl<<"  YOU CAN CONTINUE  "<<endl;
	}
	getch();
}
//***************************************************************
//    	function to  create a tone
//****************************************************************

int piano(int a)
{
		if(a=='1')
		{
			sound(300);
			cout<<"Sa ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='2')
		{
			sound(337);
			cout<<"Re ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='3')
		{
			sound(378);
			cout<<"Ga ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='4')
		{
			sound(401);
			cout<<"Me ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='5')
		{
			sound(451);
			cout<<"Pa ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='6')
		{
			sound(506);
			cout<<"Dha ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='7')
		{
			sound(569);
			cout<<"Ni ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='8')
		{
			sound(601);
			cout<<"Sa ";
			delay(100);
			nosound();
			delay(50);
		}
		else if(a=='0')
		{
			return 1;
		}

		else
		{       cout<<"TONE SAVED !!!!!"<<endl;
			return 0;
		}
		return 100;

}
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class album
{
	int note[2000];
	char name[25];
	int number;
	int n;
	public:
	int getnum()
	{return number;}
	void input();
	void list();
	void play();
	};
	void album:: input()
	{
		cout<<"\nEnter the name of tone\n";
		gets(name);
		cout<<"\nEnter the tone number\n";
		cin>>number;
		cout<<"\nEnter the tone\nTo cancel a tone press 0 and to complete, press any other key\n ";
		for(int i=0;;i++)
		{
			note[i]=getch();
			if(note[i]=='1'||note[i]=='2'||note[i]=='3'||note[i]=='4'||note[i]=='5'||note[i]=='6'||note[i]=='7'||note[i]=='8')
			{
					piano(note[i]);
			}
			else if(piano(note[i])==1)
			{
				i=i-2;
			}
			else
				break;

		}
		n=i;
	}
	void album:: list()
	{
		 cout<<" "<<number<<"   ";
		 cout<<"       ";
		 puts(name);
		 cout<<endl<<endl;
	}
	void album:: play()
	{
		for(int i=0;i<n;i++)
		piano(note[i]);
	}




//***************************************************************
//    	function declaration
//****************************************************************

void add();	//write the record in binary file
void showall();		//read all records from binary file
void search();	//accept rollno and read record from binary file
void del();	//accept rollno and delete selected records from binary file
void modify(); //modify a record
void intro();	//display welcome screen
void pass(); //password protection
int piano(int);//create a tone

//***************************************************************
//    	function to write in file
//****************************************************************

void add()
{
	ofstream fout("abc.dat",ios::binary);
	album s;
	int n;
	cout<<"Enter The No Of tones ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s.input();
		fout.write((char*)&s,sizeof(s));
	}
	fout.close();
	 cout<<"\n\n record Has Been Created ";

	getch();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************


void showall()
{       clrscr();
	album s;
	ifstream fin("abc.dat",ios::binary);
	fin.read((char*)&s,sizeof(s));
	cout<<"\n\n\t\tALL  RECORDS \n\n";
	cout<<"===============================\n";
	cout<<"R.No       Name       "<<endl;
	cout<<"===============================\n";
	while(!fin.eof())
	{
		s.list();
		fin.read((char*)&s,sizeof(s));
	}
	fin.close();


   }

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void search()
{       clrscr();
	album s;
	int r;
	cout<<"Enter Tone no To Be Searched ";
	cin>>r;
	int flag=0;
	ifstream fin("abc.dat",ios::binary);
	cout<<"\n\n\t\t SEARCH  RESULTS \n\n";
	cout<<"===============================\n";
	cout<<"R.No       Name          "<<endl;
	cout<<"===============================\n";
	while(!fin.eof())
	{
		fin.read((char*)&s,sizeof(s));
		if(s.getnum()==r)
		{
			s.list();
			delay(100);
			s.play();
			flag=1;
		}
	fin.read((char*)&s,sizeof(s));
	}
	if(flag==0)
	cout<<"Not Found ";
	fin.close();
	getch();
}
//***************************************************************
//    	function to delete specific record from file
//****************************************************************
void del()
{
	ifstream fin("abc.dat",ios::binary);
	ofstream fout("Temp.dat",ios::out);
	album s;
	int rno;
	cout<<"Enter tone No. To Be Deleted ";
	cin>>rno;
	fin.read((char*)&s,sizeof(s));

	while(fin)
	{        fin.read((char*)&s,sizeof(s));
		if(s.getnum()!=rno)
		{       fout.write((char*)&s,sizeof(s));
		}

	}
	fin.close();
	fout.close();
	remove("abc.dat");
	rename("Temp.dat","abc.dat");
	cout<<"\n\n\tRecord Deleted ..";

	getch();
}
//***************************************************************
//    	function to modify specific record from file
//****************************************************************


void modify()
{
	int found=0;
	album s;
	int rno;
	cout<<"Enter tone No. To Be Modified ";
	cin>>rno;
	fstream File;
	File.open("abc.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}

	while(File.read((char*)&s,sizeof(s))&&found==0)
	{
		if(s.getnum()==rno)
		{
			s.list();
			cout<<"\n\nPlease Enter The New Details of record"<<endl;
			s.input();
		    int pos=(-1)*sizeof(s);
		    File.seekp(pos,ios::cur);
		    File.write((char*)&s,sizeof(s));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

 void intro()
{
	cout<<"\n\n\n\t\t   PIANO";
	cout<<"\n--------------------------------------------------";
	cout<<"\n\n\t\t  PROJECT";
	cout<<"\n\n\n\tMADE BY :SARTHAK MITTAL";
	cout<<"\n\tINSTITUTION:DELHI TECHNOLOGICAL UNIVERSITY";
	getch();
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{   album s;
    clrscr();
    intro();
    pass();
    char ch;
    clrscr();

    do
     {
	clrscr();
	album s;
	int ch2;
	cout<<"\n\n\n\t!!!!!!!*********MAIN MENU*********!!!!!!!";
	cout<<"\n\n\t1.CREATE  RECORD";
	cout<<"\n\n\t2.DISPLAY ALL  RECORDS";
	cout<<"\n\n\t3.SEARCH  RECORD ";
	cout<<"\n\n\t4.MODIFY RECORD";
	cout<<"\n\n\t5.DELETE  RECORD";
	cout<<"\n\n\t6.EXIT";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch2;
	cout<<endl<<endl;
	switch(ch2)
	{
		case 1:
			add();
			break;
		case 2:
			showall();
			break;
		case 3:
			search();
			break;
		case 4:
			modify();
			break;
		case 5:
			del();
			break;
		case 6:  exit(5);
	}
	cout<<endl<<endl<<"Do You Wish To Continue ??" ;
	ch=getch();
	}while(ch=='y');
    }
//***************************************************************
//    			END OF PROJECT
//***************************************************************
