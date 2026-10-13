#include "Organizer.h"

Organizer::Organizer(string name, int organizerId, string email, string department) {
    this->name = name;
    this->organizerId = organizerId;
    this->email = email;
    this->department = department;
}

string Organizer::getName() const {
    return name;
}

int Organizer::getOrganizerId() const {
    return organizerId;
}

string Organizer::getEmail() const {
    return email;
}

string Organizer::getDepartment() const {
    return department;
}