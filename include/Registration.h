#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <iostream>
#include <string>
#include <vector>

#include"Student.h"

class Registration{
    private:
    int studentID{};
    int eventID{};
    std::string studentName{};
    std::string registrationDate{};
    std::string status{};

    public:
    Registration(); //Default constructor
    Registration(int ID, int eventID, std:: string name, std::string registrationDate, std::string status); //overloaded constructor
    ~Registration();

    int getStudentID();
    int getEventID();
    std::string getStudentName();
    std::string regDate();
    std::string showStatus();
    

};

#endif