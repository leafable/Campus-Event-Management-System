#pragma once
#include <string>

class Event(){
    private:
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
    virtual Event(string name, string description, string date, int time,  string location, int maxCap, string organizer, int eventLength);
    virtual int getEventId() const;  //Returns the event id
    virtual string getEventName() const;  //Returns the events name
    virtual string getEventDescription() const;  //Returns the events description
    virtual string getEventDate() const;  //Returns the events date in the form
                                          //of a string
    virtual int getEventTime() const;  //Returns the time the event starts
    virtual string getEventLocation() const;  //Returns the name of the location
                                              //of the event
    virtual int getEventMaxCapacity() const;  //Returns the events maximum
                                              //capacity of people
    virtual string getOrganizer() const;  //Returns name of the organizer
    virtual int getEventLength() const;  //Returns the length of the event in
                                         //the number of hours
    virtual void setEventName(string newEventName);  //Changes the events name
    virtual void setEventDescription(string newEventDescription);
                                        //changes the events description
    virtual void setEventDate(string newEventDate);  //changes the events date
    virtual void setEventTime(int newEventTime);  //changes the time the event 
                                                  //starts
    virtual void setEventLength(int newEventLength);  //changes the amount of
                                                      //hours the event is set
                                                      //to run
    virtual void setEventMaxCapacity(int newEventMaxCapacity);
                                                //changes the events max cap
    virtual void setOrganizer(string newOrganizer); //changes the organizer of
                                                    //the event
    virtual void setLocation(string newLocation);  //changes the location of the
                                                   //event
}