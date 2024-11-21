#include "Page.h"
#include <iostream>

//initializing the class
void Page::init()
{
	status = "";
	posts = "";
}

//return the posts
std::string Page::getPosts() const
{
	return posts;
}

//return the status 
std::string Page::getStatus() const
{
	return status;
}

//clean the class 
void Page::clearPage()
{
	posts = "";
}

//set the status to a get value
//status - the value to change the status to
void Page::setStatus(std::string status)
{
	Page::status = status;
}

//add post to the home page
//new_line - the new post to add
void Page::addLineToPosts(std::string new_line)
{
	posts += new_line + "\n";
}
