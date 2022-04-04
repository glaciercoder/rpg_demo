#include<iostream>
#include "allclasses.h"
int main(int argc, char const *argv[])
{
    Warrior warr1;
    Wizard wiz1;
    Cleric cler1;
    Rogue rog1;

  
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Cleric Level" << cler1.getlevel() << '\n'
            << "-MaxHP:" << cler1.getMaxHP() << '\n'
            << "-Strength:" << cler1.getStrenth() << '\n'
            << "-Intellect:" << cler1.getIntellect() << '\n'
            << "-EXP:" << cler1.getCurrentEXP() << "/" << cler1.getEXPToNextLevel() << '\n';
            cler1.gainEXP(100u);
    }
    std::cout << "-----------------\n";
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Rogue Level" << rog1.getlevel() << '\n'
            << "-MaxHP:" << rog1.getMaxHP() << '\n'
            << "-Strength:" << rog1.getStrenth() << '\n'
            << "-Intellect:" << rog1.getIntellect() << '\n'
            << "-EXP:" << rog1.getCurrentEXP() << "/" << rog1.getEXPToNextLevel() << '\n';
            rog1.gainEXP(100u);
    }
    std::cout << "-----------------\n";

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Warrior Level" << warr1.getlevel() << '\n'
            << "-MaxHP:" << warr1.getMaxHP() << '\n'
            << "-Strength:" << warr1.getStrenth() << '\n'
            << "-Intellect:" << warr1.getIntellect() << '\n'
            << "-EXP:" << warr1.getCurrentEXP() << "/" << warr1.getEXPToNextLevel() << '\n';
            warr1.gainEXP(100u);
    }
    std::cout << "-----------------\n";
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Wizard Level" << wiz1.getlevel() << '\n'
            << "-MaxHP:" << wiz1.getMaxHP() << '\n'
            << "-Strength:" << wiz1.getStrenth() << '\n'
            << "-Intellect:" << wiz1.getIntellect() << '\n'
            << "-EXP:" << wiz1.getCurrentEXP() << "/" << wiz1.getEXPToNextLevel() << '\n';
            wiz1.gainEXP(100u);
    }
  
    return 0;
}
