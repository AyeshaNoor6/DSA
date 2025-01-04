//#include<iostream>
//using namespace std;
//class Queue{
//	int data[10];
//	int front;
//	int rear;
//	int size = 10;
//public:
//		Queue():front(-1),rear(-1){}
//
//		bool isempty()
//		{
//			return front == -1;
//		}
//		bool isfull()
//		{
//			return (rear + 1) % size==front;
//		}
//		void enqueue(int num)
//		{
//			if (isfull())
//			{
//				cout << "\nStack is full!";
//				return;
//			}
//			if (front == -1)
//			{
//				data[++front]=num;
//				rear++;
//			}
//			else
//			{
//				rear = (rear + 1) % size;
//				data[rear]=num;
//			}
//		}
//
//		int dequeue()
//		{
//			int num;
//			if (isempty())
//			{
//				cout << "\nQueue is empty! ";
//				
//			}
//			if (front == rear)
//			{
//				num = data[front];
//				front = -1;
//				rear = -1;
//			}
//			else
//			{
//				num = data[front];
//				front = (front + 1) % size;
//			}
//			return num;
//		}
//		int last()
//		{
//			return rear;
//		}
//};
//class Stack {
//	Queue q1, q2;
//	int status = 1;
//
//public:
//	bool isempty()
//	{
//		if (status == 1)
//		{
//			return q1.isempty();
//		}
//		else
//			return q2.isempty();
//	}
//	bool isfull()
//	{
//		if (status == 1)
//		{
//			return q1.isfull();
//		}
//		else
//			return q2.isfull();
//	}
//	void push()
//	{
//		int num;
//			cout << "\nEnter data: ";
//			cin >> num;
//		if (status == 1)
//		{
//			q1.enqueue(num);
//		}
//		else
//			q2.enqueue(num);
//			
//	}
//	void pop()
//	{
//		int num;
//		if (status == 1)
//		{
//			for (int i = 0; i <= q1.last() - 1; i++)
//			{
//				num = q1.dequeue();
//				q2.enqueue(num);
//			}
//			cout << endl << q1.dequeue();
//			status == 2;
//		}
//		else
//		{
//			for (int i = 0; i <= q2.last() - 1; i++)
//			{
//				num = q2.dequeue();
//				q1.enqueue(num);
//			}
//			cout << endl << q2.dequeue();
//			status == 1;
//		}
//	}
//};
//int main()
//{
//	Stack stack;
//	int choice, value;
//
//	do {
//		std::cout << "\nMenu:\n";
//		std::cout << "1. Push\n";
//		std::cout << "2. Pop\n";
//		std::cout << "3. Exit\n";
//		std::cout << "Enter your choice: ";
//		std::cin >> choice;
//
//		switch (choice) 
//		{
//		case 1: 
//			stack.push();
//			break;
//		case 2: // Pop
//			stack.pop();
//			break;
//		
//		case 3: // Exit
//			std::cout << "Exiting...\n";
//			break;
//		default:
//			std::cout << "Invalid choice. Please try again.\n";
//		}
//	} while (choice != 3);
//	system("pause");
//}