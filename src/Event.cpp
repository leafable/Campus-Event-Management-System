#include <Event.h>

Event::Event(string name, string description, string date, int time,  string location, int maxCap, string organizer){
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

int Event::getEventId(){
    return eventId;
}

string Event::getEventName(){
    return eventName;
}

string Event::getEventDescription(){
    return eventDescription;
}

string Event::getEventDate(){
    return eventDate;
}

int Event::getEventTime(){
    return eventTime;
}

string Event::getEventLocation(){
    return eventLocation;
}

int Event::getEventMaxCapacity(){
    return eventMaxCapacity;
}

string Event::getOrganizer(){
    return organizer;
}