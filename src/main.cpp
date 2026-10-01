#include <iostream>
#include "../include/StudentManagement.h"
#include "../include/Student.h"

using namespace std;

int getSelection();
void processSelection(int selection);

int main()
{
    StudentManagement studentManagement;
    int selection{};
    
    selection = getSelection();
    processSelection(selection);

    return 0;
}

int getSelection() {
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

    cout << endl << "Enter selection: ";
    int selection;
    cin >> selection;

    while (selection < 0 || selection > 11) {
        cout << "Invalid selection. Please try again: ";
        cin >> selection;
    }
    return selection;
}

void processSelection(int selection) {
    switch (selection) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 0:
            cout << "Exiting program." << endl;
            exit(0);
    }
}