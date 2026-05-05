#include<iostream>
using namespace std;

class ownerDetails;
class MaintenanceLog;
class InsuranceDetails;
class performance;

// ===================== VEHICLE CLASS =====================
class vehicle
{
private:
    string regNo;
protected:
    string model;
    string type;
public:
    friend class Admin;
    vehicle()
    {
        regNo = "ABB_123";
        model = "Toyota Corolla";
        type = "Sedan";
    }
    void display()
    {
        cout << " Registration number: " << regNo << endl;
        cout << " Model: " << model << endl;
        cout << " Vehicle Type: " << type << endl;
    }
};

// ===================== OWNER DETAILS =====================
class ownerDetails : public vehicle
{
protected:
    string name;
    string contact;
    string email;
    string address;
public:
    friend class Admin;
    ownerDetails()
    {
        name = "Aqeedat";
        contact = "0302-6349096";
        email = "CarWala@gmail.com";
        address = "Car Walay Ka Ghar on Gola";
    }
    void show()
    {
        cout << " Owner Name: " << name << endl;
        cout << " Owner Contact: " << contact << endl;
        cout << " Owner Email: " << email << endl;
        cout << " Owner Address: " << address << endl;
    }
};

// ===================== MAINTENANCE LOG =====================
class MaintenanceLog : public ownerDetails
{
protected:
    string date, MaintenanceType;
    int cost;

    string date_2, MaintenanceType_2;
    int cost_2;

    string date_3, MaintenanceType_3;
    int cost_3;

public:
    friend class Admin;
    MaintenanceLog()
    {
        date = "12/3/2025";
        MaintenanceType = "OilChange";
        cost = 30000;
    }
    void maintenencelog2()
    {
        date_2 = "14/5/2025";
        MaintenanceType_2 = "Brake Pad Replacement";
        cost_2 = 2000;
    }
    void maintenencelog3()
    {
        date_3 = "24/7/2025";
        MaintenanceType_3 = "Tire Rotation";
        cost_3 = 15000;
    }
    void disp()
    {
        cout << " Service Date: " << date << " | Service: " << MaintenanceType << " | Cost: " << cost << endl;
    }
    void disp2()
    {
        cout << " Service Date: " << date_2 << " | Service: " << MaintenanceType_2 << " | Cost: " << cost_2 << endl;
    }
    void disp3()
    {
        cout << " Service Date: " << date_3 << " | Service: " << MaintenanceType_3 << " | Cost: " << cost_3 << endl;
    }
};

// ===================== TRAFFIC VIOLATION =====================
class TraficViolation_Record : public vehicle
{
protected:
    string ViolationType, date;
    int ticket;
    string ViolationType_2, date_2;
    int ticket_2;

public:
    friend class Admin;
    TraficViolation_Record()
    {
        ViolationType = "Speeding";
        ticket = 300;
        date = "16/6/2015";
        ViolationType_2 = "Parking";
        ticket_2 = 200;
        date_2 = "25/5/2018";
    }
    void fetch()
    {
        cout << " Date: " << date << " | Violation: " << ViolationType << " | Penalty: " << ticket << endl;
    }
    void fetch2()
    {
        cout << " Date: " << date_2 << " | Violation: " << ViolationType_2 << " | Penalty: " << ticket_2 << endl;
    }
};

// ===================== INSURANCE DETAILS =====================
class InsuranceDetails
{
private:
    string company;
    string PolicyNumber;
    string coverage;
public:
    friend class Admin;
    InsuranceDetails()
    {
        company = "National Insurance Corporation";
        PolicyNumber = "ABC123456789";
        coverage = "Active (Expires: 23/12/2029)";
    }
    void print()
    {
        cout << " Company: " << company << " | Policy Number: " << PolicyNumber << " | Coverage Status: " << coverage << endl;
    }
};

// ===================== PERFORMANCE =====================
class performance : public MaintenanceLog
{
private:
    string engineHealth;
    string fuelEfficiency;
    string diagnostics;
public:
    friend class Admin;
    performance()
    {
        engineHealth = "Good (No Issue Found)";
        fuelEfficiency = "15 km/l";
        diagnostics = "All Parts Working Properly";
    }
    void print2()
    {
        cout << " Engine Health: " << engineHealth << endl;
        cout << " Fuel Efficiency: " << fuelEfficiency << endl;
        cout << " Diagnostics: " << diagnostics << endl;
    }
};

// ===================== ADMIN CLASS =====================
class Admin
{
private:
    string ID = "123456";

    // vehicle
    string newregNo, newmodel, newtype;

    // owner
    string newname, newcontact, newemail, newaddress;

    // maintenance
    string newmaintenancedate, newMaintenanceType;
    int newcost;
    string newmaintenancedate_2, newMaintenanceType_2;
    int newcost_2;
    string newdate_3, newMaintenanceType_3;
    int newcost_3;

    // violations
    string newViolationType, newdate, newViolationType_2, newdate_2;
    int newticket, newticket_2;

    // insurance
    string newcompany, newPolicyNumber, newcoverage;

    // performance
    string newengineHealth, newfuelEfficiency, newdiagnostics;

public:
    string enterid() { return ID; }

    // VEHICLE
    void vehicle_in(vehicle& v)
    {
        cout << " New reg No: ";
        cin >> newregNo;
        cout << " New Model: ";
        cin >> newmodel;
        cout << " New Type: ";
        cin >> newtype;

        v.regNo = newregNo;
        v.model = newmodel;
        v.type = newtype;
    }

    // OWNER
    void owner(ownerDetails& n)
    {
        cout << " Enter new name: ";
        cin >> newname;
        cout << " Enter new contact: ";
        cin >> newcontact;
        cout << " Enter new email: ";
        cin >> newemail;
        cout << " Enter new address: ";
        cin >> newaddress;

        n.name = newname;
        n.contact = newcontact;
        n.email = newemail;
        n.address = newaddress;
    }

    // MAINTENANCE
    void Maintenance_in(MaintenanceLog& m)
    {
        cout << " Enter new maintenance date1: ";
        cin >> newmaintenancedate;
        cout << " Enter new maintenance type1: ";
        cin >> newMaintenanceType;
        cout << " Enter new maintenance cost1: ";
        cin >> newcost;

        m.date = newmaintenancedate;
        m.MaintenanceType = newMaintenanceType;
        m.cost = newcost;
    }

    void maintenance_in2(MaintenanceLog& m)
    {
        cout << " Enter new maintenance date2: ";
        cin >> newmaintenancedate_2;
        cout << " Enter new maintenance type2: ";
        cin >> newMaintenanceType_2;
        cout << " Enter new maintenance cost2: ";
        cin >> newcost_2;

        m.date_2 = newmaintenancedate_2;
        m.MaintenanceType_2 = newMaintenanceType_2;
        m.cost_2 = newcost_2;
    }

    void maintenance_in3(MaintenanceLog& m)
    {
        cout << " Enter new maintenance date3: ";
        cin >> newdate_3;
        cout << " Enter new maintenance type3: ";
        cin >> newMaintenanceType_3;
        cout << " Enter new maintenance cost3: ";
        cin >> newcost_3;

        m.date_3 = newdate_3;
        m.MaintenanceType_3 = newMaintenanceType_3;
        m.cost_3 = newcost_3;
    }

    // VIOLATION
    void updateviolation1(TraficViolation_Record& v)
    {
        cout << " Enter new violation type 1: ";
        cin >> newViolationType;
        cout << " Enter new violation ticket 1: ";
        cin >> newticket;
        cout << " Enter new violation date 1: ";
        cin >> newdate;

        v.ViolationType = newViolationType;
        v.ticket = newticket;
        v.date = newdate;
    }

    void updateviolation2(TraficViolation_Record& v)
    {
        cout << " Enter new violation type 2: ";
        cin >> newViolationType_2;
        cout << " Enter new violation ticket 2: ";
        cin >> newticket_2;
        cout << " Enter new violation date 2: ";
        cin >> newdate_2;

        v.ViolationType_2 = newViolationType_2;
        v.ticket_2 = newticket_2;
        v.date_2 = newdate_2;
    }

    // INSURANCE
    void updateinsurance(InsuranceDetails& i)
    {
        cout << " Enter new company name: ";
        cin >> newcompany;
        cout << " Enter new policy number: ";
        cin >> newPolicyNumber;
        cout << " Enter new coverage status: ";
        cin >> newcoverage;

        i.company = newcompany;
        i.PolicyNumber = newPolicyNumber;
        i.coverage = newcoverage;
    }

    // PERFORMANCE
    void updateperformance(performance& p)
    {
        cout << " Enter Engine health: ";
        cin >> newengineHealth;
        cout << " Enter fuel efficiency: ";
        cin >> newfuelEfficiency;
        cout << " Enter diagnostics: ";
        cin >> newdiagnostics;

        p.engineHealth = newengineHealth;
        p.fuelEfficiency = newfuelEfficiency;
        p.diagnostics = newdiagnostics;
    }
};

// ===================== MAIN =====================
int main()
{
    vehicle v;
    ownerDetails o;
    MaintenanceLog m;
    TraficViolation_Record t;
    InsuranceDetails i;
    performance p;
    Admin a;
    string id;
    int x;
    char y, z;

    // initialize other logs
    m.maintenencelog2();
    m.maintenencelog3();

    cout << "Enter 1 to display the details of the vehicle:\n";
    cout << "Enter 2 to edit the details of the vehicle:\n";
    cin >> x;

    if (x == 1)
    {
        v.display();
        o.show();
        m.disp();
        m.disp2();
        m.disp3();
        t.fetch();
        t.fetch2();
        i.print();
        p.print2();
    }
    else if (x == 2)
    {
        cout << "Please enter your ID to edit the details of the vehicle: ";
        cin >> id;

        if (id == a.enterid())
        {
            cout << "\n1. Edit Vehicle Details\n2. Edit Owner Details\n3. Edit Maintenance Details\n4. Edit Violation Details\n5. Edit Insurance Details\n6. Edit Performance Details\n";
            cin >> x;

            if (x == 1) a.vehicle_in(v);
            else if (x == 2) a.owner(o);
            else if (x == 3)
            {
                cout << "Enter a for 1st Maintenance, b for 2nd, c for 3rd: ";
                cin >> y;
                if (y == 'a') a.Maintenance_in(m);
                else if (y == 'b') a.maintenance_in2(m);
                else if (y == 'c') a.maintenance_in3(m);
            }
            else if (x == 4)
            {
                cout << "Enter a for 1st Violation, b for 2nd: ";
                cin >> z;
                if (z == 'a') a.updateviolation1(t);
                else if (z == 'b') a.updateviolation2(t);
            }
            else if (x == 5) a.updateinsurance(i);
            else if (x == 6) a.updateperformance(p);
            else cout << "Invalid Input!\n";
        }
        else
        {
            cout << "Invalid Admin ID!\n";
        }
    }
}
