#include <iostream>
#include <iomanip>

/* Name: Julissa Su Qiu
Date: 10/7/2022
Section: 0013
Assignment: Playing with Numbers Program
Due Date: 10/9/2022
About this project: This program will run a menu-driven program
of either computing the number of combinations, computing
the number of permutations, or quitting the program.
Assumptions: Number of combinations and permutations are greater than 0
All work below was performed by Julissa Su Qiu */

using namespace std;
void GetValidUserInputPosNumGTO (long int &num); //Get user to 
long double Factorial(long int num); //Factorial
long double ComputeCombination(long int n, long int k); //ComputeCombination
long double ComputePermutation(long int n, long int k); //ComputePermutation

int main()
{
    
    //Variables
    int choice;
    long int n,k;

    do
    {
        //Welcome message
        cout << "Welcome to playing with numbers!\n"
        //Display the menu options
            << "1) Compute the number of Combinations\n"
            << "2) Compute the number of Permutations\n"
            << "3) Quit\n"
            //Prompt user for choice and read it in
            << "Select and option (1,2,or 3) ";
        cin >> choice;
        //Input validation
        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << "You entered an invalid choice.\n";
            cout << "Please select option 1, 2, or 3 ";
            cin >> choice;
        }
    
        switch (choice)
        {
            //If user picked option 1
            case 1: 
            {
                //prompt and read in n value
                cout << "Enter in n: ";
                cin >> n;
                GetValidUserInputPosNumGTO(n); //Call for GetValidUserInputPosNumGTO to validate n
                //prompt and read in k value
                cout << "Enter in k: ";
                cin >> k;
                GetValidUserInputPosNumGTO(k); //Call for GetValidUserInputPosNumGTO to validate k
                cout << fixed << setprecision(0) << noshowpoint;
                cout << "Number of Combinations: " << ComputeCombination(n,k) << endl; //Display the number of combinations
                break;
            }
            //If user picked option 2
            case 2:
            {
                //prompt and read in n value
                cout << "Enter in n: ";
                cin >> n;
                GetValidUserInputPosNumGTO(n); //Call for GetValidUserInputPosNumGTO to validate n
                //prompt and read in k value
                cout << "Enter in k: ";
                cin >> k;
                GetValidUserInputPosNumGTO(k); //Call for GetValidUserInputPosNumGTO to validate k
                cout << fixed << setprecision(0) << noshowpoint;
                cout << "Number of Permutations: " << ComputePermutation(n,k) << endl; //Display the number of permutations
                break;
            }
            case 3:
            break;
        }
    } while (choice != 3);

    return 0;
}
 
//Definition of GetValidUserInputPosNumGTO
void GetValidUserInputPosNumGTO (long int &num)
{
    //Input validation loop
    while (num <= 0)
    {
        cout << "Please enter in a positive number greater than 0: ";
        cin >> num;
    }
}

//Definition of Factorial
long double Factorial(long int num)
{
    //Formula of factorial
    long double fact = 1;
    for (int a = 1; a <= num; a++)
    {
        fact *= a;
    }
    return fact;
}

//Definition of ComputeCombination
long double ComputeCombination(long int n, long int k)
{
    //Formula for combinations
    return Factorial(n) / (Factorial(k) * Factorial(n-k));
}

//Definition of ComputePermutation
long double ComputePermutation(long int n, long int k)
{
    //Formula for permutations
    return Factorial(n) / Factorial(n-k);
}