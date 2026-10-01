#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "Student.h"
#include "Event.h"
#include "Registration.h"

class RegistrationManager{
    private:
    vector<Student> student;
    //vector<Event> events;
    vector<Registration> registrations;

    public:
    RegistrationManager();
    RegistrationManager(vector<Student> list);

    bool studentExist(int ID);
    bool checkEvent(int eventID);

    void registerStudent(int ID, int eventID, std::string name); //Registers student to event
    void viewRegisteredStudents(int eventID); //displays the list of students registered for that event
    void viewStudentEvent(int studentID); //displays list of events registered by that student

    string getCurrentTime();
};

#endif 