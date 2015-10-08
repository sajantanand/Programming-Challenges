#include <cmath>
#include <cstdlib>
#include <iostream>
#include<iomanip>

using namespace std;

struct circle
{
	double centerX;
	double centerY;
	double radius;
};

bool isInsideCircle (double x, double y, circle ring)
{
	return ((pow(x-ring.centerX, 2.0) + pow(y-ring.centerY, 2.0)) <= pow(ring.radius, 2.0));
}

void generateRandomPoint (double & x, double & y, double maxRadius, double maxX, double maxY)
{
	x = rand()/(double)RAND_MAX * maxRadius * 2;
	y = rand()/(double)RAND_MAX * maxRadius * 2;
	
	double offsetX = 2 * maxRadius - maxX;
	double offsetY = 2 * maxRadius - maxY;
	
	x -= offsetX;
	y -= offsetY;
}

int main()
{
	cout << fixed;
	cout << setprecision(2);

	srand (time(NULL));
	double x, y, radius, xMax, yMax;
	int numCircles;
	
	double data[25];
	int dataSets = 0;
	bool insideCell;
	
	int inside;
	inside = 0;
	
	circle * circleList;
	
	cin >> numCircles;
	while (numCircles != 0)
	{
		inside = 0;
		circleList = new (nothrow) circle[numCircles];
		for (int i = 0; i < numCircles; i++)
		{
			cin >> x >> y >> radius;
			
			circleList[i].centerX = x;
			circleList[i].centerY = y;
			circleList[i].radius = radius;
		
			//cout << circleList[i].centerX << circleList[i].centerY << circleList[i].radius << endl;
		}
		
		xMax = circleList[0].centerX + (double)circleList[0].radius;
		yMax = circleList[0].centerY + (double)circleList[0].radius;

		int i = 0;
		while ( i < 200000)
		{
			generateRandomPoint(x, y, circleList[0].radius, xMax, yMax);
			//cout << "Random Point: " << x << " " << y  << " " << endl;
			insideCell = false;
			if(isInsideCircle(x, y, circleList[0]) != 0)
			{
				for(int j = 1; j < numCircles && !insideCell; j++)
				{
					if(isInsideCircle(x, y, circleList[j]))
					{
						insideCell = true;
						inside++;
					}
				}
				i++;
			}
		}
		
		data[dataSets] = inside / (double)i;
		dataSets++;
		cin >> numCircles;

		delete [] circleList;
	}
	
	for (int z = 0; z < dataSets; z++)
	{
		double temp = data[z];
		temp *= 100;
		temp = round(temp);
		temp /= 100;
		cout << temp << endl;
	}
}				
		
