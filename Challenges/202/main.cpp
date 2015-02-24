#include <cstdio>
#include <climits>

/*
	/r/DailyProgrammer - Challenge no. 202
	Author: B. Bartyzel
	URL: http://redd.it/2w84hl
*/

void read_bin();

int main(void)
{
	read_bin();
	return 0;
}

void read_bin()
{
	char c, letter = 0;
	int j = CHAR_BIT;

	while ((c = getchar()) != EOF && c != '\n')
	{
		letter += (c - '0') * (1 << (j - 1));
		if (!--j)
		{
			putchar(letter);
			j = CHAR_BIT;
			letter = 0;
		}
	}
	putchar('\n');
}