#pragma once
using stattype = std::uint16_t;
class StatBlock
{
private:
    stattype strength;
    stattype intellect;
    stattype agility;
    stattype armor;
    stattype elementresistance;
public:
    StatBlock() :  strength(stattype(1u)), intellect(stattype(1u)), agility(stattype(1u)), armor(stattype(1u)), elementresistance(stattype(1u)){}
    explicit StatBlock(stattype s, stattype i, stattype a = 0, stattype arm = 0u, stattype ele =0u) : strength(s), intellect(i), agility(a), armor(arm), elementresistance(ele){}
    stattype getStrenth(){return strength;}
    stattype getIntellect(){return intellect;}
    stattype getAgility(){return agility;}
    stattype getArmor(){return armor;}
    stattype getResistance(){return elementresistance;}
protected:
    void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype ele = 0){
        strength += s;
        intellect += i;
        agility += a;
        armor += arm;
        elementresistance += ele;
    }
};
