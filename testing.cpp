#include <iostream>
#include <limits>
#include <fstream>
#include <chrono>
#include <thread>
#ifdef _WIN32
    #include <cstdlib>
#endif

using namespace std;

// Function prototypes
void clearScreen();
void sleep_ms(int ms);
int getValidInput(int min, int max);
void mainMenu();
void adminLogin();
void adminPanel();
void studentPanel();
void addTeacherData();
void viewTeacherData();
void addStudentData();
void viewStudentData();
void checkStudentResult();
void viewSchoolUpdate();

// Cross-platform function to clear the screen
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

// Get a valid integer input within a given range
int getValidInput(int min, int max) {
    int choice;
    while (true) {
        if (cin >> choice) {
            if (choice >= min && choice <= max)
                break;
            else
                cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}

int main() {
    clearScreen();
    mainMenu();
    return 0;
}

// Main menu
void mainMenu() {
    int menu = 0;
    while (true) {
        clearScreen();
        cout << ">>> SCORE STREAM <<<" << endl;
        cout << "=------------------=" << endl;
        cout << "| 1. Admin Panel   |" << endl;
        cout << "| 2. Student Panel |" << endl;
        cout << "| 3. Exit          |" << endl;
        cout << "=------------------=" << endl;
        cout << ">> ";
        menu = getValidInput(1, 3);

        switch (menu) {
            case 1:
                adminLogin();
                break;
            case 2:
                studentPanel();
                break;
            case 3:
                clearScreen();
                cout << "Exiting..." << endl;
                sleep_ms(1500);
                return; // Exit the program
        }
    }
}

// Admin login with passcode validation
void adminLogin() {
    const int passCode = 2112;
    int userPasscode;
    while (true) {
        clearScreen();
        cout << ">>> ADMIN LOGIN <<<" << endl;
        cout << "Enter The Passcode: ";
        if (cin >> userPasscode) {
            if (userPasscode == passCode) {
                clearScreen();
                cout << "Login Successfully!" << endl;
                cout << "Please wait..." << endl;
                sleep_ms(1500);
                adminPanel();
                return;
            } else {
                clearScreen();
                cout << "Passcode not recognized. Try again." << endl;
                sleep_ms(1500);
            }
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sleep_ms(1500);
        }
    }
}

// Admin panel with options for teacher and student data management
void adminPanel() {
    int adminMenu = 0;
    while (true) {
        clearScreen();
        cout << ">>> ADMIN PANEL <<<" << endl;
        cout << "=---------------------=" << endl;
        cout << "| 1. View Teacher Data     |" << endl;
        cout << "| 2. Add Teacher Data      |" << endl;
        cout << "| 3. View Student Data     |" << endl;
        cout << "| 4. Add Student Data      |" << endl;
        cout << "| 5. Back                  |" << endl;
        cout << "=---------------------=" << endl;
        cout << ">> ";
        adminMenu = getValidInput(1, 5);

        switch (adminMenu) {
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
                return; // Return to main menu
        }
    }
}

// Student panel with options for checking results and viewing school updates
void studentPanel() {
    int studentMenu = 0;
    while (true) {
        clearScreen();
        cout << ">>> STUDENT PANEL <<<" << endl;
        cout << "=------------------------=" << endl;
        cout << "| 1. Check Result        |" << endl;
        cout << "| 2. School Update       |" << endl;
        cout << "| 3. Back                |" << endl;
        cout << "=------------------------=" << endl;
        cout << ">> ";
        studentMenu = getValidInput(1, 3);

        switch (studentMenu) {
            case 1:
                checkStudentResult();
                break;
            case 2:
                viewSchoolUpdate();
                break;
            case 3:
                return; // Return to main menu
        }
    }
}

// Function to add teacher data (saves to teachers.txt)
void addTeacherData() {
    clearScreen();
    string name, subject;
    
    // Clear any leftover newline characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << ">>> ADD TEACHER DATA <<<" << endl;
    cout << "Enter Teacher Name: ";
    getline(cin, name);
    cout << "Enter Subject: ";
    getline(cin, subject);
    
    ofstream file("teachers.txt", ios::app);
    if (file) {
        file << name << "," << subject << "\n";
        cout << "Teacher data saved successfully." << endl;
    } else {
        cout << "Error opening file to save teacher data." << endl;
    }
    sleep_ms(1500);
}

// Function to view teacher data from teachers.txt
void viewTeacherData() {
    clearScreen();
    ifstream file("teachers.txt");
    string line;
    cout << ">>> TEACHER DATA <<<" << endl;
    if (file) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No teacher data found." << endl;
    }
    cout << "\nPress enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Function to add student data (saves to students.txt)
void addStudentData() {
    clearScreen();
    string name, gender;
    int age;
    
    // Clear any leftover newline characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << ">>> ADD STUDENT DATA <<<" << endl;
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Age: ";
    while (!(cin >> age)) {
        cout << "Invalid input. Please enter a valid number for age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Student Gender: ";
    getline(cin, gender);
    
    ofstream file("students.txt", ios::app);
    if (file) {
        file << name << "," << age << "," << gender << "\n";
        cout << "Student data saved successfully." << endl;
    } else {
        cout << "Error opening file to save student data." << endl;
    }
    sleep_ms(1500);
}

// Function to view student data from students.txt
void viewStudentData() {
    clearScreen();
    ifstream file("students.txt");
    string line;
    cout << ">>> STUDENT DATA <<<" << endl;
    if (file) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No student data found." << endl;
    }
    cout << "\nPress enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Function for a student to check their result by searching their name in students.txt
void checkStudentResult() {
    clearScreen();
    string searchName;
    
    // Clear any leftover newline characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << ">>> CHECK RESULT <<<" << endl;
    cout << "Enter your name: ";
    getline(cin, searchName);
    
    ifstream file("students.txt");
    string line;
    bool found = false;
    if (file) {
        while (getline(file, line)) {
            // Assuming the record format is: name,age,gender
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string name = line.substr(0, pos);
                if (name == searchName) {
                    cout << "\nRecord Found:" << endl;
                    cout << line << endl;
                    found = true;
                    break;
                }
            }
        }
        file.close();
        if (!found)
            cout << "\nNo record found for " << searchName << endl;
    } else {
        cout << "No student data available." << endl;
    }
    cout << "\nPress enter to continue...";
    cin.get();
}

// Function to view school updates by reading from school_update.txt
void viewSchoolUpdate() {
    clearScreen();
    ifstream file("school_update.txt");
    cout << ">>> SCHOOL UPDATES <<<" << endl;
    if (file) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No school updates available." << endl;
    }
    cout << "\nPress enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
