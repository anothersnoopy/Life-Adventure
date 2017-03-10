#include<iostream>
#include"class.h"
using namespace std;

Good::Good()
{
	total_word_score = 0;
	show_word = 0;
}

void Good::word()
{
		total_word_score += 10;
		show_word = total_word_score;
}
