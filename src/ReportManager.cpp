#include "../include/ReportManager.h"
#include <iostream>
using namespace std;

// Report 1: Events with available capacity
void ReportManager::showAvailableEvents(
     vector<Event>& events,
    const RegistrationManager& registrations)
{
    cout << "\nEvents with Available Capacity:\n";

    for ( Event& event : events)
    {
        int count = registrations.countForEvent(event.getEventId());
        int available = event.getEventMaxCapacity() - count;

        if (available > 0)
        {
            cout << event.getEventName()
                 << " - Available spots: " << available << endl;
        }
    }
}

// Report 2: Full events
void ReportManager::showFullEvents(
     vector<Event>& events,
    const RegistrationManager& registrations)
{
    cout << "\nFull Events:\n";

    for ( Event& event : events)
    {
        int count = registrations.countForEvent(event.getEventId());

        if (count >= event.getEventMaxCapacity())
        {
            cout << event.getEventName() << endl;
        }
    }
}

// Report 3: Registration count for each event
void ReportManager::showRegistrationCounts(
     vector<Event>& events,
    const RegistrationManager& registrations)
{
    cout << "\nRegistration Counts:\n";

    for ( Event& event : events)
    {
        cout << event.getEventName() << ": "
             << registrations.countForEvent(event.getEventId())
             << " registrations" << endl;
    }
}

// Report 4: Most popular event
void ReportManager::showMostPopularEvent(
     vector<Event>& events,
    const RegistrationManager& registrations)
{
    if (events.empty())
    {
        cout << "No events available.\n";
        return;
    }

    int highest = -1;
    string popularEvent;

    for ( Event& event : events)
    {
        int count = registrations.countForEvent(event.getEventId());

        if (count > highest)
        {
            highest = count;
            popularEvent = event.getEventName();
        }
    }

    cout << "\nMost Popular Event: " << popularEvent
         << " (" << highest << " registrations)" << endl;
}
