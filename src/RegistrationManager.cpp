#include "RegistrationManager.h"

using namespace std;

int RegistrationManager::findIndex(int studentID, int eventID) const
{
    for (size_t i = 0; i < registrations.size(); i++)
    {
        if (registrations[i].getStudentID() == studentID &&
            registrations[i].getEventID() == eventID)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool RegistrationManager::addRegistration(const Registration& registration)
{
    if (isRegistered(registration.getStudentID(), registration.getEventID()))
    {
        return false;
    }
    registrations.push_back(registration);
    return true;
}

bool RegistrationManager::isRegistered(int studentID, int eventID) const
{
    return findIndex(studentID, eventID) != -1;
}

bool RegistrationManager::cancelRegistration(int studentID, int eventID)
{
    int index = findIndex(studentID, eventID);
    if (index == -1)
    {
        return false;
    }
    registrations.erase(registrations.begin() + index);
    return true;
}

int RegistrationManager::countForEvent(int eventID) const
{
    int count = 0;
    for (const Registration& registration : registrations)
    {
        if (registration.getEventID() == eventID)
        {
            count++;
        }
    }
    return count;
}

vector<int> RegistrationManager::getEventIDsForStudent(int studentID) const
{
    vector<int> eventIDs;
    for (const Registration& registration : registrations)
    {
        if (registration.getStudentID() == studentID)
        {
            eventIDs.push_back(registration.getEventID());
        }
    }
    return eventIDs;
}

vector<int> RegistrationManager::getStudentIDsForEvent(int eventID) const
{
    vector<int> studentIDs;
    for (const Registration& registration : registrations)
    {
        if (registration.getEventID() == eventID)
        {
            studentIDs.push_back(registration.getStudentID());
        }
    }
    return studentIDs;
}

const vector<Registration>& RegistrationManager::getAllRegistrations() const
{
    return registrations;
}