#pragma once
#include "Rivers.h"
#include <ostream>
#include <istream>
//#define ASSIGNMENT_2				//uncomment to switch to assignment 2
//#define RUN_PAUSE_TEST  			//uncomment to run pause test (for assignment 2 only)


class Game {
	Rivers r;
	//further variables...
	int score = 0;
	int total = 0;

public:
	Game(Rivers& rivers) : r(rivers) { }
	int getScore() { return score; }
	int getTotal() { return total; }
	//reset score and total to 0
	void reset() {
		score = 0;
		total = 0;
	}

	//this method should implement one round of the game only, 
	//it should return true if the player wishes to continue ('s' or 'd') and false otherwise ('q')
	bool playRound(std::ostream& out, std::istream& in);
	
	//No need to implement this until assignment 2 
	std::vector<std::string> getFastest() { return std::vector<std::string>(); }
};