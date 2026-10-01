#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    string email;
    string major;
public:
    Student();
    Student(int id, const string& name, const string& email, const string& major);
    int getId() const;
    string getName() const;
    string getEmail() const;
    string getMajor() const;
};