#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "Event.h"

class EventSystem
{
private:
    vector<unique_ptr<Event>> events;
    static int numEvents;
    friend class FileManager;
public:
    void createEvent(unique_ptr<Event> event);
    int findEventById(const int& id); // Returns index of event
    void displayEvent(const int& id);
    void displayEvent(const string& name);
    void displayAllEvents();
    int findEventByName(const string& name); // Returns index of event
};