// Kevin Wang
// 09/08/2015

using namespace std;
#include <string>
#include <iostream>

string pigLatin(string outputWord)
{

	int vowelPosition;

	bool capitalized = false;	//Only the first word is ever capitalized so this way, you don't have to loop through word. If the word is capitalized before any changes, it must be capitalized after.
	capitalized = isupper(outputWord.at(0));
	if( capitalized )	//if first letter is capitalized, make it lower case.
	{
		outputWord.at(0) = tolower(outputWord.at(0));
	}

	vowelPosition = outputWord.find_first_of("aeiou");
	if (vowelPosition < 0)	//if vP is < 0, 'aeiou' is not in word. recheck with treating 'y' as vowel.
	{
		vowelPosition = outputWord.find_first_of("y");
		
	}

	outputWord.append(outputWord.substr(0,(vowelPosition)));
	outputWord.erase(0,(vowelPosition));
	outputWord = outputWord + "ay";


	if ( capitalized )	//if if first letter was a capital, make new first letter a capital.
	{
		outputWord.at(0) = toupper(outputWord.at(0));
	}

	for (int j=0; j < outputWord.length(); j++) {  //if punctuation

		if (ispunct(outputWord.at(j)) != 0) {
		outputWord.push_back(outputWord.at(j));
		outputWord.erase(j,1);

	}
}

	outputWord.push_back(' ');
	//I put this code at the end, because adding the space behind the word should be the last thing done before returning to main. If not, the space could get shuffled around by the punctuation.

	return outputWord;
}
