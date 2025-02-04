#include <iostream>

using namespace std;

// New Line
 void nl(int n);
// New Tap
 void nt(int n);

 void mainMenu(int menu);
 void adminPanel(int adminChoice);
 void studentPanel();
 void studentInfo();
 void studentScore();
 void studentGrade();
 void confirmChoice(char choiceInfo);
 void displayResult(string studentName, int age, string gender, int math, int phy, int bio, int att);
 
 int main () {

// Addition System
    system ("cls");
    system ("color 9");

// Declearation
      int age, math, phy, bio, score, grade, avg, att;
      int menu, adminChoice, studentChoice;
      string studentName, gender, passCode;
      char choiceInfo;
       
      mainMenu(menu);

          
    return 0;

 }

// Function New Line
 void nl (int n) {

    for (int i=1; i<=n; i++) {

        cout << endl;
    }
 }

// Function New Tap
  void nt (int n) {

    for (int i=1; i<=n; i++) {

        cout << "\t";
    }
  }

 void mainMenu (int menu) {
      
      MAINMENU:
      cout << " >>> ScoreStream <<< " << endl;
      cout << "1. Admin Panel" << endl;
      cout << "2. Student Panel" << endl;
      cout << "  >>  ";
      cin >> menu;

      if (menu == 1) {

        const int passCode = 2112;
        int userPasscode = 0;
        
        ADMINPASS:
        cout << "Enter Password" << endl;
        cout << "  >>  ";
        cin >> userPasscode;

          if (userPasscode == passCode) {

            adminPanel();
          }
          else {

            cout << "Invalid Password. Try again" << endl;
            goto ADMINPASS;
          }
      }
      else if (menu == 2) {

        studentPanel();
      }
      else {

        cout << "Invalid input. Try again" << endl;
        goto MAINMENU;
      }
 void adminPanel (int adminChoice) {

      int adminChoice;

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
              
              cout << "Empty" << endl;
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

 void studentPanel () {

   int studentChoice;

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
 void studentInfo (string studentName, int age, string gender) {

    nt(2); cout << " >>> Student INFO <<< "; nl (3);
      cout << "Student Name: ";
      cin >> studentName;
      cout << "Student Age: ";
      cin >> age;
      cout << "Student gender: ";
      cin >> gender;
      nl (3);

    confirmChoice();
 }

 void studentScore (int math, int phy, int bio, int att) {

    nt (2); cout << " >>> Student Score <<< "; nl (2);
      cout << "Math : ";
      cin >> math;
      cout << "Physic : ";
      cin >> phy;
      cout << "Biology : "; 
      cin >> bio;
      cout << "Attendant : ";
      cin >> att;

    confirmChoice();
 }

 void confirmChoice (char choiceInfo) {
 
      CONFIRM:
      cout << "Student Info Confirm? [y] Yes or [n] No." << endl;
      cout << " >>  ";
      cin >> choiceInfo;

      if (choiceInfo == 'Y' || choiceInfo == 'y') {
             
             system ("cls");
             studentScore();
      }
      else if (choiceInfo == 'N' || choiceInfo == 'n') {
        
        system ("cls");
      }
      else {

        cout << "Invalid Input. Please choose [y] to CONFIRM or [n] to Back to Student Info." << endl;
        goto CONFIRM;
      }

 }
// Function Display Result
 void displayResult (string studentName, int age, string gender, int math, int phy, int bio, int att) {

        cout << "     >>>     Student Result     <<<        " << endl;
        cout << " >> Name   : " << studentName << endl;
        cout << " >> Age    : " << age << endl;
        cout << " >> Gender : " << gender << endl;
        cout << "=---------------------------------------=" << endl;
        cout << "    Math  Physic   Biology   Attendant " << endl;
        cout << "    " << math << "    " << phy << "      " << bio << "         " << att << endl;
 }
  
  void studentGrade (int score, int avg) {

        score = math + phy + bio + att; 
        avg = score / 4;

        if (avg >= 90) {

        system ("cls");

        displayResult(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE A. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg >= 80) {

        system ("cls");
        
        displayResult(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE B. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg >= 70) {

        system ("cls");
        
        displayResult(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE C. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg >= 60) {

        system ("cls");
        
        displayResult(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE D. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else if (avg >= 50) {

        system ("cls");
        
        displayResult(studentName, age, gender, math, phy, bio, att);
        cout << " Congratulation, You're passed GRADE E. " << endl;
        cout << "=---------------------------------------=" << endl;
    }
    else {

        system ("cls");
        
        displayResult(studentName, age, gender, math, phy, bio, att);
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
  }
 