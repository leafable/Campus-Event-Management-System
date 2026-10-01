#include "RegistrationManager.h"

RegistrationManager::RegistrationManager(){

};

RegistrationManager::RegistrationManager(vector<Student> list){
    list = student;
};


std::string getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&currentTime);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d"); // Format: YYYY-MM-DD
    return oss.str();
}

bool RegistrationManager::studentExist(int ID){
    bool exist = false;

    for(int i = 0; i<student.size();i++){
        if(ID == student[i].getId()){
            exist = true;
            return exist;
        }
    }
    return exist;
}

bool RegistrationManager::checkEvent(int eventID){
    
}

void RegistrationManager::registerStudent(int ID, int eventID, std::string name){
    Registration registration(ID, eventID, name, getCurrentDate(), "Registered"); //add a way to input date
    registrations.push_back(registration);
} //Registers student to event

void RegistrationManager::viewRegisteredStudents(int eventID){

} //displays the list of students registered for that event

void RegistrationManager::viewStudentEvent(int studentID){

} //displays list of events registered by that student

