#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Wizard : public hp, public StatBlock, public LevelSystem
{
private:
    void LevelUp() override{
         setMaxHP(HPGROWTH + getMaxHP());
         increaseStats(STRGROWTH, INTGROWTH);
    }
public: 
    static const hpType HPGROWTH = (hpType)5u;
    static const stattype STRGROWTH = (stattype)1u;
    static const stattype INTGROWTH = (stattype)2u;

    static const hpType BASEHP  = (hpType)10u;
    static const stattype BASESTR = (stattype)1u;
    static const stattype BASEINT = (stattype)4u;
    
    Wizard() : hp(BASEHP, BASEHP), StatBlock(BASESTR,BASEINT){}
    ~Wizard(){}
};


