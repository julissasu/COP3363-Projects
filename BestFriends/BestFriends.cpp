/* Name: Julissa Su Qiu
Date: 9/17/2022 
Section: 0013
Assignment: Ordered Best Friend Names Program
Due Date: 9/18/2022
About this project: This program will ask the user to enter in three first names and display them in ascending order.
Assumptions: NA
All work below was performed by Julissa Su Qiu */

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    cout << "Welcome to the Ordered Best Friend Names Program.\n";

    string name1, name2, name3;
    

    cout << "Please enter in the first name of a best friend:\n";
    getline(cin, name1);

    cout << "Please enter in the first name of another best friend:\n";
    getline(cin, name2);   

    cout << "Please enter in the first name of another best friend:\n";
    getline(cin, name3);
    
    if (name1 == name2 && name1 == name3 && name2 == name3)
        cout << "All the names are equal.\n";
    
    else if (name1 < name2 && name2 < name3)
    {   cout << name1 << endl;
        cout << name2 << endl;
        cout << name3 << endl;
    }

    else if (name2 < name1 && name1 < name3)
    {
        cout << name2 << endl;
        cout << name1 << endl;
        cout << name3 << endl;
    }
    else if (name1 < name3 && name3 < name2)
    {
        cout << name1 << endl;
        cout << name3 << endl;
        cout << name2 << endl;

    }
    else if (name2 < name3 && name3 < name1)
    {   
        cout << name2 << endl;
        cout << name3 << endl;
        cout << name1 << endl;
    }
    else if (name3 < name1 && name1 < name2)
    {   
        cout << name3 << endl;
        cout << name1 << endl;
        cout << name2 << endl;
    }
    else if (name3 < name2 && name2 < name1)
    {   
        cout << name3 << endl;
        cout << name2 << endl;
        cout << name1 << endl;
    }
    else 
        cout << "Invalid input.";

    return 0;
}