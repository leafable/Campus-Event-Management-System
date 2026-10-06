#pragma once
#include "Event.h"

class CareerEvent : public Event{
    private:
    string companyName;
    string recruiterName;
    public:
    CareerEvent(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength, string companyName, string recruiterName);
    string getCompanyName() const;
    string getRecruiterName() const;
    void setCompanyName(string newCompanyName);
    void setRecruiterName(string newRecruiterName);
};