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

       switch (menu) {

        case 1:

        system ("cls");
         adminLogin();
         break;

        case 2:

        system ("cls");
         studentPanel();
         break;

        case 3:
        
        system ("cls");
         cout << "Exiting..." << endl;
         break;

        default:
        
        system ("cls");
         cout << "Invalid Option. Try Again." << endl;
         goto MAINMENU;
         break;
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
         
    ADMINPANEL:   
      cout << " >>> ADMIN PANEL <<< " << endl;
      cout << "=---------------------=" << endl;
      cout << "| 1. Teacher Data     |" << endl;
      cout << "| 2. Add Teacher Data |" << endl;
      cout << "| 3. Student Data     |" << endl;
      cout << "| 4. Add Student Data |" << endl;
      cout << "| 5. Back             |" << endl;
      cout << "=---------------------=" << endl;

         int adminMenu; 
      cout << "  >>  ";
      cin >> adminMenu;

       switch (adminMenu) {

        case 1: 
        
        system ("cls");
         cout << " 1. Teacher Data" << endl;
         break;

        case 2:
        
        system ("cls");
         cout << " 2. Add Teacher Data" << endl;
         break;

        case 3:
        
        system ("cls");
         cout << " 3. Student Data" << endl;
         break;

        case 4:
        
        system ("cls");
         cout << " 4. Add Student Data" << endl;
         break;

        case 5:
         
        system ("cls");
         mainMenu();
         break;

        default:
        
        system ("cls");
         cout << "Invalid Option. Try Again" << endl;
         goto ADMINPANEL;
         break;
       }
 }

  void studentPanel () {

    STUDENTPANEL:
      cout << " >>> STUDENT PANEL <<< " << endl;
      cout << "=------------------------=" << endl;
      cout << "| 1. Checking The Result |" << endl;
      cout << "| 2. School Update       |" << endl;
      cout << "| 3. Back                |" << endl;
      cout << "=------------------------=" << endl;
          
          int studentMenu;
      cout << "  >>  ";
      cin >> studentMenu;

       switch (studentMenu) {

        case 1: 

        system ("cls");  
         cout << " 1. Teacher Data" << endl;
         break;

        case 2:
        
        system ("cls");
         cout << " 2. Add Teacher Data" << endl;
         break;

        case 3:
         
        system ("cls"); 
         mainMenu();

        default:

        system ("cls");
         cout << "Invalid Option. Try Again" << endl;
         goto STUDENTPANEL;
         break;
       }
  }