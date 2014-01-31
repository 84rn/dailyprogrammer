
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, char> morse_map;
string filename = "code.txt";

void init_map() {
	morse_map[".-"] = 'A';
	morse_map["-..."] = 'B';
	morse_map["-.-."] = 'C';
	morse_map["-.."] = 'D';
	morse_map["."] = 'E';
	morse_map["..-."] = 'F';
	morse_map["--."] = 'G';
	morse_map["...."] = 'H';
	morse_map[".."] = 'I';
	morse_map[".---"] = 'J';
	morse_map["-.-"] = 'K';
	morse_map[".-.."] = 'L';
	morse_map["--"] = 'M';
	morse_map["-."] = 'N';
	morse_map["---"] = 'O';
	morse_map[".--."] = 'P';
	morse_map["--.-"] = 'Q';
	morse_map[".-."] = 'R';
	morse_map["..."] = 'S';
	morse_map["-"] = 'T';
	morse_map["..-"] = 'U';
	morse_map["...-"] = 'V';
	morse_map[".--"] = 'W';
	morse_map["-..-"] = 'X';
	morse_map["-.--"] = 'Y';
	morse_map["--.."] = 'Z';
	morse_map["/"] = ' ';
}

char get_morse_letter(ifstream& file) {
	if (file.eof())
		return (char)0;

	string tmp;	file >> tmp;
	return morse_map[tmp];
}


int main(int argc, char* argv[]) {

	ifstream file;
	char c;

	if (argc == 2)
		filename = argv[1];
	else if (argc != 1)	{
		cout << "Usage: " << argv[0] << " [filename] \n\n\t- [filename] defaults to code.txt\n\t- use \'/\' for spaces" << endl;
		return 1;
	}

	file.open(filename, ios_base::in);

	if (!file.is_open()) {
		cout << "Could not open file: " << filename << endl;
		return 1;
	}

	init_map();

	cout << "Decoded message: ";
	while (c = get_morse_letter(file))
		cout << c;
	cout << endl;

	file.close();

	return 0;
}
