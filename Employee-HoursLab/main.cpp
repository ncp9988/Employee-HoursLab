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
    cout << deptName << " " << jobTitle<< endl;
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
        string name;
        int posColon;
        string delimeter = " ";
        
        posColon = line.find(":", 1); // find the position of the colon
        
        name = line.substr(0, posColon);// get the name from the line using substr
        
        line.erase(0, posColon +2);// delete everything befor colon and space
        
        cout << name << endl;
        
        
        
        
        
        // getting Department and Employee type
        int posSpace = -1;
        int count = 0;
        for ( int i = line.length(); i>0 ; i--)
        {
            if (line[i] == ' ')
                count ++;
            if (count == 2)
                posSpace = i;
        }
        
        string dept_job = line.substr(posSpace+1);
        line.erase(posSpace);
        
        
        // if this employee is not the right department and job type then skip
        if (dept_job.find(deptName) == string::npos)
            continue; // skip this employee
        if (dept_job.find(jobTitle) == string::npos)
            continue; // skip this employee
        
        
        
        
        int totalHours = 0;
        while (true)
        {
            int Hpos = line.find("h");
            int Mpos = line.find("m");
            
            
            if (Hpos == string::npos && Mpos == string::npos) //no labels left
                break;
            
            
            if(Hpos < Mpos)
            {
                // read in hours
                int spaceAfter = line.find(" ", Hpos);
                line.erase(Hpos, spaceAfter-Hpos);
                int hour = stoi(line.substr(0, Hpos));
                line.erase(0, Hpos);
            }
            else
            {
                // read in minutes
                int spaceAfter = line.find(" ", Mpos);
                line.erase(Mpos, spaceAfter-Mpos);
                int minutes = stoi(line.substr(0, Mpos));
                line.erase(0, Mpos);
            }
        }
        
        
        // ouput the hours here
    }
    
    
   

}

int main() {
    ifstream file;
    file.open("Hours.txt");
    string department = "";
    
    // skip the "Department :" line
    getline( file, department);
    
    while (true)
    {
        getline (file , department);
        
        if (department == "Employees: ")
            break;
        
        // get name of department
        string name = department.substr(0, department.find(":"));
        
        while (true)
        {
        }
        return 0;
    }
}
