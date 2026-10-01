#include <event.h>

Event(string name, string description, int year, int month, int day, int time,  string location, int maxCap, string organizer){
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

int getEventId(){
    return eventId;
}

string getEventName(){
    return eventName;
}

string getEventDescription(){
    return eventDescription;
}

int getEventYear(){
    return eventYear;
}

int getEventMonth(){
    return eventMonth;
}

int getEventDay(){
    return eventDay;
}

int getEventTime(){
    return eventTime;
}

string getEventLocation(){
    return eventLocation;
}

int getEventMaxCapacity(){
    return eventMaxCapacity;
}

string getOrganizer(){
    return organizer;
}