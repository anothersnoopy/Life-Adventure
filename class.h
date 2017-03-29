class Good
{
	public:
	Good();
	void word();
	void outhome();
	void cn_paper();// read a paper writed in Chinese
	void en_paper();// read a paper writed in English
	void sleep();
	void sport();//
	void OTG();// do One Thing Good
	void PP();// Phone Parents
	void NFN();// No Food at Night
	void sunny_mind();// keep a fresh, healthy, and sunny mind for whole day
	void review();// review what you learn this day
	void TheFour();//Read <The Four>
	void Nsleep();// Noon sleep for 20-30min between 12:30-13:50

	private:
	int word_score;
	int out_score;
	int cnpaper_score;
	int enpaper_score;
	int sleep_score;
	int sport_score;
	int OTG_score, PP_score, NFN_score, sunny_mind_score, review_score;
	int TheFour_score;
	int Nsleep_score;
};

class Bad
{
	public:
	Bad();//default constructor
	void S();//
	void game_weekday();//
	void dark_mind();//
	void unhealthy_info();//
	void UNB();//useless_net_browse
	void MM();//Morning mobile: play mobile when get up.
	void CM();//Class mobile: play mobile on Class.
	void GV();//Game Video: watch game video during weekday
	
	private:
	int S_score,  gamewkd_score, dark_mind_score,\
	unhealthy_info_score, UNB_score, MM_score,\
	CM_score, GV_score;
};

class Write
{
	public:
	void date();
	void summary();
	void table_head();
	void note();
};

class Data
{
	public:
	void read();
};
