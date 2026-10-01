#pragma once
#include <string>

class Event(){
    private:
    int eventId;
    static int numEvents = 0;
    string eventName;
    string eventDescription;
    int eventYear;
    int eventMonth;
    int eventDay;
    int eventTime;  //the time will just be the hour the event starts
    string eventLocation;
    int eventMaxCapacity;
    string organizer;
    public:
    Event(string name, string description, int year, int month, int day, int time,  string location, int maxCap, string organizer);
    int getEventId();
    string getEventName();
    string getEventDescription();
    int getEventYear();
    int getEventMonth();
    int getEventDay();
    int getEventTime();
    string getEventLocation();
    int getEventMaxCapacity();
    string getOrganizer();
}