//#include<iostream>
//using namespace std;
//class Stack {
//	int data[10];
//	int top = -1;
//	int size = 10;
//public:
//	bool isempty()
//	{
//		return top == -1;
//	}
//	bool isfull()
//	{
//		return top == size;
//	}
//	void push(int num)
//	{
//		if (isfull())
//		{
//			cout << "\nstack overflow!";
//			return;
//		}
//		top++;
//		data[top] = num;
//	}
//	int pop()
//	{
//		if (isempty())
//		{
//			cout << "stackunderflow! ";
//		}
//		top--;
//		return data[top + 1];
//	}
//	bool last()
//	{
//		return top == 0;
//	}
//};
//
//class Queue {
//	Stack s1,s2;
//	int status = 1;
//	
//	public:
//		bool isempty()
//		{
//			if (status == 1)
//			{
//				return s1.isempty();
//			}
//			else
//				return s2.isempty();
//		}
//		bool isfull()
//		{
//			if (status == 1)
//			{
//				return s1.isfull();
//			}
//			else
//				return s2.isfull();
//		}
//		void enqueue()
//		{
//			int num;
//				cout << "\nEnter data: ";
//				cin >> num;
//			if (status == 1)
//			{
//				s1.push(num);
//			}
//			else
//				s2.push(num);
//				
//		}
//		void dequeue()
//		{
//			int num;
//			if (status == 1)
//			{
//				while (!s1.last())
//				{
//					num = s1.pop();
//					s2.push(num);
//				}
//				cout << endl << s1.pop();
//				status == 2;
//			}
//			else
//			{
//				while (!s2.last())
//				{
//					num = s2.pop();
//					s1.push(num);
//				}
//				cout << endl << s2.pop();
//				status == 1;
//			}
//		}
//};
//
//int main()
//{
//	Queue q;
//	int choice, value;
//
//	do {
//		std::cout << "\nMenu:\n";
//		std::cout << "1. enqueue\n";
//		std::cout << "2. dequeue\n";
//		std::cout << "3. Exit\n";
//		std::cout << "Enter your choice: ";
//		std::cin >> choice;
//
//		switch (choice) 
//		{
//		case 1: 
//			q.enqueue();
//			break;
//		case 2: // Pop
//			q.dequeue();
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