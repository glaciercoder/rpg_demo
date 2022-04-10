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
            << "-MP:" << p1.getCurrentMP() << "/" << p1.getMaxMP() << '\n'
            << "-Strength:" << p1.getTotalStrength() << '\n' 
            << "-Intellect:" << p1.getTotalIntellect() << '\n'
            << "-Agility:" << p1.getTotalAgility() << '\n'
            << "-Armor:" << p1.getTotalArmor() << '\n'
            << "-ElemebtResistance:" << p1.getTotalElementResistance() << '\n';
        std::cout << "-Abilities: \n";
        auto AllAbilities = p1.getAbilityList();
        for (auto pc : AllAbilities)
             std::cout << " -" << pc.name  << '\n';
        if (i < 1) {
            Buff arm_buff("StoneShield", 10, 0, 0, 0, 5, 0, false);
            p1.applyBuff(arm_buff);
            p1.gainEXP(100u);
        }
    }
    return 0;
}
