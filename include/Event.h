#pragma once
#include <string>

class Event(){
    private:
    int eventId;
    static int numEvents = 0;
    string eventName;
    string eventDescription;
    string eventDate;
    int eventTime;  //the time will just be the hour the event starts
    string eventLocation;
    int eventMaxCapacity;
    string organizer;
    public:
    Event(string name, string description, string date, int time,  string location, int maxCap, string organizer);
    int getEventId();
    string getEventName();
    string getEventDescription();
    string getEventDate();
    int getEventTime();
    string getEventLocation();
    int getEventMaxCapacity();
    string getOrganizer();
}