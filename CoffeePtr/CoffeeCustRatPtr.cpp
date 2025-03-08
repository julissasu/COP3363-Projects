#include <iostream>
#include <iomanip>

/* Name: Julissa Su Qiu
Date: 11/4/2022
Section: 0013
Assignment: Starbucks - Coffee Customer Rating Program Part 3
Due Date: 11/9/2022
About this project: This program will run a menu-driven program
with the following choices:
    1) Display number of ratings per option
    2) Change a rating
    3) Display the average rating
    4) Find the lowest rating
    5) Display Sorted Ratings Asc
    6) Display Sorted Ratings Desc
    7) Add another rating
    8) Quit
Assumptions: 
* Rating must be between 1 and 5 
* Customers range between 1 and 113
* Need a function for swapping integers
* Do not need to modify functions if array size changes 
All work below was performed by Julissa Su Qiu */

using namespace std;

int getValidRating(); //Get valid rating
int getValidCustomer(); //Get valid customer
void displayRatings(int *, int); //Function to display ratings
void ChangeARating(int *, int); //Function to change a rating
void displayAverageRating(int *, int); //Function to display the average rating
void displayLowestRatings(int *, int); //Function to display lowest ratings
void displaySortedRatingsAsc(int *, int); //Function to sort ratings in ascending order
void displaySortedRatingsDesc(int *, int); //Function to sort ratings in descending order
void swap(int &, int &); //Function for swapping
int * AddAnotherRating(int *, int &); //Allows user to add more ratings

int main()
{
    //Variable for menu choice
    int choice;

    //Number of customers
    int numCustomers =113;
    
    //Dynamically allocated pointer array
    int * productRatings = new int [numCustomers]{
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
            << "7) Add another rating\n"
            << "8) Quit\n"
            << "Select an option (1..8) ";
        cin >> choice;
        //Input validation loop
        while (choice < 1 || choice > 8)
        {
            cout << "Please enter in a valid option (1..8) ";
            cin >> choice;
        }
        
        switch(choice)
        {
            //If user chose option 1
            case 1:
            {
                displayRatings(productRatings, numCustomers); //Call function displayRatings
                break;
            }
            //If user chose option 2
            case 2:
            {
                ChangeARating(productRatings, numCustomers); //Call function ChangeARating
                break;
            }
            //If user chose option 3
            case 3:
            {
                displayAverageRating(productRatings, numCustomers); //Call function displayAverageRating
                break;
            }
            //If user chose option 4
            case 4:
                displayLowestRatings(productRatings, numCustomers); //Call function displayLowestRatings
                break;
            //If user chose option 5
            case 5:
                displaySortedRatingsAsc(productRatings, numCustomers); //Call function displaySortedRatingsAsc  
                displayRatings(productRatings, numCustomers); //Display the ratings in ascending order
                break;
            //If user chose option 6
            case 6:
                displaySortedRatingsDesc(productRatings, numCustomers); //Call function displaySortedRatingsDesc
                displayRatings(productRatings, numCustomers); //Display the ratings in descending order
                break;
            //If user chose option 7
            case 7:
                productRatings = AddAnotherRating(productRatings, numCustomers);
                break;
        }
    
    } while (choice != 8);

    //Free the dynamically allocated memory
    //and set the pointer to 0
    delete [] productRatings;
    productRatings = nullptr; 

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
int getValidCustomer(int &numCustomers)
{
    int customer;
    //Prompt and read in customer
    cout << "Please enter in the number of the customer: "; 
    cin >> customer;
    //Input validation loop
    while (customer < 1 || customer > numCustomers)
    {
        cout << "Please enter in a valid customer number: ";
        cin >> customer; 
    }
    return customer;
}

//Definition of displayRatings
void displayRatings(int *productRatings, int numCustomers)
{
    cout << "Display Ratings\n";
    //Set all rates = 0
    int rate1 = 0, rate2 = 0, rate3 = 0, rate4 = 0, rate5 = 0;
    //Display the numbers in rows of 10
    for (int i = 0; i < numCustomers; i++)
    {
        if ((i+1) % 10 == 0)
            cout << setw(5) << *(productRatings + i) << setw(5) << endl;
        else 
            cout << setw(5) << *(productRatings + i) << setw(5);
    }
    for (int i = 0; i < numCustomers; i++)
    {
        //Sum of the amount of each rating
        if (*(productRatings + i) == 1)
            rate1++;
        else if (*(productRatings + i) == 2)
            rate2++;
        else if (*(productRatings + i) == 3)
            rate3++;
        else if (*(productRatings + i) == 4)
            rate4++;
        else if (*(productRatings + i) == 5)
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
void ChangeARating(int *productRatings, int numCustomers)
{
    //Variables
    int customerName, customerRate;
    cout << "Change a rating " << endl;
    customerName = getValidCustomer(numCustomers); //call for customer
    customerRate = getValidRating(); //call for rating
    *(productRatings + customerName - 1) = customerRate; //new rate 
}

//Definition of displayAverageRating
void displayAverageRating(int *productRatings, int numCustomers)
{
    double totalRating = 0;
    //Loop through each customer
    for (int i = 0; i < numCustomers; i++)
        //Compute total ratings
        totalRating += *(productRatings + i);
    //Compute and display average rating
    double avgRate = (totalRating) / (numCustomers);
    //Set up numeric formatting
    cout << fixed << showpoint << setprecision(2);
    cout << "The average of rating is " << avgRate << endl;
}

//Definition of displayLowestRatings
void displayLowestRatings(int *productRatings, int numCustomers)
{
    //Index of the Lowest Rating
    int idxLowestRating = 0;
    //Loop through each customer 
    for (int i = 1; i < numCustomers; i++)
    {
        //Rating of a customer at element i 
        //is less than indxLowestRating
        if (*(productRatings + i) < *(productRatings + idxLowestRating))
            //If true, set idxLowestRating equal to i
            idxLowestRating = i;  
    }
    //Display the lowest rating 
    cout << "The lowest rating is " << *(productRatings + idxLowestRating) << endl;
}

//Definition of displaySortedRatingsAsc
void displaySortedRatingsAsc(int *productRatings, int numCustomers)
{
    //Initialize Bubble Sort Algorithm
    for (int value = numCustomers - 1; value > 0; value--)
    {
        for (int i = 0; i < value; i++)
        {
            //Compare the elements
            if (*(productRatings + i) > *(productRatings + i + 1))
                //Swap if expression is true
                swap(*(productRatings + i), *(productRatings + i + 1));
        }
    }
}

//Definition of displaySortedRatingsDesc
void displaySortedRatingsDesc(int *productRatings, int numCustomers)
{
    //Initialize Selection Sort Algorithm
    //Varibles to keep track of max values 
    int maxIdx, temp;
    double maxVal;
    //Loop from 0 to (NUM_CUSTOMERS - 1)
    for (int start = 0; start < (numCustomers - 1); start++)
    {
        //Set current element as max index
        maxIdx = start;
        maxVal = *(productRatings + start);
        temp = *(productRatings + start);
        //Find index of the max element
        for (int i = start + 1; i < numCustomers; i++)
        {
            if (*(productRatings+i) > maxVal)
            {
                maxVal = *(productRatings + i);
                temp = *(productRatings + i);
                maxIdx = i;
            }
        }
        //Swap the max and current if necessary
        swap(*(productRatings + maxIdx), *(productRatings + start));
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

//Definition of AddAnotherRating 
int * AddAnotherRating(int *productRatings, int & numCustomers)
{
    //Get a valid rating
    int newRating = getValidRating();
    
    //Allocated on heap
    int *newproductRatings = new int[numCustomers - 1];
    for (int index = 0; index < numCustomers; index++)
        //Copy values to new array
        *(newproductRatings + index) = *(productRatings + index);
    numCustomers++;
    //Set the rating to newRating
    *(newproductRatings + numCustomers - 1) = newRating;

    //Free old array memory and set pointer to zero
    delete [] productRatings;
    productRatings = nullptr;

    //Return the new array
    return newproductRatings;
}   