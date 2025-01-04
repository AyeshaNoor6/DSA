//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class Stack {
//	char* arr;//array to hold expression
//	int top;
//	int capacity;//size of expression
//
//public:
//	Stack(int size) 
//	{
//		arr = new char[size];
//		capacity = size;
//		top = -1;
//	}
//	//destructor
//	~Stack()
//	{
//		delete[] arr;
//	}
//
//	void push(char x) 
//	{
//		if (top == capacity - 1) 
//		{
//			cout << "Stack Overflow" << endl;
//			return;
//		}
//		arr[++top] = x;
//	}
//
//	char pop() 
//	{
//		if (top == -1)
//		{
//			cout << "Stack Underflow" << endl;
//			return '\0';
//		}
//		return arr[top--];
//	}
//
//	char peek() {
//		if (top == -1) {
//			return '\0';
//		}
//		return arr[top];
//	}
//
//	bool isEmpty() {
//		return top == -1;
//	}
//};
//
//int precedence(char op)//function to check precedence
//{
//	if (op == '^') return 3;
//	if (op == '*' || op == '/') return 2;
//	if (op == '+' || op == '-') return 1;
//	return 0;
//}
//
//bool isOperator(char c)//check if char is operator or symbol
//{
//	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
//}
//
//void infixToPostfix(const char* infix, char* postfix)
//{
//	Stack stack(strlen(infix));//eveluation and giving size to stack equal to size of expression
//	int j = 0;
//
//	for (int i = 0; infix[i]; i++)
//	{
//		if (isalnum(infix[i]))//check id alpha numeric or not
//		{
//			postfix[j++] = infix[i];
//		}
//		else if (infix[i] == '(') 
//		{
//			stack.push('(');
//		}
//		else if (infix[i] == ')')
//		{
//			while (!stack.isEmpty() && stack.peek() != '(')
//			{
//				postfix[j++] = stack.pop();//pop elemnt and push tp postfix until ( comes
//			}
//			stack.pop(); // Pop '('
//		}
//		else if (isOperator(infix[i])) //pop previous element if have higher or greater precedence until less
//		{
//			while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(infix[i]))
//			{
//				postfix[j++] = stack.pop();
//			}
//			stack.push(infix[i]);
//		}
//	}
//
//	while (!stack.isEmpty())//pop remaining elemnts
//	{
//		postfix[j++] = stack.pop();
//	}
//	postfix[j] = '\0';
//}
//
//void reverse(char* exp)//reversing the expression
//{
//	int n = strlen(exp);
//	for (int i = 0; i < n / 2; i++)
//	{
//		swap(exp[i], exp[n - i - 1]);
//	}
//}
//
//void infixToPrefix(const char* infix, char* prefix) 
//{
//	int n = strlen(infix);
//	char* reversedInfix = new char[n + 1];
//
//	for (int i = 0; i < n; i++)
//	{
//		reversedInfix[i] = infix[n - i - 1]; // Reverse the infix
//	}
//	reversedInfix[n] = '\0'; // Null-terminate the string
//
//							 // Reverse parentheses
//	for (int i = 0; i < n; i++)
//	{
//		if (reversedInfix[i] == '(')
//		{
//			reversedInfix[i] = ')';
//		}
//		else if (reversedInfix[i] == ')') 
//		{
//			reversedInfix[i] = '(';
//		}
//	}
//
//	char* postfix = new char[n + 1];
//	infixToPostfix(reversedInfix, postfix);
//	reverse(postfix);
//
//	for (int i = 0; postfix[i] != '\0'; i++) 
//	{
//	prefix[i] = postfix[i];
//	}
//	// Null-terminate the destination string
//	prefix[strlen(postfix)] = '\0';
//	delete[] reversedInfix;
//	delete[] postfix;
//}
//
//int main()
//{
//	const char* infix = "(((20+30)*2)/6)";
//	char postfix[100];
//	char prefix[100];
//
//	infixToPostfix(infix, postfix);
//	infixToPrefix(infix, prefix);
//
//	cout << "Infix Expression: " << infix << endl;
//	cout << "Postfix Expression: " << postfix << endl;
//	cout << "Prefix Expression: " << prefix << endl;
//
//	system("pause");
//}
