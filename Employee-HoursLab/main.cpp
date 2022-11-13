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


void getEmployees(string filename, string deptName, string jobTitle)
{
    cout << deptname << " " << jobTitle<< endl;
    ifstream inputfile;
    
    // open input file
    inputfile.open("hours.txt");
    
    string line;
    
    // loop to skip line until line "Employee:"
    while(true)
    {
        getline( inputfile, line);
        if ( line == "Employees:")
            break;
    }
    
    
    while ( line != "EOF")
    {
        getline( inputfile, line);
        string wholeString;
        string name;
        int posColon;
        string delimeter = " ";
        
        posColon = line.find(":", 1); // find the position of the colon
        
        name = line.substr(0, posColon);// get the name from the line using substr
        
        line.erase(0, posColon +1);// delete everything befor colon and space
        
        cout << name << endl;
        
        
        
        
        
        
        
    }
    
    
   

}

int main() {
    ifstream file; file.open("Hours.txt");
    string department = "";
    
    // skip the "Department :" line
    getline( file, department);
    
    while (true)
    {
        getline (file , department);
        
        // get name of department
        string name = department.substr(0, department.find(":"));
    }
    return 0;
}
