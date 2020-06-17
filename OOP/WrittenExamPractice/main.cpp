#include "Stack.h"
#include "Telephone.h"
#include "Expresie.h"
#include "TestAndSpecify.h"
#include "ToDo.h"
#include "Results.h"
#include <deque>
#include "CarList.h"
#include "Sales.h"
#include "Pepene.h"
#include "Adder.h"
#include "Catalog.h"
#include <crtdbg.h>
#include "RationalVector.h"
#include "Beverages.h"
#include "Action.h"
int main()
{
	{
		MenuBar bar;
		
		Action* exit = new ExitAction;
		Action* createText = new CreateAction;
		Action* createC = new CreateAction;
		MenuItem* textItem = new MenuItem{ "Text", createText };
		MenuItem* textC = new MenuItem{ "C++", createC };
		
		Menu* New = new Menu{ "New" };
		Menu* Exit = new Menu{ "Exit" , exit};

		New->add(textItem);
		New->add(textC);

		Menu* File = new Menu{ "File" };
		File->add(New);
		File->add(Exit);

		Menu* About = new Menu{ "About" };

		bar.add(File);
		bar.add(About);

		bar.print();

		File->clicked();
		New->clicked();
		textC->clicked();
		Exit->clicked();


	}
	_CrtDumpMemoryLeaks();
	return 0;
}