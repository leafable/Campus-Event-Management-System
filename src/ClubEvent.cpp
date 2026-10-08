#include "ClubEvent.h"

ClubEvent(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength, string club) : Event(name, description, date, time, location, maxCap, organizer, eventLength){
    this->club = club;
}

string getClub() const{
    return club;
}

void setClub(string newClub){
    this->club = newClub;
}