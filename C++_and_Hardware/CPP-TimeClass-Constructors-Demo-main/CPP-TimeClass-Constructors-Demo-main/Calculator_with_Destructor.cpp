#include<iostream>
using namespace std;

class my_time
{
private:
    int hours;
    int minutes;

public:
    my_time()
    {
        hours = 0;
        minutes = 0;
        cout << "Default constructor called" << endl;
    }

    my_time(int h)
    {
        hours = h;
        minutes = 0;
        cout << "1-argument constructor called" << endl;
    }

    my_time(int h, int m)
    {
        hours = h;
        minutes = m;
        cout << "2-argument constructor called" << endl;
    }

    void display()
    {
        cout << "Time is: " << hours << ":" << minutes << endl;
    }

    ~my_time()
    {
        cout << "Destructor called for time: " << hours << ":" << minutes << endl;
    }
};

int main()
{
    my_time t1;
    my_time t2(5);
    my_time t3(5, 30);

    cout << "\nDisplaying times:" << endl;
    t1.display();
    t2.display();
    t3.display();

    return 0;
}
