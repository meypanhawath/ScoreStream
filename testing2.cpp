#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>
#include <thread>
#include <stdexcept>
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

// Get a valid string input (reads a full line)
string getValidString(const string &prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

// ----- Object Definitions -----

// Teacher class encapsulating teacher data
class Teacher {
public:
    string name;
    string subject;

    Teacher(const string &name, const string &subject)
        : name(name), subject(subject) {}

    // Convert teacher data to CSV format
    string toCSV() const {
        return name + "," + subject;
    }

    // Create a Teacher object from a CSV line
    static Teacher fromCSV(const string &csvLine) {
        stringstream ss(csvLine);
        string name, subject;
        getline(ss, name, ',');
        getline(ss, subject);
        return Teacher(name, subject);
    }
};

// Student class encapsulating student data
class Student {
public:
    string name;
    int age;
    string gender;

    Student(const string &name, int age, const string &gender)
        : name(name), age(age), gender(gender) {}

    // Convert student data to CSV format
    string toCSV() const {
        return name + "," + to_string(age) + "," + gender;
    }

    // Create a Student object from a CSV line
    static Student fromCSV(const string &csvLine) {
        stringstream ss(csvLine);
        string name, ageStr, gender;
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, gender);
        return Student(name, stoi(ageStr), gender);
    }
};

// FileManager class handles file-based persistence
class FileManager {
public:
    // Save a teacher record
    static void saveTeacher(const Teacher &teacher, const string &filename = "teachers.txt") {
        ofstream file(filename, ios::app);
        if (!file)
            throw runtime_error("Error opening teacher file.");
        file << teacher.toCSV() << "\n";
    }

    // Load all teacher records
    static vector<Teacher> loadTeachers(const string &filename = "teachers.txt") {
        vector<Teacher> teachers;
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (!line.empty())
                teachers.push_back(Teacher::fromCSV(line));
        }
        return teachers;
    }

    // Save a student record
    static void saveStudent(const Student &student, const string &filename = "students.txt") {
        ofstream file(filename, ios::app);
        if (!file)
            throw runtime_error("Error opening student file.");
        file << student.toCSV() << "\n";
    }

    // Load all student records
    static vector<Student> loadStudents(const string &filename = "students.txt") {
        vector<Student> students;
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (!line.empty())
                students.push_back(Student::fromCSV(line));
        }
        return students;
    }
};

// ----- SchoolSystem Class -----

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
            cout << ">>> SCORE STREAM <<<\n"
                 << "1. Admin Panel\n2. Student Panel\n3. Exit\n";
            int choice = getValidInt("Select an option: ", 1, 3);
            switch (choice) {
                case 1:
                    adminLogin();
                    break;
                case 2:
                    studentPanel();
                    break;
                case 3:
                    clearScreen();
                    cout << "Exiting...\n";
                    sleep_ms(1500);
                    return;
            }
        }
    }

    void adminLogin() {
        while (true) {
            clearScreen();
            int code = getValidInt("Enter Admin Passcode: ", 0, 10000);
            if (code == adminPasscode) {
                clearScreen();
                cout << "Login Successful!\n";
                sleep_ms(1500);
                adminPanel();
                return;
            } else {
                cout << "Incorrect Passcode. Try again.\n";
                sleep_ms(1500);
            }
        }
    }

    void adminPanel() {
        while (true) {
            clearScreen();
            cout << ">>> ADMIN PANEL <<<\n"
                 << "1. View Teacher Data\n2. Add Teacher Data\n"
                 << "3. View Student Data\n4. Add Student Data\n5. Back\n";
            int choice = getValidInt("Select an option: ", 1, 5);
            switch (choice) {
                case 1:
                    viewTeacherData();
                    break;
                case 2:
                    addTeacherData();
                    break;
                case 3:
                    viewStudentData();
                    break;
                case 4:
                    addStudentData();
                    break;
                case 5:
                    return;
            }
        }
    }

    void studentPanel() {
        while (true) {
            clearScreen();
            cout << ">>> STUDENT PANEL <<<\n"
                 << "1. Check Result\n2. School Update\n3. Back\n";
            int choice = getValidInt("Select an option: ", 1, 3);
            switch (choice) {
                case 1:
                    checkStudentResult();
                    break;
                case 2:
                    viewSchoolUpdate();
                    break;
                case 3:
                    return;
            }
        }
    }

    void addTeacherData() {
        clearScreen();
        string name = getValidString("Enter Teacher Name: ");
        string subject = getValidString("Enter Subject: ");
        Teacher teacher(name, subject);
        try {
            FileManager::saveTeacher(teacher);
            cout << "Teacher data saved successfully.\n";
        } catch (const exception &e) {
            cout << e.what() << "\n";
        }
        sleep_ms(1500);
    }

    void viewTeacherData() {
        clearScreen();
        vector<Teacher> teachers = FileManager::loadTeachers();
        cout << ">>> TEACHER DATA <<<\n";
        if (teachers.empty()) {
            cout << "No teacher data found.\n";
        } else {
            for (const auto &t : teachers) {
                cout << "Name: " << t.name << " | Subject: " << t.subject << "\n";
            }
        }
        cout << "\nPress enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void addStudentData() {
        clearScreen();
        string name = getValidString("Enter Student Name: ");
        int age = getValidInt("Enter Student Age: ", 1, 150);
        string gender = getValidString("Enter Student Gender: ");
        Student student(name, age, gender);
        try {
            FileManager::saveStudent(student);
            cout << "Student data saved successfully.\n";
        } catch (const exception &e) {
            cout << e.what() << "\n";
        }
        sleep_ms(1500);
    }

    void viewStudentData() {
        clearScreen();
        vector<Student> students = FileManager::loadStudents();
        cout << ">>> STUDENT DATA <<<\n";
        if (students.empty()) {
            cout << "No student data found.\n";
        } else {
            for (const auto &s : students) {
                cout << "Name: " << s.name << " | Age: " << s.age
                     << " | Gender: " << s.gender << "\n";
            }
        }
        cout << "\nPress enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void checkStudentResult() {
        clearScreen();
        string searchName = getValidString("Enter your name: ");
        vector<Student> students = FileManager::loadStudents();
        bool found = false;
        for (const auto &s : students) {
            if (s.name == searchName) {
                cout << "\nRecord Found:\n";
                cout << "Name: " << s.name << " | Age: " << s.age
                     << " | Gender: " << s.gender << "\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "\nNo record found for " << searchName << "\n";
        cout << "\nPress enter to continue...";
        cin.get();
    }

    void viewSchoolUpdate() {
        clearScreen();
        ifstream file("school_update.txt");
        cout << ">>> SCHOOL UPDATES <<<\n";
        if (file) {
            string line;
            while (getline(file, line))
                cout << line << "\n";
            file.close();
        } else {
            cout << "No school updates available.\n";
        }
        cout << "\nPress enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
};

int main() {
    SchoolSystem system;
    system.run();
    return 0;
}
