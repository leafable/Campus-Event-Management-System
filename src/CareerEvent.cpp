#include "CareerEvent.h"

CareerEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string companyName, string recruiterName) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->companyName = companyName;
    this->recruiterName = recruiterName;
}

string getCompanyName() const{
    return companyName;
}

string getRecruiterName() const{
    return recruiterName;
}

void setCompanyName(string newCompanyName){
    this->companyName = newCompanyName;
}

void setRecruiterName(string newRecruiterName){
    this->recruiterName = newRecruiterName;
}