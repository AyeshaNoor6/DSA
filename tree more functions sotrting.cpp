#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
public:
	int emp_id;
	string name;
	string position;
	Node() : emp_id(0), name(""), position(""), left(nullptr), right(nullptr) {}
	Node* left;
	Node* right;
};

class Tree {
	int count = 0;
	Node* root = nullptr;
	int posi_c = 0;

	void insert(Node*& node, int data, string name, string posi)
	{
		if (node == nullptr)
		{
			node = new Node();
			node->emp_id = data;
			node->name = name;
			node->position = posi;
		}
		else if (data < node->emp_id) 
		{
			insert(node->left, data, name, posi);
		}
		else
		{
			insert(node->right, data, name, posi);
		}
	}

	void BFS(Node* node)
	{
		if (node == nullptr) 
		{
			cout << "\nTree is empty!";
			return;
		}
		queue<Node*> q;
		q.push(node);
		while (!q.empty())
		{
			Node* current = q.front();
			q.pop();
			cout << "\nEmployee ID: " << current->emp_id << "\nName: " << current->name << "\nPosition: " << current->position;
			if (current->left)
			{
				q.push(current->left);
			}
			if (current->right)
			{
				q.push(current->right);
			}
		}
	}

	void in(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		in(node->left);
		cout << "\nEmployee ID: " << node->emp_id << "\nName: " << node->name << "\nPosition: " << node->position;
		in(node->right);
	}

	void enqueueNodes(Node* node, std::queue<Node*>& q)
	{
		if (node)
		{
			enqueueNodes(node->left, q);
			q.push(node);
			enqueueNodes(node->right, q);
		}
	}

	void sortQueue()
	{
		std::queue<Node*> q;
		enqueueNodes(root, q);
		int size = q.size();
		Node** arr = new Node*[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = q.front();
			q.pop();
		}

		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (arr[j]->emp_id > arr[j + 1]->emp_id)
				{
					Node* temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		root = nullptr; 
		for (int i = 0; i < size; ++i)
		{
			insert(root, arr[i]->emp_id, arr[i]->name, arr[i]->position);
		}
		delete[] arr;
	}
	bool isUnique(Node* node, int emp_id)
	{
		if (node == nullptr)
		{
			return true; 
		}

		if (emp_id == node->emp_id)
		{
			return false; 
		}
		return isUnique(node->left, emp_id) && isUnique(node->right, emp_id);
	}
	//helper function for search by ID
	void searchByPosition(Node* node, const string& position)
	{
		if (node == nullptr)
		{
			return; 
		}
		if (node->position == position)
		{
			cout << "Employee ID: " << node->emp_id << ", Name: " << node->name << ", Position: " << node->position << endl;
		}
		searchByPosition(node->left, position);
		searchByPosition(node->right, position);
	}
	//helper function for search by ID
	void searchByID(Node* node, int id)
	{
		if (node == nullptr)
		{
			return;
		}
		if (node->emp_id == id)
		{
			cout << "Employee ID: " << node->emp_id << ", Name: " << node->name << ", Position: " << node->position << endl;
		}
		searchByID(node->left, id);
		searchByID(node->right, id);
	}
	//helper function to update 
	void updateid(Node* node, int id)
	{
		if (node == nullptr)
		{
			return;
		}
		if (node->emp_id == id)
		{
			cout << "\nEnter new name: ";
			cin >> node->name;
			cout << "Enter new position: ";
			cin >> node->position;
		}
		searchByID(node->left, id);
		searchByID(node->right, id);
	}
	//helper function to count by osition
	void countByPosition(Node* node, const string& position)
	{
		if (node == nullptr)
		{
			return;
		}
		if (node->position == position)
		{
			posi_c++;
		}
		countByPosition(node->left, position);
		countByPosition(node->right, position);
	}
public:
	void insertLevelOrder(int data, string name, string posi)
	{
		if (isUnique(root, data))
		{
			insert(root, data, name, posi);
		count++;

		}
		else
			cout << "\nEmployee ID already exist cannot enter!";
	}
	void printLevelOrder()
	{
		BFS(root);
	}
	void inOrder() 
	{
		in(root);
	}
	void sort()
	{
		sortQueue();
	}
	void deletenode(int emp_id)
	{
		std::queue<Node*> q;
		enqueueNodes(root, q);
		int size = q.size();
		Node** arr = new Node*[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = q.front();
			q.pop();
		}

		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i]->emp_id == emp_id)
				arr[i]->emp_id = -1;
		}

		root = nullptr;
		for (int i = 0; i < size; ++i)
		{
			if(!(arr[i]->emp_id==-1))
			insert(root, arr[i]->emp_id, arr[i]->name, arr[i]->position);
		}
		delete[] arr;
	}
	void countEmployee()
	{
		cout << "\nTotal Employee: " << count;
	}
	void ByID(int id)
	{
		cout << "Employees with position \"" << id
			<< "\":\n" << endl;
		searchByID(root, id);
	}
	void ByPosition(const string& position)
	{
		cout << "Employees with position \"" << position<< "\":\n" << endl;
		searchByPosition(root, position);
	}
	void update(int id)
	{
		updateid(root, id);
	}
	void countPOSI(const string& posi)
	{
		countByPosition(root, posi);
		cout << "\nTotal employee with this position: " << posi_c;
	}
};

int main()
{
	Tree tree;
	tree.insertLevelOrder(3, "ayesha", "senior");
	tree.insertLevelOrder(3, "ayesha", "senior");
	tree.insertLevelOrder(2, "faran", "junior");
	tree.insertLevelOrder(1, "kainat", "higher");
	tree.printLevelOrder();
	tree.sort();
	tree.printLevelOrder();
	tree.deletenode(2);
	tree.printLevelOrder();
	tree.ByPosition("senior");
	tree.countPOSI("senior");
	system("pause");
}