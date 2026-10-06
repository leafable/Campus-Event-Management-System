#pragma once
#include "Event.h"

class SocialEvent : public Event{
    private:
    bool isFancy;
    public:
    SocialeEvent(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength, bool isFancy);
    bool getIfFancy() const;
    void setIfFancy(bool isFancy);
}