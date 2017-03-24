#include<iostream>
#include<fstream>
#include"function.cpp"
using namespace std;

int main()
{
	Good good;
	Bad bad;
	Write write;
	Data data;

	
	data.read();//read yesterday's summary
	write.date();//write today's date
	write.table_head();
	
	good.word();
	good.outhome();
	good.cn_paper();
	good.en_paper();
	good.sleep();
	good.sport();
	good.OTG();
	good.PP();
	good.NFN();
	good.sunny_mind();
	good.review();
	
	bad.S();
	bad.game_weekday();
	bad.dark_mind();
	bad.unhealthy_info();
	bad.UNB();
	bad.MM();

	write.summary();

	
	cout<<endl;
	cout<<"ok,finished."<<endl;

	return 0;
}
