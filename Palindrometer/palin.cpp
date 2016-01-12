#include <iostream>
#include <cmath>
#include <string.h>
#include <cstdlib>

using namespace std;

void radd ( char * array, int position )
{
	if ( array[position] == '9' )
	{
		array[position] = '0';
		position--;
		radd ( array, position );
	}
	else
	{
		array[position]++;
	}
}

bool checkPalin ( char * array, int length )
{
	bool palin = true;
	for ( int i = 0; i < length/2 && palin; i++ )
	{
		if ( array[i] != array[length-1-i] )
		{
			palin = false;
		}
	}
	return palin;
}

int main()
{
	char * string = new (nothrow) char[50];
	int number, toDrive, goal, size;
	cin >> string;
	number = atoi ( string );
	while ( number != 0 )
	{
		size = strlen(string);
		
		while ( !checkPalin(string, size ))
		{
			radd ( string, size - 1 );
		}

		goal = atoi ( string );
		toDrive = goal - number;

		cout << toDrive << endl;

		cin >> string;
		number = atoi ( string );
	}
	delete [] string;
}
