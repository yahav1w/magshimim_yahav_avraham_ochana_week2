#include "Device.h"
#include <iostream>

/// the function initialize the class
/// id - the id of the device
/// type - from witch device he on
/// os - the operating console he use
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	Device::id = id;
	Device::type = type;
	device = os;
	active = true;
}
//return the vaue of the id
unsigned int Device::getID() const
{
	return id;
}

//return the value of the type(witch device he on)
DeviceType Device::getType() const
{
	return type;
}

//return thr value of the operating console
std::string Device::getOS() const
{
	return device;
}

//check if the device is active and return true or false respectly
bool Device::isActive() const
{
	return active;
}

//change the activation status to on(true)
void Device::activate()
{
	active = true;
}

//change the activation status to off(false)
void Device::deactivate()
{
	active = false;
}