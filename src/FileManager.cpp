#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "../include/FileManager.h"

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

        //create a stringstream to grab line
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

}

