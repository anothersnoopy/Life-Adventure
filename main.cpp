#include<iostream>
#include<fstream>
#include"function.cpp"
using namespace std;

int main()
{
	Good good;
	Write write;
	Data data;

	
	data.read();//read yesterday's summary
	write.date();//write today's date
	write.table_head();
	good.word();
	good.outhome();
	good.cn_paper();
	good.en_paper();
	write.summary();

	
	cout<<endl;
	cout<<"ok,finished."<<endl;

	return 0;
}
