#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>

class Registration
{
private:
    int studentID;
    int eventID;
    std::string registrationDate;
    std::string status;

public:
    Registration();

    Registration(int studentID, int eventID,
                 const std::string& registrationDate,
                 const std::string& status = "Registered");

    int getStudentID() const;
    int getEventID() const;
    const std::string& getRegistrationDate() const;
    const std::string& getStatus() const;

    void setStatus(const std::string& status);
};

#endif