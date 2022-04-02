#pragma once
#include "hp.h"
#include "statblock.h"
class Rogue : public hp, public StatBlock
{
private:
    /* data */
public: 
    static const hpType HPGROWTH = (hpType)19u;
    static const stattype BASESTR = (stattype)4u;
    static const stattype BASEINT = (stattype)1u;
    Rogue() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR,BASEINT){}
    ~Rogue(){};
    
};
 
