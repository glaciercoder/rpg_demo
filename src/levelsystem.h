#pragma once
#include<cstdint>
using exptype = std::uint64_t;
using leveltype = std::uint16_t;
class LevelSystem
{
protected:
   leveltype CurrentLevel;
   exptype CurrentEXP; 
   exptype EXPToNextLevel;
   void check_if_leveled(){
       static const exptype LEVELSCALAR = 2u;// increase by 2^n

       if(CurrentEXP > EXPToNextLevel){
           ++CurrentLevel;
           LevelUp();
           EXPToNextLevel *= LEVELSCALAR;
       } 
   }
   virtual void LevelUp() = 0;
private:

    
public:
    static const exptype LEVEL2AT = 100u;
    LevelSystem(): CurrentLevel(1u), CurrentEXP(0u), EXPToNextLevel(LEVEL2AT){}
    ~LevelSystem(){}

    void gainEXP(exptype gained_exp){
        CurrentEXP += gained_exp;
        check_if_leveled();
    }
};
