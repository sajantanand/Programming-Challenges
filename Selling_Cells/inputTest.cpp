#include <iostream>
using namespace std;

int main() {
	double x, y, z, alpha;
	alpha = 1.0;
	
	cin >> alpha;	
	
	while (alpha) {
		//cin >> alpha;
		cin >> x >> y >> z;

		cout << alpha << x << y << z << endl;
	}
	return 0;
} 
