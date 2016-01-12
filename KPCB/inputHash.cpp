#include <iostream>
#include <string.h>
#include <functional>
using namespace std;

int main()
{
	char * string = new (nothrow) char[50];
	unsigned long long total;
	size_t average;
	int occurrance[101] = { 0 };

	//std::hash<char*> ptr_hash;	

	while ( !cin.eof() )
	{
		total=0;
		average=0;
		cin >> string;
		//cout << string << endl;
		for ( int i = 0; i < strlen(string); i++ )
		{
			//total+= total*128 + string[i];
			total += string[i];
		}
		average = total%101;
		//average = ptr_hash(string)%157;
		occurrance[average]++;
		//cout << total << " " << average << endl;
	}
	for ( int i = 0; i < 100; i++ )
	{
		cout << occurrance[i] << " " << flush;
	}
	cout << endl;
}
