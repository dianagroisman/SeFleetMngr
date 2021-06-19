#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    public:
    Vehicle(const string& serialNumber) : m_serialNumber(serialNumber){};
    Vehicle() = delete;
    virtual ~Vehicle() = default;
    virtual unsigned int getStatus () const {return m_status;}
    
    unsigned int operator-(Vehicle& v) {
        if (m_status >= 10 && v.m_status >= 10) {
            m_status -= 10;
            v.m_status -= 10;
            return m_status > v.m_status ? v.m_status : m_status;
        }
    }
    
    private:
    string m_serialNumber;
    unsigned int m_status = 100;
};

class Car : public Vehicle {
    public:
    Car() = delete;
    Car (const string& serialNumber) : Vehicle (serialNumber) {};
    virtual ~Car() = default;
};

class Truck : public Vehicle {
    public:
    Truck() = delete;
    Truck (const string& serialNumber) : Vehicle (serialNumber) {};
    virtual ~Truck() = default;
};
