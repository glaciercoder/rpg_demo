#pragma once
#include "hp.h"
#include "statblock.h"
class Cleric : public hp, public StatBlock
{
private:
    /* data */
public: 
    static const hpType HPGROWTH = (hpType)14u;
    static const stattype BASESTR = (stattype)2u;
    static const stattype BASEINT = (stattype)4u;
    Cleric() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR,BASEINT){}
    ~Cleric(){};
};
 
