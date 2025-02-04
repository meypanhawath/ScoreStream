#include <iostream>

using namespace std;

 void mainMenu();
 void adminPanel();
 void adminLogin();
 void studentPanel();
 void studentInfo(string studentName, int age, string gender);
 void studentScore();
 void studentGrade();
 void confirmChoice();
 void displayResult();
 void loadingBar();

 int main () {
     
     system ("cls");
     system ("color 9");
     mainMenu();

    return 0;
 }

 void mainMenu () {
    
          int menu;

    do {
      cout << " >>> SCORE STREAM <<< " << endl;
      cout << "=------------------=" << endl;
      cout << "| 1. Admin Panel   |" << endl;
      cout << "| 2. Student Panel |" << endl;
      cout << "| 3. Exit          |" << endl;
      cout << "=------------------=" << endl;
         
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
         _sleep(1500);
        system ("cls");
         break;
       }
    }while (menu > 3); 
 }

 void adminLogin () {

    const int passCode = 2112;
          int userPasscode = 0;

   do {
      cout << " ADMIN LOGIN " << endl;
      cout << "  Enter The Passcode " << endl;
      cout << "  >>  ";

      cin >> userPasscode;

       if (userPasscode == passCode) {
         
        system ("cls"); 
         cout << "Login Successfully!" << endl;

          adminPanel ();
       }
       else {
        
        system ("cls");
         cout << "Passcode not recognized. Try again." << endl;
         _sleep(1500);
        system ("cls");
       }
   }while(userPasscode != 2112);
 }

 void adminPanel () {

          int adminMenu;

   do {
      cout << " >>> ADMIN PANEL <<< " << endl;
      cout << "=---------------------=" << endl;
      cout << "| 1. Teacher Data     |" << endl;
      cout << "| 2. Add Teacher Data |" << endl;
      cout << "| 3. Student Data     |" << endl;
      cout << "| 4. Add Student Data |" << endl;
      cout << "| 5. Back             |" << endl;
      cout << "=---------------------=" << endl;

      cout << "  >>  ";
      cin >> adminMenu;

       switch (adminMenu) {

        case 1: 
        
        system ("cls");
         cout << " 1. Teacher Data " << endl;
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
         _sleep(1500);
        system ("cls");
         break;
       }
   }while(adminMenu > 6);
 }

  void studentPanel () {

          int studentMenu;

   do {
      cout << " >>> STUDENT PANEL <<< " << endl;
      cout << "=------------------------=" << endl;
      cout << "| 1. Checking The Result |" << endl;
      cout << "| 2. School Update       |" << endl;
      cout << "| 3. Back                |" << endl;
      cout << "=------------------------=" << endl;
          
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
         _sleep(1500);
        system ("cls");
         break;
       }
   }while(studentMenu > 4);
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
