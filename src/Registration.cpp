#include "Registration.h"

using namespace std;

Registration::Registration()
    : studentID(0), eventID(0), registrationDate(""), status("Registered")
{
}

Registration::Registration(int studentID, int eventID,
                           const string& registrationDate,
                           const string& status)
    : studentID(studentID), eventID(eventID),
      registrationDate(registrationDate), status(status)
{
}

int Registration::getStudentID() const
{
    return studentID;
}

int Registration::getEventID() const
{
    return eventID;
}

const string& Registration::getRegistrationDate() const
{
    return registrationDate;
}

const string& Registration::getStatus() const
{
    return status;
}

void Registration::setStatus(const string& status)
{
    this->status = status;
}