#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
	string input_string;
	int num, a, b, c;

	getline(cin, input_string);

	stringstream input_stream(input_string);
	input_stream >> num >> a >> b >> c;

	if (input_stream.fail()) 
	{
		cout << "Improper arguments" << endl;
		return 1;
	}

	int ret = 2 * num + a;

	if (b >= a)
		ret += num + (num - (b - a));
	else
		ret += num + (a - b);

	if (c > b)
		ret += (c - b);
	else
		ret += num - (b - c);

	cout << ret << endl;

	return 0;
}