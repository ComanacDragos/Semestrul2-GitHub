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
		BeverageMachine m;
		m.prepare("Tea", 0);
		m.prepare("Coffee", 0);


		m.prepare("Tea", 1);
		m.prepare("Coffee", 1);

		m.prepare("Tea", 2);
		m.prepare("Coffee", 2);

	}
	_CrtDumpMemoryLeaks();
	return 0;
}