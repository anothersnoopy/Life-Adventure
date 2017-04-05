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
	good.NFN();
	good.cn_paper();
	good.en_paper();
	good.review();
	good.PP();
	good.OTG();
	good.PureThinking();
	good.WhiteHouse();
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

	data.write();//write today's data
	
	system("clear");
	
	cout<<endl;
	cout<<" ok,finished."<<endl;
	cout<<endl;

	return 0;
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

	cout<<endl;
	cout<<"		Now your H-E-S value is:"<<endl;
	cout<<endl;
	cout<<"		Health: "<<yesterday_H<<"%"<<endl;
	cout<<"		Energy: "<<yesterday_E<<"%"<<endl;
	cout<<"		Spirit: "<<yesterday_S<<"%"<<endl;
	cout<<endl;

	return 0;

}


int make_plan()
{
	Plan plan;
	plan.make();
	return 0;
}





int check_plan()
{
	system("clear");
	Plan plan;
	plan.check();
	return 0;
}