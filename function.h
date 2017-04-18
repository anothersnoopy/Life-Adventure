#include"class.h"
#include<ctime>
#include<sstream>
#include<iomanip>
using namespace std;

#define PATH_data "/home/Kevin/Diary/28-field/data/data.md"
#define PATH "/home/Kevin/Diary/28-field/data/diary.md"
#define PATH_plan "/home/Kevin/Diary/28-field/data/plan.md"
//#define PATH "/mnt/f/OneDrive/diary.md"
//#define PATH_data "/mnt/f/OneDrive/diarydata/data.md"
//#define PATH_plan "/mnt/f/OneDrive/diarydata/plan.md"

static int total_sc,total_wd,total_ot,total_cnp, total_enp,\
total_slpe, total_spt, total_OTG, total_PP,  \
total_rv, total_day, total_TheFour, total_Nsleep,\
reward, total_PT, total_WH, total_RG, total_PD, total_BP, \
total_fruit, total_ss;//total socres (Good)

static int total_S, total_gmwd, total_uhi, total_UNB, \
total_MM, total_CM, total_GV, total_DM, total_daze;//total scores(Bad)

static double yesterday_H, yesterday_E, yesterday_S, today_energy,\
today_health, today_spirit, H_growth, E_growth, S_growth;

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
	review_score = 0;
	total_day = 0;
	TheFour_score = 0;
	Nsleep_score = 0;
	PT_score = 0;
	WH_score = 0;
	RG_score = 0;
	PD_score = 0;
	baptism_score = 0;
	fruit_score = 0;
	ss_score = 0;

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
		word_score = 20;
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
	cout<<"Morning: Go out of dormitory before 8:30?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		out_score = 20;
	}
	else out_score = -50;

	cout<<"	Noon: Go out of dormitory before 14:30?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		out_score = out_score + 20;
	}
	else out_score = out_score - 50;

	cout<<"		Evening: Go out of dormitory before 19:30?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		out_score += 20;
	}
	else out_score = out_score - 50;

	total_ot += out_score;

	diary<<"| outhome score | "<<out_score<<" |"<<endl;
	diary.close();
}

void Good::cn_paper()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Read literatures in Chinese?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cout<<"	How many ?"<<endl;
		int i;
		cin>>i;
		while(cin.fail())// if cin went wrong, return 'true'
		{
			cin.clear();//reset cin parameter
			cout<<"	You should input a number. ^_~"<<endl;
			cout<<"	How many papers ?"<<endl;
			cin.ignore(10000,'\n');//clear last-time input content
			cin>>i;
		}

		cnpaper_score = 50 * i;
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
	cout<<"Read literatures in English?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cout<<"	How many ?"<<endl;
		int i;
		cin>>i;
		while(cin.fail())// if cin went wrong, return 'true'
		{
			cin.clear();//reset cin parameter
			cout<<"	You should input a number. ^_~"<<endl;
			cout<<"	How many papers ?"<<endl;
			cin.ignore(10000,'\n');//clear last-time input content
			cin>>i;
		}
		enpaper_score = 200 * i;
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
		sleep_score = 30;
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
		sport_score = 30;
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
		while(cin.fail())// if cin went wrong, return 'true'
		{
			cin.clear();//reset cin parameter
			cout<<"	The number should between 0-9. ^_~"<<endl;
			cout<<"	I ask you again: how many times ?"<<endl;
			cin.ignore(10000,'\n');//clear last-time input content
			cin>>i;
		}
		TheFour_score = (30 * i);
	}
	else TheFour_score = -20;
	if( TheFour_score >= 60 )
	{
		TheFour_score = 60;// no more than 60 per day
	}

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
			Nsleep_score = -10;
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
	else WH_score = -30; 
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
		RG_score = 15;
	}
	else RG_score = -15;
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


void Good::baptism()
{
	ofstream diary;
	diary.open(PATH,ios::app);
		
	char finish;
	cout<<"Baptism ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		baptism_score = 30;
	}
	else baptism_score = -5;
	total_BP += baptism_score;
	diary<<"| Baptism score | "<<baptism_score<<" |"<<endl;
	diary.close();
}

void Good::fruit()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Did you eat fruit today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		fruit_score = 10;
	}

	total_fruit += fruit_score;

	diary<<"| fruit score | "<<fruit_score<<" |"<<endl;
	diary.close();
}


void Good::sacredsight()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Keep your sight sacred today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		ss_score = 30;
	}
	else
	{
		cout<<"	You are not an animal ! Please keep sacred."<<endl;
		ss_score = -30;
	}

	total_ss += ss_score;

	diary<<"| sacred sight score | "<<ss_score<<" |"<<endl;
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
	DM_score = 0;
	daze_score = 0;

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
		int i;
		cin>>i;
		
		while(cin.fail())// if cin went wrong, return 'true'
		{
			cin.clear();//reset cin parameter
			cout<<"	Input a number please. "<<endl;
			cout<<"	How many times ?"<<endl;
			cin.ignore(10000,'\n');//clear last-time input content
			cin>>i;
		}

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


void Bad::DM()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Eat Food at dormitory today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		DM_score = -20;
	}
	else DM_score = 5;
	
	total_DM += DM_score;
	
	diary<<"| Dormitory Meal | "<<DM_score<<" |"<<endl;
	diary.close();
}


void Bad::daze()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Sometimes in a daze ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		cout<<"		It will kill you. Your life must be explicit and sane."<<endl;
		cout<<endl;
		cout<<"		loss 50 points"<<endl<<endl;
		daze_score = -50;
	}
	else daze_score = 5;
	
	total_daze += daze_score;
	
	diary<<"| Daze | "<<daze_score<<" |"<<endl;
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
	,m_slpe[15],m_spt[15],m_OTG[15],m_PP[15],m_rv[15]\
	,m_S[15],m_gwkd[15],m_uhi[15], m_UNB[15], m_MM[15],m_CM[15]\
	,m_day[15],m_TheFour[15],m_Nsleep[15],m_GV[15],m_PT[15],m_Health[15]\
	,m_Energy[15], m_Spirit[15], m_WhiteHouse[15], m_readgood[15], m_PD[15]\
	,m_BP[15],m_Hgrowth[15],m_Egrowth[15],m_Sgrowth[15], m_DM[15], m_fruit[15]\
	,m_plan[15], m_daze[15], m_ss[15];
	
	ss>>m_total>>total_sc>>m_word>>total_wd>>m_outhome>>total_ot\
	>>m_cnpaper>>total_cnp>>m_enpaper>>total_enp>>m_slpe>>total_slpe>>\
	m_spt>>total_spt>>m_OTG>>total_OTG>>m_PP>>total_PP\
	>>m_rv>>total_rv>>m_S>>total_S>>m_gwkd>>total_gmwd\
	>>m_uhi>>total_uhi>>m_UNB>>total_UNB>>m_MM>>total_MM\
	>>m_CM>>total_CM>>m_day>>total_day>>m_TheFour>>total_TheFour>>m_Nsleep\
	>>total_Nsleep>>m_GV>>total_GV>>m_PT>>total_PT>>m_Health\
	>>yesterday_H>>m_Energy>>yesterday_E>>m_Spirit>>yesterday_S>>m_WhiteHouse\
	>>total_WH>>m_readgood>>total_RG>>m_PD>>total_PD>>m_BP>>total_BP\
	>>m_Hgrowth>>H_growth>>m_Egrowth>>E_growth>>m_Sgrowth>>S_growth>>m_DM\
	>>total_DM>>m_fruit>>total_fruit>>m_plan>>total_plan>>m_daze>>total_daze\
	>>m_ss>>total_ss;
	
	infile.close();
}




void Write::summary()
{	
/////////////Get total_plan score/////////////
	ifstream infile;
	infile.open(PATH_plan);

	if(!infile)
	{
		cout<<"Can not open plan list !"<<endl;
	}
	
	string line;
	string temp;
	while(infile>>temp)
	{
		getline(infile, line);
	}
	istringstream ss(line);
	
	ss>>total_plan;

	infile.close();
/////////////Get total_plan score END///////

	ofstream diary;
	diary.open(PATH,ios::app);


/////////////////Day///////////////////////
	diary<<endl;
	diary<<"### Data Analysis:"<<endl;
	diary<<" *Day* : "<<total_day<<endl;
///////////////End Day/////////////////////



///////////////Victory Day reward system//////////
	if(total_day <= 14)
	{
		reward = (total_day * 2);
	}
	else if(total_day <= 30)
	{
		reward = 30;
	}
	else if(total_day <= 60)
	{
		reward = 40;
	}
	else if(total_day <= 90)
	{
		reward = 50;
	}
	else if(total_day <= 120)
	{
		reward = 60;
	}
	else
		reward = 80;
	
	
	cout<<endl;/////for good display on bash shell
	if( total_day != 0)
	{////avoid total_day = 0 trouble///////////

	if((total_day % 7) == 0)
	{
		reward = reward + 30;
		diary<<"**Yes! Week reward: 30**"<<endl<<endl;
		cout<<" Yes! Week reward: 30 "<<endl;
	}
	
	if((total_day % 30) == 0 )
	{
		reward = reward + 100;
		diary<<"**Good! Month reward: 100**"<<endl<<endl;
		cout<<" Good! Month reward: 100 "<<endl;
	}
	
	if((total_day % 100) == 0 )
	{
		reward = reward + 300;
		diary<<"**Excellent! Hundred-Day reward: 300**"<<endl<<endl;
		cout<<" Excellent! Hundred-Day reward: 300 "<<endl;
	}
	
	if((total_day % 183) == 0 )
	{
		reward = reward + 500;
		diary<<"**Splendid! Half-Year reward: 500**"<<endl<<endl;
		cout<<"Splendid! Half-Year reward: 500 "<<endl;
	}
	
	if((total_day % 365) == 0 )
	{
		reward = reward + 1000;
		diary<<"**Unbelievable ! Year reward: 1000** "<<endl<<endl;
		cout<<"Unbelievable ! Year reward: 1000 "<<endl;
	}
	}///////////avoid end////////////
	diary<<" victory-day reward: "<<reward<<endl;


/////////////////VD Reward system End/////////////




////////////////////////total score//////////////////////////

///////If add new items, you need edit this line below////////////
	total_sc = total_wd + total_ot + total_cnp + total_enp + total_slpe\
	+ total_spt + total_OTG + total_PP +  total_rv\
	+ total_TheFour + total_Nsleep + total_PT + total_S + total_gmwd\
	+  total_uhi + total_UNB + total_MM + total_CM + total_WH + total_RG\
	+ total_PD + total_GV + reward + total_plan + total_BP + total_DM\
	+ total_fruit + total_daze + total_ss;



//////////Health, Energy, Spirit///////////
	
	double total_health = 5000.00;
	today_health = (total_slpe + total_spt + total_S\
	+ total_uhi + total_Nsleep + total_PT + total_WH\
	+ reward + total_fruit) / total_health * 100;
	diary<<endl;
	
	H_growth = today_health - yesterday_H;

	diary<<"**Health** : "<<fixed<<setprecision(2)<<today_health\
	<<"%"<<"	("<<showpos<<H_growth<<"%)"<<endl;

///////////////Energy Reward////////////
	int E_reward;
	if(today_health < 0)
	{
		E_reward = today_health;
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
	+ total_CM + total_GV + E_reward + total_RG + total_PD + \
	+ total_plan + total_DM + total_daze + total_ss) / total_energy * 100;

	E_growth = today_energy - yesterday_E;
	
	diary<<"**Energy** : "<<fixed<<setprecision(2)<<noshowpos\
	<<today_energy<<"%"<<"	("<<showpos<<E_growth<<"%)"<<endl;


///////////////Spirit Reward////////////
	int S_reward;
	if(today_energy < 0)
	{
		S_reward = today_energy;
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
	+ total_BP + S_reward) / total_spirit * 100 ;

	S_growth = today_spirit - yesterday_S;
	
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
	<<total_OTG<<" PP "<<total_PP<<" review "<<total_rv<<" S "<<total_S<<\
	" game_weekday "<<total_gmwd<<" unhealthy_info "<<total_uhi\
	<<" UNB "<<total_UNB<<" MM "<<total_MM<<" CM "<<total_CM\
	<<" day "<<total_day<<" TheFour "<<total_TheFour<<" Nsleep "\
	<<total_Nsleep<<" GameVideo "<<total_GV<<" PureThinking "\
	<<total_PT<<" Health "<<today_health<<" Energy "<<today_energy\
	<<" Spirit "<<today_spirit<<" WhiteHouse "<<total_WH<<" Readgood "\
	<<total_RG<<" PaperDiary "<<total_PD<<" Baptism "<<total_BP\
	<<" H_growth "<<H_growth<<" E_growth "<<E_growth\
	<<" S_growth "<<S_growth<<" Dorm_meal "<<total_DM<<" fruit "\
	<<total_fruit<<" plan "<<total_plan<<" daze "<<total_daze\
	<<" sacredsight "<<total_ss<<endl;

}
//////////////////// Write summary END ////////////////////////



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
	ofstream diary;
	diary.open(PATH_plan, ios::app);// trunc: clean exist file, creat new.

	diary<<endl;

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
	diary<<"Get "<<total_plan<<endl;

	cout<<"today you get: "<<total_plan<<endl;
	cout<<endl;

	return 0;
}



Message::Message()
{
	msg[1] = "	原来人可以度过最无望的日子，抖落身上的灰雨，重披一身星光。";
	msg[2] = "	若你有幸与众不同，那么请永远不要改变。";
	msg[3] = "	人生的精彩，与奢华无关。";
	msg[4] = "	在德不在险。";
	msg[5] = "	站在树上的鸟儿，从来不会害怕树枝断裂，因为它相信的不是树枝，而是自己的翅膀";
	msg[6] = "	走崎岖路，需平常心";
	msg[7] = "	不要，只因一次挫败，就放弃你原来决心达到的目的。";
	msg[8] = "	当你真心渴望某样东西时，整个世界都会来帮忙。";
	msg[9] = "	生活中最困难的事情也是最值得去做的。";
	msg[10] = "	担心出现问题，往往比问题真正出现更加让人感到难过和痛苦。";
	msg[11] = "	明年今日，你会希望此时此刻自己已经行动了。";
	msg[12] = "	记得常回头看看以前犯的错误，但绝不要为它们感到后悔。";
	msg[13] = "	培养能力就是创造一个强大的心理免疫系统。";
	msg[14] = "	你要做的是相信自己，你能作茧自缚，那么你也能破茧成蝶。";
	msg[15] = "	生活就像自行车。要保持平衡，你就得不停地前进。";
	msg[16] = "	有时候，最困难的不是放手，而是学着如何开始。";
	msg[17] = "	决定我们成为什么样的人的，不是我们的能力，而是我们的选择。";
	msg[18] = "	世界上对勇气的最大考验是忍受失败，而不是丧失信心。";
	msg[19] = "	只要你不停攀登，就能到达任何一座山峰之巅";
	msg[20] = "	正是那些让人心绪沉重的时刻，日后成了我们巨大满足和快乐的源泉";
	msg[21] = "	坏消息是光阴似箭，好消息是弓在你手中";
	msg[22] = "	努力没有替代品。最先开始，最后离开。";
	msg[23] = "	成功不是结局，失败也不是灾难，持续的勇气才是最重要的。";
	msg[24] = "	不管你的目标是什么，一心一意是最关键的。";
	msg[25] = "	一个新的目标，一个新的梦想，从来不晚";
	msg[26] = "	你要贪玩儿，可以，但要记住，贪玩儿是要付出代价的。";
	msg[27] = "	人生是要奋斗的，顺境要奋斗，逆境更要如此。人生因奋斗而有意义，没有奋斗的人生就像行尸走肉一般。";
	msg[28] = "	无论做什么事都要懂得规划，有了规划才能有目标，有目标做事才有动力。";
	msg[29] = "	但是身处当时的自己，却是那么享受那种设定目标并完成目标、发现困难并克服困难的成就感。";
	msg[30] = "	奋斗是为了让自己成长，让自己变强大，而不是为了去和他人比较";
	msg[31] = "	每个奋斗的日子，我都不敢停歇脚步，因为心里明白未来还有好多目标等着我一个一个去攻克，未来还有好多路等着我去踏上坚实的足印。";
	msg[32] = "	知道傻子为什么能成功吗？因为傻子很傻，他不管自己是不是能够做成，也不管别人怎么笑话他，也不管遇到多少困难，他只是一个人傻头傻脑的一直做。而聪明人很聪明，他总会考虑自己目前的目标对不对，会不会有更好的方法，能不能抄捷径省时间。最后聪明人选择了一条又一条路，每条路都刚走了一点点又换，所以，他总是在离起点不远的地方徘徊。最后，傻子比聪明人先到达了终点。";
	msg[33] = "	对于未来，我只梦想最好的情况，并定下最踏实的计划，而绝不花时间在无畏的担心上，因为我知道，只要把我对自己的承诺付诸实践，我的未来将不会只是一个梦。";
	msg[34] = "	慆慢则不能励精，险躁则不能冶性。";
	msg[35] = "	非淡泊无以明志，非宁静无以致远。";
	msg[36] = "	吾闻之，新沐者必弹冠，新浴者必振衣；安能以身之察察，受物之汶汶者乎！";
	msg[37] = "	安能以皓皓之白，而蒙世俗之尘埃乎！";
	msg[38] = "	夫祸患常积于忽微，而智勇多困于所溺。";
	msg[39] = "	料峭春风吹酒醒，微冷，山头斜照却相迎。";
	msg[40] = "	竹杖芒鞋轻胜马，谁怕？一蓑烟雨任平生。";
	msg[41] = "	回首向来萧瑟处，归去，也无风雨也无晴。";
	msg[42] = "	山气日夕佳，飞鸟相与还。此中有真意，欲辩已忘言。";
	msg[43] = "	我来问道无余说，云在青天水在瓶。";
	msg[44] = "	苍苍竹林寺，杳杳钟声晚。";
	msg[45] = "	客亦知夫水与月乎？逝者如斯，而未尝往也；盈虚者如彼，而卒莫消长也";
	msg[46] = "	南朝四百八十寺，多少楼台烟雨中。";
	msg[47] = "	行到水穷处，坐看云起时。偶然值林叟，谈笑无还期。";
	msg[48] = "	春潮带雨晚来急，野渡无人舟自横。";
	msg[49] = "	春有百花秋有月，夏有凉风冬有雪。";
	msg[50] = "	空山新雨后，天气晚来秋。";
	msg[51] = "	明月松间照，清泉石上流";
	msg[52] = "	惟江上之清风，与山间之明月。耳得之而为声，目遇之则成色。";


}
