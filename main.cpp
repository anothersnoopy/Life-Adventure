#include<iostream>
#include<fstream>
#include<cstdlib>
#include"function.h"
#include"call_function.h"
//#include"Message.h"
using namespace std;

int main()
{
	int i;
	do
	{
		welcome();
		cin>>i;
		switch(i)
		{
			case 1: i = write_diary();break;
			case 2: i = check_data();break;
			case 3: i = make_plan();break;
			case 4: i = check_plan();break;
			case 5: 
			{
				cout<<endl<<"    ";
				random_sentences();
				i = overcheck();
				break;
			}
			case 0: cout<<endl<<"			Bye ^_~"<<endl<<endl;break;
			default: cout<<endl<<"	请输入个数字..."<<endl<<endl;break;
		}

	}
	while( i != 0);

	return 0;
}
