#pragma once

#include <vector>
#include <map>
#include <iostream>

const std::string id					= "ID ������: ";
const std::string sex					= "���: ";
const std::string age					= "�������: ";
const std::string country				= "������: ";
const std::string work					= "���������?: ";
const std::string fcolor				= "������� ����: ";
const std::string fplanguage			= "������� ���� ����������������: ";
const std::string fdpattern				= "������� �������� ��������������: ";
const std::string genre_of_films		= "������� ���� �������: ";
const std::string food_delivery			= "����������� ��������� ���?: ";
const std::string mobile_operator		= "��� ��������� ��������: ";
const std::string ninja_turtles			= "� ����� ����������-������ �� ���� ������������?: ";
const std::string fmusketeer			= "��� ������� ��������: ";
const std::string spiderman				= "� ����������� ���� ��� ������ ����� �������� �������-����?: ";
const std::string zodiac_sign			= "��� ���� �������: ";
const std::string domestic_crocodiles	= "������� � ��� �������� ����������?: ";
const std::string harmonica				= "������� �� ������ ��������?: ";
const std::string fchar					= "��� ������� ������: ";
const std::string fmovie				= "������ �� ������ ��� ������� �����?: ";
const std::string chicken_or_egg		= "������ ��� ���� ��������� ������?: ";
const std::string error_massage			= "������������ ����=((. ���������� �����";
const std::string age_warning			= "������� ���� ����� �� 1 �� 100.";
const std::string domestic_crocodiles_warning = "������� �������������� ����� ������ 65535.";

std::vector<char> _sex					= { '�','�' };
std::vector<std::string> _country		= { "������", "��������", "�������", "�������", 
											"����������", "��", "�����", "������" };
std::vector<bool> _work					= { true, false };
std::vector<std::string> _fcolor		= { "�������", "���������", "������", "�������", 
											"�������", "�����", "����������" };
std::vector<std::string> _fplanguage	= { "���������������", "PHP", "��", "Prolog",
										 "Matlab", "������" };
std::vector<std::string> _fdpattern		= { "�����������", " �����������", "�������������" };
std::vector<std::string> _genre_of_films = { "�������", "�������", "�����", "������",
											 "�������", "��������������", "�������"," ������" };
std::vector<bool> _food_delivery		= { true, false };
std::vector<std::string> _mobile_operator = { "���","������","����2","������" };
std::vector<std::string> _ninja_turtles = { "��������", "���������", "������������", "�������" };
std::vector<std::string> _fmusketeer	= { "����", "������", "������", "�'��������" };
std::vector<std::string> _spiderman		= { "����� �������", "���� �������", "��� �������" };
std::vector<std::string> _zodiac_sign	= { "����", "�����", "��������", "���", "���"
										  "����", "����", "��������", "�������",
										  "�������", "�������", "����" };
std::vector<bool> _harmonica			= { true, false };
std::vector<std::string> _fmovie		= { "������ ��� �� ��������", "������ ��� �� ����� ��������",
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