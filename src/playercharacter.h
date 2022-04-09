#pragma once
#include<cstdint>
#include  "statblock.h"
#include <memory>
#include "pointwell.h"
#include "ability.h"
#include <vector>
using exptype = std::uint64_t;
using leveltype = std::uint16_t;
class PlayerCharacterDelegate : public StatBlock
{
protected:
   leveltype CurrentLevel;
   exptype CurrentEXP; 
   exptype EXPToNextLevel;
   bool check_if_leveled(){
       static const exptype LEVELSCALAR = 2u;// increase by 2^n

       if(CurrentEXP >= EXPToNextLevel){
           ++CurrentLevel;
           LevelUp();
           EXPToNextLevel *= LEVELSCALAR;
           return true;
       } 
       return false;
   }
private:
public:
    static const exptype LEVEL2AT = 100u;
    std::unique_ptr<PointWell> HP;
    std::unique_ptr<PointWell> MP;
    std::vector<Ability> Abilities;
    PlayerCharacterDelegate(): StatBlock(0u,0u), CurrentLevel(1u), CurrentEXP(0u), EXPToNextLevel(LEVEL2AT){
        HP = std::make_unique<PointWell>();
    }
    ~PlayerCharacterDelegate(){}

    void gainEXP(exptype gained_exp){
        CurrentEXP += gained_exp;
        while (check_if_leveled()){}
    }

    leveltype getlevel(){return CurrentLevel;}
    exptype getCurrentEXP(){return CurrentEXP;}
    exptype getEXPToNextLevel(){return EXPToNextLevel;}
    virtual void LevelUp() = 0;
    virtual std::string getClassName() = 0;

};

class PlayerCharacter
{
private:
    PlayerCharacterDelegate *pcclass;
public:
    PlayerCharacter() = delete;
    PlayerCharacter(PlayerCharacterDelegate *pc) : pcclass(pc) {}
    ~PlayerCharacter(){delete pcclass; pcclass = nullptr;};

    std::string getClassName() {return pcclass->getClassName();}
    leveltype getLevel(){return pcclass->getlevel();}
    exptype getCurrentEXP(){return pcclass->getCurrentEXP();}
    exptype getEXPToNextLevel(){return pcclass->getEXPToNextLevel();}
    welltype getCurrentHP(){return pcclass->HP->getCurrentFulness();}
    welltype getMaxHP(){return pcclass->HP->getMax();}
    welltype getCurrentMP(){return (pcclass->MP ?  pcclass->MP->getCurrentFulness() : 0);}
    welltype getMaxMP(){return (pcclass->MP? pcclass->MP->getMax() : 0);}

    stattype getStrength(){return pcclass->getStrenth();}
    stattype getIntellect(){return pcclass->getIntellect();}
    stattype getAgility(){return pcclass->getAgility();}
    stattype getArmor(){return pcclass->getArmor();}
    stattype getElementResistance(){return pcclass->getResistance();}
    const std::vector<Ability>& getAbilityList(){return pcclass->Abilities;}
    

    void gainEXP(exptype gain){return pcclass->gainEXP(gain);}
    void takeDamage(welltype amt){return pcclass->HP->reduce(amt);}
    void heal(welltype amt){return pcclass->HP->increaseCurrent(amt);}
};