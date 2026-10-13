#include <iostream>
#include <limits>
#include "../include/System.h"

using namespace std;

int getSelection();
void processSelection(int selection);

int main()
{
    System system;
    int selection{};
    
   do {
       selection = getSelection();
       processSelection(selection);
   }
       
    while (selection != 0);
    return 0;
}

int getSelection()
{
    int selection;
    cout << "\n===== Campus Event Management System =====\n";
    cout << "1. Add Student" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Create Event" << endl;
    cout << "4. View Events" << endl;
    cout << "5. Search Events" << endl;
    cout << "6. Register Student for Event" << endl;
    cout << "7. Cancel Registration" << endl;
    cout << "8. View Student Registrations" << endl;
    cout << "9. View Event Attendees" << endl;
    cout << "10. View Organizers" << endl;
    cout << "11. System Reports" << endl;
    cout << "0. Exit" << endl;

    cout << "\nEnter selection: ";

    while (!(cin >> selection) || selection < 0 || selection > 11)
        {
            cout << "Invalid selection. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return selection;
}

void processSelection(int selection)
{
    switch (selection) {
        case 1:
            cout << "Add Student selected.\n";
            break;

        case 2:
            cout << "View Students selected.\n";
            break;

        case 3:
            cout << "Create Event selected.\n";
            break;

        case 4:
            cout << "View Events selected.\n";
            break;

        case 5:
            cout << "Search Events selected.\n";
            break;

        case 6:
            cout << "Register Student for Event selected.\n";
            break;

        case 7:
            cout << "Cancel Registration selected.\n";
            break;

        case 8:
            cout << "View Student Registrations selected.\n";
            break;

        case 9:
            cout << "View Event Attendees selected.\n";
            break;

        case 10:
            cout << "View Organizers selected.\n";
            break;

        case 11:
            cout << "System Reports selected.\n";
            break;

        case 0:
            cout << "Exiting program.\n";
            break;
    }
}
