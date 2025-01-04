#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "functions.h"
#include "User.h"
#include "Graph.h"
#include "BST.h"
#include "Hash.h"
void runMyMain()
{
	Graph graph;      // To manage users and relationships
	BST bst;          // For searching users efficiently
	HashTable hashTable; 
	string loggedInUser;
	displayFrontScreen();
	int choice;
	do {
		if (loggedInUser.empty())
		{
			displayInitialMenu(); // Show only Signup and Login if not logged in
		}
		else
		{
			cout << endl;
			displayLoggedInMenu(); // Show all options after logging in
			cout << endl;
		}
		setConsoleColor(2, 0);
		cin >> choice;

		switch (choice)
		{
		case 1: // Signup
		{
			string username, password, city, question, answer;
			cout << "Enter username: ";
			cin >> username;

			// Check if the username already exists in the hash table
			if (hashTable.contains(username)) {
				cout << "Username already taken. Please choose another one.\n";
				break;
			}

			cout << "Enter password: ";
			cin >> password;
			cout << "Enter city: ";
			cin >> city;
			cout << "Enter security question: ";
			cin.ignore();
			getline(cin, question);
			cout << "Enter answer to the security question: ";
			getline(cin, answer);

			// Add user to the graph and the BST as before
			graph.addUser(username, password, city, question, answer);
			User* user = graph.findUser(username);
			if (user) bst.insert(username, user);

			// Insert username and password into the hash table
			hashTable.insert(username, password);
			break;
		}

		case 2: // Login
		{
			string username, password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			// Retrieve the password from the hash table
			string storedPassword = hashTable.retrieve(username);

			// Check if the password matches
			if (storedPassword == password) {
				graph.loginUser(username, password);  // Login and update last login
				loggedInUser = username;  // If login is successful, set loggedInUser
				cout << "Login successful.\n";
			}
			else {
				cout << "Invalid username or password.\n";
			}
			break;
		}

		case 3: // Logout
		{
			loggedInUser.clear();
			cout << "Logged out successfully.\n";
			break;
		}
		case 4: // Send Follow Request
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			string receiverUsername;
			cout << "Enter username to send a follow request: ";
			cin >> receiverUsername;

			if (graph.isBlocked(loggedInUser, receiverUsername) || graph.isBlocked(receiverUsername, loggedInUser))
			{
				cout << "Follow request could not be sent. The user has blocked you or you have blocked the user.\n";
				break;
			}

			graph.addFriendRequest(loggedInUser, receiverUsername);
			break;
		}

		case 5: // View/Accept Friend Requests
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			User* user = graph.findUser(loggedInUser);
			if (user)
			{
				cout << "Friend Requests:\n";
				user->friendRequests.display();
				string senderUsername;
				cout << "Enter username to accept friend request (or 'none' to skip): ";
				cin >> senderUsername;
				if (senderUsername != "none")
				{
					if (graph.isBlocked(loggedInUser, senderUsername) || graph.isBlocked(senderUsername, loggedInUser))
					{
						cout << "Friend request cannot be accepted. The user has blocked you or you have blocked the user.\n";
					}
					else
					{
						graph.acceptFriendRequest(loggedInUser, senderUsername);
					}
				}
			}
			break;
		}

		case 6: // Create Post
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}

			User* user = graph.findUser(loggedInUser);
			if (user)
			{
				string content;
				cout << "Enter post content: ";
				cin.ignore();
				getline(cin, content);
				user->addPost(content);
			}
			break;
		}
		case 7: // View Newsfeed
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}

			User* user = graph.findUser(loggedInUser);
			if (user)
			{
				cout << "Newsfeed:\n";
				user->newsFeed.display();
			}
			break;
		}
		case 8: // View Notifications
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}

			User* user = graph.findUser(loggedInUser);
			if (user)
			{
				cout << "Notifications:\n";
				user->notifications.display();
			}
			break;
		}
		case 9: // Send Message
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			string receiverUsername, message;
			cout << "Enter receiver's username: ";
			cin >> receiverUsername;

			if (graph.isBlocked(loggedInUser, receiverUsername) || graph.isBlocked(receiverUsername, loggedInUser))
			{
				cout << "Message could not be sent. The user has blocked you or you have blocked the user.\n";
				break;
			}

			cout << "Enter message: ";
			cin.ignore();
			getline(cin, message);

			User* receiver = graph.findUser(receiverUsername);
			if (receiver)
			{
				receiver->messages.enqueue("Message from " + loggedInUser + ": " + message);
				cout << "Message sent successfully.\n";
			}
			else
			{
				cout << "User not found.\n";
			}
			break;
		}

		case 10: // Search Users
		{
			string username;
			cout << "Enter username to search: ";
			cin >> username;

			User* user = bst.search(username);
			if (user)
			{
				cout << "User found: " << username << " (" << user->city << ")\n";
			}
			else
			{
				cout << "User not found.\n";
			}
			break;
		}
		case 11: // View Follower's List
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			graph.viewFollowersList(loggedInUser);
			break;
		}

		case 12: // View User's Posts
		{
			string username;
			cout << "Enter username: ";
			cin >> username;

			User* user = graph.findUser(username);
			if (user)
			{
				user->displayPosts();
			}
			else
			{
				cout << "User not found.\n";
			}
			break;
		}
		case 13: // View Messages
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}

			User* user = graph.findUser(loggedInUser);
			if (user)
			{
				cout << "Messages:\n";
				user->messages.display();
			}
			break;
		}
		case 14: // View Connections
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			graph.displayConnections(loggedInUser);
			break;
		}
		case 15: // Block a User
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			string blockedUsername;
			cout << "Enter the username to block: ";
			cin >> blockedUsername;

			User* blockedUser = graph.findUser(blockedUsername);
			if (!blockedUser)
			{
				cout << "User not found.\n";
				break;
			}

			graph.blockUser(loggedInUser, blockedUsername);
			break;
		}
		case 16: // Reset Password
		{
			resetPassword(graph);
			break;
		}
		case 17: // Unblock a User
		{
			if (loggedInUser.empty())
			{
				cout << "Please login first.\n";
				break;
			}
			string blockedUsername;
			cout << "Enter the username to unblock: ";
			cin >> blockedUsername;

			User* blockedUser = graph.findUser(blockedUsername);
			if (!blockedUser)
			{
				cout << "User not found.\n";
				break;
			}

			graph.unblockUser(loggedInUser, blockedUsername);
			break;
		}

		case 0:
			graph.saveAllData();  // Save users before exiting
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 0);
}