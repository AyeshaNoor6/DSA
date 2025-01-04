#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template <typename T>
class Stack {
private:
	Node<T>* top;
public:
	Stack() : top(nullptr) {}

	void push(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = top;
		top = newNode;
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty!";
		}
		Node<T>* temp = top;
		T value = top->data;
		top = top->next;
		delete temp;
		return value;
	}

	T peek()
	{
		if (isEmpty())
		{
			cout << "Stack is empty!";
		}
		return top->data;
	}

	bool isEmpty()
	{
		return top == nullptr;
	}

	void display()
	{
		Node<T>* current = top;
		while (current)
		{
			cout << current->data << "\n";
			current = current->next;
		}
	}

	~Stack()
	{
		while (!isEmpty()) pop();
	}
};



