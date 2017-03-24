#include"class.h"
#include<ctime>
#include<sstream>
using namespace std;

#define PATH "YOUR-PATH"

static int total_sc,total_wd,total_ot,total_cnp, total_enp,\
total_slpe, total_spt, total_OTG, total_PP, total_NFN, \
total_smd, total_rv;//total socres (Good)

static int total_S, total_gmwd, total_dmd, total_uhi, total_UNB, \
total_MM;//total scores(Bad)




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
	sunny_mind_score = 0;
	review_score = 0;

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
		out_score += 20;
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
			cout<<"Later than 11:00 ? (y/n)"<<endl;
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

void Good::sunny_mind()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"keep a fresh, healthy mind and no dirty thinking today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		sunny_mind_score = 20;
	}

	total_smd += sunny_mind_score;

	diary<<"| Clean Thinking | "<<sunny_mind_score<<" |"<<endl;
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
		review_score = 30;
	}

	total_rv += review_score;

	diary<<"| review knowledge | "<<review_score<<" |"<<endl;
	diary.close();
}





////////////////////////Bad Functions/////////////////////////////


Bad::Bad()// class Bad constructor
{
	S_score = 0;
	gamewkd_score = 0;
	dark_mind_score = 0;
	unhealthy_info_score = 0;
	UNB_score = 0;
	MM_score = 0;
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
		S_score = -200*i;
	}
	else S_score = 5;

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

void Bad::dark_mind()
{
	ofstream diary;
	diary.open(PATH,ios::app);

	char finish;
	cout<<"### Think any dirty things today ?"<<endl;
	cout<<"(y/n)";
	cin>>finish;
	if(finish == 'y')
	{
		dark_mind_score = -10;
	}
	
	else dark_mind_score = 5;
	
	total_dmd += dark_mind_score;
	
	diary<<"| dark mind | "<<dark_mind_score<<" |"<<endl;
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
	cout<<"### Today when you get up, did you play mobile ?"<<endl;
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



////////////////////////////Others//////////////////////////////
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

	char m_total[15],m_word[15],m_outhome[15],m_cnpaper[15],m_enpaper[15]\
	,m_slpe[15],m_spt[15],m_OTG[15],m_PP[15],m_NFN[15],m_smd[15],m_rv[15]\
	,m_S[15],m_gwkd[15],m_dmd[15],m_uhi[15], m_UNB[15], m_MM[15];
	
	ss>>m_total>>total_sc>>m_word>>total_wd>>m_outhome>>total_ot\
	>>m_cnpaper>>total_cnp>>m_enpaper>>total_enp>>m_slpe>>total_slpe>>\
	m_spt>>total_spt>>m_OTG>>total_OTG>>m_PP>>total_PP>>m_NFN>>total_NFN\
	>>m_smd>>total_smd>>m_rv>>total_rv>>m_S>>total_S>>m_gwkd>>total_gmwd\
	>>m_dmd>>total_dmd>>m_uhi>>total_uhi>>m_UNB>>total_UNB>>m_MM>>total_MM;
	
	infile.close();
}




void Write::summary()
{
	ofstream diary;
	diary.open(PATH,ios::app);

///////If add new items, you need edit this line below////////////
	total_sc = total_wd + total_ot + total_cnp + total_enp + total_slpe\
	+ total_spt + total_OTG + total_PP + total_NFN + total_smd + total_rv\
	+ total_S + total_gmwd + total_dmd + total_uhi + total_UNB;

//////////Health, Energy, Spirit///////////
	
	double total_health = 1000.00;
	double health = (total_slpe + total_NFN + total_spt + total_S\
	+ total_uhi) / total_health * 100;
	diary<<endl;
	diary<<"**Health** : "<<health<<"%"<<endl;

	double total_energy = 3000; 
	double energy = ( (health * total_health / 100) + total_ot + \
	total_wd + total_cnp + total_enp + total_gmwd + total_rv\
	+ total_UNB ) / total_energy * 100;

	diary<<"**Energy** : "<<energy<<"%"<<endl;

	double total_spirit = 5000;
	double spirit =((energy * total_energy  / 100 ) + total_OTG + \
	total_PP + total_smd + total_dmd ) / total_spirit * 100 ;

	diary<<"**Spirit** : "<<spirit<<"%"<<endl;

////////////////End//////////////////

	diary<<endl;
	diary<<"###Summary:"<<endl;
	diary<<"*"<<" total "<<total_sc<<" word "<<total_wd<<" outhome "\
	<<total_ot<<" cn_paper "<<total_cnp<<" en_paper "<<total_enp\
	<<" sleep "<<total_slpe<<" sport "<<total_spt<<" OTG "\
	<<total_OTG<<" PP "<<total_PP<<" NFN "<<total_NFN<<" smd "<<\
	total_smd<<" review "<<total_rv<<" S "<<total_S<<\
	" game_weekday "<<total_gmwd<<" dark_mind "<<total_dmd<<\
	" unhealthy_info "<<total_uhi<<" UNB "<<total_UNB<<" MM "<<\
	total_MM<<endl;

	diary.close();
}
