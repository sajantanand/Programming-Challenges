#include <iostream>

using namespace std;

int findSum ( int num1, int num2, int num3 )
{
	return ( num1 + num2 + num3 );
}

void printNumbers (  int num1, int num2, int num3 )
{
	cout << num1 << " " << num2 << " " << num3 << endl;
	cout << "============" << endl;
}

void sortArray( int * array )
{
	int temp1, temp2, temp3;
	temp1 = array[0];
	temp2 = array[1];
	temp3 = array[2];

	if ( temp1 <= temp2 && temp1 <= temp3 )
	{
		if ( temp2 > temp3 )
		{
			array[1] = temp3;
			array[2] = temp2;
		}
	}
	else if ( temp2 <= temp3 && temp2 <= temp1 )
	{
		array[0] = temp2;
		if ( temp1 < temp3 )
		{
			array[1] = temp1;
			array[2] = temp3;
		}
		else
		{
			array[1] = temp3;
			array[2] = temp1;
		}
	}
	else
	{
		array[0] = temp3;
		if ( temp1 < temp2 )
		{
			array[1] = temp1;
			array[2] = temp2;
		}
		else
		{
			array[1] = temp2;
			array[2] = temp1;
		}
	}
}

int main()
{
	int numbers[3];
	int sum, average;
	cin >> numbers[0] >> numbers[1] >> numbers[2];
	sum = findSum ( numbers[0], numbers[1], numbers[2] );
	printNumbers( numbers[0], numbers[1], numbers[2] );
	if ( sum % 3 == 0 )
	{
		average = sum / 3;
		sortArray ( numbers );
		numbers[1] += numbers[2] - average;
		numbers[2] = average;

		printNumbers( numbers[0], numbers[1], numbers[2] );

		numbers[0] += numbers[1] % average;
		numbers[1] = average;

		
		printNumbers( numbers[0], numbers[1], numbers[2] );
	}

	return 0;
}
		
