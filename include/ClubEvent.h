#pragma once
#include "Event.h"

class ClubEvent : public Event{
    private:
    string club;
    public:
    ClubEvent(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength, string club);
    string getClub() const;
    void setClub(string newClub);
}