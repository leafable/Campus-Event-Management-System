#include "AcedemicEvent.h"

AcedemicEvent(string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string department, string speaker) : Event(name, description, date, time, location, maxCap, organizer, eventLength){
    this->department = department;
    this->speaker = speaker;
}

string getDepartment() const{
    return department;
}

string getSpeaker() const{
    return speaker;
}

void setDepartment(string newDepartment){
    this->department = newDepartment;
}

void setSpeaker(string newSpeaker){
    this->speaker = newSpeaker;
}