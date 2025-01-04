#pragma once
template <typename T>
class Node {
public:
	T data;           // Stores data of the node
	Node<T>* next;    // Pointer to the next node

					  // Constructor
	Node(T value) : data(value), next(nullptr) {}
};
