/* 
 * File:   main.cpp
 * Author: wangky13
 *
 * Created on September 15, 2015, 3:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "pigLatin.h"
        
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream myFile;
    string inputWord;
    
    myFile.open("simple.txt");
    
    string line;
    
    while (getline(myFile, line)) {                 // to pull of whole line
        istringstream xx(line);                 //to pull of indiv words from line
        while (xx >> inputWord) {
            cout << pigLatin(inputWord) << endl;
        }
        cout << endl; 
    }
    myFile.close();
    return 0;
}

