#pragma once
#include<cstdint>
#include<hitpointtypes.h>           
class hp
{
private:
    hpType CurrentHP;
    hpType MaxHP;
public:
    hp(): CurrentHP(1), MaxHP(1){}
    hp(hpType cHP, hpType mHP): CurrentHP(cHP), MaxHP(mHP){}
    ~hp();
    bool setMaxHP(hpType new_max_hp) {
        if (new_max_hp < 1)
            return false;
        MaxHP = new_max_hp;

        if(CurrentHP > MaxHP) CurrentHP = MaxHP;
        return true;
    }

   void takeDamage(hpType damage){
       if(damage > CurrentHP ) {
           CurrentHP = 0;
           return ;
       }
       CurrentHP -= damage;
   }
   
   void heal(hpType amount){
       if(amount + CurrentHP > MaxHP){
           CurrentHP = MaxHP;
           return ;
       }
       CurrentHP += amount;
   }

   hpType getMaxHP() {return MaxHP;}
   hpType getCurrentHP() {return CurrentHP;}
};

hp::hp(/* args */)
{
}

hp::~hp()
{
}
