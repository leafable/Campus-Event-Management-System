#pragma once
#include "Student.h"
#include <vector>

class StudentManagement {
private:
    vector<Student> students;
    static int numStudents;
public:
    StudentManagement();
    void addStudent(const Student& student);
    void addStudent(const int& id, const string& name, const string& email, const string& major);
    int findById(const int& id) const;
    void displayStudent(const int& id) const;
    void displayAllStudents() const;
    void printCSV() const;
    bool isDuplicateId(const int& id) const;
    bool studentExists(const int& id) const;
    int getNumStudents() const;
    const vector<Student> StudentManagement::getStudentsVector();
};