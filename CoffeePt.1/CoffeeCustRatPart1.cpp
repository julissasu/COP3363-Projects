#include <iostream>
#include <iomanip>

/* Name: Julissa Su Qiu
Date: 10/14/2022
Section: 0013
Assignment: Starbucks - Coffee Customer Rating Program Part 1
Due Date: 10/16/2022
About this project: This program will run a menu-driven program
with the following choices:
    1)Display number of ratings per option
    2)Change a rating
    3)Display the average rating
    4)Quit
Assumptions: Rating must be between 1 and 5 
All work below was performed by Julissa Su Qiu */

using namespace std;

//number of customers
const int NUM_CUSTOMERS = 113;

int getValidRating();       //get valid rating
int getValidCustomer();     //get valid customer
void displayRatings(int productRatings[NUM_CUSTOMERS]); //function to display ratings
void ChangeARating(int productRatings[NUM_CUSTOMERS]);  // function to change a rating
void displayAverageRating(int productRatings[NUM_CUSTOMERS]);   //function to display the average rating

int main()
{
    //variable for menu choice
    int choice;
    //array with ratings
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
    //welcome message
    cout << "Welcome to the Starbucks Coffee Customer Ratings Program!\n";

    //keep looping until user chooses to quit
    do
    {
        //display menu options and read in the choice
        cout << "1) Display number of the ratings per option\n"
            << "2) Change a rating\n"
            << "3) Display the average rating\n"
            << "4) Quit\n"
            << "Select an option (1..4)\n";
        cin >> choice;
        // input validation loop
        while (choice < 1 || choice > 5)
        {
            cout << "Please enter in a valid option: ";
            cin >> choice;
        }
        
        switch(choice)
        {
            // if user chose option 1
            case 1:
            {
                displayRatings(productRatings); //call function displayRatings
                break;
            }
            // if user chose option 2
            case 2:
            {
                ChangeARating(productRatings); //call function ChangeARating
                break;
            }
            // if user chose option 3
            case 3:
            {
                displayAverageRating(productRatings); //call function displayAverageRating
                break;
            }
            // if user chose option 4
            case 4:
                break;
        }
    
    } while (choice != 4);

    return 0;
}

//definition of getValidRating
int getValidRating()
{
    int rating;
    // prompt and read in rating
    cout << "Please enter in a rating (1-5): ";
    cin >> rating;
    //input validation loop
    while ((rating < 1) || (rating >5))
    {
        cout << "Please enter in a valid rating (1-5): ";
        cin >> rating;
    }
    return rating;
}

//definition of getValidCustomer
int getValidCustomer()
{
    int customer;
    // prompt and read in customer
    cout << "Please enter in a customer number: "; 
    cin >> customer;
    //input validation loop
    while (customer < 1 || customer > NUM_CUSTOMERS)
    {
        cout << "Please enter in a valid customer number ";
        cin >> customer; 
    }
    return customer;
}

//definition of displayRatings
void displayRatings(int productRatings[NUM_CUSTOMERS])
{
    cout << "Display ratings\n";
    //set all rates = 0
    int rate1 = 0, rate2 = 0, rate3 = 0, rate4 = 0, rate5 = 0;
    //display the numbers in rows of 10
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        if ((i+1) % 10 == 0)
            cout << setw(5) << productRatings[i] << setw(5) << endl;
        else 
            cout << setw(5) << productRatings[i] << setw(5);
    }
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        //sum of the amount of each rating
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
    //display the amount of each rating 
    cout << endl;
    cout << "Count by rating\n";
    cout << "1 " << setw(10) << rate1 << endl;
    cout << "2 " << setw(10) << rate2 << endl;
    cout << "3 " << setw(10) << rate3 << endl;
    cout << "4 " << setw(10) << rate4 << endl;
    cout << "5 " << setw(10) << rate5 << endl;    
}

//definition of ChangeARating
void ChangeARating(int productRatings[])
{
    //variables
    int customerName, customerRate;
    cout << "Change a rating " << endl;
    customerName = getValidCustomer(); //call for customer
    customerRate = getValidRating(); //call for rating
    productRatings[customerName - 1] = customerRate; 
}

void displayAverageRating(int productRatings[NUM_CUSTOMERS])
{
    double totalRating = 0;
    // Loop through each customer
    for (int i = 0; i < NUM_CUSTOMERS; i++)
        // compute total ratings
        totalRating += productRatings[i];
    //compute and display average rating
    double avgRate = (totalRating) / (NUM_CUSTOMERS);
    //set up numeric formatting
    cout << fixed << showpoint << setprecision(2);
    cout << "The average rating is " << avgRate << endl;
}
