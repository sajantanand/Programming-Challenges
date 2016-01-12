/******************************************************************************************************************
Name:		Sajant Anand
Date:		October 16, 2015
Purpose:	KPCB Engineering Fellows Challenge Problem

Description:
	Below is a templeted hash table in C++. The hash table stores string keys and a pointer to a data object. The size of the hash map is fixed at time of declaration, and space for the given number of objects is pre-allocated.
******************************************************************************************************************/

#include <cstring>
#include <iostream>
#include <cstdlib>

#define POOLS 101		//Number of arrays that the hash table uses
using namespace std;

template<typename T>
class THashTable
{

	private:

		struct Tnode
		{
			string id;
			T * object;
		};
		Tnode ** table;
		int * number;
		int elements;
		int maxCapacity, maxSize;
		int hash ( string key ) const;
	
	public:
		THashTable ( int size );
		bool setKey ( string key, T * value );
		T * getKey ( string key );
		T * deleteKey ( string key );
		double load () const;
};

/******************************************************************************************************************
Constructor: returns an instance of the class with pre-allocated space for the given number of objects. The constructor accepts an integer parameter so that the user can specify the size of the hash table.
******************************************************************************************************************/
template<typename T>
THashTable<T>::THashTable ( int size )
{
	elements= 0;
	maxSize = size;
	number = new (nothrow) int [POOLS];
	table = new (nothrow) Tnode * [POOLS];
	maxCapacity = size/POOLS + 1;
	for ( int i = 0; i < POOLS; i++ )
	{
		table[i] = new (nothrow) Tnode [maxCapacity];
		number[i] = 0;
	}
}

/******************************************************************************************************************
hash: hashing function that returns a value for each string key. The hash value is computed by calculating the sum of the characters of the key and using modulo arithmetic to fit the sum to a predetermined range of integers.
******************************************************************************************************************/
template<typename T>
int THashTable<T>::hash ( string key ) const
{
	int total = 0;
	for ( int i = 0; i < key.length(); i++ )
	{
		total+=key[i];
	}
	return total%POOLS;
}

/******************************************************************************************************************
set: stores the given key/value pair in the hash map. Returns a boolean value indicating success (true) / failure (false) of the operation. As parameters, this function takes a string key and a pointer to the data object.
******************************************************************************************************************/
template<typename T>
bool THashTable<T>::setKey ( string key, T * value )
{
	bool worked = false;
	int pool = 0;
	if ( (pool = hash ( key )) >= 0 )		//If hash() returns a negative value, skip to end of function and return NULL
	{
		if ( number[pool] < maxCapacity  && elements < maxSize)
		{
			table[pool][number[pool]].object = value;
			table[pool][number[pool]].id = key;
			number[pool]++;
			elements++;
			worked = true;
		}
	}
	return worked;
}

/******************************************************************************************************************
get: returns the value associated with the given key, or null if no value is set. As parameters, this function takes a string key. This function returns a pointer of the type of the data object.
******************************************************************************************************************/
template<typename T>
T * THashTable<T>::getKey ( string key )
{
	int pool = 0;
	if ( (pool = hash ( key )) >= 0 )
	{	
		for ( int i = 0; i < number[pool]; i++ )
		{
			if ( key.compare(table[pool][i].id) == 0 )
			{
				return table[pool][i].object;
			}
		}
	}
	return NULL;	
}

/******************************************************************************************************************
delete: deletes the value associated with the given key, returning the value on success or null if the key has not value. As parameters, this function takes a string key. This function returns a pointer of the type of the data object.
******************************************************************************************************************/
template<typename T>
T * THashTable<T>::deleteKey ( string key )
{
	int pool = 0;
	T * desired = NULL;
	if ( (pool = hash ( key )) >= 0 )
	{
		for ( int i = 0; i < number[pool]; i++ )
		{
			if ( key.compare ( table[pool][i].id ) == 0)
			{
				desired = table[pool][i].object;
				memcpy ( &table[pool][i], &table[pool][i+1], sizeof ( table[pool][i] ) * ( number[pool] - i + 1 ) );
				elements--;
				number[pool]--;
				return desired;
			}
		}
	}
	return desired;
}

/******************************************************************************************************************
load: returns a float value representing the load factor ( items in hash table / size of hash table ) of the data structure. Since the size of the data structure is fixed, this should never be greater than 1.
******************************************************************************************************************/
template<typename T>
double THashTable<T>::load() const
{
	return elements / ( double )maxSize;
}
