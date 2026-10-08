#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <vector>
#include "Registration.h"

class RegistrationManager
{
private:
    std::vector<Registration> registrations;

    // Returns the position of a registration in the vector, or -1 if not found
    int findIndex(int studentID, int eventID) const;

public:
    // Returns false if this student is already registered for this event
    bool addRegistration(const Registration& registration);

    bool isRegistered(int studentID, int eventID) const;

    // Returns false if the registration does not exist
    bool cancelRegistration(int studentID, int eventID);

    int countForEvent(int eventID) const;

    std::vector<int> getEventIDsForStudent(int studentID) const;
    std::vector<int> getStudentIDsForEvent(int eventID) const;

    // Used by FileManager when saving
    const std::vector<Registration>& getAllRegistrations() const;
};

#endif