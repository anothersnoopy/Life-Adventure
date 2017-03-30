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
	
	good.sleep();
	good.outhome();
	good.sport();
	good.word();
	good.Nsleep();
	good.NFN();
	good.cn_paper();
	good.en_paper();
	good.review();
	good.PP();
	good.OTG();
	good.PureThinking();
	good.TheFour();


	bad.S();
	bad.MM();
	bad.CM();
	bad.game_weekday();
	bad.GV();
	bad.unhealthy_info();
	bad.UNB();
	
	write.note();
	write.summary();

	
	cout<<endl;
	cout<<" ok,finished."<<endl;
	cout<<endl;

	return 0;
}
