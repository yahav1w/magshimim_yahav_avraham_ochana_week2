#include "SocialNetwork.h"
#include <string>
void SocialNetwork::init(std::string networkName, int minAge)
{
	name = networkName;
	SocialNetwork::minAge = minAge;
	profiles = new ProfileList();
}

void SocialNetwork::clear()
{
	profiles->clear();
	delete(profiles);
}

std::string SocialNetwork::getNetworkName() const
{
	return name;
}

int SocialNetwork::getMinAge() const
{
	return minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() >= minAge)
	{
		profiles->add(profile_to_add);
		return true;
	}
	return false;
}

std::string SocialNetwork::getWindowsDevices() const
{
	std::string* res = new std::string();
	int count = 0;
	ProfileNode* prolist = profiles->get_first();
	DeviceNode* devlist = prolist->get_data().getOwner().getDevices().get_first();
	while (prolist != nullptr)
	{
		while (devlist!= nullptr)
		{
			int num = devlist->get_data().getID();
			if (!devlist->get_data().getOS().find("Windows"))
			{
				if (count != 0)
				{
					res->append(", ");
				}
				res->append("[");
				res->append(std::to_string(num));
				res->append(", ");
				res->append(devlist->get_data().getOS());
				res->append("]");
				count++;
				
			}
			devlist = devlist->get_next();
		}
		prolist = prolist->get_next();
		if(prolist != nullptr)
		devlist = prolist->get_data().getOwner().getDevices().get_first();
	}
	
	return *res;
}
