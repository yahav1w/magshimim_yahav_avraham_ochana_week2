#include "User.h"
#include <iostream>

///	the function initialize the class
/// id - the id of the user
/// username - the username of the user
/// age - the age of the user
void User::init(unsigned int id, std::string username, unsigned int age)
{
	User::id = id;
	User::username = username;
	User::age = age;
}

//the function clean the class
void User::clear()
{
	id = 0;
	username = "";
	age = 0;
	devices.clear();
}

//return the id
unsigned int User::getID() const
{
	return id;
}

//return the username
std::string User::getUserName() const
{
	return username;
}

//return the age
unsigned int User::getAge() const
{
	return age;
}

//return the devices he connected with to the account
DevicesList& User::getDevices() const
{
	DevicesList& d = *(new DevicesList());
	d = (devices);
	return d;
}

//the function adding a device to the device list
//newDevice - the new device to add to the list
void User::addDevice(Device newDevice)
{
	devices.add(newDevice);
}

//the function check if all the device are on if they do return true else return false
bool User::checkIfDevicesAreOn() const
{
	//checking if none are connected at all and if none connected retrun true
	if (&(devices) == 0 || devices.get_first() == nullptr)
	{
		return true;
	}
	bool fl = devices.get_first()->get_data().isActive();//checking the first
	DeviceNode* d = new DeviceNode();
	d = devices.get_first()->get_next();//continuing to the next
	while (fl && d != nullptr)
	{
		fl = d->get_data().isActive();//checking if the current one is active or not
		d = d->get_next();//countinuing to the next
	}
	if (fl)
	{
		return true;
	}
	return false;
}

