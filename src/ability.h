#pragma once
#include <string>
#include <cstdint>
enum class ABILITYTARGET {SELF, ENEMY, ALLY};
enum class ABILITYSCALER {NONE, STR, AGI, INT};

class Ability
{
private:
public:
    std::string name = "unnamed";
    unsigned int cost = 0;
    unsigned int cd = 1;
    ABILITYTARGET target = ABILITYTARGET::SELF;
    unsigned int hp_effect = 1;
    ABILITYSCALER scaler = ABILITYSCALER::NONE;

    Ability(std::string s, uint32_t c, uint32_t cd, ABILITYTARGET t, uint32_t hpe ,ABILITYSCALER sc) : name(s), cost(c), cd(c), target(t), hp_effect(hpe), scaler(sc){};
    ~Ability(){};
};

