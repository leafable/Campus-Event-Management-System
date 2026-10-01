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
    void addStudent(const int id, const string& name, const string& email, const string& major);
    int findById(int id) const;
    void displayStudent(int id) const;
    void displayAllStudents() const;
    bool isDuplicateId(int id) const;
    bool studentExists(int id) const;
    int getNumStudents() const;
};