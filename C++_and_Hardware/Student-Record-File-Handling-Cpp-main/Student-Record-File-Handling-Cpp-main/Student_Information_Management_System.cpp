#include <iostream>
#include <fstream>
using namespace std;

// Structure to store student data
struct Student {
    char name[50];
    char enrollment[20];
    int semestersPassed;
    float cgpa;
    char courses[8][30]; // Up to 8 courses
};

// Function to read student data from a file
void readData(Student *students, int &count, const char *filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    count = 0;
    while (!file.eof()) {
        file >> students[count].name >> students[count].enrollment >> students[count].semestersPassed >> students[count].cgpa;
        for (int i = 0; i < 6; i++) {
            file >> students[count].courses[i];
        }
        count++;
    }
    file.close();
}

// Function to display student data
void displayData(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Enrollment: " << students[i].enrollment << endl;
        cout << "Semesters Passed: " << students[i].semestersPassed << endl;
        cout << "CGPA: " << students[i].cgpa << endl;
        cout << "Courses: ";
        for (int j = 0; j < 6; j++) {
            cout << students[i].courses[j] << " ";
        }
        cout << endl << endl;
    }
}

// Function to save data to file
void saveData(Student *students, int count, const char *filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        file << students[i].name << " " << students[i].enrollment << " " << students[i].semestersPassed << " " << students[i].cgpa << " ";
        for (int j = 0; j < 6; j++) {
            file << students[i].courses[j] << " ";
        }
        file << endl;
    }
    file.close();
}

int main() {
    Student *risStudents = new Student[50];
    Student *eeStudents = new Student[50];
    int risCount = 0, eeCount = 0;

    // Read RIS data
    readData(risStudents, risCount, "ris_students.txt");
    cout << "\nRIS Student Data:\n";
    displayData(risStudents, risCount);
    saveData(risStudents, risCount, "ris_output.txt");

    // Read EE data
    readData(eeStudents, eeCount, "ee_students.txt");
    cout << "\nEE Student Data:\n";
    displayData(eeStudents, eeCount);
    saveData(eeStudents, eeCount, "ee_output.txt");

    delete[] risStudents;
    delete[] eeStudents;

    return 0;
}
