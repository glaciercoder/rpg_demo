#pragma once
#include "hp.h"
#include "statblock.h"
class Warrior : public hp, public StatBlock
{
private:
    /* data */
public: 
    static const hpType HPGROWTH = (hpType)19u;
    static const stattype BASESTR = (stattype)10u;
    static const stattype BASEINT = (stattype)1u;
    Warrior() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR,BASEINT){}
    ~Warrior(){};
};
 