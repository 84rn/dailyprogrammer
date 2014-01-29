
#include <fstream>
#include <iostream>
#include <string>

#define FILENAME "save.txt"
using namespace std;

int main(int argc, char* argv[])
{
	string name, age, username; ofstream file(FILENAME, ios_base::app);
	cout << "Name: "; cin >> name; cout << "Age: "; cin >> age; cout << "Username: "; cin >> username;
	string output = "Your name is " + name + ", you are " + age + " years old, and your username is " + username;

	if (file.is_open())
		file << output << endl;
	else {
		cout << "Could not write to file " << FILENAME << endl;
		return 1;
	}
	cout << output << endl;
	file.close();

	return 0;
}