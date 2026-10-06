#include "SocialEvent.h"

SocialeEvent(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength, bool isFancy) : Event(name, description, date, time, location, maxCap, organizer, eventLength){
    this->isFancy = isFancy;
}

bool getIfFancy() const{
    return isFancy;
}

void setIfFancy(bool isFancy){
    this->isFancy = isFancy;
}