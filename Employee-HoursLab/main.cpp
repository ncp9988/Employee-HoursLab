//
//  main.cpp
//  Employee-HoursLab
//
//  Created by Chau Pham on 11/7/22.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// get department name

// add up hours

// add up number of employee

// get part-time employee

// get full-time employee

void getString()
{
    ifstream inputfile;
    inputfile.open("hours.txt");
    string line;
    getline(inputfile, line);
    getline(inputfile, line);
    getline(inputfile, line);
    getline(inputfile, line);
    getline(inputfile, line);
    getline(inputfile, line);
    
    
    string wholeString;
    
    while (wholeString != "EOF") {
        // do something with the line
        getline(inputfile, wholeString);
        cout << wholeString << endl;

    }
    
}

int main() {
    getString();

    return 0;
}
