#include "DeviceList.h"

//a class that keeps the data of the user
class User
{
public:
	void init(unsigned int id, std::string username, unsigned int age);//initialize the class
	void clear();//clean the class
	//getters
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices() const;
	void addDevice(Device newDevice);//add a device to the device list
	bool checkIfDevicesAreOn() const;//check if all the device are on
private:
	unsigned int id;//the id of the user
	std::string username;//the username of the user
	unsigned int age;//the age of the user
	DevicesList devices;// the devices the user conect himself with
};

