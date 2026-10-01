#pragma once
#include <string>
#include <vector>
#include "Organizer.h"

class OrganizerManagement {
private:
    vector<Organizer> organizers;
    static int numOrganizers;
public:
    OrganizerManagement();
    void addOrganizer(const Organizer& organizer);
    void addOrganizer(const string& name);
    int findByName(const string& name) const;
    void displayOrganizer(const string& name) const;
    void displayAllOrganizers() const;
    bool isDuplicateName(const string& name) const;
    int getNumOrganizers() const;
};