#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
};

vector<Student> students;

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student Added!\n";
}

void viewStudents() {
    for (auto s : students) {
        s.display();
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            s.display();
            return;
        }
    }
    cout << "Not found\n";
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Deleted!\n";
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n1.Add\n2.View\n3.Search\n4.Delete\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: deleteStudent(); break;
        case 5: return 0;
        default: cout << "Invalid\n";
        }
    }
}