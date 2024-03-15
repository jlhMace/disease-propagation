#include <iostream>
#include <time.h>
#include <string>

using std::endl;
using std::cout;
using std::string;


class Person
{
    // Represents an individual
    private:
        string infectionStatus, name;
        int daysRemain;
    public:
        Person()
        {
            infectionStatus = 'susceptible';
            name = 'Joe';
            daysRemain = 0;
        }
        
        string status_string()
        {
            return infectionStatus;
        }

        int update()
        {
            daysRemain = daysRemain - 1;
        }

        int infect(int n)
        {
            daysRemain = 5;
            infectionStatus = 'sick';
        }

        void is_stable()
        {
            
        }

        string getName()
        {
            return name;
        }

        int getDay()
        {
            return daysRemain;
        }

};


int dailyReport(Person joe)
{
    float bad_luck;
    bad_luck = (float)(rand()) / (float)(RAND_MAX);
    if (bad_luck>0.95)
    {
        joe.infect(5);
    }

    cout << " " << endl;
    return 0;
}


int main()
{
    Person joe;

    dailyReport(joe);
    // cout << "On day " << joe.getDay() << ", " << joe.getName() << " is " << joe.status_string() << "." << endl;

    return 0;
}