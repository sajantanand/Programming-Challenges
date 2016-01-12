/******************************************************************************************************************
Name:		Sajant Anand
Date:		October 16, 2015
Purpose:	KPCB Engineering Fellows Challenge Problem

Description:
	Simple C++ program that uses the hash table
******************************************************************************************************************/


#include <iostream>
#include <cstdlib>
#include "hashtable.cpp"
using namespace std;


struct example			//Struct can be replaced with other data objects or primitive types
{
	int var;
};


int main()
{
	srand ( time( NULL ) );
	THashTable<example> tableExample(5000);
	THashTable<int> tableInt(5000);
	char * string = new (nothrow) char[100];
	while ( !cin.eof() )
	{
		cin >> string;
		example * test = new (nothrow) example;
		test->var = rand();
		tableExample.setKey ( string, test );
		tableInt.setKey ( string, &(test->var) );
	}	
	example * testE = new (nothrow) example;
	int * testI = new (nothrow) int;

	cout << "Testing hash table with example struct" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Load:  " << tableExample.load() << endl;
	
	testE = tableExample.deleteKey ( "Computer" );			//Not in the file
	cout << "deleteKey(\"Computer\"):\t\t" << flush;
	if ( testE ) cout << testE->var << endl;
	else cout << "(\"Computer\" is not in hash table)" << endl;
	
	testE = tableExample.deleteKey ( "and" );			//In the file
	cout << "deleteKey(\"and\"):\t" << flush;
	if ( testE ) cout << testE->var << endl;
	else cout << "(\"and\" is not in hash table)" << endl;

	cout << "Load:  " << tableExample.load() << endl;


	cout << "Testing hash table with integers" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Load:  " << tableInt.load() << endl;
	
	testI = tableInt.deleteKey ( "San Francisco" );			//Not in the file
	cout << "deleteKey(\"San Francisco\"):\t" << flush;
	if ( testI ) cout << *testI << endl;
	else cout << "(\"San Francisco\" is not in hash table)" << endl;
	
	testI = tableInt.deleteKey ( "by" );			//In the file
	cout << "deleteKey(\"by\"):\t" << flush;
	if ( testI ) cout << *testI << endl;
	else cout << "(\"by\" is not in hash table)" << endl;

	cout << "Load:  " << tableInt.load() << endl;

	return 0;
}

