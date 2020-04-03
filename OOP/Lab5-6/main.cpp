#include <crtdbg.h>

#include "tests.h"
#include "CommandUserInterface.h"
#include <functional>

void a()
{
	std::cout << "a";
}
void b()
{
	std::cout << "b";
}

bool compName(const TrenchCoat& t1, const TrenchCoat& t2)
{
	return t1.getName() < t2.getName();
}

bool compPrice(const TrenchCoat& t1, const TrenchCoat& t2)
{
	return t1.getPrice() < t2.getPrice();
}

void print(bool (*ordine)(const TrenchCoat& t1, const TrenchCoat& t2))
{
	TrenchCoat t{ "1","ab","b", 3 };

	TrenchCoat t2{ "2","aa","bc", 2};
	
	std::cout << ordine(t, t2);
}



class A
{
public:
	void f1(bool ordine(const TrenchCoat&, const TrenchCoat&))
	{
		TrenchCoat t{ "1","ab","b", 3 };

		TrenchCoat t2{ "2","aa","bc", 2 };

		std::cout << ordine(t, t2);
	}



};

int main()
{
	{
		//testAll();
		CoatRepository coatRepository;
		CoatService coatService{ coatRepository };
		CommandUserInterface commandUserInterface{ coatService };
		//commandUserInterface.startProgram();
	}
	_CrtDumpMemoryLeaks();
	
	A a;
	a.f1(compName);
	std::cout << "\n";
	a.f1(compPrice);
	

	return 0;
}