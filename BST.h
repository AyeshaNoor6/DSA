#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include <fstream>
#include <sstream>
using namespace std;
struct BSTNode {
	string username;
	User* user;
	BSTNode* left;
	BSTNode* right;

	BSTNode(string uname, User* usr) : username(uname), user(usr), left(nullptr), right(nullptr) {}
};

class BST {
private:
	BSTNode* root;

	void insert(BSTNode*& node, string username, User* user)
	{
		if (!node)
		{
			node = new BSTNode(username, user);
			return;
		}
		if (username < node->username)
		{
			insert(node->left, username, user);
		}
		else if (username > node->username)
		{
			insert(node->right, username, user);
		}
	}

	User* search(BSTNode* node, string username)
	{
		if (!node) return nullptr;
		if (node->username == username)
		{
			return node->user;
		}
		if (username < node->username)
		{
			return search(node->left, username);
		}
		return search(node->right, username);
	}

	void inorder(BSTNode* node)
	{
		if (!node) return;
		inorder(node->left);
		cout << node->username << "\n";
		inorder(node->right);
	}
	void loadUsersFromFile()
	{
		ifstream inFile("users_data.txt");
		if (!inFile)
		{
			cout << "No previous data found. Starting fresh.\n";
			return;
		}

		string username, password, city, question, answer, lastLogin;
		while (getline(inFile, username))
		{
			getline(inFile, password);
			getline(inFile, city);
			getline(inFile, question);
			getline(inFile, answer);
			getline(inFile, lastLogin);

			User* newUser = new User(username, password, city, question, answer);
			newUser->lastLogin = lastLogin;
			insert(username, newUser);
		}

		inFile.close();
	}
public:
	BST() : root(nullptr)
	{
		loadUsersFromFile();
	}

	void insert(string username, User* user)
	{
		insert(root, username, user);
	}

	User* search(string username)
	{
		return search(root, username);
	}

	void display()
	{
		inorder(root);
	}
};



