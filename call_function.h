int overcheck()
{
	cout<<"continue ? (y/n)";
	char xxx;
	cin>>xxx;
	if(xxx == 'y')
	{
		return 1;
	}
	else 
	{
		cout<<"			Good bye ~ "<<endl<<endl;
		return 0;
	}
}


int random_sentences()
{
	Message obj;
	int x;// a random number
	srand(time(NULL));
	x = rand() % 52 + 1;// generate a num between 1-52
	cout<<endl<<obj.msg[x]<<endl<<endl;
	
	return 0;
	
}


void welcome()
{
	system("clear");
	
	cout<<"			Welcome to Life Adventure !"<<endl;
	cout<<endl;
	cout<<"	Actually, there are only two kinds of human in the world,"<<endl;
	cout<<"			One is Great Personage,"<<endl;
	cout<<"			The Other is animal."<<endl<<endl;
	random_sentences();
	cout<<endl;
	cout<<"	what do you want to do?"<<endl;
	cout<<"			1. Record today."<<endl;
	cout<<"			2. Check latest data."<<endl;
	cout<<"			3. Make a plan."<<endl;
	cout<<"			4. Check plan completion"<<endl;
	cout<<"			0. Exit"<<endl;
	cout<<endl;
	cout<<"	please choose:";
}



int write_diary()
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
	
	system("clear");

	data.read();//read yesterday's data
	write.date();//write today's date
	write.table_head();
	
	good.paperDiary();
	good.sleep();
	good.readgood();
	good.outhome();
	good.sport();
	good.word();
	good.Nsleep();
	good.cn_paper();
	good.en_paper();
	good.review();
	good.PP();
	good.OTG();
	good.PureThinking();
	good.WhiteHouse();
	good.TheFour();
	good.baptism();
	good.fruit();
	good.sacredsight();


	bad.S();
	bad.MM();
	bad.CM();
	bad.DM();
	bad.game_weekday();
	bad.GV();
	bad.unhealthy_info();
	bad.UNB();
	bad.daze();
	
	write.note();
	write.summary();

	data.write();//write today's data
	
	system("clear");
	
	cout<<endl<<" ok,finished."<<endl<<endl;

	return overcheck();
	
}





int check_data()// to read yesterday's data
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

	system("clear");

	cout<<endl;
	cout<<"			Day "<<noshowpos<<total_day<<endl;
	cout<<endl;
	cout<<"		Your H-E-S value is:"<<endl;
	cout<<endl;
	cout<<"		Health: "<<fixed<<setprecision(2)<<yesterday_H\
	<<"% ("<<showpos<<H_growth<<"%)"<<endl;
	cout<<"		Energy: "<<fixed<<setprecision(2)<<noshowpos<<yesterday_E\
	<<"% ("<<showpos<<E_growth<<"%)"<<endl;
	cout<<"		Spirit: "<<fixed<<setprecision(2)<<noshowpos<<yesterday_S\
	<<"% ("<<showpos<<S_growth<<"%)"<<endl<<endl;

/////////////Set Dream Here///////////
	cout<<"	* Buy Macbook Pro: "<<noshowpos<<(int)((100 -\
	yesterday_H)/H_growth)<<" days left."<<endl<<endl;
////////////Set Dream END////////////

	return overcheck();

}



int make_plan()
{
	Plan plan;
	plan.make();
	return overcheck();
}



int check_plan()
{
	system("clear");
	Plan plan;
	plan.check();
	return overcheck();
}

