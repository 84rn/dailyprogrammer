
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define DEC_FILENAME "decrypted.txt"
#define ENC_FILENAME "encrypted.txt"

using namespace std;

int main(int argc, char* argv[])
{
	bool decrypt = false, help = true;

	if (argc == 2)
	{
		if (string(argv[1]) == "-d")
		{
			decrypt = true;
			help = false;
		}
	}
	else if (argc == 1)
		help = false;

	if (help)
	{
		cout << "Usage: \t" << argv[0] << " [-d][ decryption mode ]\n" << endl;
		cout << "\t - place decrypted text n \'decrypted.txt\',\n\t   the result will be saved in \'encrypted.txt\' in format [<key> <text>]" << endl;
		cout << "\t - place encrypted text n \'encrypted.txt\' [<key> <text>],\n\t   the result will be saved in \'decrypted.txt\'" << endl;
		return 1;
	}

	fstream dec_file(DEC_FILENAME); fstream enc_file(ENC_FILENAME);
	fstream* in; fstream* out;

	if (!dec_file.is_open() || !enc_file.is_open())
	{
		cout << "Cannot open files for read/write operations!" << endl;
		return 1;
	}

	srand((unsigned int)time(NULL));
	char factor = 1; int key; char c;

	if (decrypt)
	{
		factor = -1;
		in = &enc_file;
		out = &dec_file;

		enc_file >> key;
		cout << "Decrypting with key: " << key << endl;
		enc_file.get(c);   // space
	}
	else
	{
		in = &dec_file;
		out = &enc_file;

		key = rand() % 24 + 1; // 1-25
		cout << "Encrypting with key: " << key << endl;
	}

	out->close();
	out->open((decrypt ? DEC_FILENAME : ENC_FILENAME), ios_base::trunc | ios_base::out);
	if (!decrypt)
		*out << key << " ";

	while (in->get(c))
	{
		c = (char)toupper(c);

		if (c == ' ' || c == '\n')
			*out << (c);
		else
			*out << ((char)((c - (factor * 'A') + (factor*key)) % 26 + 'A'));
	}

	cout << "Done." << endl;

	enc_file.close();
	dec_file.close();

	return 0;
}