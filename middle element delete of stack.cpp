#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class Stack {
	int* data;
	int top = 0;
	int size;
public:
	Stack(int n)
	{
		size = n;
		data = new int[size];
	}
	//destructor
	~Stack()
	{
		delete[] data;
	}
	bool empty()
	{
		if (top == 0)return 1;
		return 0;
	}
	bool full()
	{
		if (top == size )return true;
		return false;
	}
	void push(int n)
	{
		if (!full())
		{
			data[top] = n;
			top++;
			return;
		}
		cout << "\nStack overflow!";
	}
	void peek(int& n)
	{
		if (!empty())
		{
			n = data[top];
			return;
		}
		cout << "\nStackunderflow!";
	}
	void pop()
	{
		if (!empty())
		{
			data[top] = 0;
			top--;
			return;
		}
		cout << "\nStackunderflow!";
	}
	void middle()
	{
		srand(time(0));
		if (size % 2 == 0)
		{
			int middle = size / 2-1;
			data[middle++] =  rand() % 10;
			data[middle] =rand() % 10;
			data[top-2] =  rand() % 10;
		}
		else {
			int middle = size / 2 ;
			data[middle] =  rand() % 10;
			data[top - 2] =  rand() % 10;
		}
	}
	void show()
	{
		int i = 0;
		while (i != top)
		{
			cout << data[i];
		i++;
	}

		}
};
int main()
{
	int size,n;
	cout << "\nEnter size of stack: ";
	cin >> size;
	Stack stack(size);
	cout << "\nEnter elemnts one by one: ";
	for (int i = 0; i < size; i++)
	{
		cin >> n;
		stack.push(n);
	}
	cout << "\nbefore change: ";
	stack.show();
	stack.middle();
	cout << "\nafter change: ";
	stack.show();
	system("pause");
}