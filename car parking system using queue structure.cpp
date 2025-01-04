#include<iostream>
#include<string>
using namespace std;
struct model {
	int suzuki = 0;
	int cultus = 0;
	int mehran = 0;
	int Audi = 0;
	int tesla = 0;
};
struct car {
	int car_no;
	string name;
	int start;
	int end;
	int type;
};
class queue {
	car cars[10];
	int front;
	int rear;
	int capacity;
	model type;
public:
	queue():front(-1),rear(-1),capacity(10){}

	//empty
	bool isempty()
	{
		return front == -1;
	}
	//fulll
	bool isfull()
	{
		return (rear + 1) % capacity == front;
	}
	//enqueue
	void enqueue()
	{
		if (isfull())
		{
			cout << "\nSorry1 parking is full. ";
			return;
		}
		else
		{
			int start,num;
			string temp;
			cout << "\nEnter car number: ";
			cin >> num;
			cin.ignore();
			cout << "Enter car name: ";
			getline(cin, temp);
			cout << "Enter car model:\n1. suzuki\n2. mehran\n3. tesla\n4. cultus\n5. Audi\n ";
			int choice;
			cin >> choice;
			if (choice == 1)type.suzuki++;
			else if (choice == 2)type.mehran++;
			else if (choice == 3)type.tesla++;
			else if (choice == 4)type.cultus++;
			else type.Audi++;
			cout << "enter start time in hours only: ";
			cin >> start;
			if (front == -1)
			{
				front++;
				rear++;
				cars[front].car_no = num;
				cars[front].name = temp;
				cars[front].start = start;
				if (choice == 1)cars[front].type = 1;
				else if (choice == 2)cars[front].type=2;
				else if (choice == 3)cars[front].type = 3;
				else if (choice == 4)cars[front].type = 4;
				else cars[front].type = 5;
			}
			else
			{
				rear = (rear + 1) % capacity;
				cars[rear].car_no = num;
				cars[rear].name = temp;
				cars[rear].start = start;
				if (choice == 1)cars[rear].type = 1;
				else if (choice == 2)cars[rear].type = 2;
				else if (choice == 3)cars[rear].type = 3;
				else if (choice == 4)cars[rear].type = 4;
				else cars[rear].type = 5;
			}
		}
	}

	//dequeue
	void dequeue()
	{
		if (isempty())
		{
			cout << "\nParking already empty.";
			return;
		}
		else
		{
			int end;
			cout << "enter end tme in hours only: ";
			cin >> end;
		    cars[front].end = end;
			int rate = cars[front].end - cars[front].start;
			if (rate % 2 == 0)
				rate = 10 * (rate / 2);
			else
				rate = 5 + (10 * ((rate - 1) / 2));
			cout << "Car Number: "<<cars[front].car_no;
			cout << "\nCar name: " << cars[front].name;
			cout << "\nStarting time: " << cars[front].start;
			cout << "\nEnd time: " << cars[front].end;
			cout << "\ncharges: " << rate;
			if (cars[front].type == 1)type.suzuki--;
			else if (cars[front].type == 2)type.mehran--;
			else if (cars[front].type == 3)type.tesla--;
			else if (cars[front].type == 4)type.cultus--;
			else type.Audi--;
			front = (front + 1) % capacity;
		}

	}
	//void show
	void print()
	{
		cout << endl;
		if (type.suzuki != 0)
			cout << "\nSuzuki : " << type.suzuki;
		if (type.mehran != 0)
			cout << "\nMehran : " << type.mehran;
		if (type.Audi != 0)
			cout << "\nAudi : " << type.Audi;
		if (type.cultus != 0)
			cout << "\nCultus : " << type.cultus;
		if (type.tesla != 0)
			cout << "\nTesla : " << type.tesla;
	}
}; 
int main()
{
	queue q;
	int choice;

	do {
		cout << "\n--- Parking Management System ---";
		cout << "\n1. Add Car (Enqueue)";
		cout << "\n2. Remove Car (Dequeue)";
		cout << "\n3. Show Car Statistics";
		cout << "\n4. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			q.enqueue();
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.print();
			break;
		case 4:
			cout << "Exiting the program.";
			break;
		default:
			cout << "Invalid choice, please try again.";
		}
	} while (choice != 4);

	system("pause");
}