#include <iostream>
#include <limits>
#include "../include/System.h"
#include "../include/AcademicEvent.h"
#include "../include/CareerEvent.h"
#include "../include/ClubEvent.h"
#include "../include/SocialEvent.h"

using namespace std;

int getSelection();
void processSelection(int selection, System& system);
void clearScreen();

int main()
{
    System system;
    
    int selection{};

   do {
       selection = getSelection();
       processSelection(selection, system);
   }

    while (selection != 0);
    return 0;
}
//clears screen to keep things organized
void clearScreen() {
    system("cls"); //only works in windows console
}

int getSelection()
{
    int selection;
    cout << endl << "Campus Event Management System" << endl;
    cout << "1). Add Student" << endl;
    cout << "2). View Students" << endl;
    cout << "3). Create Event" << endl;
    cout << "4). View Events" << endl;
    cout << "5). Search Events" << endl;
    cout << "6). Register Student for Event" << endl;
    cout << "7). Cancel Registration" << endl;
    cout << "8). View Student Registrations" << endl;
    cout << "9). View Event Attendees" << endl;
    cout << "10). View Organizers" << endl;
    cout << "11). System Reports" << endl;
    cout << "0). Exit" << endl;

    cout << endl << "Enter selection: ";

    while (!(cin >> selection) || selection < 0 || selection > 11)
        {
            cout << "Invalid selection. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return selection;
}

void processSelection(int selection, System& system)
{
    switch (selection) {
        case 1: {

            clearScreen();

            string c1name{};
            string c1email{};
            string c1major{};
            int c1id{};
            int c1majorselection{};
            string majorList[] = {"Biology","Business","Chemistry",
                "Computer Science","Economics","Engineering",
                "English","Mathematics","Physics","Psychology"};
            // The size of the array in bytes divided by the number of bytes in a single element.
            const int numMajors = sizeof(majorList) / sizeof(majorList[0]);

            cout << "Student name: ";
            getline(cin, c1name);
            cout << "Student email: ";
            getline(cin, c1email);

            cout << "List of majors:" << endl;
            for (int i = 0; i < numMajors; i++) {
                cout << i + 1 << "). " << majorList[i] << endl;
            }

            cout << endl << "Major: ";
            while (!(cin >> c1majorselection) || c1majorselection < 1 || c1majorselection > numMajors) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid selection." << endl;
                cout << "Major: ";
            }

            c1major = majorList[c1majorselection - 1];

            const auto& students = system.students.getStudentVector();
            if (!students.empty()) {
                c1id = students.back().getId() + 1;
            }
            else {
                c1id = 100;
            }

            if (!system.students.isDuplicateId(c1id)) {
                system.students.addStudent(c1id, c1name, c1email, c1major);
            }
            else {
                cerr << "Error: Duplicate student ID." << endl;
            }
            break;
        }
        case 2: {

            clearScreen();

            string c2name{};
            int c2id{};
            int c2selection{};

            cout << "1). View specific student" << endl;
            cout << "2). View all students" << endl;

            cout << endl << "Enter selection: ";

            while (!(cin >> c2selection) || c2selection < 1 || c2selection > 2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid selection." << endl;
                cout << endl << "Enter selection: ";
            }

            if (c2selection == 1) {
                cout << "1). Find student by name" << endl;
                cout << "2). Find student by ID" << endl;

                cout << endl << "Enter selection: ";

                while (!(cin >> c2selection) || c2selection < 1 || c2selection > 2) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                }

                if (c2selection == 1) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Student name: ";
                    getline(cin, c2name);
                    system.students.displayStudent(c2name);
                }
                else if (c2selection == 2) {
                    cout << endl << "Student ID: ";
                    while (!(cin >> c2id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid student ID. Please enter a number: ";
                    }
                    system.students.displayStudent(c2id);
                }
            }
            else if (c2selection == 2) {
                system.students.displayAllStudents();
            }
            break;
        }
        case 3: {

            clearScreen();

            int eventId{};
            string eventName{};
            string description{};
            string date{};
            string time{};
            string location{};
            int maxCap{};
            string organizer{};
            int eventLength{};
            bool validId = false;
            string department{};
            string speaker{};
            string company{};
            string recruiter{};
            string club{};
            int fancyChoice{};
            int typeChoice{};

            // keep asking until the user enters a number that no other event is using
            do {
                cout<<"Enter Event ID: ";
                if (!(cin>>eventId)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Please enter a number."<<endl;
                    continue;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (system.events.eventExists(eventId)) {
                    cout<<"That event ID is already taken."<<endl;
                }
                else {
                    validId = true;
                }
            } while (!validId);

            cout<<endl<<"Enter Event Name: ";
            getline(cin,eventName);



            do {
                cout<<endl<<"Event Type:\n1. Academic Event\n2. Career Event\n3. Club Event\n4. Social Event\n";
                cout<<"Selection: ";
                if (!(cin>>typeChoice)) {
                    cin.clear();
                    typeChoice = 0;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (typeChoice < 1 || typeChoice > 4);

            // set the type and ask for that type's extra info
            if (typeChoice == 1) {
                description = "Academic Event";
                cout<<endl<<"Enter Department: ";
                getline(cin,department);
                cout<<endl<<"Enter Speaker: ";
                getline(cin,speaker);
            }
            else if (typeChoice == 2) {
                description = "Career Event";
                cout<<endl<<"Enter Company Name: ";
                getline(cin,company);
                cout<<endl<<"Enter Recruiter Name: ";
                getline(cin,recruiter);
            }
            else if (typeChoice == 3) {
                description = "Club Event";
                cout<<endl<<"Enter Club Name: ";
                getline(cin,club);
            }
            else {
                description = "Social Event";
                do {
                    cout<<endl<<"Is it a fancy event? (1 = yes, 0 = no): ";
                    if (!(cin>>fancyChoice)) {
                        cin.clear();
                        fancyChoice = -1;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (fancyChoice != 0 && fancyChoice != 1);
            }

            cout<<endl<<"Enter date(YYYY-MM-DD): ";
            getline(cin,date);

            cout<<endl<<"Enter time(1:00-24:00): ";
            getline(cin,time);

            cout<<endl<<"Enter Location: ";
            getline(cin,location);

            // keep asking until the user enters a number of at least 1
            do {
                cout<<endl<<"Enter Max Event Capacity (must be at least 1): ";
                if (!(cin>>maxCap)) {
                    cin.clear();
                    maxCap = 0;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (maxCap <= 0);

            cout<<endl<<"Enter Organizer Name: ";
            getline(cin,organizer);

            // keep asking until the user enters a number of at least 1
            do {
                cout<<endl<<"Enter Event Length(in minutes): ";
                if (!(cin>>eventLength)) {
                    cin.clear();
                    eventLength = 0;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (eventLength <= 0);

            // create the matching event type
            std::unique_ptr<Event> event;

            if (typeChoice == 1) {
                event = std::make_unique<AcademicEvent>(eventId, eventName, description, date, time, location, maxCap, organizer, eventLength, department, speaker);
            }
            else if (typeChoice == 2) {
                event = std::make_unique<CareerEvent>(eventId, eventName, description, date, time, location, maxCap, organizer, eventLength, company, recruiter);
            }
            else if (typeChoice == 3) {
                event = std::make_unique<ClubEvent>(eventId, eventName, description, date, time, location, maxCap, organizer, eventLength, club);
            }
            else {
                event = std::make_unique<SocialEvent>(eventId, eventName, description, date, time, location, maxCap, organizer, eventLength, fancyChoice == 1);
            }

            system.events.createEvent(std::move(event));

            cout<<endl<<"Event created."<<endl;
        }
        break;

        case 4: {

            clearScreen();

            system.events.displayAllEvents();
        }
            break;
 
        case 5: {

            clearScreen();

            int input{};

            cout<<"Event Info\n\n1.Find event using ID\n2.Find event by name" << endl;

            cout<<endl<<"Enter selection: ";
            while (!(cin >> input) || input < 1 || input > 2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Invalid selection."<<endl;
                cout<<endl<<"Enter selection: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (input == 1) {
                int id{};
                cout<<"Enter Event ID: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Invalid event ID. Please enter a number: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system.events.displayEvent(id);
            }
            else {
                string name{};
                cout<<"Enter Event Name: ";
                getline(cin,name);
                system.events.displayEvent(name);
            }

        }
        break;

        case 6: {

            clearScreen();

            int studentID{};
            int eventID{};

            cout << "Enter student ID: ";

            while (!(cin >> studentID)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid student ID. Please enter a number: ";
            }

            if (system.students.isDuplicateId(studentID)) {//checks if student exists

                cout << "Enter event ID: ";
                while (!(cin >> eventID)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid event ID. Please enter a number: ";
                }

            int maxCapacity = -1;
            for (const auto& e : *system.events.getEventsPointer())
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

            if (system.registrations.addRegistration(Registration(studentID, eventID, date, true), maxCapacity))
                cout << "Student registered.\n";
            else if (system.registrations.isRegistered(studentID, eventID))
                cout << "Student is already registered for this event.\n";
            else
                cout << "This event is full.\n";
        }
            else {
                cout<<"No student with that ID found\n";
            }
            break;
        }

        case 7: {

            clearScreen();

            int studentID, eventID;
            cout << "Enter student ID: ";
            while (!(cin >> studentID)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid student ID. Please enter a number: ";
            }
            cout << "Enter event ID: ";
            while (!(cin >> eventID)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid event ID. Please enter a number: ";
            }
            cout << endl;

            if (system.registrations.cancelRegistration(studentID, eventID))
                cout << "Registration cancelled.\n";
            else
                cout << "No active registration found.\n";
            break;
        }
        case 8: {

            clearScreen();

            int studentID{};
            cout << "Enter student ID: ";
            if (!(cin >> studentID)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid student ID.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            // find the student so we can show their name
            bool studentFound = false;
            string studentName{};
            for (const Student& s : system.students.getStudentVector()) {
                if (s.getId() == studentID) {
                    studentName = s.getName();
                    studentFound = true;
                    break;
                }
            }
            if (!studentFound) {
                cout << "No student found with that ID.\n";
                break;
            }

            cout << "Student: " << studentName << "\n\n";
            cout << "Registered Events:\n";

            vector<int> eventIDs = system.registrations.getEventIDsForStudent(studentID);
            if (eventIDs.empty()) {
                cout << "  (none)\n";
                break;
            }

            // look up each event's name from its ID
            int number = 1;
            for (int id : eventIDs) {
                for (const auto& e : *system.events.getEventsPointer()) {
                    if (e->getEventId() == id) {
                        cout << number << ". " << e->getEventName() << "\n";
                        number++;
                        break;
                    }
                }
            }
            break;
        }
        case 9: {

            clearScreen();

            int eventID{};
            cout << "Enter event ID: ";
            if (!(cin >> eventID)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid event ID.\n";
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            // find the event so we can show its name
            bool eventFound = false;
            string eventName{};
            for (const auto& e : *system.events.getEventsPointer()) {
                if (e->getEventId() == eventID) {
                    eventName = e->getEventName();
                    eventFound = true;
                    break;
                }
            }
            if (!eventFound) {
                cout << "No event found with that ID.\n";
                break;
            }

            cout << "Event: " << eventName << "\n\n";
            cout << "Registered Students:\n";

            vector<int> studentIDs = system.registrations.getStudentIDsForEvent(eventID);
            if (studentIDs.empty()) {
                cout << "  (none)\n";
                break;
            }

            // look up each student's name from their ID
            int number = 1;
            for (int id : studentIDs) {
                for (const Student& s : system.students.getStudentVector()) {
                    if (s.getId() == id) {
                        cout << number << ". " << s.getName() << "\n";
                        number++;
                        break;
                    }
                }
            }
            break;
        }
        case 10: {

            clearScreen();
            int input{};
            bool done = false;


            do {
                cout<<"Organizer Info\n1.Add Organizer\n2.Find Organizer by Name\n3.Display All Organizers\n";
                cout<<endl<<"Selection: ";
                if (!(cin>>input)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Please enter a number."<<endl;
                    continue;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (input == 1) {
                    string name{};
                    int id{};
                    string email{};
                    string department{};

                    //const string& name, const int organizerId, const string& email, const string& department
                    cout<<"Enter Organizer Name: ";
                    getline(cin, name);
                    cout<<endl<<"Enter Organizer ID: ";
                    while (!(cin >> id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid Organizer ID. Please enter a number: ";
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout<<endl<<"Enter Organizer Email: ";
                    getline(cin, email);
                    cout<<endl<<"Enter Organizer Department: ";
                    getline(cin, department);
                    cout<<endl;

                    system.organizers.addOrganizer(name, id, email, department);

                    done = true;
                }
                else if (input == 2) {
                    string name{};
                    cout<<"Enter Organizer Name: ";
                    getline(cin, name);

                    system.organizers.displayOrganizer(name);

                    done = true;

                }
                else if (input == 3) {
                    system.organizers.displayAllOrganizers();

                    done = true;

                }
            }while (!done);

            break;
        }
        case 11: {

            clearScreen();

            cout << "1). Available Events\n";
            cout << "2). Full Events\n";
            cout << "3). Registration Counts\n";
            cout << "4). Most Popular Event\n";

            cout << "\nReport selection: ";

            int reportChoice;
            if (!(cin >> reportChoice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid report selection.\n";
                break;
            }

            const auto& eventList = *system.events.getEventsPointer();

            switch (reportChoice) {
                case 1:
                    system.reports.showAvailableEvents(eventList, system.registrations);
                    break;

                case 2:
                    system.reports.showFullEvents(eventList, system.registrations);
                    break;

                case 3:
                    system.reports.showRegistrationCounts(eventList, system.registrations);
                    break;

                case 4:
                    system.reports.showMostPopularEvent(eventList, system.registrations);
                    break;

                default:
                    cout << "Invalid report selection.\n";
            }
            break;
        }
        case 0:
            break;
    }
}