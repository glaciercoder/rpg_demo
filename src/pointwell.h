#pragma once
#include<cstdint>
using welltype = std::uint16_t;          
class PointWell
{
private:
    welltype CurrentFulness;
    welltype MaxWell;

public:
    PointWell(): CurrentFulness(1), MaxWell(1){}
    PointWell(welltype c, welltype m): CurrentFulness(c), MaxWell(m){
        if(CurrentFulness > MaxWell) CurrentFulness = MaxWell;
    }
    ~PointWell(){};

    bool setMax(welltype new_max) {
        if (new_max < 1)
            return false;
        MaxWell = new_max;

        if(CurrentFulness > MaxWell) CurrentFulness = MaxWell;
        return true;
    }

   void reduce(welltype damage){
       if(damage > CurrentFulness ) {
           CurrentFulness = 0;
           return ;
       }
       CurrentFulness -= damage;
   }
   
   void increaseCurrent(welltype amount){
       if(amount + CurrentFulness > MaxWell){
           CurrentFulness = MaxWell;
           return ;
       }
       CurrentFulness += amount;
   }

   welltype getMax() {return MaxWell;}
   welltype getCurrentFulness() {return CurrentFulness;}
};

