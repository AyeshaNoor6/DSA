//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct Student {
//	string name;
//	int roll_no;
//	int semester;
//	float cgpa;
//};
//
//class CircularQueue {
//	Student queue[10];
//	int front, rear, count;
//
//public:
//	CircularQueue() 
//	{
//		front = -1;
//		rear = -1;
//		count = 0;
//	}
//
//	bool isFull()
//	{
//		return count == 10;
//	}
//
//	bool isEmpty()
//	{
//		return count == 0;
//	}
//
//	void enqueue(Student s) 
//	{
//		rear = (rear + 1) % 10;
//		queue[rear] = s;
//		if (front == -1) front = 0;  
//		if (isFull())
//		{
//			front = (front + 1) % 10;  
//		}
//		else
//		{
//			count++;
//		}
//	}
//
//	void display()
//	{
//		if (isEmpty())
//		{
//			cout << "No students enrolled in the 10-size queue.\n";
//			return;
//		}
//		cout << "List of enrolled students in the 10-size queue:\n";
//		for (int i = 0; i < count; i++)
//		{
//			int index = (front + i) % 10;
//			cout << "Name: " << queue[index].name
//				<< ", Roll No: " << queue[index].roll_no
//				<< ", Semester: " << queue[index].semester
//				<< ", CGPA: " << queue[index].cgpa << endl;
//		}
//	}
//};
//
//class PreservedQueue {
//	Student queue[20];
//	int count;
//
//public:
//	PreservedQueue()
//	{
//		count = 0;
//	}
//
//	void addPreserved(Student s)
//	{
//		if (count < 20) 
//		{
//			queue[count] = s;
//			count++;
//		}
//	}
//
//	void display() 
//	{
//		if (count == 0)
//		{
//			cout << "No students enrolled in the 20-size queue.\n";
//			return;
//		}
//		cout << "List of enrolled students in the 20-size queue:\n";
//		for (int i = 0; i < count; i++) 
//		
//		{
//			cout << "Name: " << queue[i].name
//				<< ", Roll No: " << queue[i].roll_no
//				<< ", Semester: " << queue[i].semester
//				<< ", CGPA: " << queue[i].cgpa << endl;
//		}
//	}
//};
//
//int main() 
//{
//	CircularQueue cq;
//	PreservedQueue pq;
//
//	int choice;
//
//	while (true) 
//	{
//		cout << "\nMenu:\n";
//		cout << "1. Enroll Student\n";
//		cout << "2. Display 10-size Queue Students\n";
//		cout << "3. Display 20-size Queue Students\n";
//		cout << "4. Exit\n";
//		cout << "Choose an option: ";
//		cin >> choice;
//
//		if (choice == 1)
//		{
//			Student s;
//			cout << "Enter Student Name: ";
//			cin >> s.name;
//			cout << "Enter Roll Number: ";
//			cin >> s.roll_no;
//			cout << "Enter Semester: ";
//			cin >> s.semester;
//			cout << "Enter CGPA: ";
//			cin >> s.cgpa;
//
//			// Enroll in the 10-size queue
//			cq.enqueue(s);
//
//			// Preserve data in the 20-size queue if there's space
//			pq.addPreserved(s);
//		}
//		else if (choice == 2)
//		{
//			cq.display();
//		}
//		else if (choice == 3)
//		{
//			pq.display();
//		}
//		else if (choice == 4)
//		{
//			cout << "Exiting...\n";
//			break;
//		}
//		else {
//			cout << "Invalid choice. Please try again.\n";
//		}
//	}
//
//	system("pause");
//}
