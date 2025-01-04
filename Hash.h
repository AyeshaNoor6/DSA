#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

const int TABLE_SIZE = 10;

// HashTableEntry class to store key-value pairs
class HashTableEntry {
public:
	std::string key;    // Username
	std::string value;  // Password
	HashTableEntry* next;

	HashTableEntry(const std::string& k, const std::string& v)
		: key(k), value(v), next(nullptr) {}
};

// HashTable class to store users' credentials
class HashTable {
private:
	HashTableEntry* table[TABLE_SIZE];  // Array of linked lists for chaining collisions

										// Hash function to map a username to an index
	int hashFunction(const std::string& key) {
		int hash = 0;
		for (char ch : key) {
			hash = (hash + ch) % TABLE_SIZE;
		}
		return hash;
	}

public:
	// Constructor to initialize the hash table
	HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			table[i] = nullptr;
		}
		loadUsersFromFile();
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
			insert(username, password);
		}

		inFile.close();
	}



	// Insert a username and password into the hash table
	void insert(const std::string& username, const std::string& password) {
		int index = hashFunction(username);
		HashTableEntry* newEntry = new HashTableEntry(username, password);

		// Collision resolution: chaining (linked list)
		if (table[index] == nullptr) {
			table[index] = newEntry;
		}
		else {
			HashTableEntry* current = table[index];
			while (current->next) {
				current = current->next;
			}
			current->next = newEntry;
		}
	}

	// Retrieve password for a given username
	std::string retrieve(const std::string& username) {
		int index = hashFunction(username);
		HashTableEntry* current = table[index];

		// Traverse the linked list at the index to find the username
		while (current != nullptr) {
			if (current->key == username) {
				return current->value;  // Return the password
			}
			current = current->next;
		}
		return "";  // Return empty if username is not found
	}

	// Check if a username exists
	bool contains(const std::string& username) {
		int index = hashFunction(username);
		HashTableEntry* current = table[index];

		while (current != nullptr) {
			if (current->key == username) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
};

#endif
