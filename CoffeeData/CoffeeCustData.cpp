#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

/* Name: Julissa Su Qiu
Date: 11/12/2022
Section: 0013
Assignment: Starbucks - Coffee Customer Rating Data Program
Due Date: 11/13/2022
About this project: This program will read through a file and based upon the option selected 
computed and display the following:
  A or a: Diplay the maximum Price Rating by Status
  B or b: Display the average Service Rating by Method
Assumptions: 
* Need two functions to read the data
All work below was performed by Julissa Su Qiu */

using namespace std;

//function prototypes to read data from file
void readData1(vector<int> &student, vector<int> &selfEmployed, vector<int> &Employed, vector<int> &houseWife);
void readData2(vector<int> &dineIn, vector<int> &driveThru, vector<int> &takeAway, vector<int> &never, vector<int> &others);
//function prototypes 
void DisplayMaxPriceRatByStatus(vector<int> student, vector<int> selfEmployed, vector<int> employed, vector<int> housewife);
void DisplayAvgServRatByMethod(vector<int> dineIn, vector<int> driveThru, vector<int> takeAway, vector<int> never, vector<int> others);

int main()
{
    char option; //variable for menu option
    //vectors of each component
    vector<int> student;
    vector<int> selfEmployed;
    vector<int> Employed;
    vector<int> houseWife; 
    vector<int> dineIn;
    vector<int> driveThru;
    vector<int> takeAway;
    vector<int> never;
    vector<int> others;

    //Display menu and read in option
    cout << "Starbucks - Coffee Customer Rating Data\n";
    cout << "Options\n";
    cout << "A) Display the maximum Price Rating by Status...\n";
    cout << "B) Display the average Service Rating by Method...\n";
    cout << "Please select option (A-B)... \n";
    cin >> option;

    //If user chose option A or a
    if ((option == 'A') || (option == 'a'))
    {
        readData1(student, selfEmployed, Employed, houseWife);
        DisplayMaxPriceRatByStatus(student, selfEmployed, Employed, houseWife);
    }
    //If user chose option B or b
    else if ((option == 'B') || (option == 'b'))
    {
        readData2(dineIn, driveThru, takeAway, never, others);
        DisplayAvgServRatByMethod(dineIn, driveThru, takeAway, never, others);
    }
    //Invalid option
    else 
    {
        cout << "Invalid option entered.\n";
    }
    return 0;
}

//Definition of readData1
void readData1(vector<int> &student, vector<int> &selfEmployed, vector<int> &Employed, vector<int> &houseWife)
{
    //create an input stream and open it
    ifstream StarbucksDataFile;
    StarbucksDataFile.open("StarbucksData.txt");
    //test if the file opened successfully
    if (!StarbucksDataFile)
        cout << "Error";
    
    if (StarbucksDataFile)
    {
        //intialize variables to 0
        int data1 = 0, data2 = 0, data3 = 0, data4 = 0, data5 = 0;
        while (StarbucksDataFile >> data1 >> data2 >> data3 >> data4 >> data5)
        {   
            //if data1 is = 0, then add the rating into to the student vector
            if (data1 == 0)
            {
                student.push_back(data4);
            }
            //if data2 is = 1, then add the rating into to the selfEmployed vector
            else if (data1 == 1)
            {
                selfEmployed.push_back(data4);
            }
            //if data3 is = 2, then add the rating into to the Employed vector
            else if (data1 == 2)
            {
                Employed.push_back(data4);
            }
            //if data4 is = 3, then add the rating into to the houseWife vector
            else if (data1 == 3)
                houseWife.push_back(data4);
        }
    }
    //close the file
    StarbucksDataFile.close();
}

//Definition of readData2
void readData2(vector<int> &dineIn, vector<int> &driveThru, vector<int> &takeAway, vector<int> &never, vector<int> &others)
{
    //create and input stream and open it
    ifstream StarbucksDataFile;
    StarbucksDataFile.open("StarbucksData.txt");
    //check if file opened successfully
    if (!StarbucksDataFile)
        cout << "Error";

    if (StarbucksDataFile)
    {   
        //intialize variables to 0
        int data1 = 0, data2 = 0, data3 = 0, data4 = 0, data5 = 0;
        while (StarbucksDataFile >> data1 >> data2 >> data3 >> data4 >> data5)
        {
            //if data2 == 0 then add the method # into dineIn
            if (data2 == 0)
                dineIn.push_back(data5);
            //if data2 == 1 then add the method # into driveThru
            else if (data2 == 1)
                driveThru.push_back(data5);
            //if data2 == 2 then add the method # into takeAway
            else if (data2 == 2)
                takeAway.push_back(data5);
            //if data2 == 3 then add the method # into never
            else if (data2 == 3)
                never.push_back(data5);
            //if data2 == 4 then add the method # into others
            else if (data2 == 4)
                others.push_back(data5);
            else 
            {
                //set never and others to 0
                never.push_back(0);
                others.push_back(0);
            }
        }
    }
    //close file
    StarbucksDataFile.close();
}

//Definition of DisplayMaxPriceRatByStatus
void DisplayMaxPriceRatByStatus(vector<int> student, vector<int> selfEmployed, vector<int> employed, vector<int> housewife)
{
    int max1 = student[0]; //max variable for student
    for (int i = 1; i < student.size(); i++)
    {
        //if element in student is greater than max, set max to that element
        if (student[i] > max1)
            max1 = student[i];
    }
    cout << "Student\t\t\t" << max1 << endl; //Display max of student

    int max2 = selfEmployed[0]; //max variable for selfEmployed
    for (int i = 1; i < selfEmployed.size(); i++)
    {
        //if element in selfEmployed is greater than max, set max to that element
        if (selfEmployed[i] > max2)
            max2 = selfEmployed[i];
    }
    cout << "Self-Employed\t\t" << max2 << endl; //display max of selfEmployed

    int max3 = employed[0]; //max variable for employed
    for (int i = 1; i < employed.size(); i++)
    {
        //if element in employed is greater than max, set max to that element
        if (employed[i] > max3)
            max3 = employed[i];
    }
    cout << "Employed\t\t" << max3 << endl; //display max of Employed

    int max4 = housewife[0]; //max variable for houseWife
    for (int i = 1; i < housewife.size(); i++)
    {
        //if element in houseWife is greater than max, set max to that element
        if (housewife[i] > max4)
            max4 = housewife[i];
    }
    cout << "Housewife\t\t" << max4 << endl; //display max of housewife
}

//Definition of DisplayAvgServRatByMethod
void DisplayAvgServRatByMethod(vector<int> dineIn, vector<int> driveThru, vector<int> takeAway, vector<int> never, vector<int> others)
{
    //setup numeric formatting
    cout << fixed << setprecision(2) << endl;
    //Declare two sum variables
    double num1 = 0, num2 = 0;
    for (int i = 0; i < dineIn.size(); i++)
    {
        num1++; //increase num
        num2 += dineIn[i]; //add second num to dineIn
    }
    cout << "Dine In\t\t\t" << num2/num1 << endl; //display the average of dine in

    //Declare two sum variables
    double num3 = 0, num4 = 0;
    for (int i = 0; i < driveThru.size(); i++)
    {   
        num3++; //increase num
        num4 += driveThru[i]; //add second num to driveThru
    }
    cout << "Drive-thru\t\t" << num4/num3 << endl; //display average of drive-thru

    //declare two sum variables
    double num5 = 0, num6 = 0;
    for (int i = 0; i < takeAway.size(); i++)
    {
        num5++; //increase num
        num6 += takeAway[i]; //add second num to takeAway
    }
    cout << "Take away\t\t" << num6/num5 << endl; //display average of take away

    //declare two sum variables
    double num7 = 0, num8 = 0;
    for (int i = 0; i < never.size(); i++)
    {
        num7++; //increase num
        num8 += never[i]; //add second num to never
    }
    cout << "Never\t\t\t" << num8/num7 << endl; //display average of never

    //declare two sum variables
    double num9 = 0, num10 = 0;
    for (int i = 0; i < others.size(); i++)
    {
        num9++; //increase num
        num10 += others[i]; //add second num to others
    }
    cout << "Others\t\t\t" << num10/num9 << endl; //display average of never
}
