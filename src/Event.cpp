#include <Event.h>

Event::Event(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength){
    this->eventName = name;
    this->eventDescription = description;
    this->date = date;
    this->eventTime = time;
    this->eventLocation = location;
    this->eventMaxCapacity = maxCap;
    this->organizer = organizer;
    numEvents++;
    this->eventId = numEvents;
}

int Event::getEventId() const{
    return eventId;
}

string Event::getEventName() const{
    return eventName;
}

virtual string Event::getEventDescription() const{
    return eventDescription;
}

string Event::getEventDate() const{
    return eventDate;
}

int Event::getEventTime() const{
    return eventTime;
}

string Event::getEventLocation() const{
    return eventLocation;
}

int Event::getEventMaxCapacity() const{
    return eventMaxCapacity;
}

string Event::getOrganizer() const{
    return organizer;
}

int Event::getEventLength() const{
    return eventLength();
}

void Event::setEventName(string newEventName){
    this->eventName = newEventName;
}

void Event::setEventDescription(string newEventDescription){
    this->eventDescription = newEventDescription;
}

void Event::setEventDate(string newEventDate){
    this->eventDate = newEventDate;
}

void Event::setEventTime(int newEventTime){
    this->eventTime = newEventTime;
}

void Event::setEventLength(int newEventLength){
    this->eventLength = newEventLength;
}

void Event::setEventMaxCapacity(int newEventMaxCapacity){
    this->eventMaxCapacity = newEventMaxCapacity;
}

void Event::setOrganizer(string newOrganizer){
    this->organizer = newOrganizer;
}

void Event::setLocation(string newLocation){
    this-location = newLocation;
}