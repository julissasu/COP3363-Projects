/* Name: Julissa Su Qiu
Date: 9/23/2022 
Section: 0013
Assignment: Approximate PI Program
Due Date: 9/25/2022
About this project: This program will print out the approximate value of PI 
with k value chosen by the user.
Assumptions: NA
All work below was performed by Julissa Su Qiu */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //Welcome
    cout << "Welcome to the Approximate PI Program!\n";

    //k value
    int kVal;
    //prompt and read in k value
    cout << "Please enter in a value >= 1 and <= 30 for k: ";
    cin >> kVal;

    //input validation loop
    while (kVal < 1 || kVal > 30)
    {
        //invalid input
        //prompt and read in k value
        cout << "Invalid ---k must be >= 1 and <= 30.\n";
        cout << "Please enter in a value for k: ";
        cin >> kVal;
    }

    long double current;
    long double ans ;

    //loop for computing the sum of the nested square roots
    for (int i = 1; i < kVal-1; i++) 
    {
        //add 2 to my current
        current += 2.0;
        current = sqrt(current);
    }

    //compute the outermost square root
    current = sqrt(2.0-current);
    //compute and display the approximation of pi
    ans = pow(2.0, kVal-1);
    ans *= current;
    cout << setprecision(20) << ans << endl;

    return 0;
}