#pragma once

#include "questions_answers.h"
#include <iostream>
#include <vector>
#include <limits>

class Survey
{
public:
	virtual			~Survey() {}
	virtual void	generate_survey(unsigned int _id) = 0;
};

class MySurvey : public Survey {
public:
	unsigned int				ID = 0;
	char						Sex = 0;
	unsigned short				Age = 0;
	std::string					Country = "";
	bool						Work = 0;
	std::string					FColor = "";
	std::vector<std::string>	FPLanguage = {  };
	std::vector<std::string>	FDPattern = {  };
	std::string					GenreOfFilms = "";
	bool						FoodDelivery = "";
	std::string					MobileOperator = "";
	std::string					NinjaTurtles = "";
	std::string					FMusketeer = "";
	std::string					Spiderman = "";
	std::string					ZodiacSign = "";
	unsigned short				DomesticCrocodiles = 0;
	bool						Harmonica = 0;
	char						FChar = 0;
	std::string					FMovie = "";
	std::string					ÑhickenOrEgg = "";

	void	print_survey();
	void	enter_survey(unsigned int b);
	void	generate_survey(unsigned int _id) override;

	MySurvey(){};
	~MySurvey() {};

private:
	template <typename T>
	T							enter(std::string question, std::vector<T> answer);
	std::vector<std::string>	enter_vector(std::string question, std::vector<std::string> answer);
	std::string					enter_text(std::string question, std::vector<std::string> answer);
	unsigned short				enter_number(std::string question, std::string warning,
		unsigned short a, unsigned short b);
	template <typename T>
	T							generate(std::vector<T> answer);
	int							generate_number(int min, int max);
	std::vector<std::string>	generate_vector(std::vector<std::string> answer);
};

void MySurvey::generate_survey(unsigned int _id)
{
	ID = _id;
	Sex = generate(_sex);
	Age = generate_number(0, 101);
	Country = generate(_country);
	Work = generate(_work);
	FColor = generate(_fcolor);
	FPLanguage = generate_vector(_fplanguage);
	FDPattern = generate_vector(_fdpattern);
	GenreOfFilms = generate(_genre_of_films);
	FoodDelivery = generate( _food_delivery);
	MobileOperator = generate(_mobile_operator);
	NinjaTurtles = generate(_ninja_turtles);
	FMusketeer = generate(_fmusketeer);
	Spiderman = generate(_spiderman);
	ZodiacSign = generate(_zodiac_sign);
	DomesticCrocodiles = generate_number(0, USHRT_MAX);
	Harmonica = generate(_harmonica);
	FChar = generate_number(-128, 128);
	FMovie = generate(_fmovie);
	ÑhickenOrEgg = generate(_chicken_or_egg);
}

template <typename T>
T MySurvey::generate(std::vector<T> answer) 
{
	return answer[generate_number(0, answer.size() - 1)];
}

int MySurvey::generate_number(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

std::vector<std::string> MySurvey::generate_vector(std::vector<std::string> answer) 
{
	std::vector<std::string> res;
	std::vector<std::string> tmp = answer;
	int number;
	for (int i = 1; i <= generate_number(1, answer.size()); i++)
	{
		number = generate_number(0, tmp.size() - 1);
		res.push_back(tmp[number]);

		auto iter = std::find(tmp.begin(), tmp.end(), tmp[number]);
		if (iter != tmp.end()) {
			using std::swap;
			swap(*iter, tmp.back());
			tmp.pop_back();
		}
	}
	return res;
}

void MySurvey:: print_survey()
{
	std::cout << std::boolalpha
		<< id				<< ID				<< std::endl
		<< sex				<< Sex				<< std::endl
		<< age				<< Age				<< std::endl
		<< country			<< Country			<< std::endl
		<< work				<< Work				<< std::endl
		<< fcolor			<< FColor			<< std::endl
		<< fplanguage;
	for (unsigned int i = 0; i < FPLanguage.size(); i++)
		std::cout			<< FPLanguage[i] << ", ";
	std::cout << std::endl << fdpattern;
	for (unsigned int i = 0; i < FDPattern.size(); i++)
		std::cout			<< FDPattern[i] << ", ";
	std::cout << std::endl	
		<< genre_of_films	<< GenreOfFilms		<< std::endl
		<< food_delivery	<< FoodDelivery		<< std::endl
		<< mobile_operator	<< MobileOperator	<< std::endl
		<< ninja_turtles	<< NinjaTurtles		<< std::endl
		<< fmusketeer		<< FMusketeer		<< std::endl
		<< spiderman		<< Spiderman		<< std::endl
		<< zodiac_sign		<< ZodiacSign		<< std::endl
		<< domestic_crocodiles << DomesticCrocodiles << std::endl
		<< harmonica		<< Harmonica		<< std::endl
		<< fchar			<< FChar			<< std::endl
		<< fmovie			<< FMovie			<< std::endl
		<< chicken_or_egg	<< ÑhickenOrEgg		<< std::endl;
}

void MySurvey::enter_survey(unsigned int b)
{
	ID = b;
	Sex = enter(sex, _sex);
	Age = enter_number(age, age_warning, 0, 101);
	Country = enter(country, _country);
	Work = enter(work, _work);
	FColor = enter(fcolor, _fcolor);
	FPLanguage = enter_vector(fplanguage, _fplanguage);
	FDPattern = enter_vector(fdpattern, _fdpattern);
	GenreOfFilms = enter(genre_of_films, _genre_of_films);
	FoodDelivery = enter(food_delivery, _food_delivery);
	MobileOperator = enter(mobile_operator, _mobile_operator);
	NinjaTurtles = enter(ninja_turtles, _ninja_turtles);
	FMusketeer = enter(fmusketeer, _fmusketeer);
	Spiderman = enter(spiderman, _spiderman);
	ZodiacSign = enter(zodiac_sign, _zodiac_sign);
	DomesticCrocodiles = enter_number (domestic_crocodiles, 
					domestic_crocodiles_warning, 0, USHRT_MAX);
	Harmonica = enter(harmonica, _harmonica);
	std::cout << fchar << std::endl;
	FChar = std::cin.get();
	FMovie = enter(fmovie, _fmovie);
	ÑhickenOrEgg = enter(chicken_or_egg, _chicken_or_egg);
}

template <typename T>
T MySurvey::enter(std::string question, std::vector<T> answer)
{
	int k;
	while (true) 
	{		
		std::cout << question << std::endl;
		std::cout << std::boolalpha;
		for (unsigned int i = 0; i < answer.size(); i++)
			std::cout << i + 1 << ". " << answer[i] << std::endl;
		std::cin >> k;
		if ((k > (int)answer.size()) || (k < 0)) 
		{
			std::cout << error_massage << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		return answer[k - 1];
	}
}

std::vector<std::string> MySurvey::enter_vector(std::string question, std::vector<std::string> answer)
{
	int k, m;
	std::string l;
	std::vector<std::string> vect;
	while (true)
	{
		std::cout << question << std::endl;
		for (unsigned int i = 0; i < answer.size(); i++)
			std::cout << i + 1 << ". " << answer[i] << std::endl;

		std::cout << std::endl << "Ââåäèòå êîëè÷åñòâî âàðèàíòîâ: " << std::endl;
		std::cin >> k;
		if ((k > (int)answer.size()) || (k < 0))
		{
			std::cout << error_massage << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cout << "Ââîäèòå íîìåðà îòâåòîâ ÷åðåç enter: " << std::endl;
		for (int i = 0; i < k; i++) 
		{
			std::cin >> m;
			vect.push_back(answer[m - 1]);
		}
		return vect;
	}
}

std::string MySurvey::enter_text(std::string question, std::vector<std::string> answer)
{
	std::string k;
	std::cout << question << std::endl;
	std::cin >> k;
	answer.push_back(k);
	return k;	
}

unsigned short MySurvey::enter_number(std::string question, std::string warning,
										   unsigned short a, unsigned short b) 
{
	unsigned short k;
	while (true)
	{
		std::cout << question << std::endl;
		std::cin >> k;
		if ((k < a) || (k > b))
		{
			std::cout << error_massage << warning << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		return k;
	}
}
