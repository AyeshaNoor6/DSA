#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"
#include <ctime>
using namespace std;
class User {
public:
	string username;
	string password;
	string city;
	string lastLogin;
	string securityQuestion;
	string securityAnswer;

	Stack<string> posts;
	Stack<string> newsFeed;
	Queue<string> notifications;
	Queue<string> friendRequests;
	Queue<string> messages;
	User* nextUser;

	User(string uname, string pwd, string c, string question, string answer)
		: username(uname), password(pwd), city(c), lastLogin("Never"),
		securityQuestion(question), securityAnswer(answer), nextUser(nullptr) {}

	void addPost(string content)
	{
		posts.push(content);
		cout << "Post added successfully.\n";
	}

	void displayPosts()
	{
		cout << "Posts of " << username << ":\n";
		posts.display();
	}
	// Update last login time
	void updateLastLogin()
	{
		time_t now = time(0);   // Get the current time
		char* dt = ctime(&now); // Convert time to string
		lastLogin = string(dt); // Store it in lastLogin
								// Remove the newline character at the end of the string
		lastLogin = lastLogin.substr(0, lastLogin.size() - 1);
	}
};




