#include <iostream>
#include "factory_method.h"
#include "decorator.h"
#include "main.h"
#include <istream>
#include <ctime>

void Client_Code(Creator* _creator) 
{
	int a, b;
	while (true)
	{
		std::cout << "Обработка данных с использованием: " << std::endl
			<< "1. std::map" << std::endl
			<< "2. собственный односвязные список" << std::endl;
		std::cin >> a;
		if (!std::cin)
		{
			std::cout << error_massage << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (a < 1 || a > 2)
		{
			std::cout << error_massage << std::endl;
			continue;
		}

		std::cout << std::endl << "Введите количество опросов: ";
		std::cin >> b;
		if (!std::cin)
		{
			std::cout << error_massage << std::endl;			
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (b < 0)
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		break;
	}
	if (a == 1)
	{
		Map_Decorator<MySurvey*> _map;
		for (int i = 1; i <= b; i++)
			_map.insert(dynamic_cast<MySurvey*>(_creator->generate(i)));
		MENU(_map, b);
	}
	else
	{
		ForwardList_Decorator<MySurvey*> _forwardlist;
		for (int i = 1; i <= b; i++)
			_forwardlist.insert(dynamic_cast<MySurvey*>(_creator->generate(i)));
		MENU(_forwardlist, b);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	Creator* creator = new GenerateSurvey();
	Client_Code(creator);

	delete creator;
}
