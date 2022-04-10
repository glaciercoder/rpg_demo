#pragma once
#include "types.h"
class CoreStats
{
private:
    /* data */
public:
    stattype strength = 1;
    stattype intellect = 1;
    stattype agility = 1;
    stattype armor = 0;
    stattype elementresistance = 0;
    
    CoreStats& operator+=(const CoreStats& rhs){
        this->strength          += rhs.strength;
        this->intellect         += rhs.intellect;
        this->agility           += rhs.agility;
        this->armor             += rhs.armor;
        this->elementresistance += rhs.elementresistance;
        return *this;
    }
    CoreStats& operator-=(const CoreStats& rhs){
        this->strength = (this->strength > rhs.strength) ? (this->strength - rhs.strength) : 0;
        this->intellect = (this->intellect > rhs.intellect) ? (this->intellect - rhs.intellect) : 0;
        this->agility = (this->agility > rhs.agility) ? (this->agility - rhs.agility) : 0;
        this->armor = (this->armor > rhs.armor) ? (this->armor - rhs.armor) : 0;
        this->elementresistance = (this->elementresistance > rhs.elementresistance) ? (this->elementresistance - rhs.elementresistance) : 0;
        return *this;
    }
    explicit CoreStats(stattype s, stattype i, stattype a = 0, stattype arm = 0u, stattype ele =0u): strength(s), intellect(i), agility(a), armor(arm), elementresistance(ele){};
    CoreStats() = default;
    ~CoreStats(){};
};

