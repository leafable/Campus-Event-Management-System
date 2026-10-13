#include "../include/StudentManagement.h"

StudentManagement::StudentManagement() {
    vector<Student> students;
    numStudents = 0;
}

void StudentManagement::addStudent(const Student& student) {
    if (isDuplicateId(student.getId())) {
        cout << "Error: Duplicate student ID." << endl;
    }
    else {
        students.push_back(student);
        numStudents++;
    }
}

void StudentManagement::addStudent(const int& id, const string& name, const string& email, const string& major) {
    if (isDuplicateId(id)) {
        cout << "Error: Duplicate student ID." << endl;
    }
    else {
        Student student(id, name, email, major);
        students.push_back(student);
        numStudents++;
    }
}

int StudentManagement::findById(const int& id) const {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void StudentManagement::displayStudent(const int& id) const {
    int index = findById(id);
    if (index != -1) {
        cout << "ID: " << students[index].getId() << endl;
        cout << "Name: " << students[index].getName() << endl;
        cout << "Email: " << students[index].getEmail() << endl;
        cout << "Major: " << students[index].getMajor() << endl;
    }
    else {
        cout << "Student not found." << endl;
    }
}

void StudentManagement::displayAllStudents() const {
    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].getId() << ", Name: " << students[i].getName() << ", Email: " << students[i].getEmail() << ", Major: " << students[i].getMajor() << endl;
    }
}

bool StudentManagement::isDuplicateId(const int& id) const {
    return (findById(id) != -1);
}

int StudentManagement::getNumStudents() const {
    return numStudents;
}

const vector<Student> StudentManagement::getStudentsVector(){
    return students;
}