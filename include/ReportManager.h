#pragma once

#include <vector>
#include "Event.h"
#include "RegistrationManager.h"

using namespace std;

class ReportManager
{
public:
    void showAvailableEvents(
        const vector<Event>& events,
        const RegistrationManager& registrations);

    void showFullEvents(
        const vector<Event>& events,
        const RegistrationManager& registrations);

    void showRegistrationCounts(
        const vector<Event>& events,
        const RegistrationManager& registrations);

    void showMostPopularEvent(
        const vector<Event>& events,
        const RegistrationManager& registrations);
};
