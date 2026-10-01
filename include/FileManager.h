#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>


void readStudents(std::string fileName);
void writeStudents(std::string fileName);
void readEvents(std::string fileName);
void writeEvents(std::string fileName);
void readOrganizers(std::string fileName);
void writeOrganizers(std::string fileName);
void readRegistrations(std::string fileName);
void writeRegistrations(std::string fileName);

#endif