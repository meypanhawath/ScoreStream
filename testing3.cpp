#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#ifdef _WIN32
    #include <cstdlib>
#endif

using namespace std;

// Cross-platform screen clear function
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Sleep for a given number of milliseconds
void sleep_ms(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Get a valid integer input within a specified range
int getValidInt(const string &prompt, int min, int max) {
    int choice;
    while (true) {
        cout << prompt;
        if (cin >> choice) {
            if (choice >= min && choice <= max)
                break;
            else
                cout << "Please enter a number between " << min << " and " << max << ".\n";
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
    return choice;
}

// Get a valid string input
string getValidString(const string &prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

// ----- Class Definitions -----
class User {
public:
    string name;
    User(const string &name) : name(name) {}
    virtual string toCSV() const = 0;
};

class Teacher : public User {
public:
    string subject;
    Teacher(const string &name, const string &subject) : User(name), subject(subject) {}
    string toCSV() const override {
        return name + "," + subject;
    }
};

class Student : public User {
public:
    int age;
    string gender;
    unordered_map<string, int> grades; // subject -> grade
    
    Student(const string &name, int age, const string &gender) : User(name), age(age), gender(gender) {}
    string toCSV() const override {
        stringstream ss;
        ss << name << "," << age << "," << gender;
        for (const auto &g : grades) {
            ss << "," << g.first << "-" << g.second;
        }
        return ss.str();
    }
    void addGrade(const string &subject, int grade) {
        grades[subject] = grade;
    }
};

// FileManager for handling data persistence
class FileManager {
public:
    static void saveUser(const User &user, const string &filename) {
        ofstream file(filename, ios::app);
        if (!file) throw runtime_error("Error opening file.");
        file << user.toCSV() << "\n";
    }
};

// ----- School System -----
class SchoolSystem {
private:
    const int adminPasscode = 2112;
public:
    void run() {
        mainMenu();
    }
private:
    void mainMenu() {
        while (true) {
            clearScreen();
            cout << "\n>>> SCHOOL SYSTEM <<<\n";
            cout << "1. Admin Panel\n2. Student Panel\n3. Exit\n";
            int choice = getValidInt("Select an option: ", 1, 3);
            switch (choice) {
                case 1: adminLogin(); break;
                case 2: studentPanel(); break;
                case 3: return;
            }
        }
    }
    
    void adminLogin() {
        int code = getValidInt("Enter Admin Passcode: ", 0, 9999);
        if (code == adminPasscode) {
            cout << "Login Successful!\n";
            sleep_ms(1000);
            adminPanel();
        } else {
            cout << "Incorrect Passcode.\n";
            sleep_ms(1000);
        }
    }
    
    void adminPanel() {
        while (true) {
            clearScreen();
            cout << "\n>>> ADMIN PANEL <<<\n";
            cout << "1. Add Teacher\n2. Add Student\n3. Back\n";
            int choice = getValidInt("Select an option: ", 1, 3);
            switch (choice) {
                case 1: addTeacher(); break;
                case 2: addStudent(); break;
                case 3: return;
            }
        }
    }
    
    void studentPanel() {
        clearScreen();
        cout << "Student Panel Coming Soon...\n";
        sleep_ms(1500);
    }
    
    void addTeacher() {
        string name = getValidString("Enter Teacher Name: ");
        string subject = getValidString("Enter Subject: ");
        Teacher teacher(name, subject);
        FileManager::saveUser(teacher, "teachers.txt");
        cout << "Teacher data saved successfully.\n";
        sleep_ms(1000);
    }
    
    void addStudent() {
        string name = getValidString("Enter Student Name: ");
        int age = getValidInt("Enter Age: ", 5, 100);
        string gender = getValidString("Enter Gender: ");
        Student student(name, age, gender);
        FileManager::saveUser(student, "students.txt");
        cout << "Student data saved successfully.\n";
        sleep_ms(1000);
    }
};

int main() {
    SchoolSystem system;
    system.run();
    return 0;
}
