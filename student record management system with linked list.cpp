//#include<iostream>
//#include<string>
//using namespace std;
////node class
//class Node {
//public:
//	int info;
//	float cgpa;
//	string name;
//	int semester;
//	Node* next;
//	Node(int val, float cg, string n, int sem) :info(val), cgpa(cg), name(n), semester(sem), next(nullptr) {}
//};
////linked list
//class Linkedlist {
//	Node* head = nullptr;
//	Node* newnode = nullptr;
//	Node* current = nullptr;
//	int count = 0;
//public:
//	Linkedlist() {}
//	//destructor
//	~Linkedlist()
//	{
//		current = head;
//		newnode = nullptr;
//		while (current != nullptr)
//		{
//			newnode = current->next;
//			delete current;
//			current = newnode;
//		}
//		current = nullptr;
//		newnode = nullptr;
//		delete current;
//		delete newnode;
//	}
//	void add(int roll, float cgp, string nam, int sem, int num)
//	{
//		//at first
//		newnode = new Node(roll, cgp, nam, sem);
//		if (cgp < 3)
//			{
//				cout << "\nCGPA is less then 3. Record cannot be saved. Try to excell your studies instead of sitting in cafe!";
//				return;
//			}
//		if (num == 1)
//		{
//			if (head == nullptr)
//			{
//				head = newnode;
//			}
//			else
//			{
//				current = head;
//				head = newnode;
//				head->next = current;
//			}
//		}
//		//at last
//		if (num == 2)
//		{
//			if (head == nullptr)
//			{
//				head = newnode;
//			}
//			else
//			{
//
//			current = head;
//			while (current->next != nullptr)
//			{
//				current = current->next;
//			}
//			current->next = newnode;
//			}
//		}
//		//at specific position
//		if (num == 3)
//		{
//			cout << "\nenter index:";
//			cin >> num;
//			for (int i = 1; i < num - 1 && current != NULL; i++)
//			{
//				if (current->next == NULL)
//				{
//					cout << "out of bound index " << i;
//					return;
//				}
//				current = current->next;
//			}
//			newnode->next = current->next;
//			current->next = newnode;
//		}
//	}
//	//print
//	void print()
//	{
//		current = head;
//		while (current != nullptr)
//		{
//			cout << "\n\nRoll No: " << current->info << "\nCGPA: " << current->cgpa << "\nName: " << current->name << "\nSemester: " << current->semester;
//			current = current->next;
//		}
//	}
//	//sorting function
//	void sort()
//	{
//		current = head;
//		newnode = head;
//		while(newnode!=nullptr)
//		{
//			current = head;
//			while (current->next != nullptr)
//			{
//				if (current->info > current->next->info)
//				{
//					int data = current->info;
//					current->info = current->next->info;
//					current->next->info = data;
//
//					data = current->semester;
//					current->semester = current->next->semester;
//					current->next->semester = data;
//
//					float temp = current->cgpa;
//					current->cgpa = current->next->cgpa;
//					current->next->cgpa = temp;
//
//					string n = current->name;
//					current->name = current->next->name;
//					current->next->name = n;
//				}
//				current = current->next;
//			}
//			newnode = newnode->next;
//		}
//	}
//	//deleteing fucntion
//	void del() {
//		int num;
//		cout << "\nEnter roll number of the student to be deleted: ";
//		cin >> num;
//
//		// Handle deletion
//		if (head == nullptr) return;
//
//		if (head->info == num) {
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//			return;
//		}
//
//		current = head;
//		while (current->next != nullptr && current->next->info != num) {
//			current = current->next;
//		}
//
//		if (current->next != nullptr) {
//			Node* temp = current->next;
//			current->next = current->next->next;
//			delete temp;
//			cout << "\nRecord succesfully deleted!";
//		}
//		else {
//			cout << "\nRoll number not found." << endl;
//		}
//	}
//	//finding function
//	void find()
//	{
//		int roll;
//		cout << "\nEnter Roll No to find: ";
//		cin >> roll;
//		current = head;
//			bool flag = false;
//		while (current != nullptr)
//		{
//			if (current->info == roll)
//			{
//				flag = true;
//				cout << "\nStudent data with this Roll No: \nRoll No: " << current->info << "\nCGPA: " << current->cgpa << "\nSemester: " << current->semester << "\nName: " << current->name;
//			
//			}
//			current = current->next;
//		}
//			if (!flag)
//			{
//				cout << "\nNo student record found with this Roll No.";
//			}
//	}
//	//maximum cgpa
//	void maxgpa()
//	{
//
//		current = head;
//		newnode = head;
//		while (newnode != nullptr)
//		{
//			current = head;
//			while (current->next != nullptr)
//			{
//				if (current->cgpa < current->next->cgpa)
//				{
//					int data = current->info;
//					current->info = current->next->info;
//					current->next->info = data;
//
//					data = current->semester;
//					current->semester = current->next->semester;
//					current->next->semester = data;
//
//					float temp = current->cgpa;
//					current->cgpa = current->next->cgpa;
//					current->next->cgpa = temp;
//
//					string n = current->name;
//					current->name = current->next->name;
//					current->next->name = n;
//				}
//				current = current->next;
//			}
//			newnode = newnode->next;
//		}
//		current = head;
//		cout<<"\n\tStudent with maximum cgpa:  \nRoll No: " << current->info << "\nCGPA: " << current->cgpa << "\nSemester: " << current->semester << "\nName: " << current->name; 
//		sort();
//	}
//};
//int main()
//{
//	Linkedlist list;
//	int roll, i = 0;
//	int num;
//	int sem;
//	string nam;
//	float cgp;
//	while (1)
//	{
//		system("cls");
//		cout << "\tStudent Record Management system!\n1. Enter record of Student\n2. Sort the list\n3. Delete a specific item\n4. Search record through Roll No\n5. Find maximum CGPA\n6. Print The list\n7. Exit from system\nEnter your choice: ";
//		cin >> num;
//		switch (num)
//		{
//		case 1:
//		cout << "\nEnter Rollno: ";
//		cin >> roll;
//		cout << "enter CGPA: ";
//		cin >> cgp;
//		cout << "Enter semester: ";
//		cin >> sem;
//		cout << "Enter name: ";
//		cin.ignore();
//		getline(cin, nam);
//		cout << "Enter 1 for first index\nEnter 2 for last index\nEnter 3 for specific index\n";
//		cin >> num;
//		list.add(roll, cgp, nam, sem, num);
//		i++;
//		break;
//		case 2:
//	      list.sort();
//		  system("pause");
//		  break;
//		case 3:
//			list.del();
//			system("pause");
//			break;
//		case 4:
//			list.find();
//			system("pause");
//			break;
//		case 5:
//			list.maxgpa();
//			system("pause");
//			break;
//		case 6:
//			list.print();
//			system("pause");
//			break;
//		case 7:
//			exit(0);
//			break;
//		default:
//			break;
//
//		}
//	}
//	list.print();
//	cout << "\n\tList after sorting: \n";
//	list.print();
//	list.del();
//	list.print();
//	list.find();
//	list.maxgpa();
//	system("pause");
//}