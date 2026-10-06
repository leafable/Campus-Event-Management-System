#include <Event.h>

virtual Event::Event(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength){
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

virtual int Event::getEventId() const{
    return eventId;
}

virtual string Event::getEventName() const{
    return eventName;
}

virtual string Event::getEventDescription() const{
    return eventDescription;
}

virtual string Event::getEventDate() const{
    return eventDate;
}

virtual int Event::getEventTime() const{
    return eventTime;
}

virtual string Event::getEventLocation() const{
    return eventLocation;
}

virtual int Event::getEventMaxCapacity() const{
    return eventMaxCapacity;
}

virtual string Event::getOrganizer() const{
    return organizer;
}

virtual int Event::getEventLength() const{
    return eventLength();
}

virtual void Event::setEventName(string newEventName){
    this->eventName = newEventName;
}

virtual void Event::setEventDescription(string newEventDescription){
    this->eventDescription = newEventDescription;
}

virtual void Event::setEventDate(string newEventDate){
    this->eventDate = newEventDate;
}

virtual void Event::setEventTime(int newEventTime){
    this->eventTime = newEventTime;
}

virtual void Event::setEventLength(int newEventLength){
    this->eventLength = newEventLength;
}

virtual void Event::setEventMaxCapacity(int newEventMaxCapacity){
    this->eventMaxCapacity = newEventMaxCapacity;
}

virtual void Event::setOrganizer(string newOrganizer){
    this->organizer = newOrganizer;
}
virtual void Event::setLocation(string newLocation){
    this-location = newLocation;
}