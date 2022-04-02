#pragma once
#include "stattypes.h"
struct StatBlock
{
    stattype strength;
    stattype intellect;
    StatBlock() :  strength(stattype(1u)), intellect(stattype(1u)){}
    StatBlock(stattype s, stattype i) : strength(s), intellect(i){}
};
