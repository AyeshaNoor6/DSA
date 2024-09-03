
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	string data;
	Node* next;
	Node(string d) : data(d), next(nullptr) {}
};

// Train class to manage the linked list of bogies and engines
class Train {
public:
	Node* head;
	Train() : head(nullptr) {}

	void append(string data)
	{
		Node* newNode = new Node(data);
		if (head == nullptr) 
		{
			head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->next != nullptr) 
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	// Print the train
	void print() 
	{
		Node* temp = head;
		while (temp != nullptr) 
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// Reverse the linked list
	void reverse()
	{
		Node* prev = nullptr;
		Node* curr = head;
		Node* next = nullptr;
		while (curr != nullptr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	// Join this train to another train (Train2) at the end
	void join(Train& other)
	{
		if (head == nullptr)
		{
			head = other.head;
		}
		else
		{
			Node* temp = head;
			while (temp->next != nullptr) 
			{
				temp = temp->next;
			}
			temp->next = other.head;
		}
	}
};

int main() {
	// Create Train1
	Train train1;
	train1.append("Engine1");
	train1.append("Bogie1");
	train1.append("Bogie2");
	train1.append("Bogie3");
	train1.append("Engine2");

	cout << "Train 1: ";
	train1.print();

	// Create Train2
	Train train2;
	train2.append("Engine3");
	train2.append("Bogie4");
	train2.append("Bogie5");
	train2.append("Bogie6");
	train2.append("Engine4");

	cout << "Train 2: ";
	train2.print();

	// Reverse Train2
	train2.reverse();

	cout << "Reversed Train 2: ";
	train2.print();

	// Join Train2 to Train1
	train1.join(train2);

	cout << "Combined Train: ";
	train1.print();
	system("pause");
}
