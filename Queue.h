#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template <typename T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue() : front(nullptr), rear(nullptr) {}

	void enqueue(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		if (isEmpty())
		{
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	T dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty!";
		}
		Node<T>* temp = front;
		T value = front->data;
		front = front->next;
		if (!front)
		{
			rear = nullptr;
		}
		delete temp;
		return value;
	}

	bool isEmpty()
	{
		return front == nullptr;
	}

	void display()
	{
		Node<T>* current = front;
		while (current)
		{
			cout << current->data << "\n";
			current = current->next;
		}
	}

	~Queue()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}
};




