#include <iostream>

using namespace std;


 void mainMenu();
 void adminPanel();
 void adminLogin();
 void studentPanel();
 void studentInfo();
 void studentScore();
 void studentGrade();
 void confirmChoice();
 void displayResult();

 int main () {
     
     system ("cls");

     mainMenu();

    return 0;
 }

 void mainMenu () {
    
    MAINMENU:
      cout << " >>> SCORE STREAM <<< " << endl;
      cout << "=------------------=" << endl;
      cout << "| 1. Admin Panel   |" << endl;
      cout << "| 2. Student Panel |" << endl;
      cout << "| 3. Exit          |" << endl;
      cout << "=------------------=" << endl;
         
         int menu;
      cout << "  >>  ";
      cin >> menu;

       if (menu == 1) {
        
        system ("cls");
         adminLogin();
       }
       else if (menu == 2) {
        
        system ("cls");
         studentPanel ();
       }
       else if (menu == 3) {
        
        system ("cls");
         cout << "Exiting..." << endl;
       }
       else {
        
        system ("cls");
         cout << "Invalid Option. Try Again." << endl;
         goto MAINMENU;

       }
 }

 void adminLogin () {

    ADMINLOGIN:
      cout << " ADMIN LOGIN " << endl;
      cout << "  Enter The Passcode " << endl;
      cout << "  >>  ";

         const int passCode = 2112;
         int userPasscode = 0;
      cin >> userPasscode;

       if (userPasscode == passCode) {
         
        system ("cls"); 
         cout << "Login Successfully!" << endl;

          adminPanel ();
       }
       else {
        
        system ("cls");
         cout << "Passcode not recognized. Try again." << endl;
         goto ADMINLOGIN;
       }

 }

 void adminPanel () {
         
         
      cout << " >>> ADMIN PANEL <<< " << endl;
      cout << "=---------------------=" << endl;
      cout << "| 1. Teacher Data     |" << endl;
      cout << "| 3. Add Teacher Data |" << endl;
      cout << "| 2. Student Data     |" << endl;
      cout << "| 4. Add Student Data |" << endl;
      cout << "| 5. Back             |" << endl;
      cout << "=---------------------=" << endl;

         int adminMenu; 
      cout << "  >>  ";
      cin >> adminMenu;
 }

  void studentPanel () {

      cout << " >>> STUDENT PANEL <<< " << endl;
      cout << "=------------------------=" << endl;
      cout << "| 1. Checking The Result |" << endl;
      cout << "| 2. School Update       |" << endl;
      cout << "| 3. Back                |" << endl;
      cout << "=------------------------=" << endl;
          
          int studentMenu;
      cout << "  >>  ";
      cin >> studentMenu;
  }