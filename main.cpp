#include<iostream>
#include<fstream>
#include<cstdlib>
#include"function.h"
#include"call_function.h"
using namespace std;

int main()
{
	int write_diary();
	int check_data();
	int make_plan();
	int check_plan();
	
	system("clear");
	
	cout<<"		Welcome to Life Adventure !"<<endl;
	cout<<endl;
	cout<<"what do you want to do?"<<endl;
	cout<<"		1. Record today."<<endl;
	cout<<"		2. Check latest data."<<endl;
	cout<<"		3. Make a plan."<<endl;
	cout<<"		4. Check plan completion"<<endl;
	cout<<endl;
	cout<<"please choose:";

	int i;
	cin>>i;
	switch(i)
	{
		case 1: write_diary();break;
		case 2: check_data();break;
		case 3: make_plan();break;
		case 4: check_plan();break;
	};

	return 0;
}
