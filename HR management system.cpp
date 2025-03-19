#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int employeeID;
    string name;
    string position;
    double salary;

public:
    Employee(int id, string name, string position, double salary)
        : employeeID(id), name(name), position(position), salary(salary) {}

    int getEmployeeID() const { return employeeID; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }

    void displayEmployeeDetails() const {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class HRMS {
private:
    vector<Employee> employees;

public:
    void addEmployee(int id, string name, string position, double salary) {
        Employee newEmployee(id, name, position, salary);
        employees.push_back(newEmployee);
        cout << "Employee added successfully!" << endl;
    }

    void removeEmployee(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getEmployeeID() == id) {
                employees.erase(it);
                cout << "Employee with ID " << id << " removed successfully!" << endl;
                return;
            }
        }
        cout << "Employee with ID " << id << " not found!" << endl;
    }

    void displayAllEmployees() const {
        if (employees.empty()) {
            cout << "No employees found!" << endl;
            return;
        }

        for (const auto& employee : employees) {
            employee.displayEmployeeDetails();
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    HRMS hrms;
    int choice, id;
    string name, position;
    double salary;

    while (true) {
        cout << "HRMS Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Display All Employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Position: ";
                getline(cin, position);
                cout << "Enter Salary: ";
                cin >> salary;
                hrms.addEmployee(id, name, position, salary);
                break;

            case 2:
                cout << "Enter Employee ID to remove: ";
                cin >> id;
                hrms.removeEmployee(id);
                break;

            case 3:
                hrms.displayAllEmployees();
                break;

            case 4:
                cout << "Exiting the system...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
