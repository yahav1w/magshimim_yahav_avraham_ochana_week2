#include "Profile.h"
#include <iostream>

//the function initialize the class
//owner - the owner of the profile the user
void Profile::init(User owner)
{
	user = owner;
	page = new Page();
	friends = new UserList();
}

//the function clean the class
void Profile::clear()
{
	delete(page);
	friends->clear();
}

//the function return the owner of the profile
User Profile::getOwner() const
{
	return user;
}

//the function set the value of the status
//new_status - the status that gonna riplayce the old status
void Profile::setStatus(std::string new_status)
{
	page->setStatus(new_status);
}

//the function add post to the profile page
//post - the post to add
void Profile::addPostToProfilePage(std::string post)
{
	Profile::page->addLineToPosts(post);
}

//the function add a friend to the friend list
//friend_to_add - the user of the friend we want to add
void Profile::addFriend(User friend_to_add)
{
	friends->add(friend_to_add);
}

//the function return the page the string of the page
std::string Profile::getPage() const
{
	return "Status: " + Profile::page->getStatus() +
		"\n*******************\n*******************\n"
		+ Profile::page->getPosts();
}

//the function return a list of frinds in string
std::string Profile::getFriends() const
{
	std::string res = *(new std::string());
	UserNode* temp = new UserNode();
	temp = friends->get_first();
	while (temp->get_next() != nullptr)
	{
		res = res + temp->get_data().getUserName() + ",";
		temp = temp->get_next();
	}
	res += temp->get_data().getUserName();
	return res;
}

//the function return only the friends that has the same name length
std::string Profile::getFriendsWithSameNameLength() const
{
	int numOfLetter = user.getUserName().length();
	int count = 0;
	std::string res = *(new std::string());
	UserNode* temp = new UserNode();
	temp = friends->get_first();
	while (temp->get_next() != nullptr)
	{
		if (temp->get_data().getUserName().length() == numOfLetter)
		{
			if (count == 0)
			{
				res = res + temp->get_data().getUserName();
				count++;
			}
			else
			{
				res = res + "," + temp->get_data().getUserName();
			}
		}
		temp = temp->get_next();
	}
	
	return res;
}
