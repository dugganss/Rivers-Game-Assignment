#include "Game.h"
#include <istream>
#include <ostream>
#include <string>

//Be sure to refer to in and out - NOT cin and cout in this code. Tests will fail otherwise
bool Game::playRound(std::ostream& out, std::istream& in) {

	std::string river1 = r.getRandomRiver();
	std::string river2 = r.getRandomRiver();
	out << river1 << "\n" << river2 << "\n";

	std::string userInput;
	in >> userInput;

	bool isSame = r.sameContinent(river1, river2);

	if (userInput == "s" && isSame) {
		out << "correct" << "\n";
		score++;
		total++;
		
	}
	else if (userInput == "d" && isSame == false) {
		out << "correct" << "\n";
		score++;
		total++;
	}
	else if (userInput == "q") {
		return false;
	}
	else {
		out << "incorrect" << "\n";
		total++;
	}

	out << river1 << "'s continent is " << r.getContinent(river1) << "\n";
	out << river2 << "'s continent is " << r.getContinent(river2);
	
	out << "\n" << score << "\n" << total;
	
	return true;
}