#pragma once
#include "types.h"
#include<vector>
#include "buff.h"
#include<iostream>
class StatBlock
{
private:
    CoreStats baseStats;
    CoreStats TotalStatsFromBuff;
        // Effect from buffs
    void recalculatebuffs(Buff b){
        std::cout << "b.arm = " << b.buffstats.armor << std::endl; 
        if(b.isDebuff)    baseStats -= b.buffstats;
        else baseStats += b.buffstats;
    }
public:
    StatBlock() = default;
    explicit StatBlock(stattype s, stattype i, stattype a = 0, stattype arm = 0u, stattype ele =0u) : baseStats(s, i, a, arm, ele){}
    stattype getStrenth(){return    baseStats.strength;}
    stattype getIntellect(){return  baseStats.intellect;}
    stattype getAgility(){return    baseStats.agility;}
    stattype getArmor(){return      baseStats.armor;}
    stattype getResistance(){return baseStats.elementresistance;}
    
    stattype getTotalStrenth(){return    baseStats.strength +          TotalStatsFromBuff.strength;}
    stattype getTotalIntellect(){return  baseStats.intellect +         TotalStatsFromBuff.intellect;}
    stattype getTotalAgility(){return    baseStats.agility +           TotalStatsFromBuff.agility;}
    stattype getTotalArmor(){return      baseStats.armor +             TotalStatsFromBuff.armor;}
    stattype getTotalResistance(){return baseStats.elementresistance + TotalStatsFromBuff.elementresistance;}

protected:
    std::vector<Buff> Buffs; 
    void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype ele = 0){
        baseStats.strength += s;
        baseStats.intellect += i;
        baseStats.agility += a;
        baseStats.armor += arm;
        baseStats.elementresistance += ele;
    }
    void increaseStats(CoreStats& stats){
        baseStats += stats;
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
