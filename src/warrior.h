#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Warrior : public hp, public StatBlock, public LevelSystem
{
private:
    void LevelUp() override{
         setMaxHP(HPGROWTH + getMaxHP());
         increaseStats(STRGROWTH, INTGROWTH);
    }
public: 
    static const hpType HPGROWTH = (hpType)9u;
    static const stattype STRGROWTH = (stattype)2u;
    static const stattype INTGROWTH = (stattype)1u;

    static const hpType BASEHP  = (hpType)18u;
    static const stattype BASESTR = (stattype)4u;
    static const stattype BASEINT = (stattype)1u;
    Warrior() : hp(BASEHP, BASEHP), StatBlock(BASESTR,BASEINT){}
    ~Warrior(){};
};
 
