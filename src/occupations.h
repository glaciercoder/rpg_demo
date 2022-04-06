#pragma once
#include "pointwell.h"
#include "statblock.h"
#include "playercharacter.h"
#include <string>

#define __PCCONSTRUCT__  PlayerCharacterDelegate(){ \
        HP->setMax(BASEHP); \
        HP->increaseCurrent(BASEHP); \
        increaseStats(BASESTR, BASEINT); \
}

#define __LEVELUP__   void LevelUp() override{\
         HP->setMax((welltype)(BASEHP/2.f+ HP->getMax()));\
         increaseStats((stattype)((BASESTR+1u)/2.f),(stattype)((BASEINT+1u)/2.f));\
         HP->increaseCurrent((welltype)(BASEHP/2.f));\
}

#define __CHARACTERCLASS__(classname, basehp, basestr, baseint) \
class classname : public PlayerCharacterDelegate{\
private:\
    __LEVELUP__ \
public:\
    static const welltype BASEHP  = (welltype)basehp;\
    static const stattype BASESTR = (stattype)basestr;\
    static const stattype BASEINT = (stattype)baseint;\
    classname() :__PCCONSTRUCT__ \
    ~classname(){};\
    std::string  getClassName() override{return std::string(#classname);}\
};

__CHARACTERCLASS__(Cleric, 14, 3, 5);
__CHARACTERCLASS__(Warrior, 14, 3, 5);
__CHARACTERCLASS__(Wizard, 10, 1, 8);
__CHARACTERCLASS__(Rogue, 14, 4, 4);