#include <iostream>

using namespace std;

int getSelection();

int main()
{
    getSelection();

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