#include <memory>
#include <iostream>
#include "Aircraft.h"

#include "UI.h"

int main()
{
	Helicopter h{ 1,"a","a",4,"private" };
	std::cout << h.toString() << '\n';
	Aircraft& a = h;
	std::unique_ptr<Aircraft> p = std::make_unique<Helicopter>(h);
	//std::cout << p->toString();
	
	Repository repo;
	
	repo.add(p);

	std::vector<std::unique_ptr<Aircraft>>& v = repo.getAircraftsActivity("a");
	for (auto& i : v)
	{
		std::cout << "Yes\n";
		std::cout << i->toString()<<'\n';
	}
		//Service srv{ repo };

//	srv.addHelicopter(1, "a", "a", 4, "private");
}
