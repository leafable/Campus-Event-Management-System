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
    std::string registrationDate{};
    std::string status{};

    public:
    Registration(); //Default constructor
    Registration(int ID, int eventID); //overloaded constructor
    ~Registration();

    

};

#endif