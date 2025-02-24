#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Structure to represent a Student
struct Student
{
    string name;
    int rollNo;
    string department;
    int semester;
    float marks;
    float cgpa;
    string contact;
    string address;
};

// Function declarations
void loadFromFile(vector<Student> &students);
void saveToFile(const vector<Student> &students);
void addStudent(vector<Student> &students);
void displayAllStudents(const vector<Student> &students);
void searchStudent(const vector<Student> &students);
void deleteStudent(vector<Student> &students);

#endif