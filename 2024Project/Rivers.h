#pragma once
#include <string>
#include <vector>


class Rivers
{
	//Insert data structure(s) here...
	std::vector<std::string> africaRivers;			// vectors used because the data is static
	std::vector<std::string> europeRivers;			// therefore linked list would be inappropriate
	std::vector<std::string> asiaRivers;				// stack and queue would not be appropriate either
	std::vector<std::string> sAmericaRivers;			// as data is accessed randomly
	std::vector<std::string> allRivers;

	
	
public:
	//Time complexity: O(n) (linear) 
	Rivers(const std::vector<std::string>& filenames);
	//Time complexity: O(1) (constant)
	std::string getRandomRiver();
	//Time complexity: O(n) (linear)
	bool sameContinent(std::string river1, std::string river2);
	//Time complexity: O(n) (linear)
	std::string getContinent(std::string river);

	//No need to implement this until assignment 2
	void setMode(int mode) {}
};