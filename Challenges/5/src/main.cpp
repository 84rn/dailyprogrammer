
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string psswd_file = "passwd.txt";

int main(int argc, char* argv[]) {

	string user, passwd, given_username, given_password;
	ifstream file(psswd_file);

	if (!file.is_open()) {
		cout << "Could not open file: " << psswd_file << endl;
		return 1;
	}

	file >> user; file >> passwd;

	cout << "Enter username: ";	cin >> given_username;
	cout << "Enter password: "; cin >> given_password;

	if (given_username == user && given_password == passwd)
		cout << "Welcome!" << endl;
	else
		cout << "Access denied!" << endl;

	return 0;
}