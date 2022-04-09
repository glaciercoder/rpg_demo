#pragma once
#include "pointwell.h"
#include "statblock.h"
#include "playercharacter.h"
#include <string>

#define __PCCONSTRUCT__ \
HP->setMax(BASEHP); \
HP->increaseCurrent(BASEHP); \
if(MP){\
MP->setMax(BASEMP);\
MP->increaseCurrent(BASEMP);}\
increaseStats(BASESTR, BASEINT, BASEAGI); 


#define __LEVELUP__ \
HP->setMax((welltype)(BASEHP/2.f+ HP->getMax()));\
increaseStats((stattype)((BASESTR+1u)/2.f),((stattype)((BASEINT+1u)/2.f)), (stattype)((BASEAGI+1u)/2.f));\
HP->increaseCurrent((welltype)(BASEHP/2.f));\
if(MP){\
MP->setMax((welltype)(BASEMP/2.f+ MP->getMax()));\
MP->increaseCurrent((welltype)(BASEMP/2.f));}


class Cleric : public PlayerCharacterDelegate{
private:
     void LevelUp() override{
         __LEVELUP__
        if (CurrentLevel == 2) Abilities.emplace_back("Smite", 2u, 1u, ABILITYTARGET::ENEMY, 2u, ABILITYSCALER::INT);
     } 
public:
     static const welltype BASEHP  = (welltype)14;
     static const stattype BASESTR = (stattype)3;
     static const stattype BASEINT = (stattype)5;
     static const stattype BASEAGI = (stattype)1;
     static const welltype BASEMP = (welltype)10u;
     std::string  getClassName() override{return std::string("Cleric");}

     Cleric() : PlayerCharacterDelegate(){
       MP = std::make_unique<PointWell>();
       __PCCONSTRUCT__ 
       Abilities.emplace_back("Heal", 2u, 1u, ABILITYTARGET::ALLY, 2u, ABILITYSCALER::INT);
     }
     ~Cleric(){};
 };

class Wizard : public PlayerCharacterDelegate{
private:
     void LevelUp() override{
         __LEVELUP__
        if (CurrentLevel == 2) Abilities.emplace_back("ThunderBolt", 2u, 1u, ABILITYTARGET::ENEMY, 4u, ABILITYSCALER::INT);
     } 
public:
     static const welltype BASEHP  = (welltype)10;
     static const stattype BASESTR = (stattype)1;
     static const stattype BASEINT = (stattype)8;
     static const stattype BASEAGI = (stattype)1;
     static const welltype BASEMP = (welltype)14u;
     std::string  getClassName() override{return std::string("Wizard");}

     Wizard() : PlayerCharacterDelegate(){
       MP = std::make_unique<PointWell>();
       __PCCONSTRUCT__ 
       Abilities.emplace_back("FireBall", 3u, 1u, ABILITYTARGET::ENEMY, 6u, ABILITYSCALER::INT);
     }
     ~Wizard(){};
 };

class Warrior : public PlayerCharacterDelegate{
private:
     void LevelUp() override{
         __LEVELUP__
        if (CurrentLevel == 2) Abilities.emplace_back("PowerAttack", 0u, 3u, ABILITYTARGET::ENEMY, 4u, ABILITYSCALER::STR);
     } 
public:
     static const welltype BASEHP  = (welltype)18;
     static const stattype BASESTR = (stattype)6;
     static const stattype BASEINT = (stattype)2;
     static const stattype BASEAGI = (stattype)2;
     static const welltype BASEMP = (welltype)0u;
     std::string  getClassName() override{return std::string("Warrior");}

     Warrior() : PlayerCharacterDelegate(){
    //   MP = std::make_unique<PointWell>();
       __PCCONSTRUCT__ 
     }
     ~Warrior(){};
 };
