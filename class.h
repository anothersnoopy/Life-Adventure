class Good
{
	public:
	Good();
	void word();
	void outhome();
	void cn_paper();// read a paper writed in Chinese
	void en_paper();// read a paper writed in English
	void sleep_early();
	void sport();//
	void OTG();// do One Thing Good
	void PP();// Phone Parents
	void NFN();// No Food at Night
	void sunny_mind();// keep a fresh, healthy, and sunny mind for whole day
	void review();// review what you learn this day
	int word_score;
	int out_score;
	int cnpaper_score;
	int enpaper_score;
	int sleep_e_score;
	int sport_score;
	int OTG_score, PP_score, NFN_score, sunny_mind_score, review_score;
};

class Bad
{
	public:
	Bad();//default constructor
	void S();//
	void game_weekday();//
	void dark_mind();//
	void unhealthy_info();//
	int S_score, sleep_l_score, gamewkd_score, dark_mind_score,\
	unhealthy_info_score;
};

class Write
{
	public:
	void date();
	void summary();
	void table_head();
};

class Data
{
	public:
	void read();
};
