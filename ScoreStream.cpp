#include <iostream>

using namespace std;

// New Line
 void nl (int n) {

    for (int i=1; i<=n; i++) {

        cout << endl;
    }
 }
// New Tab
 void nt (int n) {

    for (int i=1; i<=n; i++) {

        cout << "\t";
    }
 }

 void result (string studentName, int age, string gender, int math, int phy, int bio, int att) {
          
        cout << "     >>>     Student Result     <<<        " << endl;
        cout << " >> " << studentName << endl;
        cout << " >> " << age << endl;
        cout << " >> " << gender << endl;
        cout << "=---------------------------------------=" << endl;
        cout << "    Math  Physic   Biology   Attendant " << endl;
        cout << "    " << math << "    " << phy << "      " << bio << "         " << att << endl;
  }
 
 int main () {

// Addition System
    system ("cls");
    system ("color 9");

// Declearation
      int age, math, phy, bio, score, grade, avg, att;
      int main, adminChoice, studentChoice;
      string studentName, gender, passCode;
      char choiceInfo;

// Main Menu
      cout << "Welcome!" << endl;

      MAINMENU:
      cout << "1. Admin Panel" << endl;
      cout << "2. Student Panel" << endl;
      cout << "  >>  ";
      cin >> main;

      if (main == 1) {
        
        ADMINPANEL:
        cout << " >>> Admin Panel <<< " << endl;
        cout << "Passcode : ";
        cin >> passCode;

        if (passCode == "2112") {
          
          ADMINMENU:
          cout << "Welcome Admin!" << endl;
          cout << "1. Add Student Info" << endl;
          cout << "2. Remove Student Info" << endl;
          cout << "3. Subject Score" << endl;
          cout << "4. Back" << endl;
          cout << "  >>  ";
          cin >> adminChoice;

          switch (adminChoice) {

            case 1:
              
              cout << "Hello!" << endl;
              break;
            
            case 2:
              
              cout << "Empty" << endl;
              break;

            case 3:
              
              cout << "Empty" << endl;
              break;

            case 4:
              
              system ("cls");
              goto MAINMENU;
              break;

            default: 
              
              system ("cls");
              cout << "Invalid input. Try again..."; nl (2);
              goto ADMINMENU;
              break;
          }
        }
        else {
          
          system ("cls");
          cout << "Wrong Passcode. Try Again!!!"; nl (2);
          goto ADMINPANEL;
        }
      }
      else if (main == 2) {
        
        STUDENTMENU:
        cout << "Welcome Student!" << endl;
        cout << "1. Checking Result" << endl;
        cout << "2. School Info Update" << endl;
        cout << "3. Back " << endl;
        cout << "  >>  ";
        cin >> studentChoice;

        switch (studentChoice) {

            case 1:
              
              cout << "Empty" << endl;
              break;
            
            case 2:
              
              cout << "Empty" << endl;
              break;

            case 3:
              
              system ("cls");
              goto MAINMENU;
              break;

            default: 
              
              system ("cls");
              cout << "Invalid input. Try again!!!"; nl (2);
              goto STUDENTMENU;
              break;
          }
      }
      else {

        system ("cls");
        cout << "Invalid input. Try again"; nl(3);
        goto MAINMENU;
      }
// Admin Panel

// Student Panel
      INFO:
     nt(2); cout << " >>> Student INFO <<< "; nl (3);
      cout << "Student Name: ";
      cin >> studentName;
      cout << "Student Age: ";
      cin >> age;
      cout << "Student gender: ";
      cin >> gender;
      nl (3);

      CONFIRMINFO:
      cout << "Student Info Confirm? [y] Yes or [n] No." << endl;
      cout << " >>  ";
      cin >> choiceInfo;

      if (choiceInfo == 'Y' || choiceInfo == 'y') {

        goto SCORE;
      }
      else if (choiceInfo == 'N' || choiceInfo == 'n') {
        
        system ("cls");
        goto INFO;
      }
      else {

        cout << "Invalid Input. Please choose [y] to CONFIRM or [n] to Back to Student Info." << endl;
        goto CONFIRMINFO;

      }
// STUDENT's Score Panel
      SCORE:
      nt (2); cout << " >>> Student Score <<< "; nl (2);
      cout << "Math : ";
      cin >> math;
      cout << "Physic : ";
      cin >> phy;
      cout << "Biology : "; 
      cin >> bio;
      cout << "Attendant : ";
      cin >> att;

      cout << "Student Score Confirm? [y] Yes or [n] No." << endl;
      cout << " >>  ";
      cin >> choiceInfo;

      if (choiceInfo == 'Y' || choiceInfo == 'y') {

        score = math + phy + bio + att; 
        avg = score / 4;

        if (avg > 90) {

        system ("cls");
        
        result(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE A. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg > 80) {

        system ("cls");
        
        result(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE B. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg > 70) {

        system ("cls");
        
        result(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE C. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg > 60) {

        system ("cls");
        
        result(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE D. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg >= 50) {

        system ("cls");
        
        result(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE E. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else {

        system ("cls");
        
        result(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE F. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
  
      }
      else if (choiceInfo == 'N' || choiceInfo == 'n') {
        
        system ("cls");
        goto SCORE;
      }
      else {

        cout << "Invalid Input. Please choose [y] to CONFIRM or [n] to Back to Student Info." << endl;
        goto CONFIRMINFO;

    }  
    return 0;
 }