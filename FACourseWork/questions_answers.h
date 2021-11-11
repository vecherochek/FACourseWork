#pragma once

#include <vector>
#include <map>
#include <iostream>

std::string id				= "ID ������: ";
std::string sex				= "���: ";
std::string age				= "�������: ";
std::string country			= "������: ";
std::string work			= "���������?: ";
std::string fcolor			= "������� ����: ";
std::string fplanguage		= "������� ���� ����������������: ";
std::string fdpattern		= "������� �������� ��������������: ";
std::string genre_of_films	= "������� ���� �������: ";
std::string food_delivery	= "����������� ��������� ���?: ";
std::string mobile_operator = "��� ��������� ��������: ";
std::string ninja_turtles	= "� ����� ����������-������ �� ���� ������������?: ";
std::string fmusketeer		= "��� ������� ��������: ";
std::string spiderman		= "� ����������� ���� ��� ������ ����� �������� �������-����?: ";
std::string zodiac_sign		= "��� ���� �������: ";
std::string domestic_crocodiles = "������� � ��� �������� ����������?: ";
std::string harmonica		= "������� �� ������ ��������?: ";
std::string fchar			= "��� ������� ������: ";
std::string fmovie			= "������ �� ������ ��� ������� �����?: ";
std::string chicken_or_egg	= "������ ��� ���� ��������� ������?: ";

std::string error_massage	= "������������ ����=((. ���������� �����";
std::string age_warning		= "������� ���� ����� �� 1 �� 100.";
std::string domestic_crocodiles_warning = "������� �������������� ����� ������ 65535.";

std::vector<char> _sex = { '�','�' };
std::vector<std::string> _country = { "������", "��������", "�������", "�������", 
									  "����������", "��", "�����", "������" };
std::vector<bool> _work = { true, false };
std::vector<std::string> _fcolor = { "�������", "���������", "������", "�������", 
									 "�������", "�����", "����������" };
std::vector<std::string> _fplanguage = { "���������������", "PHP", "��", "Prolog",
										 "Matlab", "������" };
std::vector<std::string> _fdpattern = { "�����������", " �����������", "�������������" };
std::vector<std::string> _genre_of_films = { "�������", "�������", "�����", "������",
											 "�������", "��������������", "�������"," ������" };
std::vector<bool> _food_delivery = { true, false };
std::vector<std::string> _mobile_operator = { "���","������","����2","������" };
std::vector<std::string> _ninja_turtles = { "��������", "���������", "������������", "�������" };
std::vector<std::string> _fmusketeer = { "����", "������", "������", "�'��������" };
std::vector<std::string> _spiderman = { "����� �������", "���� �������", "��� �������" };
std::vector<std::string> _zodiac_sign = { "����", "�����", "��������", "���", "���"
										  "����", "����", "��������", "�������",
										  "�������", "�������", "����" };
std::vector<bool> _harmonica = { true, false };
std::vector<std::string> _fmovie = { "������ ��� �� ��������", "������ ��� �� ����� ��������",
									 "������ ��� ������ ��� ��������� �� �" };
std::vector<std::string> _chicken_or_egg = { "������", "����" };

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