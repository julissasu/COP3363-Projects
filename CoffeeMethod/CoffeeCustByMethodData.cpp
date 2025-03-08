#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

/* Name: Julissa Su Qiu
Date: 11/19/2022
Section: 0013
Assignment: Starbucks - Coffee Customer Rating by Method Program
Due Date: 11/20/2022
About this project: This program will read through a file and fills the array 
of structures with the correct data. Then runs a menu-driven program with the 
following options
  A) Display Data
  B) Find Method with the largest number of service ratings <= 2
  C) Find Method with the largest percentage of service ratings >= 4
  D) Quit
Assumptions: 
* Must loop through elements in array to compute results
* Need to read through method column and link with the service rate
* Only read rate 1 and 2 for option b 
* Only read rate 4 and 5 for option c
All work below was performed by Julissa Su Qiu */

using namespace std;

//structure 
struct CoffeeRatingsData
{
    string Method;
    //declare variable for each rating number 
    // and intialize to 0
    int NumSerRateEq1 = 0;
    int NumSerRateEq2 = 0;  
    int NumSerRateEq3 = 0;
    int NumSerRateEq4 = 0;
    int NumSerRateEq5 = 0;
};

//function prototypes
void showMenu();    //show menu options
int SelectValidMenuOption();    //select a valid menu option
void ReadData(CoffeeRatingsData []);    //function to read data
void displayData(CoffeeRatingsData []); //function to display data
void largestNumOfServRat(CoffeeRatingsData[]);  //function for option A
void largestPercentOfServRat(CoffeeRatingsData[]); //function for option B

int main()
{
    //Welcome message
    cout << "Welcome to Avengers Data by Range Program\n";

    //data is an array that is an instance of CoffeeRatingsData
    CoffeeRatingsData data[5];
    //set each element of the array to the corresponding method
    data[0].Method = "Dine In";
    data[1].Method = "Drive-thru";
    data[2].Method = "Take away";
    data[3].Method = "Never";
    data[4].Method = "Others";
    
    char option; //variable for menu choice
    do
    {
        //call function for user menu choice
        option = SelectValidMenuOption();

        switch (option)
        {   
            //if user chose A or a
            case 'A': case 'a':
                ReadData(data);
                displayData(data);
                break;
            //if user chose B or b
            case 'B': case 'b':
                ReadData(data);
                largestNumOfServRat(data);
                break;
            //if user chose C or c
            case 'C': case 'c':
                ReadData(data);
                largestPercentOfServRat(data);
                break;
        }
    } while (toupper(option) != 'D');
    
    return 0;
}

//definition of showMenu
void showMenu()
{
    cout << "Menu Options:\n";
    cout << "A) Display Data:\n";
    cout << "B) Find Method with the largest"
        << " number of service ratings <= 2\n";
    cout << "C) Find the Method with the largest"
        << " percentage of service >=4\n";
    cout << "D) Quit\n";
}

//definition of SelectValidMenuOption
int SelectValidMenuOption()
{
    char ch;
    //display menu options
    showMenu();
    //read in choice
    cin >> ch;
    //input validation loop
    while(toupper(ch) != 'A' && toupper(ch) != 'B' && 
            toupper(ch) != 'C' && toupper(ch) != 'D')
    {
        //prompt and read in choice
        showMenu();
        cin >> ch;
    }
    //return the user's menu choice
    return ch;
}

//definition of ReadData
void ReadData(CoffeeRatingsData data[5])
{
    //create an input stream and open it
    ifstream StarbucksDataFile;
    StarbucksDataFile.open("StarbucksData.txt");
    //test if the file opened successfully
    if (!StarbucksDataFile)
        cout << "Error";
    
    if (StarbucksDataFile)
    {   
        //create variable for each record
        int data1 = 0, data2 = 0, data3 = 0, data4 = 0, data5 = 0;
        while (StarbucksDataFile >> data1 >> data2 >> data3 >> data4 >> data5)
        {
            //if method is dine in
            if (data2 == 0)
            {
                //check each rating from serviceRate
                if (data5 == 1)
                    //if rating is 1 then accumulate the amount
                    data[0].NumSerRateEq1++;
                else if (data5 == 2)
                    //if rating is 2 then accumulate the amount
                    data[0].NumSerRateEq2++;
                else if (data5 == 3)
                    //if rating is 3 then accumulate the amount
                    data[0].NumSerRateEq3++;
                else if (data5 == 4)
                    //if rating is 4 then accumulate the amount
                    data[0].NumSerRateEq4++;
                else if (data5 == 5)
                    //if rating is 5 then accumulate the amount
                    data[0].NumSerRateEq5++;
            }
            //if method is drive thru
            else if (data2 == 1)
            {
                //check each rating from serviceRate
                if (data5 == 1)
                    //if rating is 1 then accumulate the amount
                    data[1].NumSerRateEq1++;
                else if (data5 == 2)
                    //if rating is 2 then accumulate the amount
                    data[1].NumSerRateEq2++;
                else if (data5 == 3)
                    //if rating is 3 then accumulate the amount
                    data[1].NumSerRateEq3++;
                else if (data5 == 4)
                    //if rating is 4 then accumulate the amount
                    data[1].NumSerRateEq4++;
                else if (data5 == 5)
                    //if rating is 5 then accumulate the amount
                    data[1].NumSerRateEq5++;
            }
            //if method is take away
            else if (data2 == 2)
            {
                //check each rating from serviceRate
                if (data5 == 1)
                    //if rating is 1 then accumulate the amount
                    data[2].NumSerRateEq1++;
                else if (data5 == 2)
                    //if rating is 2 then accumulate the amount
                    data[2].NumSerRateEq2++;
                else if (data5 == 3)
                    //if rating is 3 then accumulate the amount
                    data[2].NumSerRateEq3++;
                else if (data5 == 4)
                    //if rating is 4 then accumulate the amount
                    data[2].NumSerRateEq4++;
                else if (data5 == 5)
                    //if rating is 5 then accumulate the amount
                    data[2].NumSerRateEq5++;
            }
            //if method is never
            else if (data2 == 3)
            {
                //check each rating from serviceRate
                if (data5 == 1)
                    //if rating is 1 then accumulate the amount
                    data[3].NumSerRateEq1++;
                else if (data5 == 2)
                    //if rating is 2 then accumulate the amount
                    data[3].NumSerRateEq2++;
                else if (data5 == 3)
                    //if rating is 3 then accumulate the amount
                    data[3].NumSerRateEq3++;
                else if (data5 == 4)
                    //if rating is 4 then accumulate the amount
                    data[3].NumSerRateEq4++;
                else if (data5 == 5)
                    //if rating is 5 then accumulate the amount
                    data[3].NumSerRateEq5++;
            }
            //if method is others
            else if (data2 == 4)
            {
                //check each rating from serviceRate
                if (data5 == 1)
                    //if rating is 1 then accumulate the amount
                    data[4].NumSerRateEq1++;
                else if (data5 == 2)
                    //if rating is 2 then accumulate the amount
                    data[4].NumSerRateEq2++;
                else if (data5 == 3)
                    //if rating is 3 then accumulate the amount
                    data[4].NumSerRateEq3++;
                else if (data5 == 4)
                    //if rating is 4 then accumulate the amount
                    data[4].NumSerRateEq4++;
                else if (data5 == 5)
                    //if rating is 5 then accumulate the amount
                    data[4].NumSerRateEq5++;
            }
        }
    }
    //close file
    StarbucksDataFile.close();
}

//definition of displayData
void displayData(CoffeeRatingsData data[5])
{
    //setup numeric formatting
    cout << fixed << showpoint << setprecision(2); 

    cout << right << setw(9) << "Method" << setw(11) << "Rate=1" << setw(10) << "Rate=2" << setw(10)
        << "Rate=3" << setw(10) << "Rate=4" << setw(10) << "Rate=5" << left << setw(9) << endl;
    
    //Display the count of each rating for Dine In
    cout << right << setw(10) << "Dine In" << left << setw(10) << endl;
    cout << right << setw(10) << "Count" << setw(10) << data[0].NumSerRateEq1 << setw(10) 
        << data[0].NumSerRateEq2 << setw(10) << data[0].NumSerRateEq3 << setw(10) << data[0].NumSerRateEq4 
        << setw(10) << data[0].NumSerRateEq5 << left << setw(10) << endl;
    //calculate the percentage of each rating and display values
    double sum0 = data[0].NumSerRateEq1 + data[0].NumSerRateEq2 + data[0].NumSerRateEq3 + 
                    data[0].NumSerRateEq4 + data[0].NumSerRateEq5;
    double percentRate0A = (data[0].NumSerRateEq1 / sum0) * 100;
    double percentRate0B = (data[0].NumSerRateEq2 / sum0) * 100;
    double percentRate0C = (data[0].NumSerRateEq3 / sum0) * 100;
    double percentRate0D = (data[0].NumSerRateEq4 / sum0) * 100;
    double percentRate0E = (data[0].NumSerRateEq5 / sum0) * 100;
    if (sum0 == 0)  //if nan then set the percent to 0
    {
        percentRate0A = 0;
        percentRate0B = 0;
        percentRate0C = 0;
        percentRate0D = 0;
        percentRate0E = 0;
    }
    cout << right << setw(10) << "%" << setw(10) << percentRate0A << setw(10) << percentRate0B << setw(10) 
        << percentRate0C << setw(10) << percentRate0D << setw(10) << percentRate0E << setw(10) << endl;

    //Display the count of each rating for Dine In
    cout << right << setw(10) << "Drive-thru" << left << setw(10) << endl;
    cout << right << setw(10) << "Count" << setw(10) << data[1].NumSerRateEq1 << setw(10) 
        << data[1].NumSerRateEq2 << setw(10) << data[1].NumSerRateEq3 << setw(10) << data[1].NumSerRateEq4 
        << setw(10) << data[1].NumSerRateEq5 << left << setw(10) << endl;
    //calculate the percentage of each rating and display values
    double sum1 = data[1].NumSerRateEq1 + data[1].NumSerRateEq2 + data[1].NumSerRateEq3 + 
                    data[1].NumSerRateEq4 + data[1].NumSerRateEq5;
    double percentRate1A = (data[1].NumSerRateEq1 / sum1) * 100;
    double percentRate1B = (data[1].NumSerRateEq2 / sum1) * 100;
    double percentRate1C = (data[1].NumSerRateEq3 / sum1) * 100;
    double percentRate1D = (data[1].NumSerRateEq4 / sum1) * 100;
    double percentRate1E = (data[1].NumSerRateEq5 / sum1) * 100;
    if (sum1 == 0)  //if nan then set the percent to 0
    {
        percentRate1A = 0;
        percentRate1B = 0;
        percentRate1C = 0;
        percentRate1D = 0;
        percentRate1E = 0;
    }
    cout << right << setw(10) << "%" << setw(10) << percentRate1A << setw(10) << percentRate1B << setw(10) 
        << percentRate1C << setw(10) << percentRate1D << setw(10) << percentRate1E << setw(10) << endl;

    //Display the count of each rating for Take away
    cout << right << setw(10) << "Take away" << left << setw(10) << endl;
    cout << right << setw(10) << "Count" << setw(10) << data[2].NumSerRateEq1 << setw(10) 
        << data[2].NumSerRateEq2 << setw(10) << data[2].NumSerRateEq3 << setw(10) << data[2].NumSerRateEq4 
        << setw(10) << data[2].NumSerRateEq5 << left << setw(10) << endl;
    //calculate the percentage of each rating and display values
    double sum2 = data[2].NumSerRateEq1 + data[2].NumSerRateEq2 + data[2].NumSerRateEq3 + 
                    data[2].NumSerRateEq4 + data[2].NumSerRateEq5;
    double percentRate2A = (data[2].NumSerRateEq1 / sum2) * 100;
    double percentRate2B = (data[2].NumSerRateEq2 / sum2) * 100;
    double percentRate2C = (data[2].NumSerRateEq3 / sum2) * 100;
    double percentRate2D = (data[2].NumSerRateEq4 / sum2) * 100;
    double percentRate2E = (data[2].NumSerRateEq5 / sum2) * 100;
    if (sum2 == 0)  //if nan then set the percent to 0
    {
        percentRate2A = 0;
        percentRate2B = 0;
        percentRate2C = 0;
        percentRate2D = 0;
        percentRate2E = 0;
    }
    cout << right << setw(10) << "%" << setw(10) << percentRate2A << setw(10) << percentRate2B << setw(10) 
        << percentRate2C << setw(10) << percentRate2D << setw(10) << percentRate2E << setw(10) << endl;
    
    //Display the count of each rating for Never
    cout << right << setw(10) << "Never" << left << setw(10) << endl;
    cout << right << setw(10) << "Count" << setw(10) << data[3].NumSerRateEq1 << setw(10) 
        << data[3].NumSerRateEq2 << setw(10) << data[3].NumSerRateEq3 << setw(10) << data[3].NumSerRateEq4 
        << setw(10) << data[3].NumSerRateEq5 << left << setw(10) << endl;
    //calculate the percentage of each rating and display values
    double sum3 = data[3].NumSerRateEq1 + data[3].NumSerRateEq2 + data[3].NumSerRateEq3 + 
                    data[3].NumSerRateEq4 + data[3].NumSerRateEq5;
    double percentRate3A = (data[3].NumSerRateEq1 / sum3) * 100;
    double percentRate3B = (data[3].NumSerRateEq2 / sum3) * 100;
    double percentRate3C = (data[3].NumSerRateEq3 / sum3) * 100;
    double percentRate3D = (data[3].NumSerRateEq4 / sum3) * 100;
    double percentRate3E = (data[3].NumSerRateEq5 / sum3) * 100;
    if (sum3 == 0) //if nan then set the percent to 0
    {
        percentRate3A = 0;
        percentRate3B = 0;
        percentRate3C = 0;
        percentRate3D = 0;
        percentRate3E = 0;
    }
    cout << right << setw(10) << "%" << setw(10) << percentRate3A << setw(10) << percentRate3B << setw(10) 
        << percentRate3C << setw(10) << percentRate3D << setw(10) << percentRate3E << setw(10) << endl;

    //Display the count of each rating for Others
    cout << right << setw(10) << "Others" << left << setw(10) << endl;
    cout << right << setw(10) << "Count" << setw(10) << data[4].NumSerRateEq1 << setw(10) 
        << data[4].NumSerRateEq2 << setw(10) << data[4].NumSerRateEq3 << setw(10) << data[4].NumSerRateEq4 
        << setw(10) << data[4].NumSerRateEq5 << left << setw(10) << endl;
    double sum4 = data[4].NumSerRateEq1 + data[4].NumSerRateEq2 + data[4].NumSerRateEq3 + 
                    data[4].NumSerRateEq4 + data[4].NumSerRateEq5;
    //calculate the percentage of each rating and display values
    double percentRate4A = (data[4].NumSerRateEq1 / sum4) * 100;
    double percentRate4B = (data[4].NumSerRateEq2 / sum4) * 100;
    double percentRate4C = (data[4].NumSerRateEq3 / sum4) * 100;
    double percentRate4D = (data[4].NumSerRateEq4 / sum4) * 100;
    double percentRate4E = (data[4].NumSerRateEq5 / sum4) * 100;
    if (sum4 == 0) //if nan then set the percent to 0
    {
        percentRate4A = 0;
        percentRate4B = 0;
        percentRate4C = 0;
        percentRate4D = 0;
        percentRate4E = 0;
    }
    cout << right << setw(10) << "%" << setw(10) << percentRate4A << setw(10) << percentRate4B << setw(10)
        << percentRate4C << setw(10) << percentRate4D << setw(10) << percentRate4E << left << setw(10) << endl;
}   

//definition of largestNumOfServRat
void largestNumOfServRat(CoffeeRatingsData data[5])
{
    //declare a variable for max num rating
    int maxNumRating = 0;
    //declare a variable for max method
    string maxMethod;
    int totalRatings = 0;

    for (int i = 0; i < 5; i++)
    {
        //calc total ratings of rates 1 and 2 
        totalRatings = data[i].NumSerRateEq1 + data[i].NumSerRateEq2;
        //if the sum of method 1 and 2 is greater than max num rating
        if (totalRatings > maxNumRating)
        {
            //set the sum to the max
            maxNumRating = totalRatings;
            //set the maxmethod to the corresponding method that is max
            maxMethod = data[i].Method;
        }
    }
    cout << "The method with the largest number of service rating <= 2 is ...\n"
            << maxMethod << endl;
}

//definition of largestPercentOfServRat
void largestPercentOfServRat(CoffeeRatingsData data[5])
{
    //declare a variable for the max percent rating
    int maxPercentRating = 0;
    //declare a variable for the max method 
    string maxMethod;
    int totalRatings = 0;

    for (int i = 0; i < 5; i++)
    {
        //calculate total ratings of rates 4 and 5
        totalRatings = data[i].NumSerRateEq4 + data[i].NumSerRateEq5;
        //if the total ratings is greater than the max percent
        if (totalRatings > maxPercentRating)
        {
            //set the total to the max
            maxPercentRating = totalRatings;
            //set the maxmethod to the corresponding method that is max
            maxMethod = data[i].Method;
        }
    }

    cout << "The method with the largest percentage of service rating >=4 is ...\n"
            << maxMethod << endl;
}