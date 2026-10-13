#include "ClubEvent.h"

ClubEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string club) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->club = club;
}

string getClub() const{
    return club;
}

void setClub(string newClub){
    this->club = newClub;
}