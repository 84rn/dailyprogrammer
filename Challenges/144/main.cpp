#include <fstream>
#include <iostream>
#include <map>

using namespace std;

typedef map<string, int> mymap;
typedef map<string, int>::iterator imymap;

int main(int argc, char* argv[])
{
	ifstream in_file("input.txt");
	mymap start_list;
	int nr_pos;

	if (!in_file.is_open() || in_file.bad())
	{
		cout << "Problem with input file";
		return 1;
	}
	
	in_file >> nr_pos;
	for (int i = 0; i < 2 * nr_pos; i++)
	{
		char name[100];
		int cents;

		in_file >> name;
		in_file >> cents;

		if (i < nr_pos)
			start_list[name] = cents;		
		else
		{
			imymap it = start_list.find(name);
			if (it != start_list.end() && it->second - cents != 0)
				cout << it->first.c_str() << " " << (cents - it->second > 0 ? "+" : "") << (cents - it->second) << endl;
		}
	}

	start_list.clear();
	return 0;
}