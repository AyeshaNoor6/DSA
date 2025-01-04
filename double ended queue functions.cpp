//#include <iostream>
//using namespace std;
//
//class Deque {
//private:
//	int* dequeArr;
//	int maxSize;
//	int front;
//	int rear;
//	int size;
//
//public:
//	Deque(int capacity) {
//		maxSize = capacity;
//		dequeArr = new int[maxSize];
//		front = -1;
//		rear = 0;
//		size = 0;
//	}
//
//	~Deque()
//	{
//		delete[] dequeArr;
//	}
//
//	bool isEmpty() 
//	{
//		return size == 0;
//	}
//
//	bool isFull() 
//	{
//		return size == maxSize;
//	}
//
//	void insertFront(int value)
//	{
//		if (isFull())
//		{
//			cout << "Deque is full. Cannot insert " << value << " at the front." << endl;
//			return;
//		}
//		if (isEmpty()) 
//		{
//			front = 0;
//			rear = 0;
//		}
//		else
//		{
//			front = (front - 1 + maxSize) % maxSize;
//		}
//		dequeArr[front] = value;
//		size++;
//	}
//
//	void insertBack(int value)
//	{
//		if (isFull()) 
//		{
//			cout << "Deque is full. Cannot insert " << value << " at the back." << endl;
//			return;
//		}
//		if (isEmpty())
//		{
//			front = 0;
//			rear = 0;
//		}
//		else {
//			rear = (rear + 1) % maxSize;
//		}
//		dequeArr[rear] = value;
//		size++;
//	}
//
//	int removeFront() {
//		if (isEmpty()) {
//			cout << "Deque is empty. Cannot remove from the front." << endl;
//			return -1;
//		}
//		int removedValue = dequeArr[front];
//		if (front == rear) {
//			front = -1;
//			rear = 0;
//		}
//		else {
//			front = (front + 1) % maxSize;
//		}
//		size--;
//		return removedValue;
//	}
//
//	int removeBack() {
//		if (isEmpty()) {
//			cout << "Deque is empty. Cannot remove from the back." << endl;
//			return -1;
//		}
//		int removedValue = dequeArr[rear];
//		if (front == rear) {
//			front = -1;
//			rear = 0;
//		}
//		else {
//			rear = (rear - 1 + maxSize) % maxSize;
//		}
//		size--;
//		return removedValue;
//	}
//
//	int getFront() {
//		if (isEmpty()) {
//			cout << "Deque is empty. No front element." << endl;
//			return -1;
//		}
//		return dequeArr[front];
//	}
//
//	int getBack() {
//		if (isEmpty()) {
//			cout << "Deque is empty. No back element." << endl;
//			return -1;
//		}
//		return dequeArr[rear];
//	}
//
//	void display() {
//		if (isEmpty()) {
//			cout << "Deque is empty." << endl;
//			return;
//		}
//		cout << "Deque elements: ";
//		for (int i = 0; i < size; i++) {
//			cout << dequeArr[(front + i) % maxSize] << " ";
//		}
//		cout << endl;
//	}
//};
//
//int main() {
//	int capacity;
//	cout << "Enter the capacity of the deque: ";
//	cin >> capacity;
//
//	Deque deque(capacity);
//	int choice, value;
//
//	do {
//		cout << "\nMenu:\n";
//		cout << "1. Insert Front\n";
//		cout << "2. Insert Back\n";
//		cout << "3. Remove Front\n";
//		cout << "4. Remove Back\n";
//		cout << "5. Display Deque\n";
//		cout << "6. Get Front\n";
//		cout << "7. Get Back\n";
//		cout << "8. Exit\n";
//		cout << "Choose an option: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "Enter value to insert at front: ";
//			cin >> value;
//			deque.insertFront(value);
//			break;
//		case 2:
//			cout << "Enter value to insert at back: ";
//			cin >> value;
//			deque.insertBack(value);
//			break;
//		case 3:
//			value = deque.removeFront();
//			if (value != -1) {
//				cout << "Removed from front: " << value << endl;
//			}
//			break;
//		case 4:
//			value = deque.removeBack();
//			if (value != -1) {
//				cout << "Removed from back: " << value << endl;
//			}
//			break;
//		case 5:
//			deque.display();
//			break;
//		case 6:
//			value = deque.getFront();
//			if (value != -1) {
//				cout << "Front element: " << value << endl;
//			}
//			break;
//		case 7:
//			value = deque.getBack();
//			if (value != -1) {
//				cout << "Back element: " << value << endl;
//			}
//			break;
//		case 8:
//			cout << "Exiting..." << endl;
//			break;
//		default:
//			cout << "Invalid choice. Please try again." << endl;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}
