#pragma once
#include <iostream>
#include <string>
#include "Graph.h"
#include <Windows.h>
using namespace std;
void resetPassword(Graph& graph)
{
	string username;
	cout << "Enter your username: ";
	cin >> username;

	User* user = graph.findUser(username);
	if (!user)
	{
		cout << "User not found.\n";
		return;
	}

	string answer;
	cout << "Security Question: " << user->securityQuestion << "\n";
	cout << "Enter your answer: ";
	cin.ignore();
	getline(cin, answer);

	if (answer == user->securityAnswer)
	{
		string newPassword;
		cout << "Enter new password: ";
		cin >> newPassword;
		user->password = newPassword;
		cout << "Password reset successfully.\n";
	}
	else
	{
		cout << "Incorrect answer. Password reset failed.\n";
	}
}

// Function to set text and background colors
void setConsoleColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
// Function to display the front screen with large "INSTAGRAM" text and credits
void displayFrontScreen() {

	setConsoleColor(4, 0); // Red text on black background


	system("cls");

	// Printing the large "INSTAGRAM" text
	cout << "\n\n\n";
	setConsoleColor(4, 0); // Red text on black background
	cout << " IIIII   N   N   SSSSS   TTTTT   AAAAA    GGGG    RRRR      AAAAA    M   M\n";
	cout << "   I     NN  N   S         T    A     A   G       R   R    A     A   MM MM\n";
	cout << "   I     N N N   SSSSS     T    AAAAAAA   G  GG   RRRR     AAAAAAA   M M M\n";
	cout << "   I     N  NN       S     T    A     A   G   G   R  R     A     A   M   M\n";
	cout << " IIIII   N   N   SSSSS     T    A     A   GGGG    R   R    A     A   M   M\n";
	cout << endl;
	cout << "----------------------------------------------------------------------------\n";
	cout << "                       By: Ali Naqi and Ayesha Noor     \n";
	cout << "----------------------------------------------------------------------------\n";
	// Adding some space between the title and credits
	cout << "\n\n";

	// Displaying the credits in red on black background
	setConsoleColor(4, 0);


	system("pause"); // Wait for a key press
}
void displayInitialMenu()
{

	setConsoleColor(4, 1);


	cout << string(42, ' ') << endl;
	cout << string(42, ' ') << endl;



	setConsoleColor(0, 14);


	cout << "******************************************\n";

	setConsoleColor(9, 14);
	cout << "*                                        *\n";
	setConsoleColor(5, 14);
	cout << "* ----- Mini Instagram LOGIN Page -----  *\n";
	setConsoleColor(6, 14);
	cout << "* 1. Signup                              *\n";
	setConsoleColor(3, 14);
	cout << "* 2. Login                               *\n";
	setConsoleColor(4, 14);
	cout << "* 0. Exit                                *\n";
	setConsoleColor(5, 14);
	cout << "*          Enter your choice             *\n";
	cout << "*                                        *\n";


	cout << "******************************************\n";
	setConsoleColor(4, 1);

	cout << string(42, ' ') << endl;
	cout << string(42, ' ') << endl;



	setConsoleColor(2, 0);
}

void displayLoggedInMenu()
{

	setConsoleColor(2, 1);


	cout << string(42, ' ') << endl;
	cout << string(42, ' ') << endl;



	setConsoleColor(0, 14);

	cout << "******************************************\n";


	setConsoleColor(9, 14);
	cout << "*                                        *\n";
	setConsoleColor(5, 14);
	cout << "*       --- Mini Instagram HOME Page --- *\n";
	setConsoleColor(6, 14);
	cout << "* 3. Logout                              *\n";
	setConsoleColor(3, 14);
	cout << "* 4. Send Follow Request                 *\n";
	setConsoleColor(4, 14);
	cout << "* 5. View/Accept Friend Requests         *\n";
	setConsoleColor(2, 14);
	cout << "* 6. Create Post                         *\n";
	setConsoleColor(9, 14);
	cout << "* 7. View Newsfeed                       *\n";
	setConsoleColor(5, 14);
	cout << "* 8. View Notifications                  *\n";
	setConsoleColor(6, 14);
	cout << "* 9. Send Message                        *\n";
	setConsoleColor(3, 14);
	cout << "* 10. Search Users                       *\n";
	setConsoleColor(7, 14);
	cout << "* 11. View Follower's List               *\n";
	setConsoleColor(4, 14);
	cout << "* 12. View User's Posts                  *\n";
	setConsoleColor(2, 14);
	cout << "* 13. View Messages                      *\n";
	setConsoleColor(9, 14);
	cout << "* 14. View Connections                   *\n";
	setConsoleColor(5, 14);
	cout << "* 15. Block a User                       *\n";
	setConsoleColor(3, 14);
	cout << "* 16. Reset Password                     *\n";
	cout << "*          Enter your choice             *\n";


	cout << "******************************************\n";
	setConsoleColor(4, 1);
	cout << string(42, ' ') << endl;
	cout << string(42, ' ') << endl;



	setConsoleColor(15, 0);
}



