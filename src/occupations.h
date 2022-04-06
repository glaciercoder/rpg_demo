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


class Cleric : public PlayerCharacterDelegate
{
private:
    __LEVELUP__
public: 
    static const welltype BASEHP  = (welltype)14u;
    static const stattype BASESTR = (stattype)2u;
    static const stattype BASEINT = (stattype)3u;
    Cleric() :__PCCONSTRUCT__ 
    ~Cleric(){};

    std::string  getClassName() override{return std::string("Cleric");}
};


class Rogue : public PlayerCharacterDelegate
{
private:
    __LEVELUP__
public: 
    static const welltype BASEHP  = (welltype)12u;
    static const stattype BASESTR = (stattype)3u;
    static const stattype BASEINT = (stattype)2u;
    Rogue() : __PCCONSTRUCT__ 
    ~Rogue(){};

    std::string  getClassName() override{return std::string("Rogue");}
};

class Warrior : public PlayerCharacterDelegate
{
private:
    __LEVELUP__
public: 
    static const welltype BASEHP  = (welltype)14u;
    static const stattype BASESTR = (stattype)2u;
    static const stattype BASEINT = (stattype)3u;
    Warrior() : __PCCONSTRUCT__ 
    ~Warrior(){};

    std::string  getClassName() override{return std::string("Warrior");}
};

class Wizard : public PlayerCharacterDelegate
{
private:
    __LEVELUP__
public: 
    static const welltype BASEHP  = (welltype)10u;
    static const stattype BASESTR = (stattype)1u;
    static const stattype BASEINT = (stattype)4u;
    Wizard() : __PCCONSTRUCT__ 
    ~Wizard(){};

    std::string  getClassName() override{return std::string("Wizard");}
};
 
 


 