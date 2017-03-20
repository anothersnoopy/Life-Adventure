class Good
{
	public:
	Good();
	void word();
	void outhome();
	void cn_paper();// read a paper writed in Chinese
	void en_paper();// read a paper writed in English
	int word_score;
	int out_score;
	int cnpaper_score;
	int enpaper_score;
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
