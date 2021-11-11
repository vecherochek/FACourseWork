#pragma once

#include <vector>
#include <map>
#include <iostream>

std::string id				= "ID опроса: ";
std::string sex				= "Пол: ";
std::string age				= "Возраст: ";
std::string country			= "Страна: ";
std::string work			= "Работаете?: ";
std::string fcolor			= "Любимый цвет: ";
std::string fplanguage		= "Любимые язык программирования: ";
std::string fdpattern		= "Любимые паттерны проектирования: ";
std::string genre_of_films	= "Любимый жанр фильмов: ";
std::string food_delivery	= "Пользуетесь доставкой еды?: ";
std::string mobile_operator = "Ваш мобильный оператор: ";
std::string ninja_turtles	= "С какой черепашкой-ниндзя Вы себя ассоциируете?: ";
std::string fmusketeer		= "Ваш любимый мушкетер: ";
std::string spiderman		= "В исполнениия кого Вам больше всего нравится Человек-Паук?: ";
std::string zodiac_sign		= "Ваш знак зодиака: ";
std::string domestic_crocodiles = "Сколько у Вас домашних крокодилов?: ";
std::string harmonica		= "Играете на губной гармошке?: ";
std::string fchar			= "Ваш любимый символ: ";
std::string fmovie			= "Почему Вы любите Ваш любимый фильм?: ";
std::string chicken_or_egg	= "Курица или яйцо появилось раньше?: ";

std::string error_massage	= "Неправильный ввод=((. Попробуйте снова";
std::string age_warning		= "Введите одно число от 1 до 100.";
std::string domestic_crocodiles_warning = "Введите неорицательное число меньше 65535.";

std::vector<char> _sex = { 'м','ж' };
std::vector<std::string> _country = { "Россия", "Норвегия", "Америка", "Испания", 
									  "Средиземье", "Оз", "Готэм", "другое" };
std::vector<bool> _work = { true, false };
std::vector<std::string> _fcolor = { "красный", "оранжевый", "желтый", "зеленый", 
									 "голубой", "синий", "фиолетовый" };
std::vector<std::string> _fplanguage = { "Алгоритмический", "PHP", "МТ", "Prolog",
										 "Matlab", "другое" };
std::vector<std::string> _fdpattern = { "Порождающие", " Структурные", "Поведенческие" };
std::vector<std::string> _genre_of_films = { "Триллер", "Комедия", "Драма", "Боевик",
											 "Вестерн", "Документальный", "Фэнтази"," другое" };
std::vector<bool> _food_delivery = { true, false };
std::vector<std::string> _mobile_operator = { "МТС","Билайн","Теле2","другое" };
std::vector<std::string> _ninja_turtles = { "Леонардо", "Донателло", "Микеланджело", "Рафаэль" };
std::vector<std::string> _fmusketeer = { "Атос", "Арамис", "Портос", "Д'Артаньян" };
std::vector<std::string> _spiderman = { "Эндрю Гарфилд", "Тоби Магуайр", "Том Холланд" };
std::vector<std::string> _zodiac_sign = { "Овен", "Телец", "Близнецы", "Рак", "Лев"
										  "Дева", "Весы", "Скорпион", "Стрелец",
										  "Козерог", "Водолей", "Рыбы" };
std::vector<bool> _harmonica = { true, false };
std::vector<std::string> _fmovie = { "Потому что он классный", "Потому что он очень классный",
									 "Потому что потому все кончается на у" };
std::vector<std::string> _chicken_or_egg = { "курица", "яйцо" };

enum class Something {
	country,
	ninja_turtles,
	fmusketeer,
	spiderman,
	chicken_or_egg
};
const std::map<std::string, Something> convert_str_to_enum{ {country, Something::country},
															{ninja_turtles, Something::ninja_turtles},
															{fmusketeer, Something::fmusketeer},
															{spiderman, Something::spiderman},
															{chicken_or_egg, Something::chicken_or_egg}
};