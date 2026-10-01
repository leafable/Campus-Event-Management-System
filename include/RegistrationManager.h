#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H
#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Registration.h"

class RegistrationManager{
    private:
    vector<Student> student;
    vector<Registration> registrations;

    public:
    RegistrationManager();
    RegistrationManager(vector<Student> list);

    bool studentExist(int ID);
    bool checkEvent(int eventID);

    void registerStudent(int ID, int eventID); //Registers student to event
    void viewRegisteredStudents(int eventID); //displays the list of students registered for that event
    void viewStudentEvent(int studentID); //displays list of events registered by that student
};

#endif 