#pragma once
#include "Aircraft.h"
#include <vector>
#include <memory>

class Repository
{
private:
	std::vector<std::unique_ptr<Aircraft>> aircrafts;

public:
	void add(std::unique_ptr<Aircraft>& aircraft);

	std::vector<std::unique_ptr<Aircraft>>& getAircraftsActivity(const std::string activity);

	std::vector<std::unique_ptr<Aircraft>>& getAircraftsAltitude(int altitude);

};

