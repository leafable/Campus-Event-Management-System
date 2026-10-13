#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager {

    public:
    FileManager();
    void readStudents(StudentManager& sm);
    void writeStudents(StudentManager& sm);
    void readEvents(EventSystem& es);
    void writeEvents(EventSystem& es);
    void readOrganizers(Organizer& org);
    void writeOrganizers(Organizer& org);
    void readRegistrations(RegistrationManager& rm);
    void writeRegistrations(RegistrationManager& rm);

    private:

};

#endif