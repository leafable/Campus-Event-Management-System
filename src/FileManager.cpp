#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "FileManager.h"

#include "CareerEvent.h"
#include "ClubEvent.h"
#include "StudentManagement.h"


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

void FileManager::writeStudents(string fileName) {

};

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
            AcademicEvent::addEvent(name, description, date, istart, location,
                imaxcap, org, flength, department, speaker);
        }
        else if (description == "Career Event") {
            string company, recruiter;
            getline(ss, company, ',');
            getline(ss, recruiter, ',');
            CareerEvent::addEvent(name, description, date, istart, location,
                imaxcap, org, flength, company, recruiter);
        }
        else if (description == "Club Event") {
            string department, speaker;
            getline(ss, department, ',');
            getline(ss, speaker, ',');
            ClubEvent::addEvent(name, description, date, istart, location,
                imaxcap, org, flength, department, speaker);
        }
        else if (description == "Social Event") {
            string department, speaker;
            getline(ss, department, ',');
            getline(ss, speaker, ',');
            ClubEvent::addEvent(name, description, date, istart, location,
                imaxcap, org, flength, department, speaker);
        }
        else {
            cerr << "Error reading event type. Skipped line: " << i << endl;
        }
    }
    eventFile.close();
}



