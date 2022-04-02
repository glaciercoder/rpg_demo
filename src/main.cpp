#include<iostream>
#include "allclasses.h"
int main(int argc, char const *argv[])
{
    Warrior warr1;
    Wizard wiz1;
    Cleric cler1;
    Rogue rog1;

    std::cout << "Warrior\n" << "-MaxHP:" << warr1.getMaxHP() << std::endl 
              << "-Strength:" << warr1.getStrenth() << std::endl
              << "-Intellect:" << warr1.getIntellect() << std::endl;  
    std::cout << "Wizard\n" << "-MaxHP:" << wiz1.getMaxHP() << std::endl 
              << "-Strength:" << wiz1.getStrenth() << std::endl
              << "-Intellect:" << wiz1.getIntellect() << std::endl;  
    std::cout << "Cleric\n" << "-MaxHP:" << cler1.getMaxHP() << std::endl 
              << "-Strength:" << cler1.getStrenth() << std::endl
              << "-Intellect:" << cler1.getIntellect() << std::endl;  
    std::cout << "Rogue\n" << "-MaxHP:" << rog1.getMaxHP() << std::endl 
              << "-Strength:" << rog1.getStrenth() << std::endl
              << "-Intellect:" << rog1.getIntellect() << std::endl;  
   
 

  
    return 0;
}
