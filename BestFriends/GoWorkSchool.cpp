/* Name: Julissa Su Qiu
Date: 9/17/2022 
Section: 0013
Assignment: Do I go to Work or School? Program
Due Date: 9/18/2022
About this project: This program will ask the user questions to determine whether to go to school/work or not. 
Assumptions: NA
All work below was performed by Julissa Su Qiu */

#include <iostream>
using namespace std;

int main()
{
    // Welcome message
    cout << "Welcome to the 'Do I go to Work or School?' Program.\n";

    char wakeUp, waterPress, weather, opinion; 

    cout << "Please answer the following questions.\n";
    
    // Asking user the first question
    cout << "Did you wake up on time? (Y/N)\n";
    cin >> wakeUp;

    // User chooses option Y 
    if (wakeUp == 'y' || wakeUp == 'Y')
    {
        // Asking user the second question
        cout << "How's the shower's water pressure?\n";
        cout << "A) Fine?\n";
        cout << "B) Meh\n";
        cin >> waterPress;

        // User chooses option A
        if (waterPress == 'a' || waterPress == 'A')
        {
            // Asking user the third question
            cout << "Is it snowy or rainy outside?\n";
            cout << "A) Nah\n";
            cout << "B) Kinda\n";
            cin >> weather;

            // User chooses option A
            if (weather == 'a' || weather == 'A')
            {
                // Asking user the fourth question
                cout << "Do you actually feel like going?\n";
                cout << "A) Sure\n";
                cout << "B) Nope\n";
                cin >> opinion;

                // User chooses option A
                if (opinion == 'a' || opinion == 'A')
                    cout << "Get a move on!\n";
                // User chooses option B
                else if (opinion == 'b' || opinion == 'B')
                    cout << "Call in sick!\n";
                else // Invalid input by the user
                    cout << "You have not entered a valid choice. Please run the program again.\n";
            }
            // User chooses option B 
            else if (weather == 'b' || weather == 'B')
                cout << "Call in sick!\n";
            else // Invalid input by the user
                cout << "You have not entered a valid choice. Please run the program again.\n";

        }
        // User chooses option B 
        else if (waterPress == 'b' || waterPress == 'B')
            cout << "Call in sick!\n";
        else // Invalid input by the user
            cout << "You have not entered a valid choice. Please run the program again.\n";
    }
    // User chooses option N
    else if (wakeUp == 'n' || wakeUp == 'N')
        cout << "Call in sick!\n";
    else // Invalid input by the user
        cout << "You have not entered a valid choice. Please run the program again.\n";

    return 0;
}