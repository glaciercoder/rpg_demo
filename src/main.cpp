#include<iostream>
#include "occupations.h"
#include "playercharacter.h"
int main(int argc, char const *argv[])
{
    PlayerCharacter p1(new Warrior());

    for (int i = 0; i < 2; i++)
    {
        std::cout
            << p1.getClassName()
            << " Level " << p1.getLevel() << "\n"
            << "-EXP:" << p1.getCurrentEXP() << "/" << p1.getEXPToNextLevel() << '\n'
            << "-HP:" << p1.getCurrentHP() << "/" << p1.getMaxHP() << '\n'
            << "-Strength:" << p1.getStrength() << '\n' 
            << "-Intellect:" << p1.getIntellect() << '\n'
            << "-Agility:" << p1.getAgility() << '\n'
            << "-Armor:" << p1.getArmor() << '\n'
            << "-ElemebtResistance:" << p1.getElementResistance() << '\n';
            if (i < 1) p1.gainEXP(100u);
    }
    
  
    return 0;
}
