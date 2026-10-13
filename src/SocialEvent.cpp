#include "SocialEvent.h"

SocialEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, bool isFancy) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->isFancy = isFancy;
}

bool getIfFancy() const{
    return isFancy;
}

void setIfFancy(bool isFancy){
    this->isFancy = isFancy;
}