#include "stats.h"
#include <algorithm>
#include <cmath>

struct Stats Statistics::ComputeStatistics(const std::vector<float>& num) {
    
    /*Creation of Stats object*/
    Stats stat1;
    
    if(!num.empty())
    {
        for(auto i:num)
        {
            stat1.average+-i;
        }
    
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

void EmailAlert::SetAlert()
{
    this->emailSent = true;
}

LEDAlert::LEDAlert() 
{ 
    ledGlows = false; 
}

void LEDAlert::SetAlert()
{
    this->ledGlows = true; 
}

StatsAlerter::StatsAlerter(float f , std::vector<IAlerter*>& i)
    :max(m) , alerter(al)
{}

void StatsAlerter::checkAndAlert(const std::vector<float>& n)
{
    for (auto i : n)
    {
        if (i > max)
        { 
            for (int j = 0; j < alerter.size(); ++j)
            {
                this->alerter.at(j)->SetAlert();
            }
            break;
        }
    }
}
