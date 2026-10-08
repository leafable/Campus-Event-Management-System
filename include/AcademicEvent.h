#pragma once
#include "Event.h"

class AcedemicEvent : public Event{
    private:
    string department;  //stores the department name
    string speaker;  //stoes the speakers name
    public:
    AcedemicEvent(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength, string department, string speaker);
    string getDepartment() const;
    string getSpeaker() const;
    void setDepartment(string newDepartment);
    void setSpeaker(string newSpeaker);
};