#include <iostream>
#include <string>

using namespace std;
class Device 
{
    std::string devName;
    int devID;
    int allocateDevID();     
public:
    void setDevName(const std::string &str);
    void showDeviceDetais();

};

void Device:: setDevName(const std::string &str)
{
   devName = str;
   devID = allocateDevID();

}
int Device::allocateDevID()
{
    static int id  = 100;
    ++id; return id-1;
}

void demo_device_class_des()
{
   Device oDeviceEvalA;
   oDeviceEvalA.setDevName("Character1");
   oDeviceEvalA.showDeviceDetais();
   Device *pDeviceEvalA = new Device;
   Device &rDeviceEvalA = oDeviceEvalA;

}

void Device:: showDeviceDetais()
{
   cout <<"Device Details: " << endl;
   cout <<"Device Name = " << devName <<endl;
   cout << "Device Id =" << devID;
}

int main()
{

   demo_device_class_des();

}
