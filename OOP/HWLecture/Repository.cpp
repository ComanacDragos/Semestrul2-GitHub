#include "Repository.h"

void Repository::add(std::unique_ptr<Aircraft>& aircraft)
{
	this->aircrafts.push_back(std::move(aircraft));
}

std::vector<std::unique_ptr<Aircraft>>& Repository::getAircraftsActivity(const std::string activity)
{
	std::vector<std::unique_ptr<Aircraft>> aircrafts;
	for (int i = 0; i < this->aircrafts.size(); i++)
		if (this->aircrafts[i]->getActivity() == activity)
		{
			std::unique_ptr<Aircraft> aircraft = std::make_unique<Aircraft>(*(this->aircrafts[i]));
			aircrafts.push_back(std::move(aircraft));
		}

	return aircrafts;
}

std::vector<std::unique_ptr<Aircraft>>& Repository::getAircraftsAltitude(int altitude)
{
	std::vector<std::unique_ptr<Aircraft>> aircrafts;
	for (int i = 0; i < this->aircrafts.size(); i++)
		if (this->aircrafts[i]->getAltitude() == altitude)
		{
			std::unique_ptr<Aircraft> aircraft = std::make_unique<Aircraft>(*(this->aircrafts[i]));
			aircrafts.push_back(std::move(aircraft));
		}
	return aircrafts;
}
