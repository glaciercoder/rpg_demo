#pragma once
#include "types.h"
#include<vector>
#include "buff.h"
class StatBlock
{
private:
    stattype strength;
    stattype intellect;
    stattype agility;
    stattype armor;
    stattype elementresistance;
    // Effect from buffs
    stattype Buffstrength = 0;
    stattype Buffintellect = 0;
    stattype Buffagility = 0;
    stattype Buffarmor = 0;
    stattype Buffelementresistance = 0;

    void recalculatebuffs(Buff b){
        if(b.isDebuff){
            Buffstrength = (Buffstrength > b.strength) ? (Buffstrength - b.strength) : 0;
            Buffintellect = (Buffintellect > b.intellect) ? (Buffintellect - b.intellect) : 0;
            Buffagility = (Buffagility > b.agility) ? (Buffagility - b.agility) : 0;
            Buffarmor = (Buffarmor > b.armor) ? (Buffarmor - b.armor) : 0;
            Buffelementresistance = (Buffelementresistance > b.elementresistance) ? (Buffelementresistance - b.elementresistance) : 0;
        }
        else{
            Buffstrength += b.strength;
            Buffintellect += b.intellect;
            Buffagility += b.agility;
            Buffarmor += b.armor;
            Buffelementresistance += b.elementresistance;
        }
    }
public:
    StatBlock() :  strength(stattype(1u)), intellect(stattype(1u)), agility(stattype(1u)), armor(stattype(1u)), elementresistance(stattype(1u)){}
    explicit StatBlock(stattype s, stattype i, stattype a = 0, stattype arm = 0u, stattype ele =0u) : strength(s), intellect(i), agility(a), armor(arm), elementresistance(ele){}
    stattype getStrenth(){return strength;}
    stattype getIntellect(){return intellect;}
    stattype getAgility(){return agility;}
    stattype getArmor(){return armor;}
    stattype getResistance(){return elementresistance;}
    
    stattype getTotalStrenth(){return strength + Buffstrength;}
    stattype getTotalIntellect(){return intellect + Buffintellect;}
    stattype getTotalAgility(){return agility + Buffagility;}
    stattype getTotalArmor(){return armor + Buffarmor;}
    stattype getTotalResistance(){return elementresistance + Buffelementresistance;}

protected:
    std::vector<Buff> Buffs; 
    void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype ele = 0){
        strength += s;
        intellect += i;
        agility += a;
        armor += arm;
        elementresistance += ele;
    }
    void addNewBuff(Buff b){
        for(auto& buff : Buffs){
            if(b.Name == buff.Name){
                buff.duration = b.duration;
                return;
            }
        }
        Buffs.push_back(b);
        recalculatebuffs(b);
    }
};
