#include <vector>

struct Stats
{
    float average,max,min;
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}

class IAlerter
{
    public:
        virtual void SetAlert()=0;
};

class EmailAlert:public IAlerter
{
 public:
    bool emailSent;
    EmailAlert();
    void SetAlert();    
};

class LEDAlert:public IAlerter
{
 public:
    bool ledGlows;
    LEDAlert();
    void SetAlert();
};

class StatsAlerter
{
    float max;
    std::vector<IAlerter*> al;
    
  public:
     StatsAlerter(float , std::vector<IAlerter*>& );
     void checkAndAlert(std::vector<float>& );
};
