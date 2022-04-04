#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Rogue : public hp, public StatBlock, public LevelSystem
{
private:
    void LevelUp() override{
         setMaxHP(HPGROWTH + getMaxHP());
         increaseStats(STRGROWTH, INTGROWTH);
    }
public: 
    static const hpType HPGROWTH = (hpType)6u;
    static const stattype STRGROWTH = (stattype)2u;
    static const stattype INTGROWTH = (stattype)1u;

    static const hpType BASEHP  = (hpType)12u;
    static const stattype BASESTR = (stattype)3u;
    static const stattype BASEINT = (stattype)2u;
    Rogue() : hp(BASEHP, BASEHP), StatBlock(BASESTR,BASEINT){}
    ~Rogue(){};
    
};
 
