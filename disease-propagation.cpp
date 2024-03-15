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
        int countDaysTotal, countDaysRemain;
    public:
        Person()
        {
            infectionStatus = "susceptible";
            countDaysTotal = 0;
        }
        
        string getStatusString()
        {
            if (infectionStatus=="sick")
            {
                return infectionStatus + " (" + to_string(countDaysRemain) + " days remaining)";
            }
            else {return infectionStatus;}
        }

        void update()
        {
            countDaysTotal++;
        }

        void infect(int n)
        {
            if (infectionStatus == "susceptible")
            {
                infectionStatus = "sick";
                countDaysRemain = n;
            }
        }

        void progressInfection()
        {
            countDaysRemain--;
            if (countDaysRemain==0)
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
            return countDaysTotal;
        }

        string getStatus()
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
        if (joe.getStatus() == "sick")
        {
            joe.progressInfection();
        }
        if (bad_luck>0.95)
        {
            joe.infect(5);
        }

        cout << "On day " << joe.getDay() << ", Joe is " << joe.getStatusString() << "." << endl;
    }
    return 0;
}


int main()
{
    Person joe;

    infectionReport(joe);
    
    return 0;
}