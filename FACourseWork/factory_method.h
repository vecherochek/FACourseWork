#pragma once
#include "class_survey.h"

class Creator
{
public:
	virtual ~Creator() {};
	virtual Survey* FactoryMethod(unsigned int _id) const = 0;
	Survey* generate(unsigned int _id) const
	{
		return this->FactoryMethod(_id);
	}
};

class GenerateSurvey : public Creator
{
public:
	Survey* FactoryMethod(unsigned int _id) const override
	{
		MySurvey* inter = new MySurvey();
		inter->generate_survey(_id);
		return inter;
	}
};
