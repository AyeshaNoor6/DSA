#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct Relationship {
	string type; // friend, follower
	string status; // active, blocked, pending
};

// Structure to hold the time-related information of friend requests
struct FriendRequestInfo {
	string sender;
	string receiver;
	string requestTime;
	string acceptTime;

	FriendRequestInfo(string s, string r, string reqTime, string accTime)
		: sender(s), receiver(r), requestTime(reqTime), acceptTime(accTime) {}
};
class Graph {
private:
	User* users[100]; // Array of User pointers to store users
	Relationship adjMatrix[100][100]; // Adjacency matrix for relationships
	int userCount;
	vector<FriendRequestInfo> friendRequestDetails; // Vector to store friend request times and acceptances

public:
	Graph() : userCount(0)
	{
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				adjMatrix[i][j] = { "none", "none" };
			}
		}
		loadUsersFromFile();
		loadFriendRequestDetails(); // Load friend request details
	}
	void saveFriendRequestDetails()
	{
		ofstream outFile("friend_requests.txt");
		if (!outFile)
		{
			cout << "Error opening file to save friend request data.\n";
			return;
		}

		for (auto& request : friendRequestDetails)
		{
			outFile << request.sender << "\n";
			outFile << request.receiver << "\n";
			outFile << request.requestTime << "\n";
			outFile << request.acceptTime << "\n";
		}

		outFile.close();
	}
	// Load friend request details from a file
	void loadFriendRequestDetails() {
		ifstream inFile("friend_requests.txt");
		if (!inFile) {
			cout << "No previous friend request data found.\n";
			return;
		}

		string sender, receiver, requestTime, acceptTime;
		while (getline(inFile, sender)) {
			getline(inFile, receiver);
			getline(inFile, requestTime);
			getline(inFile, acceptTime);

			// Add to the vector to store the friend request information
			friendRequestDetails.push_back(FriendRequestInfo(sender, receiver, requestTime, acceptTime));

			// Find the sender and receiver indices
			int senderIndex = findUserIndex(sender);
			int receiverIndex = findUserIndex(receiver);

			if (senderIndex == -1 || receiverIndex == -1) {
				cout << "Error: User not found while loading friend requests.\n";
				continue;
			}

			// Print the details while loading
			cout << "Loading Friend Request:\n";
			cout << "Sender: " << sender << "\n";
			cout << "Receiver: " << receiver << "\n";
			cout << "Request Time: " << requestTime << "\n";
			cout << "Accept Time: " << acceptTime << "\n";

			// Update adjMatrix based on the acceptance status
			if (acceptTime != "None") {
				adjMatrix[senderIndex][receiverIndex] = { "friend", "active" };
				adjMatrix[receiverIndex][senderIndex] = { "friend", "active" };
				cout << "Friendship Accepted and Status Updated as Active.\n";
			}
			else {
				adjMatrix[senderIndex][receiverIndex] = { "friend", "pending" };
				cout << "Friendship Pending.\n";
			}

			cout << "---------------------------------\n"; // Separator for readability
		}

		inFile.close();
	}
	// Save all users to a file
	void saveUsersToFile()
	{
		ofstream outFile("users_data.txt");
		if (!outFile)
		{
			cout << "Error opening file to save data.\n";
			return;
		}

		for (int i = 0; i < userCount; ++i)
		{
			outFile << users[i]->username << "\n";
			outFile << users[i]->password << "\n";
			outFile << users[i]->city << "\n";
			outFile << users[i]->securityQuestion << "\n";
			outFile << users[i]->securityAnswer << "\n";
			outFile << users[i]->lastLogin << "\n";
		}

		outFile.close();
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
			users[userCount++] = newUser;
		}

		inFile.close();

		cout << "Users loaded from file:\n";
		for (int i = 0; i < userCount; ++i)
		{
			cout << "Username: " << users[i]->username << "\n"
				<< "City: " << users[i]->city << "\n"
				<< "Last Login: " << users[i]->lastLogin << "\n"
				<< "Security Question: " << users[i]->securityQuestion << "\n"
				<< "Security Answer: " << users[i]->securityAnswer << "\n"
				<< "-------------------------\n";
		}

		// Display total count of users loaded
		cout << "Total users loaded: " << userCount << endl;
	}
	// Login function to update last login time
	void loginUser(string username, string password)
	{
		User* user = findUser(username);
		if (user && user->password == password)
		{
			cout << "Login successful!\n";
			user->updateLastLogin();  // Update the last login time
			cout << "Last Login Updated: " << user->lastLogin << endl << endl;  // Debugging line
			saveUsersToFile();        // Save the updated user data to file immediately after login
		}
		else
		{
			cout << "Invalid username or password.\n";
		}
	}
	void addUser(string username, string password, string city, string question, string answer)
	{
		if (findUser(username))
		{
			cout << "User " << username << " already exists.\n";
			return;
		}
		User* newUser = new User(username, password, city, question, answer);
		users[userCount++] = newUser;
		cout << "User " << username << " added successfully.\n";
	}


	User* findUser(string username)
	{
		for (int i = 0; i < userCount; ++i)
		{
			if (users[i]->username == username)
			{
				return users[i];
			}
		}
		return nullptr;
	}

	// Find user index 
	int findUserIndex(string username)
	{
		for (int i = 0; i < userCount; ++i)
		{
			if (users[i]->username == username)
			{
				return i;
			}
		}
		return -1;
	}

	void addFriendRequest(string senderUsername, string receiverUsername)
	{
		User* sender = findUser(senderUsername);
		User* receiver = findUser(receiverUsername);
		if (!sender || !receiver)
		{
			cout << "Invalid usernames.\n";
			return;
		}

		int senderIndex = findUserIndex(senderUsername);
		int receiverIndex = findUserIndex(receiverUsername);

		adjMatrix[senderIndex][receiverIndex] = { "friend", "pending" };
		receiver->friendRequests.enqueue(senderUsername);
		receiver->notifications.enqueue("Friend request from " + senderUsername);

		// Store the friend request time
		time_t now = time(0);
		char* dt = ctime(&now);
		string requestTime = string(dt);
		requestTime = requestTime.substr(0, requestTime.size() - 1); // Remove newline

		friendRequestDetails.push_back(FriendRequestInfo(senderUsername, receiverUsername, requestTime, "None"));

		cout << "Friend request sent successfully.\n";
	}

	void acceptFriendRequest(string receiverUsername, string senderUsername)
	{
		int senderIndex = findUserIndex(senderUsername);
		int receiverIndex = findUserIndex(receiverUsername);

		if (senderIndex == -1 || receiverIndex == -1)
		{
			cout << "Invalid usernames.\n";
			return;
		}

		if (adjMatrix[senderIndex][receiverIndex].status != "pending")
		{
			cout << "No friend request found.\n";
			return;
		}

		// Update relationship status
		adjMatrix[senderIndex][receiverIndex].status = "active";
		adjMatrix[receiverIndex][senderIndex] = { "friend", "active" };

		// Notify both users that they are friends now
		User* receiver = findUser(receiverUsername);
		User* sender = findUser(senderUsername);
		if (receiver)
		{
			receiver->notifications.enqueue("You are now friends with " + senderUsername);
		}
		if (sender)
		{
			sender->notifications.enqueue(receiverUsername + " accepted your friend request");
		}

		// Update the accept time for this friend request
		time_t now = time(0);
		char* dt = ctime(&now);
		string acceptTime = string(dt);
		acceptTime = acceptTime.substr(0, acceptTime.size() - 1); // Remove newline

																  // Find and update the friend request in the details vector
		for (auto& request : friendRequestDetails)
		{
			if (request.sender == senderUsername && request.receiver == receiverUsername && request.acceptTime == "None")
			{
				request.acceptTime = acceptTime;
				break;
			}
		}

		// Remove friend request from the receiver's queue
		removeFriendRequest(receiver, senderUsername);

		cout << "Friend request accepted successfully.\n";
	}

	void saveAllData()
	{
		saveUsersToFile();
		saveFriendRequestDetails(); // Save the friend request data
	}


	// Block user
	void blockUser(string blockerUsername, string blockedUsername)
	{
		int blockerIndex = findUserIndex(blockerUsername);
		int blockedIndex = findUserIndex(blockedUsername);

		adjMatrix[blockerIndex][blockedIndex] = { "blocked", "blocked" };
		adjMatrix[blockedIndex][blockerIndex] = { "blocked", "blocked" };
		cout << blockerUsername << " has blocked " << blockedUsername << ".\n";
	}
	bool isBlocked(string blockerUsername, string blockedUsername)
	{
		int blockerIndex = findUserIndex(blockerUsername);
		int blockedIndex = findUserIndex(blockedUsername);

		if (blockerIndex == -1 || blockedIndex == -1)
		{
			return false; // If either user does not exist
		}

		return adjMatrix[blockerIndex][blockedIndex].type == "blocked" &&
			adjMatrix[blockerIndex][blockedIndex].status == "blocked";
	}
	void unblockUser(string blockerUsername, string blockedUsername)
	{
		int blockerIndex = findUserIndex(blockerUsername);
		int blockedIndex = findUserIndex(blockedUsername);

		if (blockerIndex == -1 || blockedIndex == -1)
		{
			cout << "Invalid usernames.\n";
			return;
		}

		if (adjMatrix[blockerIndex][blockedIndex].type == "blocked" && adjMatrix[blockerIndex][blockedIndex].status == "blocked")
		{
			adjMatrix[blockerIndex][blockedIndex] = { "none", "none" };
			adjMatrix[blockedIndex][blockerIndex] = { "none", "none" };
			cout << blockerUsername << " has unblocked " << blockedUsername << ".\n";
		}
		else
		{
			cout << blockedUsername << " is not blocked by " << blockerUsername << ".\n";
		}
	}


	void removeFriendRequest(User* user, string senderUsername)
	{
		Queue<string> tempQueue; // Temporary queue to hold requests
		while (!user->friendRequests.isEmpty())
		{
			string currentRequest = user->friendRequests.dequeue();
			if (currentRequest != senderUsername)
			{
				tempQueue.enqueue(currentRequest); // Keep all except the accepted one
			}
		}
		// Restore the remaining requests back to the user's friendRequests queue
		while (!tempQueue.isEmpty())
		{
			user->friendRequests.enqueue(tempQueue.dequeue());
		}
	}

	void viewFollowersList(string username)
	{
		int userIndex = findUserIndex(username);
		if (userIndex == -1)
		{
			cout << "User not found.\n";
			return;
		}

		cout << "Followers of " << username << ":\n";
		bool hasFollowers = false;
		for (int i = 0; i < userCount; ++i)
		{
			if (adjMatrix[i][userIndex].type == "friend" && adjMatrix[i][userIndex].status == "active")
			{
				cout << "-> " << users[i]->username << " (friend)\n";
				hasFollowers = true;
			}
			else if (adjMatrix[i][userIndex].type == "follower" && adjMatrix[i][userIndex].status == "active")
			{
				cout << "-> " << users[i]->username << " (follower)\n";
				hasFollowers = true;
			}
		}

		if (!hasFollowers)
		{
			cout << "No followers found.\n";
		}
	}

	// Display all connections of a user
	void displayConnections(string username)
	{
		int userIndex = findUserIndex(username);
		if (userIndex == -1)
		{
			cout << "User not found.\n";
			return;
		}

		cout << "Connections for " << username << ":\n";
		for (int i = 0; i < userCount; ++i)
		{
			if (adjMatrix[userIndex][i].type != "none")
			{
				cout << "-> " << users[i]->username << " (" << adjMatrix[userIndex][i].type << ", " << adjMatrix[userIndex][i].status << ")\n";
			}
		}
	}
};




