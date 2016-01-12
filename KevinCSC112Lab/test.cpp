#include <string>
#include <iostream>

using namespace std;

int main()
{
	string test = "mz";
	//cout << ispunct(test.at(5)) << endl;

	for (int j=0; j < test.length(); j++) {  //if punctuation

		if (ispunct(test.at(j)) != 0) {
			cout << "punct " << test.at(j) << endl;
			test.push_back(test.at(j));
			test.erase(j,1);
		}
	}
	
	int vowelPosition = test.find_first_of("aeiou");
	cout << vowelPosition << endl;
	return 0;
}
