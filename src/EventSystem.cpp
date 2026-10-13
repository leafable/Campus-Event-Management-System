#include "../include/EventSystem.h"
#include "../include/AcademicEvent.h"
#include "../include/ClubEvent.h"
#include "../include/CareerEvent.h"
#include "../include/SocialEvent.h"

void EventSystem::createEvent(unique_ptr<Event> event)
{
    events.push_back(event);
}
int EventSystem::findEventById(const int& id)
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventId() == id)
        {
            return i;
        }
    }
    return -1;
}
void EventSystem::displayEvent(const int& id)
{
    int index = findEventById(id);
    if (index != -1)
    {
        // Shared event data
        cout << "Event ID: " << events[index]->getEventId() << endl;
        cout << "Name: " << events[index]->getEventName() << endl;
        cout << "Description: " << events[index]->getEventDescription() << endl;
        cout << "Date: " << events[index]->getEventDate() << endl;
        cout << "Time: " << events[index]->getEventTime() << endl;
        cout << "Location: " << events[index]->getEventLocation() << endl;
        cout << "Capacity: " << events[index]->getEventMaxCapacity() << endl;
        cout << "Organizer: " << events[index]->getOrganizer() << endl;

        // Derived event data
        if (events[index]->getEventDescription() == "Academic Event")
        {
            AcademicEvent* eventPtr = dynamic_cast<AcademicEvent*>(events[index].get());
            cout << "Department: " << eventPtr->getDepartment() << endl;
            cout << "Speaker: " << eventPtr->getSpeaker() << endl;
        }
        else if (events[index]->getEventDescription() == "Career Event")
        {
            CareerEvent* eventPtr = dynamic_cast<CareerEvent*>(events[index].get());
            cout << "Company: " << eventPtr->getCompanyName() << endl;
            cout << "Recruiter: " << eventPtr->getRecruiterName() << endl;
        }
        else if (events[index]->getEventDescription() == "Club Event")
        {
            ClubEvent* eventPtr = dynamic_cast<ClubEvent*>(events[index].get());
            cout << "Club: " << eventPtr->getClub() << endl;
        }
        else if (events[index]->getEventDescription() == "Social Event")
        {
            SocialEvent* eventPtr = dynamic_cast<SocialEvent*>(events[index].get());
            cout << "Fancy: " << (eventPtr->getIfFancy() ? "True" : "False") << endl;
        }
    }
    else
    {
        cerr << "Error: Event not found." << endl;
    }
}
void EventSystem::displayEvent(const string& name)
{
    int index = findEventByName(name);
    displayEvent(index);
}
void EventSystem::displayAllEvents()
{
    for (int index = 0; index < events.size(); index++)
    {
        // Shared event data
        cout << "Event ID: " << events[index]->getEventId() << endl;
        cout << "Name: " << events[index]->getEventName() << endl;
        cout << "Description: " << events[index]->getEventDescription() << endl;
        cout << "Date: " << events[index]->getEventDate() << endl;
        cout << "Time: " << events[index]->getEventTime() << endl;
        cout << "Location: " << events[index]->getEventLocation() << endl;
        cout << "Capacity: " << events[index]->getEventMaxCapacity() << endl;
        cout << "Organizer: " << events[index]->getOrganizer() << endl;

        // Derived event data
        if (events[index]->getEventDescription() == "Academic Event")
        {
            AcademicEvent* eventPtr = dynamic_cast<AcademicEvent*>(events[index].get());
            cout << "Department: " << eventPtr->getDepartment() << endl;
            cout << "Speaker: " << eventPtr->getSpeaker() << endl;
        }
        else if (events[index]->getEventDescription() == "Career Event")
        {
            CareerEvent* eventPtr = dynamic_cast<CareerEvent*>(events[index].get());
            cout << "Company: " << eventPtr->getCompanyName() << endl;
            cout << "Recruiter: " << eventPtr->getRecruiterName() << endl;
        }
        else if (events[index]->getEventDescription() == "Club Event")
        {
            ClubEvent* eventPtr = dynamic_cast<ClubEvent*>(events[index].get());
            cout << "Club: " << eventPtr->getClub() << endl;
        }
        else if (events[index]->getEventDescription() == "Social Event")
        {
            SocialEvent* eventPtr = dynamic_cast<SocialEvent*>(events[index].get());
            cout << "Fancy: " << (eventPtr->getIfFancy() ? "True" : "False") << endl;
        }
    }
}
int EventSystem::findEventByName(const string& name)
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventName() == name)
        {
            return i;
        }
    }
    return -1;
}