#include "Registration.h"

Registration::Registration(){
    studentID = 0;
    eventID = 0;
    registrationDate = "1/1/2000";
    status = "Registered";
}

Registration::Registration(int studentID, int eventID, string name, string regDate, string stat){
    this->studentID = studentID;
    this->eventID = eventID;
    studentName = name;
    registrationDate = regDate;
    status = stat;
}

int Registration::getStudentID(){
    return studentID;
};

int Registration::getEventID(){
    return eventID;
};

std::string Registration::getStudentName(){
    return studentName;
};

std::string Registration::regDate(){
    return registrationDate;
};

std::string Registration::showStatus(){
    return status;
};

