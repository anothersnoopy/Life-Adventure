#include"class.h"
#include<ctime>
#include<sstream>
using namespace std;

#define PATH "/home/Kevin/Diary/6-field/diary.md"

static int total_sc,total_wd,total_ot,total_cnp, total_enp;//should be read from yesterday




Good::Good()//class Good constructor
{
	word_score = 0;//this score only for today
	out_score = 0;//only for today
}

void Good::word()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Have you finished learn words?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		word_score = 10;
	}

	total_wd += word_score;

	diary<<"| words score | "<<word_score<<" |"<<endl;
	diary.close();
}

void Good::outhome()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	cout<<"Have you go out of dormitory before 8:30?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		out_score += 10;
	}
	total_ot += out_score;
	diary<<"| outhome score | "<<out_score<<" |"<<endl;
	diary.close();
}

void Good::cn_paper()// kevin add this on 3.20
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Read a piece of literature in Chinese?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cnpaper_score = 10;
	}

	total_cnp += cnpaper_score;

	diary<<"| cn_paper score | "<<cnpaper_score<<" |"<<endl;
	diary.close();
}// add end


void Good::en_paper()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Read a piece of literature in English?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		enpaper_score = 10;
	}

	total_enp += enpaper_score;

	diary<<"| en_paper score | "<<enpaper_score<<" |"<<endl;
	diary.close();
}

void Write::table_head()
{
	ofstream diary;
	diary.open(PATH,ios::app);
	diary<<"| item | score |"<<endl;
	diary<<"| --- | --- |"<<endl;
	diary.close();
}


void Write::date()
{
	ofstream diary;
	diary.open(PATH,ios::app);
	
	time_t today;
	time(&today);
	diary<<endl;
	diary<<"-------------------------------"<<endl;
	diary<<"##"<<ctime(&today)<<endl;
	
	diary.close();
}



void Data::read()// to read yesterday's data
{
	ifstream infile;
	infile.open(PATH);

	string line;
	string temp;
	while(infile>>temp)
	{
		getline(infile, line);
	}
	istringstream ss(line);

	char m_total[5],m_word[4],m_outhome[7];
	ss>>m_total>>total_sc>>m_word>>total_wd>>m_outhome>>total_ot;
	infile.close();
}




void Write::summary()
{
	ofstream diary;
	diary.open(PATH,ios::app);
	
	total_sc = total_wd + total_ot + total_cnp + total_enp;

	diary<<endl;
	diary<<"###Summary:"<<endl;
	diary<<"*"<<" total "<<total_sc<<" word "<<total_wd<<" outhome "<<total_ot<<" cn_paper "<<total_cnp<<" en_paper "<<total_enp<<endl;

	diary.close();
}
