#include "Rivers.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>


using namespace std;

Rivers::Rivers(const std::vector<std::string>& filenames) 
{
	ifstream africaIFS("Africa.txt");		// creates input file stream for txt file
	ifstream europeIFS("Europe.txt");
	ifstream asiaIFS("Asia.txt");
	ifstream sAmericaIFS("South America.txt");

	string line;							// variable referrring to each line

	while (getline(africaIFS, line)) {		// iterates until end line
		africaRivers.push_back(line);		// adds line to vector
	}
	while (getline(europeIFS, line)) {	
		europeRivers.push_back(line);		
	}
	while (getline(asiaIFS, line)) {	
		asiaRivers.push_back(line);		
	}
	while (getline(sAmericaIFS, line)) {	
		sAmericaRivers.push_back(line);		
	}
	
	allRivers.reserve(africaRivers.size() + europeRivers.size() + asiaRivers.size() + sAmericaRivers.size()); // reserves space in memory for combination of all arrays
	allRivers.insert(allRivers.end(), africaRivers.begin(), africaRivers.end());  // inserts array into allRivers, same for each following
	allRivers.insert(allRivers.end(), europeRivers.begin(), europeRivers.end());
	allRivers.insert(allRivers.end(), asiaRivers.begin(), asiaRivers.end());
	allRivers.insert(allRivers.end(), sAmericaRivers.begin(), sAmericaRivers.end());


	srand((unsigned)time(NULL)); // Creating random seed based on time
}

std::string Rivers::getRandomRiver() 
{
	int randomValue = rand() % allRivers.size(); // generates random value within range of array based on seed defined above
	return allRivers[randomValue];
}

bool Rivers::sameContinent(std::string r1, std::string r2)
{
	string r1Continent = getContinent(r1);	// gets r1 continent
	string r2Continent = getContinent(r2);	// gets r2 continent
	
	if (r1Continent == "" || r2Continent == "") {	//checks if invalid continent
		return false;
	}
	else if (r1Continent == r2Continent) {	// checks if continent the same
		return true;
	}
	return false;
}

std::string Rivers::getContinent(std::string river) 
{
	if (find(africaRivers.begin(), africaRivers.end(), river) != africaRivers.end()) {	// searches for river in africa array
		return "Africa";
	}
	else if (find(europeRivers.begin(), europeRivers.end(), river) != europeRivers.end()) {	// searches for river in europe array
		return "Europe";
	}
	else if (find(asiaRivers.begin(), asiaRivers.end(), river) != asiaRivers.end()) {	// searches for river in asia array
		return "Asia";
	}
	else if (find(sAmericaRivers.begin(), sAmericaRivers.end(), river) != sAmericaRivers.end()) {	// searches for river in sAmerica array
		return "South America";
	}
	else {	// invalid river
		return "";
	}
	
}