#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <windows.h>
#include <time.h>

// Define Color Code
#define RESET "\033[0m"
#define RED "\033[91m"
#define CYAN "\033[36m"
#define BLUE "\033[94m"
#define GREEN "\033[32m"

using namespace std;

// Function
 void mainMenu();
 void adminPanel();
 void adminLogin();
 void studentPanel();
 void studentInfo(string studentName, int age, string gender);
 void studentScore();
 void studentGrade();
 void confirmChoice();
 void displayResult();

// additional Function
 void loadingBar();
 void sleep(int ms);
 void cls();
 void pause();
 void nl(int n);
 void t(int n);

// Class Student
 class student {
    
     int studentID;
     string studentName;
     int studentAge;
     string studentGender;
      
      struct score {
          
          int math;
          int physic;
          int chemistry;
          int attendance; 
     } score;
 };

// Class Teacher
 class teacher {

     int teacherID;
     string teacherName;
     string gender;
     string teacherSubject;
     int teacherSalary;
 };

// Main Function
 int main () {
     
     cls();
     cout << BLUE;

     loadingBar();
     mainMenu();

    return 0;
 }

 void mainMenu () {
    
          int menu;
          int delay = 3;

    do {
      nl(2); t(8); cout << "  >>> SCORE STREAM <<< " << endl;
      nl(1); t(7); cout << "========================================" << endl;
      t(8); cout << "=------------------=" << endl;
      t(8); cout << "| 1. Admin Panel   |" << endl;
      t(8); cout << "| 2. Student Panel |" << endl;
      t(8); cout << "| 3. Exit          |" << endl;
      t(8); cout << "=------------------=" << endl;
         
      nl(2); t(4); cout << "  >>  ";
      cin >> menu;

       switch (menu) {

        case 1:

        cls();
         adminLogin();
         break;

        case 2:

        cls();
         studentPanel();
         break;

        case 3:
        
        cls();
                         cout << RED;
            nl(8); t(9); cout << "Exiting";
          for (int i = 1; i <= delay; i++) {

                cout << ".";
             sleep(1500);
          }
         break;

        default:
        
         cout << RED;
         nl(2); t(4); cout << "Invalid Option." << endl;
                t(4); cout << "Try again." << endl;
         sleep(1500);
         cout << BLUE;
        cls();
         break;
       }
    }while (menu < 1 || menu > 3); 
 }

 void adminLogin () {

    const int passCode = 2112;
          int userPasscode = 0;

   do {
      nl(2); t(10); cout << "  ADMIN LOGIN " << endl;
      nl(1); t(9); cout << "===============================" << endl;
      nl(3); t(4); cout << "  Enter The Passcode " << endl;
      nl(1); t(5); cout << "  >>  ";

      cin >> userPasscode;

       if (userPasscode == passCode) {
         
         cout << GREEN;
         nl(2); t(4); cout << "Login Successfully!" << endl;
                t(4); cout << "Please wait..." << endl;
         sleep(1500);
         cout << BLUE;
        cls();

          adminPanel ();
       }
       else {
        
         cout << RED;
         nl(2); t(4); cout << "Invalid Passcode." << endl;
                t(4); cout << "Try again." << endl;
         sleep(1500);
         cout << BLUE;
        cls();
       }
   }while(userPasscode != 2112);
 }

 void adminPanel () {

          int adminMenu;

   do {
      nl(2); t(9); cout << "  >>> ADMIN PANEL <<< " << endl;
      nl(1); t(8); cout << "=======================================" << endl;
      t(9); cout << "=---------------------=" << endl;
      t(9); cout << "| 1. Teacher Data     |" << endl;
      t(9); cout << "| 2. Add Teacher Data |" << endl;
      t(9); cout << "| 3. Student Data     |" << endl;
      t(9); cout << "| 4. Add Student Data |" << endl;
      t(9); cout << "| 5. Back             |" << endl;
      t(9); cout << "=---------------------=" << endl;

      nl(2); t(4); cout << "  >>  ";
      cin >> adminMenu;

       switch (adminMenu) {

        case 1: 
        
        cls();
         cout << " 1. Teacher Data " << endl;
         break;

        case 2:
        
        cls();
         cout << " 2. Add Teacher Data" << endl;
         break;

        case 3:
        
        cls();
         cout << " 3. Student Data" << endl;
         break;

        case 4:
        
        cls();
         cout << " 4. Add Student Data" << endl;
         break;

        case 5:
         
        cls();
         mainMenu();
         break;

        default:
      
         cout << RED;
         nl(2); t(4); cout << "Invalid Option." << endl;
                t(4); cout << "Try again." << endl;
         sleep(1500);
         cout << BLUE;
        cls();
         break;
       }
   }while(adminMenu < 1 || adminMenu > 6);
 }

  void studentPanel () {

          int studentMenu;

   do {
      nl(2); t(8); cout << "  >>> STUDENT PANEL <<< " << endl;
      nl(1); t(7); cout << "=========================================" << endl;
      t(8); cout << "=------------------------=" << endl;
      t(8); cout << "| 1. Checking The Result |" << endl;
      t(8); cout << "| 2. School Update       |" << endl;
      t(8); cout << "| 3. Back                |" << endl;
      t(8); cout << "=------------------------=" << endl;
           
      nl(2); t(4); cout << "  >>  ";
      cin >> studentMenu;

       switch (studentMenu) {

        case 1: 

        cls();  
         cout << " 1. Teacher Data" << endl;
         break;

        case 2:
        
        cls();
         cout << " 2. Add Teacher Data" << endl;
         break;

        case 3:
         
        cls(); 
         mainMenu();
         break;

        default:

         cout << RED;
         nl(2); t(4); cout << "Invalid Option." << endl;
                t(4); cout << "Try again." << endl;
         sleep(1500);
         cout << BLUE;
        cls();
         break;
       }
   }while(studentMenu < 1 || studentMenu > 4);
  }

 void studentInfo (string studentName, int age, string gender) {
       
       cout << " >>> Student Info <<< " << endl;
       cout << " Student Name : ";
       cin >> studentName; cout << endl;
       cout << "Student Age : ";
       cin >> age; cout << endl;
       cout << "Student Gender : ";
       cin >> gender; cout << gender;
 }

 void studentScore (int math, int physic, int chemistry, int attendance) {

       cout << " >>> Student Result <<< " << endl;
       cout << " Math : ";
       cin >> math; cout << endl;
       cout << " Physic : ";
       cin >> physic; cout << endl;
       cout << " Chemistry : " << endl;
       cin >> chemistry; cout << endl;
       cout << " Attendance: " << endl;
       cin >> attendance; cout << endl;
       
 }
 void cls () {

   #ifdef _WIN32
    system("cls");
   #else
    system("clear");
   #endif
 }

 void sleep (int ms) {

   this_thread::sleep_for(chrono::milliseconds(ms));
 }

 void loadingBar () {
	
	SetConsoleCP(450);
    SetConsoleOutputCP(450);
    nl(8); t(8); cout << "   This program is being built by Raz." << endl;
    int bar1 = 15, bar2 = 219;

       nl(8); t(10); cout <<" LOADING";
       nl(3); t(9);

    for (int i=0; i<25; i++)
       cout << (char)bar1;
       cout <<"\r";t(9);
       
       for (int i=0; i<25; i++){

        cout <<(char)bar2;
        sleep(75);
       }
       
    pause();
    cls();
}

 void pause () {
	
	nl(3); t(8); cout << (char)1 <<" >>  ";
    system("Pause");
}

 void nl (int n) {

   for (int i=1; i<=n; i++) {

     cout << endl;
   }
 }
 
 void t (int n) {

   for (int i=1; i<=n; i++) {

     cout << "\t";
   }
 }