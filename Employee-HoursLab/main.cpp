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

string wholeString;
string name;
int posColon;
string delimeter = " ";



// get department name
void getDepartment ()
{
    ifstream inputfile;
    inputfile.open("hours.txt");
    string line;
    getline(inputfile, line);
    string departmentString;

    for ( int i = 0; i<=4 ; i++)
    {
        getline(inputfile, departmentString);
        string department = departmentString.substr(0, departmentString.find(":", 1));

        cout << department << endl;
    
    }
    
    
    
}


void getName()
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
    
    
    
    while (wholeString != "EOF" )
    {
        getline(inputfile, wholeString);
        posColon = wholeString.find(":", 1);
        name = wholeString.substr(0, posColon);
        cout << name << endl;
        int pos;
        //cout << wholeString << endl;

        
        
        while ( (pos = wholeString.find(" ") )!= string::npos)
        {

            string token =wholeString.substr(0,pos);
            cout << "\t"<<token << endl;
            wholeString.erase(0, (pos +1));
            
            
        }
        
        
    }
    
    

}

int main() {
    getDepartment();
    getName();
    return 0;
}
