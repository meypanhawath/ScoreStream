#include <iostream>

using namespace std;


 int main () {

    system ("cls");

        char choice;
        cout << " [y] Yes/No [n]" << endl;
        cout << "  >>  ";
        cin >> choice;
           while (choice != 'y') {

            cout << "Wrong Password" << endl;
            break;
            
           }


    return 0;
 }