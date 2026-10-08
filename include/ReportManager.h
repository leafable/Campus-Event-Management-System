#pragma once

#include <vector>
#include "Event.h"
#include "RegistrationManager.h"

using namespace std;

class ReportManager
{
public:
    void showAvailableEvents(
        vector<Event>& events,
        const RegistrationManager& registrations);

    void showFullEvents(
        vector<Event>& events,
        const RegistrationManager& registrations);

    void showRegistrationCounts(
        vector<Event>& events,
        const RegistrationManager& registrations);

    void showMostPopularEvent(
       vector<Event>& events,
        const RegistrationManager& registrations);
};
