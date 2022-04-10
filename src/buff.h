#pragma once
#include <cstdint>
#include "types.h"
#include <string>
class Buff
{
private:
public:
    uint16_t duration;
    stattype strength;
    stattype intellect;
    stattype agility;
    stattype armor;
    stattype elementresistance;
    bool isDebuff; 
    std::string Name; 

    Buff(std::string name = "unnamed", uint16_t dur = 2u, stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0u, stattype ele =0u, bool isde = false) :
         Name(name), strength(s), intellect(i), agility(a), armor(arm), elementresistance(ele), isDebuff(isde){}
    ~Buff(){};
};

