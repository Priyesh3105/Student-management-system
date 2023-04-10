#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the Student class
class Student {
public:
    string name;
    int age;
    int roll_number;
    
    // Constructor to initialize student data
    Student(string n, int a, int r) {
        name = n;
        age = a;
        roll_number = r;
    }
};

// Define the Student Management System class
class StudentManagementSystem {
private:
    vector<Student> students;  // Vector to store student data
    
public:
    // Method to add a new student record
    void addStudent(string name, int age, int roll_number) {
        Student new_student(name, age, roll_number);
        students.push_back(new_student);
        cout << "Student record added successfully." << endl;
    }
    
    // Method to modify an existing student record
    void modifyStudent(int roll_number, string new_name, int new_age) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].roll_number == roll_number) {
                students[i].name = new_name;
                students[i].age = new_age;
                cout << "Student record modified successfully." << endl;
                return;
            }
        }
        cout << "Student record not found." << endl;
    }
    
    // Method to delete an existing student record
    void deleteStudent(int roll_number) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].roll_number == roll_number) {
                students.erase(students.begin() + i);
                cout << "Student record deleted successfully." << endl;
                return;
            }
        }
        cout << "Student record not found." << endl;
    }
    
    // Method to display all student records
    void displayAllStudents() {
        if (students.size() == 0) {
            cout << "No student records found." << endl;
            return;
        }
        
        cout << "Student Records:" << endl;
        for (int i = 0; i < students.size(); i++) {
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Roll Number: " << students[i].roll_number << endl;
            cout << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;  // Create a new Student Management System object
    
    // Add some sample student records
    sms.addStudent("John", 18, 1001);
    sms.addStudent("Jane", 19, 1002);
    sms.addStudent("Mike", 20, 1003);
    
    // Display all student records
    sms.displayAllStudents();
    
    // Modify a student record
    sms.modifyStudent(1002, "Janet", 20);
    
    // Display all student records again
    sms.displayAllStudents();
    
    // Delete a student record
    sms.deleteStudent(1003);
    
    // Display all student records one last time
    sms.displayAllStudents();

   
    return 0;
}