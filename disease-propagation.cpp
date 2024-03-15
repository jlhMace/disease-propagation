#include <iostream>
#include <time.h>
#include <string>

using std::endl;
using std::cout;
using std::string;


class Person
{
    private:
        string infectionStatus, name;
        int step, daysRemain;
    public:
        Person()
        {
            infectionStatus = "susceptible";
            name = "Joe";
            step = 0;
        }

        Person(string givenName)
        {
            infectionStatus = "susceptible";
            name = givenName;
            step = 0;
        }
        
        string status_string()
        {
            return infectionStatus;
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

        void is_stable()
        {
            infectionStatus = "recovered";
        }

        string getName()
        {
            return name;
        }

        int getDay()
        {
            return step;
        }
};


int infectionReport(Person joe)
{
    srand(time(NULL));
    while (joe.status_string() != "recovered")
    {
        joe.update();
        
        
        float bad_luck;
        bad_luck = (float)(rand()) / (float)(RAND_MAX);
        if (bad_luck>0.95)
        {
            joe.infect(5);
        }
        if (joe.status_string() == "sick")
        {
            joe.infection_progression();
        }

        cout << "On day " << joe.getDay() << ", " << joe.getName() << " is " << joe.status_string() << ". (" << bad_luck << ")" << endl;
    }
    return 0;
}


int main()
{
    Person joe;

    infectionReport(joe);
    
    return 0;
}