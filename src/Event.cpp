#include <Event.h>

Event::Event(string name, string description, int year, int month, int day, int time,  string location, int maxCap, string organizer){
    this->eventName = name;
    this->eventDescription = description;
    this->eventYear = year;
    this->eventMonth = month;
    this->eventDay = day;
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

int Event::getEventYear(){
    return eventYear;
}

int Event::getEventMonth(){
    return eventMonth;
}

int Event::getEventDay(){
    return eventDay;
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