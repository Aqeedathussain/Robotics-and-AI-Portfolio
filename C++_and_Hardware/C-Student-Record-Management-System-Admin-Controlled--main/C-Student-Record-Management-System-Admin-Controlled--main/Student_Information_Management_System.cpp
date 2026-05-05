#include<iostream>
#include<string>
using namespace std;

class academicDetails {
private:
    string name;
    string roll_number;
protected:
    string grades1, grades2, grades3;
public:
    academicDetails() {
        name = "Aqeedat Hussain";
        roll_number = "09-239241-026";
        grades1 = "A";
        grades2 = "A+";
        grades3 = "A";
    }
    void out() {
        cout << "----- Student Details -----"<<endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
    }
    void disp() {
        cout << "Grades:\n";
        cout << "Subject 1: " << grades1 << endl;
        cout << "Subject 2: " << grades2 << endl;
        cout << "Subject 3: " << grades3 << endl;
    }
    friend class admin;
};

class ExtraCurricular {
private:
    string club;
    string achievement;
public:
    ExtraCurricular() {
        club = "Robotics Club";
        achievement = "Won Line Following Competition";
    }
    void display() {
        cout << "----- Extra Curricular Activities -----"<<endl;
        cout << "Club: " << club << endl;
        cout << "Achievement: " << achievement << endl;
    }
    friend class admin;
};

class disciplinaryRecords {
private:
    string record;
public:
    disciplinaryRecords() {
        record = "No Disciplinary Action";
    }
    void show() {
        cout << "----- Disciplinary Record -----"<<endl;
        cout << record << endl;
    }
    friend class admin;
};

class LibraryAccount {
private:
    int booksIssued;
    string status;
public:
    LibraryAccount() {
        booksIssued = 3;
        status = "Clear";
    }
    void get() {
        cout << "----- Library Account -----"<<endl;
        cout << "Books Issued: " << booksIssued << endl;
        cout << "Status: " << status << endl;
    }
    friend class admin;
};

class sportsPart {
private:
    string game;
    string position;
public:
    sportsPart() {
        game = "Football";
        position = "Captain";
    }
    void on() {
        cout << "----- Sports Participation -----"<<endl;
        cout << "Game: " << game << endl;
        cout << "Position: " << position << endl;
    }
    friend class admin;
};

class admin {
private:
    string id;
    string newname, newrollnumber;
    string newgrades1, newgrades2, newgrades3;
    string newclub, newachievement;
    string newrecord;
    int newbooksIssued;
    string newstatus;
    string newgame, newposition;

public:
    admin(academicDetails& a, ExtraCurricular& e, disciplinaryRecords& d, LibraryAccount& l, sportsPart& s) {
        id = "09-239241-026"; 
    }

    string returnid() {
        return id;
    }

    void instudent(academicDetails& a) {
        cout << "Enter New Name: "<<endl;
        cin.ignore();
        getline(cin, newname);
        cout << "Enter New Roll Number: "<<endl;
        cin >> newrollnumber;

        a.name = newname;
        a.roll_number = newrollnumber;
    }

    void inAcademic(academicDetails& a) {
        cout << "Enter Grade1: "<<endl;
        cin >> newgrades1;
        cout << "Enter Grade2: "<<endl;
        cin >> newgrades2;
        cout << "Enter Grade3: "<<endl;
        cin >> newgrades3;

        a.grades1 = newgrades1;
        a.grades2 = newgrades2;
        a.grades3 = newgrades3;
    }

    void inExtracricullar(ExtraCurricular& e) {
        cout << "Enter Club Name: "<<endl;
        cin.ignore();
        getline(cin, newclub);
        cout << "Enter Achievement: "<<endl;
        getline(cin, newachievement);

        e.club = newclub;
        e.achievement = newachievement;
    }

    void indisplinary(disciplinaryRecords& d) {
        cout << "Enter New Record: "<<endl;
        cin.ignore();
        getline(cin, newrecord);

        d.record = newrecord;
    }

    void inLibrary(LibraryAccount& l) {
        cout << "Enter Books Issued: "<<endl;
        cin >> newbooksIssued;
        cout << "Enter Status: "<<endl;
        cin >> newstatus;

        l.booksIssued = newbooksIssued;
        l.status = newstatus;
    }

    void insports(sportsPart& s) {
        cout << "Enter Game: "<<endl;
        cin.ignore();
        getline(cin, newgame);
        cout << "Enter Position: "<<endl;
        getline(cin, newposition);

        s.game = newgame;
        s.position = newposition;
    }

    void outstudent(academicDetails& a) {
        cout << "----- Updated Student Details -----"<<endl;
        cout << "Name: " << a.name << endl;
        cout << "Roll Number: " << a.roll_number << endl;
    }
};

int main() {
    academicDetails x;
    ExtraCurricular z;
    disciplinaryRecords r;
    LibraryAccount a;
    sportsPart y;
    admin u(x, z, r, a, y);

    string ID;
    int choice;

    cout << "=========== STUDENT DETAILS ==========="<<endl;
    x.out();
    x.disp();
    z.display();
    r.show();
    a.get();
    y.on();

    cout << "Enter ID to edit the student details: "<<endl;
    cin >> ID;

    if (ID == u.returnid()) {
        do {
            cout << "=========== EDIT MENU ==========="<<endl;
            cout << "1. Edit Student Details"<<endl;
            cout << "2. Edit Academic Details"<<endl;
            cout << "3. Edit Extra-Curricular Activities"<<endl;
            cout << "4. Edit Disciplinary Records"<<endl;
            cout << "5. Edit Library Account"<<endl;
            cout << "6. Edit Sports Participation"<<endl;
            cout << "7. Exit Editing"<<endl;
            cout << "Enter your choice: "<<endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    u.instudent(x);
                    u.outstudent(x);
                    break;
                case 2:
                    u.inAcademic(x);
                    x.disp();
                    break;
                case 3:
                    u.inExtracricullar(z);
                    z.display();
                    break;
                case 4:
                    u.indisplinary(r);
                    r.show();
                    break;
                case 5:
                    u.inLibrary(a);
                    a.get();
                    break;
                case 6:
                    u.insports(y);
                    y.on();
                    break;
                case 7:
                    cout << "Exiting editing mode..."<<endl;
                    break;
                default:
                    cout << "Invalid choice! Try again."<<endl;
            }

        } while (choice != 7);
    } else {
        cout << "Invalid ID. Access denied."<<endl;
    }

    return 0;
}
