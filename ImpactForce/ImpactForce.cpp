#include <iostream>
#include <iomanip> // Needed for setw
#include <cmath> // Needed for math operators
using namespace std;

/* Name: Julissa Su Qiu
Date: 9/10/2022 
Section: 0013
Assignment: Impact Force Program
Due Date: 9/11/2022
About this project: This program will calculate impact force
Assumptions: The values that the user enters will be utilized in a formula to obtain impact force. 
All work below was performed by Julissa Su Qiu */

int main ()
{
    cout << "Welcome, user, to the Impact Force Program." << endl;

    long double mass, velocity, speed, ans;

    // Get each value needed to calculate impact force
    cout << "Please enter in the mass (in kg): " << endl;
    cin >> mass;

    cout << "velocity of the object (in m/s): " << endl;
    cin >> velocity;

    cout << "and speed (in m)" << endl;
    cin >> speed;

    // Calculate the impact force using the formula mv^2 / 2s
    ans = mass * (pow(velocity,2)) / (2 * speed);

    // Display the values and answer
    cout << setprecision(12) << fixed;
    cout << left << setw(15) << "Mass: " << right << setw(30) << mass << endl;
    cout << left << setw(15) << "Velocity: " << right << setw(30) << velocity << endl;
    cout << left << setw(15) << "Speed: " << right << setw(30) << speed << endl;
    cout << left << setw(15) << "Impact force: " << right << setw(30) << ans << endl;

    return 0;
}
