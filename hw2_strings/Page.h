#include <string>

//a class to represent the home page of the user
class Page
{
public:
	void init();//initializing the class
	//geters
	std::string getPosts() const;
	std::string getStatus() const;
	void clearPage();//clean the class
	//setters
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);//add post to the user home page
private:
	std::string status;// his status
	std::string posts;// his posts
};
