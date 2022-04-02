#pragma once
#include "hp.h"
#include "statblock.h"
class Warrior : public hp, public StatBlock
{
private:
    /* data */
public: 
    static const hpType HPGROWTH = 19u;
    Warrior() : hp(HPGROWTH, HPGROWTH){}
    ~Warrior();
};
 
Warrior::Warrior(/* args */)
{
}
 
Warrior::~Warrior()
{
}
