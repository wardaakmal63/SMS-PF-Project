#include "header.h"       // Include the header file
vector<Student> students; // Global students vector

// Function to load data from file
void loadFromFile(vector<Student> &students)
{
    ifstream file("students.txt");
    if (!file)
    {
        cout << "No existing data found. Starting with an empty database.\n";
        return;
    }

    Student student;
    while (file >> student.name >> student.rollNo >> student.department >> student.semester >> student.marks >> student.cgpa >> student.contact >> student.address)
    {
        students.push_back(student);
    }
    file.close();
}

// Function to save data to file
void saveToFile(const vector<Student> &students)
{
    ofstream file("students.txt");
    for (const auto &student : students)
    {
        file << student.name << " " << student.rollNo << " "
             << student.department << " " << student.semester << " "
             << student.marks << " " << student.cgpa << " "
             << student.contact << " " << student.address << "\n";
    }
    file.close();
}

// Function to add a student
void addStudent(vector<Student> &students)
{
    Student student;
    cout << "\nEnter Student Details:\n";

    cin.ignore();
    cout << "Name: ";
    getline(cin, student.name);

    cout << "Roll No: ";
    cin >> student.rollNo;

    cin.ignore();
    cout << "Department: ";
    getline(cin, student.department);

    cout << "Semester: ";
    cin >> student.semester;

    cout << "Marks (0-100): ";
    while (!(cin >> student.marks) || student.marks < 0 || student.marks > 100)
    {
        cout << "Invalid marks! Please enter marks between 0 and 100: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "CGPA (0.0-4.0): ";
    while (!(cin >> student.cgpa) || student.cgpa < 0.0 || student.cgpa > 4.0)
    {
        cout << "Invalid CGPA! Please enter a value between 0.0 and 4.0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Contact (10-digit number): ";
    cin >> student.contact;

    cin.ignore();
    cout << "Address: ";
    getline(cin, student.address);

    students.push_back(student);
    saveToFile(students);
    cout << "\nStudent added successfully!\n";
}

// Function to display all students
void displayAllStudents(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\nNo students in database!\n";
        return;
    }

    cout << "\nStudent Details:\n";
    for (const auto &student : students)
    {
        cout << "Name: " << student.name << ", Roll No: " << student.rollNo
             << ", Department: " << student.department << ", Semester: " << student.semester
             << ", Marks: " << student.marks << ", CGPA: " << student.cgpa
             << ", Contact Number: " << student.contact << ", Address: " << student.address << "\n";
    }
}

// Function to search for a student
void searchStudent(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\nNo students in database!\n";
        return;
    }

    int rollNo;
    cout << "\nEnter Roll No to search: ";
    cin >> rollNo;

    for (const auto &student : students)
    {
        if (student.rollNo == rollNo)
        {
            cout << "\nStudent Found:\n";
            cout << "Name: " << student.name << ", Roll No: " << student.rollNo
                 << ", Department: " << student.department << ", Semester: " << student.semester
                 << ", Marks: " << student.marks << ", CGPA: " << student.cgpa
                 << ", Contact Number: " << student.contact << ", Address: " << student.address << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Function to delete a student
void deleteStudent(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\nNo students in database!\n";
        return;
    }

    int rollNo;
    cout << "\nEnter Roll No to delete: ";
    cin >> rollNo;

    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i].rollNo == rollNo)
        {
            students.erase(students.begin() + i);
            saveToFile(students);
            cout << "\nStudent deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Main function
int main()
{
    loadFromFile(students);
    int choice;

    do
    {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayAllStudents(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            deleteStudent(students);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
