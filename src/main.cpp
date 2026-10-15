#include <iostream>
#include <limits>
#include "../include/System.h"
#include "../include/ReportManager.h"
#include "../include/EventSystem.h"
#include "../include/RegistrationManager.h"

using namespace std;

int getSelection();
void processSelection(int selection,
EventSystem& events,
RegistrationManager& registrations);

int main()
{
    System system;
    
    EventSystem events;
    RegistrationManager registrations;
    
    int selection{};
    
   do {
       selection = getSelection();
       processSelection(selection, events, registrations);
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

void processSelection(int selection,
EventSystem& events,
RegistrationManager& registrations)
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
        {
            cout<<"===== Register Student for an Event =====" << endl;

            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter event ID: ";
            cin >> eventID; 
 
            // addRegistration needs the event's max capacity, so look the event up first
            int maxCapacity = -1;
            for (const auto& e : *events.getEventsPointer())
            {
                if (e->getEventId() == eventID)
                {
                    maxCapacity = e->getEventMaxCapacity();
                }
            }
            if (maxCapacity == -1)
            {
                cout << "No event found with that ID.\n";
                break;
            }
 
            // the registration date, typed in by the user
            string date;
            cout << "Enter registration date (YYYY-MM-DD): ";
            cin >> date;
 
            if (registrations.addRegistration(Registration(studentID, eventID, date, true), maxCapacity))
                cout << "Student registered.\n";
            else if (registrations.isRegistered(studentID, eventID))
                cout << "Student is already registered for this event.\n";
            else
                cout << "This event is full.\n";
            break;
        }
 
        case 7:
        {
            cout << "===== Cancel Registration =====" << endl;
            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter event ID: ";
            cin >> eventID;
            cout << endl;
            
            if (registrations.cancelRegistration(studentID, eventID))
                cout << "Registration cancelled.\n";
            else
                cout << "No active registration found.\n";
            break;
        }
 
        case 8:
        {
            cout << "===== View Student Registrations =====" << endl;
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << endl;
            
            vector<int> eventIDs = registrations.getEventIDsForStudent(studentID);
            if (eventIDs.empty())
                cout << "No registrations found.\n";
            for (int id : eventIDs)
                cout << "  - Event " << id << "\n";
            break;
        }
 
        case 9:
        {
            cout << "===== View Event Attendee =====" << endl;
            int eventID;
            cout << "Enter event ID: ";
            cin >> eventID;
            cout << endl;
            
            vector<int> studentIDs = registrations.getStudentIDsForEvent(eventID);
            if (studentIDs.empty())
                cout << "No students registered.\n";
            for (int id : studentIDs)
                cout << "  - Student " << id << "\n";
            break;
        }
 
        case 10:
            cout << "View Organizers selected.\n";
            break;
 
    case 11:
{
    cout << "\n===== System Reports =====\n";
 
    ReportManager reports;
 
    cout << "1. Available Events\n";
    cout << "2. Full Events\n";
    cout << "3. Registration Counts\n";
    cout << "4. Most Popular Event\n";
 
    cout << "\nReport selection: ";
 
    int reportChoice;
    if (!(cin >> reportChoice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid report selection.\n";
        break;
    }
 
    const auto& eventList = *events.getEventsPointer();
 
    switch (reportChoice) {
        case 1:
            reports.showAvailableEvents(eventList, registrations);
            break;
 
        case 2:
            reports.showFullEvents(eventList, registrations);
            break;
 
        case 3:
            reports.showRegistrationCounts(eventList, registrations);
            break;
 
        case 4:
            reports.showMostPopularEvent(eventList, registrations);
            break;
        
 
        default:
            cout << "Invalid report selection.\n";
    }
 
    break;
}
        
 
        case 0:
            cout << "Exiting program.\n";
            break;
    }
}