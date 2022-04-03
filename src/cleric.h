#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"
class Cleric : public hp, public StatBlock, public LevelSystem
{
private:
    void LeveUp() override{
         setMaxHP(HPGROWTH + getMaxHP());
    }
public: 
    static const hpType HPGROWTH = (hpType)14u;
    static const stattype BASESTR = (stattype)2u;
    static const stattype BASEINT = (stattype)4u;
    Cleric() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR,BASEINT){}
    ~Cleric(){};

};
 
