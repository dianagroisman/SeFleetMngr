#include <iostream>
#include <memory>
#include <map>
#include "Application.h"
#include "Vehicle.h"

using namespace std;

void Application::Run() {
    PrintMenu ();
    
}

void Application::PrintMenu() {
    cout << "Please select an option: " << endl;
    cout << "1 - Add a new vehicle" << endl;
    cout << "2 - Report an accident" << endl;
    cout << "3 - Exit" << endl;
    
    cin >> m_option;
    cout << "Option value = " << m_option << endl;

    while ((m_option < 1) || (m_option > 3)) {
        cout << "Option value = " << m_option << endl;
        cout << "Menu options should be between 1 and 3" << endl;
        cin >> m_option;
    }
    
    Operate();
}

void Application::Operate () {
    while (m_option != 3 ) {
        switch (m_option) {
            case 1:
            CreateVehicle ();
            break;
            case 2:
            ReportAnAccident();
            break;
            case 3:
            return;
        } // switch
        
        cout << "Please select an option: " << endl;
        cin >> m_option;
    } //while
}

void Application::CreateVehicle() {
    cout << "Please enter the vehicle's serial number: " << endl;
    string serial_number;
    cin >> serial_number;
    
    cout << "Please enter the vehicle's type:" << endl;
    string vehicle_type;
    cin >> vehicle_type;
    
    // According to the instructions, validation is not needed
    if (vehicle_type == "car") {
        shared_ptr<Vehicle> v = make_shared<Car>(serial_number);
        m_vehicles[serial_number] = v;
    } else { // vehicle_type == truck
        shared_ptr<Vehicle> v = make_shared<Truck>(serial_number);
        m_vehicles[serial_number] = v;
    }
    
    cout << "You've created: " << vehicle_type <<" sn: " << serial_number << endl;
}

void Application::ReportAnAccident() {
    cout << "Please enter the 1st vehicle's sn:" << endl;
    string sn1;
    cin >> sn1;
    cout << "Please enter the 2nd vehicle's sn:" << endl;
    string sn2;
    cin >> sn2;
    
    int result = ReportAnAccident(sn1, sn2);
}

int Application::ReportAnAccident(const string& sn1, const string& sn2) {
    auto iter1 = m_vehicles.find (sn1);
    if ( iter1 != m_vehicles.end()) {
        auto iter2 = m_vehicles.find(sn2); 
        if (iter2 != m_vehicles.end()) {
            cout << "The result of the Accident is: " << *(iter1->second) - *(iter2->second);
            cout << " Status values: 1st: " << iter1->second->getStatus();
            cout << ", 2nd: " << iter2->second->getStatus()<< endl;
            
            return 0;
        } else {
            cout << "Vehicle with serial number " << sn2 << " not found" << endl;
        }  
    } else {
        cout << "Vehicle with serial number " << sn1 << " not found" << endl;
    }
    return -1;
}