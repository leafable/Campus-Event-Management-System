#include <Event.h>

Event::Event(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, int eventLength){
    this->id = id;
    this->eventName = name;
    this->eventDescription = description;
    this->eventDate = date;
    this->eventTime = time;
    this->eventLocation = location;
    this->eventMaxCapacity = maxCap;
    this->organizer = organizer;
}

string Event::getEventName() const{
    return eventName;
}

string Event::getEventDescription() const{
    return eventDescription;
}

string Event::getEventDate() const{
    return eventDate;
}

string Event::getEventTime() const{
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
    return eventLength;
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

void Event::setEventTime(string newEventTime){
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
    this->eventLocation = newLocation;
}

int Event::getEventId() const{
    return id;
}

void Event::setEventId(int EventID) {
    this->id = EventID;
}

void Event::printDetails() const {
    cout << "Event ID: " << getEventId() << endl;
    cout << "Name: " << getEventName() << endl;
    cout << "Description: " << getEventDescription() << endl;
    cout << "Date: " << getEventDate() << endl;
    cout << "Time: " << getEventTime() << endl;
    cout << "Location: " << getEventLocation() << endl;
    cout << "Capacity: " << getEventMaxCapacity() << endl;
    cout << "Organizer: " << getOrganizer() << endl;
}