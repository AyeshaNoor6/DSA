#include <iostream>
#include <string>
using namespace std;

// Struct for representing an account holder
struct AccountHolder {
	int accountNumber;
	string name;
	int priority;
};

// Class for managing the priority queue
class PriorityQueue {
private:
	AccountHolder* queue; // Dynamic array for the queue
	int capacity;         // Maximum capacity of the queue
	int size;             // Current size of the queue

public:
	// Constructor to initialize the queue
	PriorityQueue(int capacity) {
		this->capacity = capacity;
		queue = new AccountHolder[capacity];
		size = 0;
	}

	// Destructor to free memory
	~PriorityQueue() {
		delete[] queue;
	}

	// Function to add an account holder to the queue
	void enqueue(int accountNumber, const string& name, int priority) {
		if (size >= capacity) {
			cout << "Queue is full. Cannot add account: " << name << endl;
			return;
		}
		// Create a new account holder
		AccountHolder newAccount = { accountNumber, name, priority };
		queue[size] = newAccount; // Add to the end of the queue
		size++;
		// Sort the queue based on priority after adding
		sortQueue();
		cout << "Account added: " << name << " with priority " << priority << endl;
	}

	// Function to process the highest priority account
	void dequeue() {
		if (size == 0) {
			cout << "No accounts to process.\n";
			return;
		}
		AccountHolder topAccount = queue[0]; // Get the highest priority account
		cout << "Processing account: " << topAccount.name
			<< " (Account Number: " << topAccount.accountNumber
			<< ", Priority: " << topAccount.priority << ")\n";
		// Shift all accounts down
		for (int i = 1; i < size; i++) {
			queue[i - 1] = queue[i];
		}
		size--; // Decrease size
	}

	// Function to display the accounts in the queue
	void display() {
		if (size == 0) {
			cout << "No accounts in the queue.\n";
			return;
		}
		cout << "Current accounts in the queue:\n";
		cout << "Account Number\tName\t\tPriority\n";
		for (int i = 0; i < size; i++) {
			cout << queue[i].accountNumber << "\t\t"
				<< queue[i].name << "\t\t"
				<< queue[i].priority << endl;
		}
	}

private:
	// Function to sort the queue based on priority (higher priority first)
	void sortQueue() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (queue[j].priority < queue[j + 1].priority) {
					// Swap accounts
					AccountHolder temp = queue[j];
					queue[j] = queue[j + 1];
					queue[j + 1] = temp;
				}
			}
		}
	}
};

int main() {
	PriorityQueue pq(10); // Create a priority queue with a capacity of 10
	int choice;

	do {
		cout << "\nMenu:\n";
		cout << "1. Add Account\n";
		cout << "2. Process Account\n";
		cout << "3. Display Accounts\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int accountNumber, priority;
			string name;
			cout << "Enter account number: ";
			cin >> accountNumber;
			cout << "Enter account holder's name: ";
			cin.ignore(); // Clear the newline from the input buffer
			getline(cin, name);
			cout << "Enter priority (higher number = higher priority): ";
			cin >> priority;
			pq.enqueue(accountNumber, name, priority);
			break;
		}
		case 2:
			pq.dequeue();
			break;
		case 3:
			pq.display();
			break;
		case 4:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);
	system("pause");
	return 0;
}
