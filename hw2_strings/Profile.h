
#include "Page.h"
#include "UserList.h"

//a class that represent the profile of the user
class Profile
{
public:
	void init(User owner);//initializing the class
	void clear();//clean the class
	User getOwner() const;//return the owner user
	//setters
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);//adding a post
	void addFriend(User friend_to_add);//adding a friend
	//getters
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;//return all the friends with the same name length

private:
	User user;//the user information
	Page* page;//the page of the user
	UserList* friends;//his friends list
};



