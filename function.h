#include"class.h"
#include<ctime>
#include<sstream>
#include<iomanip>
using namespace std;

//#define PATH_data "/home/Kevin/Diary/22-field/data/data.md"
//#define PATH "/home/Kevin/Diary/22-field/data/diary.md"
//#define PATH_plan "/home/Kevin/Diary/22-field/data/plan.md"
#define PATH "/mnt/f/OneDrive/diary.md"
#define PATH_data "/mnt/f/OneDrive/diarydata/data.md"
#define PATH_plan "/mnt/f/OneDrive/diarydata/plan.md"

static int total_sc,total_wd,total_ot,total_cnp, total_enp,\
total_slpe, total_spt, total_OTG, total_PP, total_NFN, \
total_rv, total_day, total_TheFour, total_Nsleep,\
reward, total_PT, total_WH, total_RG, total_PD;//total socres (Good)

static int total_S, total_gmwd, total_uhi, total_UNB, \
total_MM, total_CM, total_GV;//total scores(Bad)

static double yesterday_H, yesterday_E, yesterday_S, today_energy,\
today_health, today_spirit;

static int total_plan;//plan score

//////////////////////////////////Good Funtions///////////////////////




Good::Good()//class Good constructor
{
	word_score = 0;//these scores only for today
	out_score = 0;
	cnpaper_score = 0;
	enpaper_score = 0;
	sleep_score = 0;
	sport_score = 0;
	OTG_score = 0;
	PP_score = 0;
	NFN_score = 0;
	review_score = 0;
	total_day = 0;
	TheFour_score = 0;
	Nsleep_score = 0;
	PT_score = 0;
	WH_score = 0;
	RG_score = 0;
	PD_score = 0;

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
		out_score = 20;
	}
	total_ot += out_score;
	diary<<"| outhome score | "<<out_score<<" |"<<endl;
	diary.close();
}

void Good::cn_paper()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Read a piece of literature in Chinese?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cnpaper_score = 100;
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
		enpaper_score = 200;
	}

	total_enp += enpaper_score;

	diary<<"| en_paper score | "<<enpaper_score<<" |"<<endl;
	diary.close();
}

void Good::sleep()// improve suggestion: input sleep time
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Last Night did you sleep before 10:00 ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		sleep_score = 25;
	}
	else 
		{
			cout<<"		Later than 11:00 ? (y/n)"<<endl;
			char temp;
			cin>>temp;
			if(temp == 'y')
				sleep_score = -30;
		}

	total_slpe += sleep_score;

	diary<<"| sleep | "<<sleep_score<<" |"<<endl;
	diary.close();
}


void Good::sport()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Did you do any sports today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		sport_score = 25;
	}

	total_spt += sport_score;

	diary<<"| do sport | "<<sport_score<<" |"<<endl;
	diary.close();
}


void Good::OTG()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Did One Thing Good today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		OTG_score = 20;
	}
	else OTG_score = -20;

	total_OTG += OTG_score;

	diary<<"| OTG | "<<OTG_score<<" |"<<endl;
	diary.close();
}

void Good::PP()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Phone parents today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		PP_score = 25;
	}

	total_PP += PP_score;

	diary<<"| Phone parents | "<<PP_score<<" |"<<endl;
	diary.close();
}

void Good::NFN()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"No Food at Night today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		NFN_score = 20;
	}

	total_NFN += NFN_score;

	diary<<"| No Food tonight | "<<NFN_score<<" |"<<endl;
	diary.close();
}


void Good::review()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Review what you learn today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		review_score = 50;
	}

	total_rv += review_score;

	diary<<"| review knowledge | "<<review_score<<" |"<<endl;
	diary.close();
}



void Good::TheFour()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	int i = 0;
	cout<<"Read <The Four> today?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cout<<" How many times ?"<<endl;
		cin>>i;
		TheFour_score = (30 * i);
	}
	else TheFour_score = -20;

	total_TheFour += TheFour_score;
	diary<<"| The Four | "<<TheFour_score<<" |"<<endl;
	diary.close();
}


void Good::Nsleep()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	char temp;
	cout<<"Noon sleep today?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{	
		cout<<"		No more than 30min?"<<endl;
		cout<<"(y/n)";
		cin>>temp;
		if(temp == 'y')
		{
			Nsleep_score = 20;
		}
		else
			Nsleep_score = -20;
	}

	total_Nsleep += Nsleep_score;

	diary<<"| Nsleep score | "<<Nsleep_score<<" |"<<endl;
	diary.close();
}



void Good::PureThinking()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	cout<<"Keep a pure thinking today?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		PT_score = 10;
	}
	else PT_score = -20;
	total_PT += PT_score;
	diary<<"| PureThinking | "<<PT_score<<" |"<<endl;
	diary.close();
}


void Good::WhiteHouse()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	cout<<"Keep the door open, keep the window bright?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		WH_score = 20;
	}
	else WH_score = -40; 
	total_WH += WH_score;
	diary<<"| White House | "<<WH_score<<" |"<<endl;
	diary.close();
}



void Good::readgood()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	cout<<"Did you read good articles last night ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		RG_score = 20;
	}
	else RG_score = -20;
	total_RG += RG_score;
	diary<<"| Read-Good score | "<<RG_score<<" |"<<endl;
	diary.close();
}


void Good::paperDiary()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	cout<<"Did you write diary on paper yesterday ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		PD_score = 30;
	}
	else PD_score = -10;
	total_PD += PD_score;
	diary<<"| PaperDiary score | "<<PD_score<<" |"<<endl;
	diary.close();
}


////////////////////////Bad Functions/////////////////////////////


Bad::Bad()// class Bad constructor
{
	S_score = 0;
	gamewkd_score = 0;
	unhealthy_info_score = 0;
	UNB_score = 0;
	MM_score = 0;
	CM_score = 0;
	GV_score = 0;
}
	

void Bad::S()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### S today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cout<<"		How many times?"<<endl;
		int i= 1;
		cin>>i;
		S_score = (-200*i);
		total_day = -1;
	}
	else S_score = 5;
	total_day += 1;

	total_S += S_score;

	diary<<"| S | "<<S_score<<" |"<<endl;
	diary.close();
}


void Bad::game_weekday()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Play games on weekdays ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		gamewkd_score = -20;
	}
	else gamewkd_score = 5;
	
	total_gmwd += gamewkd_score;
	
	diary<<"| game on weekday | "<<gamewkd_score<<" |"<<endl;
	diary.close();
}


void Bad::unhealthy_info()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Read any unhealthy info today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		unhealthy_info_score = -50;
	}
	
	else unhealthy_info_score = 5;

	total_uhi += unhealthy_info_score;
	
	diary<<"| unhealthy info | "<<unhealthy_info_score<<" |"<<endl;
	diary.close();
}


void Bad::UNB()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Useless Net Browsing today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		UNB_score = -20;
	}
	else UNB_score = 5;

	total_UNB += UNB_score;
	
	diary<<"| Useless Net Browsing | "<<UNB_score<<" |"<<endl;
	diary.close();
}




void Bad::MM()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"###Today when you get up, did you play mobile ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		MM_score = -30;
	}
	
	else MM_score = 5;

	total_MM += MM_score;
	
	diary<<"| Play mobile when get up | "<<MM_score<<" |"<<endl;
	diary.close();
}

void Bad::CM()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Did you play mobile in classroom today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		CM_score = -30;
	}
	
	else CM_score = 5;

	total_CM += CM_score;
	
	diary<<"| Play mobile in classroom | "<<CM_score<<" |"<<endl;
	diary.close();
}



void Bad::GV()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Watch Game Video in weekdays ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		GV_score = -20;
	}
	
	else GV_score = 5;
	
	total_GV += GV_score;
	
	diary<<"| Game Video weekday | "<<GV_score<<" |"<<endl;
	diary.close();
}

////////////////////////////Others//////////////////////////////
void Write::table_head()
{
	ofstream diary;
	diary.open(PATH,ios::app);
	diary<<"### Today score:"<<endl;
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
	diary<<"------------------------------------------------"<<endl;
	diary<<"## "<<ctime(&today)<<endl;
	
	diary.close();
}


void Write::note()
{
	char temp;
	cout<<"			Do you want write note ?"<<endl;
	cout<<"(y/n)";
	cin>>temp;
	if(temp == 'y')
	{
		cin.get();///eat the 'Enter', to avoid jump over getline(cin, note)
		ofstream diary;
		diary.open(PATH,ios::app);

		string note;
		cout<<"Write here:"<<endl;
		getline(cin, note);
		diary<<endl;
		diary<<"### Today Note:"<<endl;
		diary<<note<<endl;
		diary<<endl;

		diary.close();
	}
}




void Data::read()// to read yesterday's data
{
	ifstream infile;
	infile.open(PATH_data);

	string line;
	string temp;
	while(infile>>temp)
	{
		getline(infile, line);
	}
	istringstream ss(line);

	char m_total[15],m_word[15],m_outhome[15],m_cnpaper[15],m_enpaper[15]\
	,m_slpe[15],m_spt[15],m_OTG[15],m_PP[15],m_NFN[15],m_rv[15]\
	,m_S[15],m_gwkd[15],m_uhi[15], m_UNB[15], m_MM[15],m_CM[15]\
	,m_day[15],m_TheFour[15],m_Nsleep[15],m_GV[15],m_PT[15],m_Health[15]\
	,m_Energy[15], m_Spirit[15], m_WhiteHouse[15], m_readgood[15], m_PD[15];
	
	ss>>m_total>>total_sc>>m_word>>total_wd>>m_outhome>>total_ot\
	>>m_cnpaper>>total_cnp>>m_enpaper>>total_enp>>m_slpe>>total_slpe>>\
	m_spt>>total_spt>>m_OTG>>total_OTG>>m_PP>>total_PP>>m_NFN>>total_NFN\
	>>m_rv>>total_rv>>m_S>>total_S>>m_gwkd>>total_gmwd\
	>>m_uhi>>total_uhi>>m_UNB>>total_UNB>>m_MM>>total_MM\
	>>m_CM>>total_CM>>m_day>>total_day>>m_TheFour>>total_TheFour>>m_Nsleep\
	>>total_Nsleep>>m_GV>>total_GV>>m_PT>>total_PT>>m_Health\
	>>yesterday_H>>m_Energy>>yesterday_E>>m_Spirit>>yesterday_S>>m_WhiteHouse\
	>>total_WH>>m_readgood>>total_RG>>m_PD>>total_PD;
	
	infile.close();
}




void Write::summary()
{
	ofstream diary;
	diary.open(PATH,ios::app);


/////////////////Day///////////////////////
	diary<<endl;
	diary<<"### Data Analysis:"<<endl;
	diary<<" *Day* : "<<total_day<<endl;
///////////////End Day/////////////////////



///////////////Victory Day reward system//////////
	if(total_day <= 6)
	{
		reward = (total_day * 2);
	}
	else if(total_day <= 14)
	{
		reward = 15;
	}
	else if(total_day <= 30)
	{
		reward = 20;
	}
	else if(total_day <= 60)
	{
		reward = 30;
	}
	else if(total_day <= 90)
	{
		reward = 40;
	}
	else if(total_day <= 120)
	{
		reward = 50;
	}
	else
		reward = 60;
	
	
	cout<<endl;/////for good display on bash shell
	if( total_day != 0)
	{////avoid total_day = 0 trouble///////////

	if((total_day % 7) == 0)
	{
		reward = reward + 30;
		diary<<"Yes! Week reward: 30 "<<endl;
		cout<<" Yes! Week reward: 30 "<<endl;
	}
	
	if((total_day % 30) == 0 )
	{
		reward = reward + 100;
		diary<<"Good! Month reward: 100 "<<endl;
		cout<<" Good! Month reward: 100 "<<endl;
	}
	
	if((total_day % 100) == 0 )
	{
		reward = reward + 300;
		diary<<"Excellent! Hundred-Day reward: 300 "<<endl;
		cout<<" Excellent! Hundred-Day reward: 300 "<<endl;
	}
	
	if((total_day % 183) == 0 )
	{
		reward = reward + 500;
		diary<<"Splendid! Half-Year reward: 500 "<<endl;
		cout<<"Splendid! Half-Year reward: 500 "<<endl;
	}
	
	if((total_day % 365) == 0 )
	{
		reward = reward + 1000;
		diary<<"Unbelievable ! Year reward: 1000 "<<endl;
		cout<<"Unbelievable ! Year reward: 1000 "<<endl;
	}
	}///////////avoid end////////////
	diary<<" victory-day reward: "<<reward<<endl;


/////////////////VD Reward system End/////////////




////////////////////////total score//////////////////////////

///////If add new items, you need edit this line below////////////
	total_sc = total_wd + total_ot + total_cnp + total_enp + total_slpe\
	+ total_spt + total_OTG + total_PP + total_NFN +  total_rv\
	+ total_TheFour + total_Nsleep + total_PT + total_S + total_gmwd\
	+  total_uhi + total_UNB + total_MM + total_CM + total_WH + total_RG\
	+ total_PD + total_GV + reward + total_plan;



//////////Health, Energy, Spirit///////////
	
	double total_health = 3000.00;
	today_health = (total_slpe + total_NFN + total_spt + total_S\
	+ total_uhi + total_Nsleep + total_PT + total_WH + reward) / total_health * 100;
	diary<<endl;
	
	double H_growth = today_health - yesterday_H;

	diary<<"**Health** : "<<fixed<<setprecision(2)<<today_health\
	<<"%"<<"	("<<showpos<<H_growth<<"%)"<<endl;

///////////////Energy Reward////////////
	int E_reward;
	if(today_health < 0)
	{
		E_reward = -5;
	}
	else if(today_health < 0.2)
	{
		E_reward = 5;
	}
	else if(today_health < 0.4)
	{
		E_reward = 10;
	}
	else if(today_health < 0.6)
	{
		E_reward = 20;
	}
	else if(today_health < 0.8)
	{
		E_reward = 30;
	}
	else if(today_health < 1.0)
	{
		E_reward = 50;
	}
	else E_reward = 100;
/////////////////Energy Reward END/////////

	double total_energy = 5000; 
	today_energy = ( total_ot + total_wd + total_cnp + \
	total_enp + total_gmwd + total_rv + total_UNB + total_MM \
	+ total_CM + total_GV + E_reward + total_RG + total_PD) / total_energy * 100;

	double E_growth = today_energy - yesterday_E;
	
	diary<<"**Energy** : "<<fixed<<setprecision(2)<<noshowpos\
	<<today_energy<<"%"<<"	("<<showpos<<E_growth<<"%)"<<endl;


///////////////Spirit Reward////////////
	int S_reward;
	if(today_energy < 0)
	{
		S_reward = -5;
	}
	else if(today_energy < 0.2)
	{
		S_reward = 5;
	}
	else if(today_energy < 0.4)
	{
		S_reward = 10;
	}
	else if(today_energy < 0.6)
	{
		S_reward = 20;
	}
	else if(today_energy < 0.8)
	{
		S_reward = 30;
	}
	else if(today_energy < 1.0)
	{
		S_reward = 50;
	}
	else S_reward = 100;
/////////////////Spirit Reward END/////////


	double total_spirit = 5000;
	today_spirit =( total_OTG + total_PP + total_TheFour\
	+ S_reward) / total_spirit * 100 ;

	double S_growth = today_spirit - yesterday_S;
	
	diary<<"**Spirit** : "<<fixed<<setprecision(2)<<noshowpos\
	<<today_spirit<<"%"<<"	("<<showpos<<S_growth<<"%)"<<endl;

////////////////End H,E,S//////////////////
	diary<<endl;

	diary<<"--------------------------------------------------"<<endl;


	diary.close();
}


void Data::write()
{
	ofstream data;
	data.open(PATH_data,ios::app);

	time_t today;
	time(&today);
	data<<endl;
	data<<"------------------------------"<<endl;
	data<<"## "<<ctime(&today)<<endl;

	data<<endl;
	data<<"#### Today Data:"<<endl;
	data<<"*"<<" total "<<total_sc<<" word "<<total_wd<<" outhome "\
	<<total_ot<<" cn_paper "<<total_cnp<<" en_paper "<<total_enp\
	<<" sleep "<<total_slpe<<" sport "<<total_spt<<" OTG "\
	<<total_OTG<<" PP "<<total_PP<<" NFN "<<total_NFN\
	<<" review "<<total_rv<<" S "<<total_S<<\
	" game_weekday "<<total_gmwd<<\
	" unhealthy_info "<<total_uhi<<" UNB "<<total_UNB<<" MM "<<\
	total_MM<<" CM "<<total_CM<<" day "<<total_day<<" TheFour "\
	<<total_TheFour<<" Nsleep "<<total_Nsleep<<" GameVideo "<<\
	total_GV<<" PureThinking "<<total_PT<<" Health "<<today_health<<\
	" Energy "<<today_energy<<" Spirit "<<today_spirit<<" WhiteHouse "<<\
	total_WH<<" Readgood "<<total_RG<<" PaperDiary "<<total_PD<<endl;

}




void Plan::make()
{
	ofstream diary;
	diary.open(PATH_plan, ios::trunc);// trunc: clean exist file, creat new.


	int i;
	int total;
	string plan[15];
	int plan_score[15];


	system("clear");
////////////////write plan///////////////////////
	cout<<"Please write down your plan:"<<endl;
	diary<<"Today Plan"<<endl;
	getchar();//eat the 'Enter', avoid skipping 1st getline
	for(i = 1; ;i++)
	{
		cout<<i<<".";
		getline(cin, plan[i]);
		
		if(plan[i] == "over")
		{
			total = i - 1;
			break;
		}
		

		diary<<i<<"."<<plan[i]<<endl;
		cout<<endl;

	}
	diary<<"Plan Over"<<endl;
	diary<<endl;
/////////////write plan END////////////////////////


/////////////define score for each plan////////////
	diary<<"Score ";
	for(i = 1; i<=total ; i++)
	{
		cout<<endl;
		cout<<"score for plan "<<i<<":"<<endl;
		cin>>plan_score[i];

		diary<<plan_score[i]<<" ";
	}
//////////////define END///////////////////////////
	
	system("clear");

	cout<<"please check:"<<endl;
	for(i=1;i<=total;i++)
	{
		cout<<"		"<<i<<"."<<plan[i]<<endl;
		cout<<"		"<<"score: "<<plan_score[i]<<endl;
		cout<<endl;
	}
	cout<<endl;

}





int Plan::check()
{
	ifstream infile;
	infile.open(PATH_plan);

	if(!infile)
	{
		cout<<"Can not open!"<<endl;
		return -1;
	}
	infile.close();

	int total = 0;
	string plan[15];//number of plans should less than 15

///////////////get plan content/////////////////////
	infile.open(PATH_plan);

	int i;

	for( i = 0 ; ; i++ )
	{
		getline(infile, plan[i]);

		if(plan[i] =="Plan Over")
			break;
		
		total += 1;
	}
	
//////////////get plan content END///////////////


//////////////get plan scores////////////////////
	int plan_score[total];
	string temp;
	string scoreline;

	while(infile>>temp)
	{
		getline(infile, scoreline);
	}
	istringstream ss(scoreline);

	for(i=1; i< total; i++)
	{
		ss>>plan_score[i];
	}
	
	infile.close();
////////////////get plan scores END///////////////
	

///////////////check finish///////////////////////
	for(i=1; i< total; i++)
	{
		cout<<plan[i]<<endl;
		cout<<" finish? (y/n):";
		char finish;
		cin>>finish;
		if(finish=='y')
		{
			total_plan += plan_score[i];
		}
		cout<<endl;
	}

	cout<<"today you get: "<<total_plan<<endl;
	cout<<endl;

	return 0;
}
