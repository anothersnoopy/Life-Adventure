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
	void review();// review what you learn this day
	void TheFour();//Read <The Four>
	void Nsleep();// Noon sleep for 20-30min between 12:30-13:50
	void PureThinking();//pure thinking
	void WhiteHouse();
	void readgood();
	void paperDiary();// Did you record your life on paper yesterday?
	void baptism();
	void fruit();//eat fruit is a very good habit.
	void sacredsight();//keep my sight sacred
	void vegetarian();

	private:
	int word_score;
	int out_score;
	int cnpaper_score;
	int enpaper_score;
	int sleep_score;
	int sport_score;
	int OTG_score;
	int PP_score;
	int review_score;
	int TheFour_score;
	int Nsleep_score;
	int PT_score;
	int WH_score;
	int RG_score;
	int PD_score;
	int baptism_score;
	int fruit_score;
	int ss_score;//sacred sight
	int veg_score;
};

class Bad
{
	public:
	Bad();//default constructor
	void S();//
	void game_weekday();//
	void unhealthy_info();//
	void UNB();//useless_net_browse
	void ME();//Morning Electronic : play any kind of electronic product when get up.
	void CM();//Class Mobile: play mobile in classroom. \
				You should never play mobile in classroom !
	void GV();//Game Video: watch game video during weekday
	void DM();//Dorm Meal:Eat food at dormitory is a bad habit
	void daze();//daze is a very bad habit. It wastes your time. It will kill you.
	
	private:
	int S_score,  gamewkd_score,\
	unhealthy_info_score, UNB_score, ME_score,\
	CM_score, GV_score, DM_score, daze_score;
};


class Plan
{
	public:
	void make();
	int check();
	
}; 

class Write
{
	public:
	void date();
	void summary();
	void table_head();
	void note();
	void excel();//write excel readable data
};

class Data
{
	public:
	void read();
	void write();
};

class Message
{
	public:
	Message();
	std::string msg[100];
};
