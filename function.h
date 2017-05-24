#include"class.h"
#include<ctime>
#include<sstream>
#include<iomanip>
#include"sentence.h"
using namespace std;

				/*These lines for Linux*/
//#define PATH_data "/home/Kevin/Diary/30-field/data/data.md"
//#define PATH "/home/Kevin/Diary/30-field/data/diary.md"
//#define PATH_plan "/home/Kevin/Diary/30-field/data/plan.md"

				/*These lines for Windows*/
//#define PATH "/mnt/f/OneDrive/life/April.md"
//#define PATH_data "/mnt/f/OneDrive/life/data.md"
//#define PATH_plan "/mnt/f/OneDrive/life/plan.md"

				/*These lines for MacOS (run)*/
#define PATH "/Users/snoopy/diary/run/data/Diary.md"
#define PATH_data "/Users/snoopy/diary/run/data/data.md"
#define PATH_plan "/Users/snoopy/diary/run/data/plan.md"
#define PATH_excel "/Users/snoopy/diary/run/data/excel.txt"

				/*These lines for MacOS (Test Field)*/
//#define PATH "/Users/snoopy/diary/field/Diary.md"
//#define PATH_data "/Users/snoopy/diary/field/data.md"
//#define PATH_plan "/Users/snoopy/diary/field/plan.md"
//#define PATH_excel "/Users/snoopy/diary/field/excel.txt"

static int total_sc,total_wd,total_ot,total_cnp, total_enp,\
total_slpe, total_spt, total_OTG, total_PP,  \
total_rv, total_day, total_TheFour, total_Nsleep,\
reward, total_PT, total_WH, total_RG, total_PD, total_BP, \
total_fruit, total_ss, total_veg;//total socres (Good)

static int total_S, total_gmwd, total_uhi, total_UNB, \
total_ME, total_CM, total_GV, total_DM, total_daze;//total scores(Bad)

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
	veg_score = 0;

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

void Good::sleep()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	int sleep_time;
	cout<<"Input your sleep time(eg: 2140 for 21:40)"<<endl;
	cout<<"	sleep time:";
	cin>>sleep_time;

	while(cin.fail())// if cin went wrong, return 'true'
	{
		cin.clear();//reset cin parameter
		cout<<"	please ONLY input numbers ^_~"<<endl;
		cout<<"	Input again: ";
		cin.ignore(10000,'\n');//clear last-time input content
		cin>>sleep_time;
	}


	if(sleep_time <= 2130)
	{
		sleep_score = 50;
	}
	else if(sleep_time <= 2200)
	{
		sleep_score = 30;
	}
	else if(sleep_time <=2230)
	{
		sleep_score = 10;
	}
	else if(sleep_time <= 2300)
	{
		sleep_score = 0;
	}
	else sleep_score = -30;

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
	else WH_score = -80; 
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
	cout<<"Did you write diary on paper today ?"<<endl;
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
		ss_score = 50;
	}
	else
	{
		cout<<"	You are not an animal ! Please keep sacred."<<endl;
		ss_score = -50;
	}

	total_ss += ss_score;

	diary<<"| sacred sight score | "<<ss_score<<" |"<<endl;
	diary.close();
}

void Good::vegetarian()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"Keep a vegetarian diet today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		veg_score = 30;
	}
	else veg_score = -10;

	total_veg += veg_score;

	diary<<"| vegetarian score | "<<veg_score<<" |"<<endl;
	diary.close();
}

////////////////////////Bad Functions/////////////////////////////


Bad::Bad()// class Bad constructor
{
	S_score = 0;
	gamewkd_score = 0;
	unhealthy_info_score = 0;
	UNB_score = 0;
	ME_score = 0;
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




void Bad::ME()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"###Today when you get up, did you play mobile ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		ME_score = -30;
	}
	
	else ME_score = 5;

	total_ME += ME_score;
	
	diary<<"| Use electronics when get up | "<<ME_score<<" |"<<endl;
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
	,m_S[15],m_gwkd[15],m_uhi[15], m_UNB[15], m_ME[15],m_CM[15]\
	,m_day[15],m_TheFour[15],m_Nsleep[15],m_GV[15],m_PT[15],m_Health[15]\
	,m_Energy[15], m_Spirit[15], m_WhiteHouse[15], m_readgood[15], m_PD[15]\
	,m_BP[15],m_Hgrowth[15],m_Egrowth[15],m_Sgrowth[15], m_DM[15], m_fruit[15]\
	,m_plan[15], m_daze[15], m_ss[15], m_veg[15];
	
	ss>>m_total>>total_sc>>m_word>>total_wd>>m_outhome>>total_ot\
	>>m_cnpaper>>total_cnp>>m_enpaper>>total_enp>>m_slpe>>total_slpe>>\
	m_spt>>total_spt>>m_OTG>>total_OTG>>m_PP>>total_PP\
	>>m_rv>>total_rv>>m_S>>total_S>>m_gwkd>>total_gmwd\
	>>m_uhi>>total_uhi>>m_UNB>>total_UNB>>m_ME>>total_ME\
	>>m_CM>>total_CM>>m_day>>total_day>>m_TheFour>>total_TheFour>>m_Nsleep\
	>>total_Nsleep>>m_GV>>total_GV>>m_PT>>total_PT>>m_Health\
	>>yesterday_H>>m_Energy>>yesterday_E>>m_Spirit>>yesterday_S>>m_WhiteHouse\
	>>total_WH>>m_readgood>>total_RG>>m_PD>>total_PD>>m_BP>>total_BP\
	>>m_Hgrowth>>H_growth>>m_Egrowth>>E_growth>>m_Sgrowth>>S_growth>>m_DM\
	>>total_DM>>m_fruit>>total_fruit>>m_plan>>total_plan>>m_daze>>total_daze\
	>>m_ss>>total_ss>>m_veg>>total_veg;
	
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
	+  total_uhi + total_UNB + total_ME + total_CM + total_WH + total_RG\
	+ total_PD + total_GV + reward + total_plan + total_BP + total_DM\
	+ total_fruit + total_daze + total_ss + total_veg;



//////////Health, Energy, Spirit///////////
	
	double total_health = 5000.00;
	today_health = (total_slpe + total_spt + total_S\
	+ total_uhi + total_Nsleep + total_PT + total_WH\
	+ reward + total_fruit + total_ss + total_veg) / total_health * 100;
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
	total_enp + total_gmwd + total_rv + total_UNB + total_ME \
	+ total_CM + total_GV + E_reward + total_RG + total_PD + \
	+ total_plan + total_DM + total_daze + (total_ss/2) ) / total_energy * 100;

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
	<<" UNB "<<total_UNB<<" ME "<<total_ME<<" CM "<<total_CM\
	<<" day "<<total_day<<" TheFour "<<total_TheFour<<" Nsleep "\
	<<total_Nsleep<<" GameVideo "<<total_GV<<" PureThinking "\
	<<total_PT<<" Health "<<today_health<<" Energy "<<today_energy\
	<<" Spirit "<<today_spirit<<" WhiteHouse "<<total_WH<<" Readgood "\
	<<total_RG<<" PaperDiary "<<total_PD<<" Baptism "<<total_BP\
	<<" H_growth "<<H_growth<<" E_growth "<<E_growth\
	<<" S_growth "<<S_growth<<" Dorm_meal "<<total_DM<<" fruit "\
	<<total_fruit<<" plan "<<total_plan<<" daze "<<total_daze\
	<<" sacredsight "<<total_ss<<" vegetarian "<<total_veg<<endl;

	data.close();

}
//////////////////// Write summary END ////////////////////////

void Write::excel()
{
	ofstream excel;
	excel.open(PATH_excel,ios::app);

	excel<<fixed<<setprecision(2)<<total_day<<"	"<<today_health\
	<<"	"<<today_energy<<"	"<<today_spirit<<endl;
	excel.close();
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


