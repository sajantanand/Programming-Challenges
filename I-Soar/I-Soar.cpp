#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

#define SIMUL 10000000

int main()
{
	srand(time(NULL));

	vector<vector<float> > boundary(2, vector<float>(1));
	float size;
	float x, y, point;
	bool goOn, notCounted;
	int pairs;
	int i, inside;
	cin >> size;
	while ( size > 0 )
		{

		pairs = i = inside = 0;
		do {
			goOn = true;
			cin >> x >> y;
			if ( x > y )
			{
				goOn = false;
			}
			else
			{
				boundary[0][pairs] = x;
				boundary[1][pairs] = y;
			}
			pairs++;
		} while(goOn);
	
		while ( i < SIMUL )
		{
			notCounted = true;
			point = rand()/(float)RAND_MAX * size;
			//cout << point << endl;
			for ( int j = 0; j < pairs && notCounted; j++ )
			{
				if ( boundary[0][j] < point && point < boundary[1][j] )
				{
					inside++;
					notCounted = false;
				}
			}
			i++;
		}

		float percentage = (SIMUL - inside)/(float)SIMUL;
		percentage = round(percentage*1000)/(float)10;
		cout << "The total planting length is " << fixed << setprecision(1) << percentage << endl;
		
		cin >> size;
	}

	return 0;
}
	
	
