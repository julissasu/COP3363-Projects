#include <iostream>
#include <iomanip>

/* Name: Julissa Su Qiu
Date: 10/18/2022
Section: 0013
Assignment: Starbucks - Coffee Customer Rating Program Part 2
Due Date: 10/23/2022
About this project: This program will run a menu-driven program
with the following choices:
    1)Display number of ratings per option
    2)Change a rating
    3)Display the average rating
    4) Find the lowest rating
    5) Display Sorted Ratings Asc
    6) Display Sorted Ratings Desc
    7) Quit
Assumptions: 
* Rating must be between 1 and 5 
* Customers range between 1 and 113
* Need a function for swapping integers
All work below was performed by Julissa Su Qiu */

using namespace std;

//Number of customers
const int NUM_CUSTOMERS = 113;

int getValidRating(); //Get valid rating
int getValidCustomer(); //Get valid customer
void displayRatings(int productRatings[NUM_CUSTOMERS]); //Function to display ratings
void ChangeARating(int productRatings[NUM_CUSTOMERS]); //Function to change a rating
void displayAverageRating(int productRatings[NUM_CUSTOMERS]); //Function to display the average rating
void displayLowestRatings(int productRatings[NUM_CUSTOMERS]); //Function to display lowest ratings
void displaySortedRatingsAsc(int productRatings[NUM_CUSTOMERS]); //Function to sort ratings in ascending order
void displaySortedRatingsDesc(int productRatings[NUM_CUSTOMERS]); //Function to sort ratings in descending order
void swap(int &, int &); //Function for swapping

int main()
{
    //Variable for menu choice
    int choice;
    //Array with ratings
    int productRatings[NUM_CUSTOMERS] = {
        4, 4, 4, 2, 3, 4, 5, 4, 5, 4,
        4, 3, 4, 4, 5, 4, 4, 4, 4, 3, 
        2, 5, 5, 5, 4, 4, 4, 5, 4, 5, 
        3, 4, 2, 3, 3, 4, 3, 5, 4, 3, 
        5, 5, 4, 5, 3, 3, 3, 4, 3, 5, 
        3, 4, 4, 5, 5, 3, 4, 2, 5, 3, 
        4, 3, 4, 4, 2, 3, 4, 5, 4, 3, 
        3, 3, 4, 4, 2, 2, 3, 5, 4, 4, 
        4, 4, 3, 4, 5, 4, 4, 5, 3, 3, 
        3, 3, 4, 4, 3, 3, 4, 4, 4, 4, 
        3, 3, 4, 5, 3, 2, 5, 4, 3, 5, 
        3, 4, 1};       
    //Welcome message
    cout << "Welcome to the Starbucks Coffee Customer Ratings Program!\n";

    //Keep looping until user chooses to quit
    do
    {
        //Display menu options and read in the choice
        cout << "1) Display number of the ratings per option\n"
            << "2) Change a rating\n"
            << "3) Display the average rating\n"
            << "4) Find the lowest rating\n"
            << "5) Display Sorted Ratings Asc\n"
            << "6) Display Sorted Ratings Desc\n"
            << "7) Quit\n"
            << "Select an option (1..7) ";
        cin >> choice;
        //Input validation loop
        while (choice < 1 || choice > 7)
        {
            cout << "Please enter in a valid option (1..7) ";
            cin >> choice;
        }
        
        switch(choice)
        {
            //If user chose option 1
            case 1:
            {
                displayRatings(productRatings); //Call function displayRatings
                break;
            }
            //If user chose option 2
            case 2:
            {
                ChangeARating(productRatings); //Call function ChangeARating
                break;
            }
            //If user chose option 3
            case 3:
            {
                displayAverageRating(productRatings); //Call function displayAverageRating
                break;
            }
            //If user chose option 4
            case 4:
                displayLowestRatings(productRatings); //Call function displayLowestRatings
                break;
            //If user chose option 5
            case 5:
                displaySortedRatingsAsc(productRatings); //Call function displaySortedRatingsAsc  
                displayRatings(productRatings); //Display the ratings in ascending order
                break;
            //If user chose option 6
            case 6:
                displaySortedRatingsDesc(productRatings); //Call function displaySortedRatingsDesc
                displayRatings(productRatings); //Display the ratings in descending order
                break;
        }
    
    } while (choice != 7);

    return 0;
}

//Definition of getValidRating
int getValidRating()
{
    int rating;
    //Prompt and read in rating
    cout << "Please enter in the rating (1-5): ";
    cin >> rating;
    //Input validation loop
    while ((rating < 1) || (rating >5))
    {
        cout << "Please enter in a valid rating (1-5): ";
        cin >> rating;
    }
    return rating;
}

//Definition of getValidCustomer
int getValidCustomer()
{
    int customer;
    //Prompt and read in customer
    cout << "Please enter in the number of the customer: "; 
    cin >> customer;
    //Input validation loop
    while (customer < 1 || customer > NUM_CUSTOMERS)
    {
        cout << "Please enter in a valid customer number: ";
        cin >> customer; 
    }
    return customer;
}

//Definition of displayRatings
void displayRatings(int productRatings[NUM_CUSTOMERS])
{
    cout << "Display Ratings\n";
    //Set all rates = 0
    int rate1 = 0, rate2 = 0, rate3 = 0, rate4 = 0, rate5 = 0;
    //Display the numbers in rows of 10
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        if ((i+1) % 10 == 0)
            cout << setw(5) << productRatings[i] << setw(5) << endl;
        else 
            cout << setw(5) << productRatings[i] << setw(5);
    }
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        //Sum of the amount of each rating
        if (productRatings[i] == 1)
            rate1++;
        else if (productRatings[i] == 2)
            rate2++;
        else if (productRatings[i] == 3)
            rate3++;
        else if (productRatings[i] == 4)
            rate4++;
        else if (productRatings[i] == 5)
            rate5++;
    }
    //Display the amount of each rating 
    cout << endl;
    cout << "Count by Rating\n";
    cout << "1 " << setw(10) << rate1 << endl;
    cout << "2 " << setw(10) << rate2 << endl;
    cout << "3 " << setw(10) << rate3 << endl;
    cout << "4 " << setw(10) << rate4 << endl;
    cout << "5 " << setw(10) << rate5 << endl;    
}

//Definition of ChangeARating
void ChangeARating(int productRatings[])
{
    //Variables
    int customerName, customerRate;
    cout << "Change a rating " << endl;
    customerName = getValidCustomer(); //call for customer
    customerRate = getValidRating(); //call for rating
    productRatings[customerName - 1] = customerRate; //new rate 
}

//Definition of displayAverageRating
void displayAverageRating(int productRatings[NUM_CUSTOMERS])
{
    double totalRating = 0;
    //Loop through each customer
    for (int i = 0; i < NUM_CUSTOMERS; i++)
        //Compute total ratings
        totalRating += productRatings[i];
    //Compute and display average rating
    double avgRate = (totalRating) / (NUM_CUSTOMERS);
    //Set up numeric formatting
    cout << fixed << showpoint << setprecision(2);
    cout << "The average of rating is " << avgRate << endl;
}

//Definition of displayLowestRatings
void displayLowestRatings(int productRatings[NUM_CUSTOMERS])
{
    //Index of the Lowest Rating
    int idxLowestRating = 0;
    //Loop through each customer 
    for (int i = 1; i < NUM_CUSTOMERS; i++)
    {
        //Rating of a customer at element i 
        //is less than indxLowestRating
        if (productRatings[i] < productRatings[idxLowestRating])
            //If true, set idxLowestRating equal to i
            idxLowestRating = i;  
    }
    //Display the lowest rating 
    cout << "The lowest rating is " << productRatings[idxLowestRating] << endl;
}

//Definition of displaySortedRatingsAsc
void displaySortedRatingsAsc(int productRatings[NUM_CUSTOMERS])
{
    //Initialize Bubble Sort Algorithm
    for (int value = NUM_CUSTOMERS - 1; value > 0; value--)
    {
        for (int i = 0; i < value; i++)
        {
            //Compare the elements
            if (productRatings[i] > productRatings[i + 1])
                //Swap if expression is true
                swap(productRatings[i], productRatings[i + 1]);
        }
    }
}

//Definition of displaySortedRatingsDesc
void displaySortedRatingsDesc(int productRatings[NUM_CUSTOMERS])
{
    //Initialize Selection Sort Algorithm
    //Variables to keep track of max values 
    int maxIdx, temp;
    double maxVal;
    //Loop from 0 to (NUM_CUSTOMERS - 1)
    for (int start = 0; start < (NUM_CUSTOMERS - 1); start++)
    {
        //Set current element as max index
        maxIdx = start;
        maxVal = productRatings[start];
        temp = productRatings[start];
        //Find index of the max element
        for (int i = start + 1; i < NUM_CUSTOMERS; i++)
        {
            if (productRatings[i] > maxVal)
            {
                maxVal = productRatings[i];
                temp = productRatings[i];
                maxIdx = i;
            }
        }
        //Swap the max and current if necessary
        swap(productRatings[maxIdx], productRatings[start]);
    }
}

//Definition of swap
void swap(int &num1, int &num2)
{
    //Declare a temporary variable to equal num1
    int temp = num1;
    //Swap the two integers
    num1 = num2;
    num2 = temp;
}