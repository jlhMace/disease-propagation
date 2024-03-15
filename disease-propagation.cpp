#include <iostream>
#include <time.h>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::to_string;


class Person
{
    private:
        string infectionStatus;
        int step, daysRemain;
    public:
        Person()
        {
            infectionStatus = "susceptible";
            step = 0;
        }
        
        string status_string()
        {
            if (infectionStatus=="sick")
            {
                return infectionStatus + " (" + to_string(daysRemain) + " days remaining)";
            }
            else {return infectionStatus;}
        }

        void update()
        {
            step++;
        }

        void infect(int n)
        {
            if (infectionStatus == "susceptible")
            {
                infectionStatus = "sick";
                daysRemain = n;
            }
        }

        void infection_progression()
        {
            daysRemain--;
            if (daysRemain==0)
            {
                infectionStatus = "recovered";
            }
        }

        bool is_stable()
        {
            if (infectionStatus=="recovered" || infectionStatus=="inoculated")
            {
                return true;
            }
            else {return false;}
        }

        int getDay()
        {
            return step;
        }

        string get_status()
        {
            return infectionStatus;
        }
};


int infectionReport(Person joe)
{
    srand(time(NULL));
    while (joe.is_stable()!=true)
    {
        joe.update();
        
        float bad_luck;
        bad_luck = (float)(rand()) / (float)(RAND_MAX);
        if (joe.get_status() == "sick")
        {
            joe.infection_progression();
        }
        if (bad_luck>0.95)
        {
            joe.infect(5);
        }

        cout << "On day " << joe.getDay() << ", Joe is " << joe.status_string() << "." << endl;
    }
    return 0;
}


int main()
{
    Person joe;

    infectionReport(joe);
    
    return 0;
}