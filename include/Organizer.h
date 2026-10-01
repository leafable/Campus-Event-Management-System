#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Event.h"

using namespace std;

class Organizer {
private:
    string name;
    vector<Event&> events;
public:
    Organizer(const string& name, vector<string> events);
    Organizer(const string& name);
    string getName() const;
};