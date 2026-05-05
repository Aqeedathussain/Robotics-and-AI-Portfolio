class smart_doorlock
{
private:
    int l;
    int failed = 0;
public:
    void get()
    {
        while (true)
        {
            cout << "Enter 1 if the door is locked\nEnter 2 if the door is unlocked: ";
            cin >> l;

            if (l == 1 || l == 2)
            {
                break; // valid input
            }
            else
            {
                failed++;
                cout << "Invalid input. Try again." << endl;
                cout << "Failed attempts: " << failed << endl;
            }
        }
    }

    void show()
    {
        if (l == 1)
        {
            cout << "The door is locked." << endl;
        }
        else if (l == 2)
        {
            cout << "The door is unlocked." << endl;
        }
    }

    int lo()
    {
        return l;
    }
};
