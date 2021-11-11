#pragma once

void print_vector(std::vector<std::string> some_vector)
{
	for (unsigned int i = 0; i < some_vector.size(); i++)
		std::cout << i + 1 << ". " << some_vector[i] << std::endl;
}
template <typename T>
void add_survey(Decorator<T>& container, int b)
{
	Creator* creator_inter = new GenerateSurvey();
	MySurvey* _survey = new MySurvey;
	int c;

	while (true)
	{
		std::cout << "������� ��������� �����?" << std::endl
			<< "1. ��" << std::endl
			<< "2. ���" << std::endl;
		std::cin >> c;
		if (c < 1 || c > 2)
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		break;
	}
	b++;
	if (c == 1) {
		container.insert(dynamic_cast<MySurvey*>(creator_inter->generate(b)));
	}
	else {
		_survey->enter_survey();
		container.insert(_survey);
	}
}
template <typename T>
void delete_survey(Decorator<T>& container)
{
	int c;
	while (true)
	{
		std::cout << "������� id ������ ��� ��� ��������: ";
		std::cin >> c;
		if (c < 1)
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		switch (container.remove(c))
		{
		case 0:
			std::cout << "�������� ����" << std::endl;
			break;
		case 1:
			std::cout << "����� ������" << std::endl;
			break;
		case -1:
			std::cout << "��� ������ � ����� id" << std::endl;
			break;
		}
		break;
	}
}
template <typename T>
void display_statistics(Decorator<T>& container)
{
	int c;
	while (true)
	{
		std::cout << "����� ����������? " << std::endl
			<< "1. �� �������" << std::endl
			<< "2. �� ����������-������" << std::endl
			<< "3. �� ����������" << std::endl
			<< "4. �� ��������-�����" << std::endl
			<< "5. ������ ��� ����?" << std::endl;
		std::cin >> c;
		if (c < 1 || c > 5)
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		break;
	}
	switch (c)
	{
	case 1:
		container.statistic_by_something(country);
		break;
	case 2:
		container.statistic_by_something(ninja_turtles);
		break;
	case 3:
		container.statistic_by_something(fmusketeer);
		break;
	case 4:
		container.statistic_by_something(spiderman);
		break;
	case 5:
		container.statistic_by_something(chicken_or_egg);
		break;
	}
}
template <typename T>
void find_find(Decorator<T>& container, std::string question, std::vector<std::string> answers)
{
	int d;
	while (true)
	{
		print_vector(answers);
		std::cin >> d;
		if (d < 1 || d > (int)answers.size())
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		break;
	}
	container.find_by_something(question, answers[d - 1]);
}
template <typename T>
void search_survey(Decorator<T>& container)
{
	int d, c;
	while (true)
	{
		std::cout << "����� �� ����� ��������? " << std::endl
			<< "1. ID" << std::endl
			<< "2. �� �������" << std::endl
			<< "3. �� ����������-������" << std::endl
			<< "4. �� ����������" << std::endl
			<< "5. �� ��������-�����" << std::endl;
		std::cin >> c;
		if (c < 1 || c > 5)
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		break;
	}
	switch (c)
	{
	case 1:
		while (true)
		{
			std::cout << "������� ID: " << std::endl;
			std::cin >> d;
			if (d < 1)
			{
				std::cout << error_massage << std::endl;
				continue;
			}
			break;
		}
		container.find_by_id(d);
		break;
	case 3:
		find_find(container, ninja_turtles, _ninja_turtles);
		break;
	case 4:
		find_find(container, fmusketeer, _fmusketeer);
		break;
	case 5:
		find_find(container, spiderman, _spiderman);
		break;
	case 2:
		find_find(container, country, _country);
		break;
	}
}
template <typename T>
int MENU(Decorator<T>& container, int b)
{	
	int a;
	while (true)
	{
		std::cout << std::endl << "����:" << std::endl
			<< "1. �������� �����" << std::endl
			<< "2. ������� �����" << std::endl
			<< "3. ������� ����������" << std::endl
			<< "4. ����� ������" << std::endl
			<< "0. �����" << std::endl;
		std::cin >> a;
		if (a < -1 || a > 4)
		{
			std::cout << error_massage << std::endl;
			continue;
		}
		switch (a)
		{
		case 1:
			add_survey(container, b);
			break;
		case 2:
			delete_survey(container);
			break;
		case 3:
			display_statistics(container);
			break;
		case 4:
			search_survey(container);
			break;
		case 0:
			return 0;
		}
	}
}