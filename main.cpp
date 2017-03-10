#include<iostream>
#include"function.cpp"
using namespace std;

int main()
{
	Good good;
	char finish;
	cout<<"Have you finished learn words?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		good.word();
	}
	
	cout<<"total_word_score:"<<good.show_word<<endl;

	return 0;
}
