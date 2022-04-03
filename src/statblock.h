#pragma once
using stattype = std::uint16_t;
struct StatBlock
{
private:
    stattype strength;
    stattype intellect;
public:
    StatBlock() :  strength(stattype(1u)), intellect(stattype(1u)){}
    explicit StatBlock(stattype s, stattype i) : strength(s), intellect(i){}
    stattype getStrenth(){return strength;}
    stattype getIntellect(){return intellect;}

protected:
    void increaseStats(stattype s, stattype i){
        strength += s;
        intellect += i;
    }
};
