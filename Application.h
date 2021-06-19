#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;

class Vehicle;

class Application {
    public:
    Application() = default;
    ~Application() = default;
    
    void Run();
    
    private:
    void PrintMenu ();
    void Operate ();
    void CreateVehicle ();
    void ReportAnAccident();
    int ReportAnAccident(const string& sn1, const string& sn2);
    int m_option;
    map<string, shared_ptr<Vehicle>> m_vehicles;
};



