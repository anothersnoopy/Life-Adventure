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


	ifstream infile(PATH);
	if(!infile)
	{
		cout<<"Can not open the diary."<<endl;
		return -1 ;
	}
	infile.close();


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
	good.TheFour();
	good.Nsleep();
	
	bad.S();
	bad.game_weekday();
	bad.dark_mind();
	bad.unhealthy_info();
	bad.UNB();
	bad.MM();
	bad.CM();

	write.summary();

	
	cout<<endl;
	cout<<" ok,finished."<<endl;
	cout<<endl;

	return 0;
}
