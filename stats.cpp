#include "stats.h"
#include <algorithm>
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<float>& num) {
    
    /*Creation of Stats object*/
    Stats stat1;
    
    /*Check is the vector is array or not, if empty don't do the calculations*/
    if(!num.empty())
    {
        for(auto i:num)
        {
            stat1.average+=i;
        }
        /*Calculate the average, minimum and maximum of the vector elements*/
        stat1.average=stat1.average/num.size();
        stat1.min=*min_element(num.begin(),num.end());
        stat1.max=*max_element(num.begin(),num.end());
    }
        
    return stat1;
}

EmailAlert::EmailAlert() 
{ 
    emailSent = false; 
}

/*Set the Email alert*/
void EmailAlert::SetAlert()
{
    this->emailSent = true;
}

LEDAlert::LEDAlert() 
{ 
    ledGlows = false; 
}

/*Set the LED alert*/
void LEDAlert::SetAlert()
{
    this->ledGlows = true; 
}

StatsAlerter::StatsAlerter(float f , std::vector<IAlerter*>& ia)
    :max(f) , al(ia)
{}

/*Checks and decides when the set alert is to be invoked*/
void StatsAlerter::checkAndAlert(const std::vector<float>& n)
{
    for (auto i : n)
    {
        if (i > max)
        { 
            for (int j = 0; j < al.size(); ++j)
            {
                this->al.at(j)->SetAlert();
            }
            break;
        }
    }
}
