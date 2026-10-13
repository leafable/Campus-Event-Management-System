#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "FileManager.h"

#include "CareerEvent.h"
#include "ClubEvent.h"
#include "SocialEvent.h"
#include "StudentManagement.h"
#include "../include/Registration.h"
#include "../include/StudentManagement.h"

using namespace std;

void FileManager::readStudents(std::string fileName) {


    // open the students.txt file
    std::ifstream enrolled(fileName);

    //initialize counter variable to track line read
    int i = 0;


    string line;

    //read all the lines in the file
    while (getline(enrolled, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string name, email, major, tempId;
        int id;

        //store all CSV in the line to variables
        getline(ss, tempId, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');

        //Check if current row is missing a data member
        if (email.empty() && !getline(ss, major, ',')) {
            cerr << "Error! There is data missing from line " << i << endl;
            continue;
        }



        //convert tempId to int id and catch errors
        try {
            id = stoi(tempId);
        } catch (const exception &e) {
            cerr << "Error reading ID. Skipped line: " << i << endl;
            continue;
        }

        StudentManagement::addStudent(id, name, email, major);
    }

    enrolled.close();
}

void FileManager::writeStudents(string fileName, StudentManagement sm) {

    ofstream enrolled(fileName);

    std::vector<Student>* stuPtr = sm.getStudentsPointer();

    if (stuPtr != nullptr) {
        for (const Student& s : *stuPtr) {
            enrolled << s.id << "," << s.name << "," << s.email << "," << s.major << '\n';
        }
    }

    // for (const Student& s : sm.getStudentVector()) {
    //     enrolled << s.id << "," << s.name << "," << s.email << "," << s.major << '\n';
    // }

    close(enrolled);
}

void FileManager::readEvents(string fileName) {
    // open the students.txt file
    std::ifstream eventFile(fileName);

    //initialize counter variable to track line read
    int i = 0;

    string line; //string to hold line text

    //read all the lines in the file
    while (getline(eventFile, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string name, description, date, location, org, start, maxcap, length;
        int istart, imaxcap;
        float flength;

        //store all CSV in the line to variables
        getline(ss, name, ',');
        getline(ss, description, ',');
        getline(ss, date, ',');
        getline(ss, start, ',');
        getline(ss, location, ',');
        getline(ss, maxcap, ',');
        getline(ss, org, ',');
        if (!getline(ss, length, ',')) {
            cerr << "Missing data in line: " << i << endl;
            continue;
        }

        //convert numerical strings to proper data types
        try {
            imaxcap = stoi(maxcap);
        } catch (const exception &e) {
            cerr << "Error reading numerical values. Skipped line: " << i << endl;
            continue;
        }

        if (description == "Academic Event") {
            string department, speaker;
            getline(ss, department, ',');
            getline(ss, speaker, ',');
            AcademicEvent(name, description, date, istart, location,
                imaxcap, org, flength, department, speaker);
        }
        else if (description == "Career Event") {
            string company, recruiter;
            getline(ss, company, ',');
            getline(ss, recruiter, ',');
            CareerEvent(name, description, date, istart, location,
                imaxcap, org, flength, company, recruiter);
        }
        else if (description == "Club Event") {
            string department, speaker;
            getline(ss, department, ',');
            getline(ss, speaker, ',');
            ClubEvent(name, description, date, istart, location,
                imaxcap, org, flength, department, speaker);
        }
        else if (description == "Social Event") {
            string department, speaker;
            getline(ss, department, ',');
            getline(ss, speaker, ',');
            SocialEvent(name, description, date, istart, location,
                imaxcap, org, flength, department, speaker);
        }
        else {
            cerr << "Error reading event type. Skipped line: " << i << endl;
        }

    } //end of reading file loop

    //close the file stream
    eventFile.close();
}

void writeEvents(std::string fileName, EventSystem es) {
    ofstream events(fileName);

    std::vector<Event>* eventPtr = es.getEventPointer();

    if (eventPtr != nullptr) {
        for (const Event& e : *eventPtr) {
            cout << e.id << "," << e.name << "," << e.email << "," << e.major << '\n';
        }
    }

    // for (const Event& e : es.getStudentVector()) {
    //     cout << s.id << "," << s.name << "," << s.email << "," << s.major << '\n';
    // }

    close(enrolled);
}

void readOrganizers(std::string fileName) {

    // open the students.txt file
    std::ifstream organizer(fileName);

    //initialize counter variable to track line read
    int i = 0;

    string line;

    //read all the lines in the file
    while (getline(organizer, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string name, email, dept, tempId;
        int id;

        //store all CSV in the line to variables
        getline(ss, tempId, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, dept, ',');

        //Check if current row is missing a data member
        if (tempId.empty() || name.empty() || email.empty() || dept.empty()) {
            cerr << "Error! There is data missing from line " << i << endl;
            continue;
        }



        //convert tempId to int id and catch errors
        try {
            id = stoi(tempId);
        } catch (const exception &e) {
            cerr << "Error reading ID. Skipped line: " << i << endl;
            continue;
        }

        Organizer::addOrganizer(orgId, name, email, dept);
    }

    organizer.close();

}

void writeOrganizers(std::string fileName, Organizer org) {

    //open txt file to save organizers
    ofstream orgFile(fileName);

    //get a pointer to the vector holding the organizers
    std::vector<Organizer>* orgPtr = org.getOrganizerPointer();

    if (orgPtr != nullptr) {
        for (const Organizer& o : *orgPtr) {
            orgFile << o.id << "," << o.name << "," << o.email << "," << o.dept << '\n';
        }
    }

    // for (const Organizer& s : org.getStudentVector()) {
    //     orgFile << o.id << "," << o.name << "," << o.email << "," << o.dept << '\n';
    // }

    close(orgFile);
}

void readRegistrations(std::string fileName) {

    // open the registration.txt file
    std::ifstream registration(fileName);

    //initialize counter variable to track line read
    int i = 0;


    string line;

    //read all the lines in the file
    while (getline(registration, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string tempSId, tempEId, regDate, status;
        int SId, EId;

        //store all CSV in the line to variables
        getline(ss, studentId, ',');
        getline(ss, tempEId, ',');
        getline(ss, regDate, ',');
        getline(ss, status, ',');

        //Check if current row is missing a data member
        // if (status.empty() && !getline(ss, major, ',')) {
        //     cerr << "Error! There is data missing from line " << i << endl;
        //     continue;
        // }



        //convert temp string IDs to int IDs and catch errors
        try {
            SId = stoi(tempSId);
            EId = stoi(tempEId);
        } catch (const exception &e) {
            cerr << "Error reading IDs. Skipped line: " << i << endl;
            continue;
        }

        Registration(SId, EId, regDate, status);
    }

    registration.close();
}

void writeRegistrations(std::string fileName, RegistrationManager rm) {

    //open txt file to save registrations
    ofstream regFile(fileName);

    //get a pointer to the vector holding the organizers
    // std::vector<Registration>* regPtr = rm.getOrganizerPointer();
    //
    // if (regPtr != nullptr) {
    //     for (const Registration& r : *regPtr) {
    //         regFile << r.studentID << "," << r.eventID << "," << o.email << "," << o.dept << '\n';
    //     }
    // }

    for (const Registration& r : rm.getAllRegistrations()) {
        regFile << r.studentID << "," << r.eventID << "," << r.registrationDate << "," << r.status << '\n';
    }

    close(regFile);
}



