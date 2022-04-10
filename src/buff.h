#pragma once
#include <cstdint>
#include "types.h"
#include <string>
#include "corestats.h"


#include<iostream>
class Buff   
{
private:
public:
    CoreStats buffstats;
    uint16_t duration;
    bool isDebuff; 
    std::string Name; 

    Buff(std::string name = "unnamed", uint16_t dur = 2u, stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0u, stattype ele =0u, bool isde = false) :
         Name(name), duration(dur), isDebuff(isde), buffstats(s, i, a, arm, ele){}
    Buff(CoreStats cs, std::string name, uint16_t dur = 2u, bool isde = false) : Name(name), duration(dur), isDebuff(isde){buffstats = cs;} 
    ~Buff(){};
};

