#pragma once
#include <string>
#include <iostream>
using namespace std;

class Event(){
    protected:
    int eventId;  //an events unique id based on the total number of events
    static int numEvents = 0; //stores how many total events there are
    string eventName;  // string that stores the events name
    string eventDescription;  //string that stores the description of the event
    string eventDate;  //this is the date of the event as a string, stored as 
                       //(month day) ex) october 1st
    int eventTime;  //the time will just be the hour the event starts
    int eventLength;  //stores how long the event will run in number of hours
    string eventLocation;  //stores the name of the events location
    int eventMaxCapacity;  //stores the max capacity of the event location
    string organizer;  //stores the name of the event organizer
    public:
    Event(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength);
    int getEventId() const;  //Returns the event id
    string getEventName() const;  //Returns the events name
    virtual string getEventDescription() const;  //Returns the events description
    string getEventDate() const;  //Returns the events date in the form
                                  //of a string
    int getEventTime() const;  //Returns the time the event starts
    string getEventLocation() const;  //Returns the name of the location
                                      //of the event
    int getEventMaxCapacity() const;  //Returns the events maximum
                                      //capacity of people
    string getOrganizer() const;  //Returns name of the organizer
    int getEventLength() const;  //Returns the length of the event in
                                 //the number of hours
    void setEventName(string newEventName);  //Changes the events name
    void setEventDescription(string newEventDescription);
                                //changes the events description
    void setEventDate(string newEventDate);  //changes the events date
    void setEventTime(int newEventTime);  //changes the time the event 
                                          //starts
    void setEventLength(int newEventLength);  //changes the amount of
                                              //hours the event is set
                                              //to run
    void setEventMaxCapacity(int newEventMaxCapacity);
                                        //changes the events max cap
    void setOrganizer(string newOrganizer); //changes the organizer of
                                            //the event
    void setLocation(string newLocation);  //changes the location of the
                                           //event
};