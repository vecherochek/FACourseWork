#pragma once

#include "forward_list.h"
#include "class_survey.h"
#include <iostream>
#include <vector>
#include <map>

#define NUMBER_OF_SURVEY 5


template <typename T>
class Decorator {
public:
    virtual ~Decorator() {}
    virtual void insert(T value) = 0;
    virtual int remove(unsigned int value) = 0;
    virtual void find_by_id(unsigned int id) = 0;
    virtual void find_by_something(std::string something, std::string somestring) = 0;
    virtual void statistic_by_something(std::string something) = 0;
};

template <typename T>
class Map_Decorator : public Decorator<T> {
protected:
    std::map<unsigned int, T> _map;
public:
    Map_Decorator() {};
    ~Map_Decorator() {};
    
    void insert(T value) override
    {
        _map.insert({ value->ID, value });
    }
    
    int remove(unsigned int value) override
    {
        if (_map.empty()) return 0;

        auto iter = _map.begin(); 
        while (iter != _map.end())
        {
            if (value == (iter->second)->ID)
            {
                _map.erase(iter);
                return 1;
            }
            iter++;
        }
        return -1;
    }
    void find_by_id(unsigned int id) override 
    {
        auto iter = _map.begin();
        while (iter != _map.end())
        {
            if (id == (iter->second)->ID) 
            {
                (iter->second)->print_survey();
                break;
            }               
            iter++;
        }
        if (iter == _map.end()) std::cout << std::endl << "Нет опроса с заданным параметром=((" << std::endl;
    }
    void find_by_something(std::string something, std::string somestring) override
    {
        int number = 0;
        auto iter = _map.begin();
        auto str = convert_str_to_enum.at(something);
        switch (str)
        {
        case Something::country:
            while (iter != _map.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (iter->second)->Country)
                {
                    (iter->second)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::ninja_turtles:
            while (iter != _map.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (iter->second)->NinjaTurtles)
                {
                    (iter->second)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::fmusketeer:
            while (iter != _map.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (iter->second)->FMusketeer)
                {
                    (iter->second)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::chicken_or_egg:
            while (iter != _map.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (iter->second)->СhickenOrEgg)
                {
                    (iter->second)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::spiderman:
            while (iter != _map.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (iter->second)->Spiderman)
                {
                    (iter->second)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        }
        if (number == 0) std::cout << std::endl <<"Нет опроса с заданным параметром=((" << std::endl;
    }
    void statistic_by_something(std::string something) override
    {
        std::map<std::string, int> stat;
        auto str = convert_str_to_enum.at(something);
        auto it = _map.begin();
        switch (str)
        {
            case Something::country:
                for (it; it != _map.end(); it++)
                    stat[it->second->Country]++;
            break;
            case Something::ninja_turtles:
                for (it; it != _map.end(); it++)
                    stat[it->second->NinjaTurtles]++;
                break;
            case Something::fmusketeer:
                for (it; it != _map.end(); it++)
                    stat[it->second->FMusketeer]++;
                break;
            case Something::chicken_or_egg:
                for (it; it != _map.end(); it++)
                    stat[it->second->СhickenOrEgg]++;
                break;
            case Something::spiderman:
                for (it; it != _map.end(); it++)
                    stat[it->second->Spiderman]++;
                break;
        }

        std::cout << something << std::endl;
        auto iter = stat.begin();
        for (iter; iter != stat.end(); ++iter)
        {          
            std::cout << iter->first << std::endl 
                << " абсолютная = " << iter->second
                << "\tотносительная = " << (double)iter->second / (double)_map.size() 
                << std::endl;
        }
    }
};

template <typename T>

class ForwardList_Decorator : public Decorator<T> {
protected:
    ForwardList<T> _forwardlist;
public:
    ForwardList_Decorator() {};
    ~ForwardList_Decorator() {};

    void insert(T value) override
    {
        _forwardlist.insert(value);
    }

    int remove(unsigned int value) override
    {
        if (_forwardlist.empty()) return 0;

        auto iter = _forwardlist.begin();
        while (iter != _forwardlist.end())
        {
            if (value == (*iter)->ID)
            {
                _forwardlist.remove(*iter);
                return 1;
            }
            iter++;
        }
        return -1;
    }
    void find_by_id(unsigned int id) override
    {
        auto iter = _forwardlist.begin();
        while (iter != _forwardlist.end())
        {
            if (id == (*iter)->ID)
            {
                (*iter)->print_survey();
                break;
            }
            iter++;
        }
        if (iter == _forwardlist.end()) std::cout << std::endl << "Нет опроса с заданным параметром=((" << std::endl;
    }
    void find_by_something(std::string something, std::string somestring) override
    {
        int number = 0;
        auto iter = _forwardlist.begin();
        auto str = convert_str_to_enum.at(something);
        switch (str)
        {
        case Something::country:
            while (iter != _forwardlist.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (*iter)->Country)
                {
                    (*iter)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::ninja_turtles:
            while (iter != _forwardlist.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (*iter)->NinjaTurtles)
                {
                    (*iter)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::fmusketeer:
            while (iter != _forwardlist.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (*iter)->FMusketeer)
                {
                    (*iter)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::chicken_or_egg:
            while (iter != _forwardlist.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (*iter)->СhickenOrEgg)
                {
                    (*iter)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        case Something::spiderman:
            while (iter != _forwardlist.end() && number != NUMBER_OF_SURVEY)
            {
                if (somestring == (*iter)->Spiderman)
                {
                    (*iter)->print_survey();
                    number++;
                }
                iter++;
            }
            break;
        }
        if (number == 0) std::cout << std::endl << "Нет опроса с заданным параметром=((" << std::endl;
    }
    void statistic_by_something(std::string something) override
    {
        std::map<std::string, int> stat;
        auto str = convert_str_to_enum.at(something);
        auto it = _forwardlist.begin();
        switch (str)
        {
        case Something::country:
            for (it; it != _forwardlist.end(); it++)
                stat[(*it)->Country]++;
            break;
        case Something::ninja_turtles:
            for (it; it != _forwardlist.end(); it++)
                stat[(*it)->NinjaTurtles]++;
            break;
        case Something::fmusketeer:
            for (it; it != _forwardlist.end(); it++)
                stat[(*it)->FMusketeer]++;
            break;
        case Something::chicken_or_egg:
            for (it; it != _forwardlist.end(); it++)
                stat[(*it)->СhickenOrEgg]++;
            break;
        case Something::spiderman:
            for (it; it != _forwardlist.end(); it++)
                stat[(*it)->Spiderman]++;
            break;
        }

        std::cout << something << std::endl;
        auto iter = stat.begin();
        for (iter; iter != stat.end(); ++iter)
        {
            std::cout << iter->first << std::endl
                << " абсолютная = " << iter->second
                << "\tотносительная = " << (double)iter->second / (double)_forwardlist.size()
                << std::endl;
        }
    }
};
