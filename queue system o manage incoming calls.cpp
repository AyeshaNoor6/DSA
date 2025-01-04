//#include <iostream>
//#include <chrono>
//#include <thread>
//using namespace std;
//
//struct Call {
//	int num;
//};
//
//class Queue {
//	Call numm[10]; 
//	int count;
//	int front;
//	int rear;
//
//public:
//	Queue() : count(0), front(0), rear(0) {}
//
//	bool empty()
//	{
//		return count == 0;
//	}
//
//	bool full() 
//	{
//		return count == 10; 
//
//	}
//
//	void enqueue(int number)
//	{
//		if (full())
//		{
//			cout << "Queue is full. Cannot add call: " << number << endl;
//			return;
//		}
//		numm[rear] = { number }; 
//		rear = (rear + 1) % 10; 
//		count++;
//	}
//
//	int dequeue() 
//	{
//		if (empty()) 
//		{
//			return -1; 
//		}
//		int n = numm[front].num; 
//		front = (front + 1) % 10; 
//		count--;
//		return n;
//	}
//
//	void display() 
//	{
//		cout << "Queue: [";
//		for (int i = 0; i < count; i++)
//		{
//			cout << numm[(front + i) % 10].num;
//			if (i < count - 1) cout << ", ";
//		}
//		cout << "]" << endl;
//	}
//};
//
//int main()
//{
//	Queue incomingQueue;
//	Queue waitingQueue;
//	int totalCalls;
//
//	cout << "How many incoming calls do you want to enter (up to 20)? ";
//	cin >> totalCalls;
//
//	if (totalCalls > 20)
//	{
//		cout << "Maximum number of calls is 20. Adjusting to 20." << endl;
//		totalCalls = 20;
//	}
//
//	for (int i = 0; i < totalCalls; i++)
//	{
//		int number;
//		cout << "Incoming call: ";
//		cin >> number;
//		if (incomingQueue.full())
//		{
//			waitingQueue.enqueue(number);
//		}
//		else
//		{
//			incomingQueue.enqueue(number);
//		}
//	}
//
//	cout << "\nProcessing calls...\n";
//
//	while (!incomingQueue.empty() || !waitingQueue.empty())
//	{
//		if (!incomingQueue.empty())
//		{
//			int answeredCall = incomingQueue.dequeue();
//			if (answeredCall != -1)
//			{
//				cout << "Answering call: " << answeredCall << endl;
//				this_thread::sleep_for(chrono::seconds(5));
//			}
//		}
//		if (incomingQueue.empty() && !waitingQueue.empty())
//		{
//			cout << "Moving calls from waiting queue to incoming queue...\n";
//			while (!waitingQueue.empty() && !incomingQueue.full())
//			{
//				incomingQueue.enqueue(waitingQueue.dequeue());
//			}
//		}
//	}
//
//	cout << "All calls processed.\n";
//	system("pause");
//}
