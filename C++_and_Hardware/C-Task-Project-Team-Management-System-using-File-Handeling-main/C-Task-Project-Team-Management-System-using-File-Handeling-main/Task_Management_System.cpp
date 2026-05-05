#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee; // Forward declaration

// ---------- Abstract Base Class ----------
class FileHandler {
public:
    virtual void saveToFile() = 0;
    virtual void loadFromFile() = 0;
};

// ---------- Task Class ----------
class Task : public FileHandler {
protected:
    int taskID{};
    string taskName;
    string taskDescription;
    int taskPriority{};
public:
    Task() = default;
    Task(int id, const string& name, const string& desc, int priority)
        : taskID(id), taskName(name), taskDescription(desc), taskPriority(priority) {}

    void setTaskDetails(int id, const string& name, const string& desc, int priority) {
        taskID = id;
        taskName = name;
        taskDescription = desc;
        taskPriority = priority;
    }

    void displayTaskDetails() const {
        cout << "\n  [Task] ID: " << taskID
             << " | Name: " << taskName
             << " | Desc: " << taskDescription
             << " | Priority: " << taskPriority << endl;
    }

    void saveToFile() override {
        ofstream file("tasks.txt", ios::app);
        if (!file) {
            cerr << "Error opening tasks.txt for writing.\n";
            return;
        }
        file << taskID << '\n'
             << taskName << '\n'
             << taskDescription << '\n'
             << taskPriority << '\n';
        file.close();
    }

    void loadFromFile() override {
        ifstream file("tasks.txt");
        if (!file) {
            cerr << "Error opening tasks.txt for reading.\n";
            return;
        }
        while (file >> taskID) {
            file.ignore();
            getline(file, taskName);
            getline(file, taskDescription);
            file >> taskPriority;
            file.ignore();
            displayTaskDetails();
        }
        file.close();
    }

    friend void assignTaskToEmployee(const Task&, Employee&);
    friend class TaskManager;
};

// ---------- Project Class ----------
class Project : public Task {
protected:
    int projectID{};
    string projectName;
    string projectDeadline;
    Task taskList[10];
    int taskCount{};
public:
    Project() = default;

    void setProjectDetails(int id, const string& name, const string& deadline) {
        projectID = id;
        projectName = name;
        projectDeadline = deadline;
    }

    void addTaskToProject(const Task& t) {
        if (taskCount < 10)
            taskList[taskCount++] = t;
        else
            cout << "Task limit reached for this project.\n";
    }

    void displayProjectDetails() const {
        cout << "\n[Project] ID: " << projectID
             << " | Name: " << projectName
             << " | Deadline: " << projectDeadline << endl;
        for (int i = 0; i < taskCount; i++)
            taskList[i].displayTaskDetails();
    }

    void saveToFile() override {
        ofstream file("projects.txt", ios::app);
        if (!file) {
            cerr << "Error opening projects.txt for writing.\n";
            return;
        }
        file << projectID << '\n'
             << projectName << '\n'
             << projectDeadline << '\n'
             << taskCount << '\n';
        for (int i = 0; i < taskCount; i++) {
            file << taskList[i].taskID << '\n'
                 << taskList[i].taskName << '\n'
                 << taskList[i].taskDescription << '\n'
                 << taskList[i].taskPriority << '\n';
        }
        file.close();
    }

    void loadFromFile() override {
        ifstream file("projects.txt");
        if (!file) {
            cerr << "Error opening projects.txt for reading.\n";
            return;
        }
        while (file >> projectID) {
            file.ignore();
            getline(file, projectName);
            getline(file, projectDeadline);
            file >> taskCount;
            file.ignore();
            for (int i = 0; i < taskCount; i++) {
                file >> taskList[i].taskID;
                file.ignore();
                getline(file, taskList[i].taskName);
                getline(file, taskList[i].taskDescription);
                file >> taskList[i].taskPriority;
                file.ignore();
            }
            displayProjectDetails();
        }
        file.close();
    }

    friend class TaskManager;
};

// ---------- Employee Class ----------
class Employee : public FileHandler {
protected:
    int employeeID{};
    string employeeName;
    string employeeRole;
    Task assignedTasks[10];
    int assignedCount{};
public:
    Employee() = default;

    void setEmployeeDetails(int id, const string& name, const string& role) {
        employeeID = id;
        employeeName = name;
        employeeRole = role;
    }

    void assignTask(const Task& t) {
        if (assignedCount < 10)
            assignedTasks[assignedCount++] = t;
        else
            cout << "Task assignment limit reached for " << employeeName << endl;
    }

    void displayEmployeeDetails() const {
        cout << "\n[Employee] ID: " << employeeID
             << " | Name: " << employeeName
             << " | Role: " << employeeRole << endl;
        for (int i = 0; i < assignedCount; i++)
            assignedTasks[i].displayTaskDetails();
    }

    void saveToFile() override {
        ofstream file("employees.txt", ios::app);
        if (!file) {
            cerr << "Error opening employees.txt for writing.\n";
            return;
        }
        file << employeeID << '\n'
             << employeeName << '\n'
             << employeeRole << '\n'
             << assignedCount << '\n';
        for (int i = 0; i < assignedCount; i++) {
            file << assignedTasks[i].taskID << '\n'
                 << assignedTasks[i].taskName << '\n'
                 << assignedTasks[i].taskDescription << '\n'
                 << assignedTasks[i].taskPriority << '\n';
        }
        file.close();
    }

    void loadFromFile() override {
        ifstream file("employees.txt");
        if (!file) {
            cerr << "Error opening employees.txt for reading.\n";
            return;
        }
        while (file >> employeeID) {
            file.ignore();
            getline(file, employeeName);
            getline(file, employeeRole);
            file >> assignedCount;
            file.ignore();
            for (int i = 0; i < assignedCount; i++) {
                file >> assignedTasks[i].taskID;
                file.ignore();
                getline(file, assignedTasks[i].taskName);
                getline(file, assignedTasks[i].taskDescription);
                file >> assignedTasks[i].taskPriority;
                file.ignore();
            }
            displayEmployeeDetails();
        }
        file.close();
    }

    friend void assignTaskToEmployee(const Task&, Employee&);
};

// ---------- Team Class ----------
class Team : public Project, public Employee {
protected:
    int teamID{};
    string teamName;
public:
    void setTeamDetails(int id, const string& name) {
        teamID = id;
        teamName = name;
    }

    void assignProjectToTeam(const Project& p) {
        projectID = p.projectID;
        projectName = p.projectName;
        projectDeadline = p.projectDeadline;
        taskCount = p.taskCount;
        for (int i = 0; i < taskCount; i++)
            taskList[i] = p.taskList[i];
    }

    void displayTeamDetails() const {
        cout << "\n[Team] ID: " << teamID << " | Name: " << teamName << endl;
        displayProjectDetails();
        displayEmployeeDetails();
    }

    void saveToFile() override {
        ofstream file("teams.txt", ios::app);
        if (!file) {
            cerr << "Error opening teams.txt for writing.\n";
            return;
        }
        file << teamID << '\n' << teamName << '\n';
        file << projectID << '\n' << projectName << '\n' << projectDeadline << '\n' << taskCount << '\n';
        for (int i = 0; i < taskCount; i++) {
            file << taskList[i].taskID << '\n'
                 << taskList[i].taskName << '\n'
                 << taskList[i].taskDescription << '\n'
                 << taskList[i].taskPriority << '\n';
        }
        file << employeeID << '\n' << employeeName << '\n' << employeeRole << '\n' << assignedCount << '\n';
        for (int i = 0; i < assignedCount; i++) {
            file << assignedTasks[i].taskID << '\n'
                 << assignedTasks[i].taskName << '\n'
                 << assignedTasks[i].taskDescription << '\n'
                 << assignedTasks[i].taskPriority << '\n';
        }
        file.close();
    }

    void loadFromFile() override {
        ifstream file("teams.txt");
        if (!file) {
            cerr << "Error opening teams.txt for reading.\n";
            return;
        }
        while (file >> teamID) {
            file.ignore();
            getline(file, teamName);
            file >> projectID;
            file.ignore();
            getline(file, projectName);
            getline(file, projectDeadline);
            file >> taskCount;
            file.ignore();
            for (int i = 0; i < taskCount; i++) {
                file >> taskList[i].taskID;
                file.ignore();
                getline(file, taskList[i].taskName);
                getline(file, taskList[i].taskDescription);
                file >> taskList[i].taskPriority;
                file.ignore();
            }
            file >> employeeID;
            file.ignore();
            getline(file, employeeName);
            getline(file, employeeRole);
            file >> assignedCount;
            file.ignore();
            for (int i = 0; i < assignedCount; i++) {
                file >> assignedTasks[i].taskID;
                file.ignore();
                getline(file, assignedTasks[i].taskName);
                getline(file, assignedTasks[i].taskDescription);
                file >> assignedTasks[i].taskPriority;
                file.ignore();
            }
            displayTeamDetails();
        }
        file.close();
    }
};

// ---------- TaskManager Class ----------
class TaskManager {
public:
    void updateTaskDetails(Task& t, int id, const string& name, const string& desc, int priority) {
        t.setTaskDetails(id, name, desc, priority);
    }

    void updateProjectDetails(Project& p, int id, const string& name, const string& deadline) {
        p.setProjectDetails(id, name, deadline);
    }

    void generateSummaryReport() {
        ifstream taskFile("tasks.txt"), projFile("projects.txt"), empFile("employees.txt"), teamFile("teams.txt");
        ofstream summary("summary.txt");
        if (!summary) {
            cerr << "Error opening summary.txt for writing.\n";
            return;
        }

        summary << "==== TASK MANAGEMENT SYSTEM SUMMARY ====\n\n";

        auto copyFileToSummary = [&](ifstream& src, const string& title) {
            summary << title << "\n";
            string line;
            while (getline(src, line))
                summary << line << '\n';
            summary << "\n";
        };

        if (taskFile.is_open()) copyFileToSummary(taskFile, "[Tasks]");
        if (projFile.is_open()) copyFileToSummary(projFile, "[Projects]");
        if (empFile.is_open()) copyFileToSummary(empFile, "[Employees]");
        if (teamFile.is_open()) copyFileToSummary(teamFile, "[Teams]");

        cout << "\n✅ Summary report generated successfully: summary.txt\n";
    }
};

// ---------- Friend Function ----------
void assignTaskToEmployee(const Task& t, Employee& e) {
    e.assignTask(t);
}

// ---------- Main Function ----------
int main() {
    Task t1(1, "Design", "System architecture design", 2);
    t1.saveToFile();

    Task t2(2, "Coding", "Implement core modules", 1);
    t2.saveToFile();

    Project p1;
    p1.setProjectDetails(101, "ProjectX", "2025-12-31");
    p1.addTaskToProject(t1);
    p1.addTaskToProject(t2);
    p1.saveToFile();

    Employee e1;
    e1.setEmployeeDetails(501, "Alice", "Developer");
    assignTaskToEmployee(t1, e1);
    assignTaskToEmployee(t2, e1);
    e1.saveToFile();

    Team team1;
    team1.setTeamDetails(1001, "Alpha Team");
    team1.assignProjectToTeam(p1);
    team1.setEmployeeDetails(502, "Bob", "Team Lead");
    team1.assignTask(t1);
    team1.saveToFile();

    cout << "\n--- Loading Data ---\n";
    cout << "\nTasks:"; Task().loadFromFile();
    cout << "\nProjects:"; Project().loadFromFile();
    cout << "\nEmployees:"; Employee().loadFromFile();
    cout << "\nTeams:"; Team().loadFromFile();

    TaskManager manager;
    manager.generateSummaryReport();

    return 0;
}
