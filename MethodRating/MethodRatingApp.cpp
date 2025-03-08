#include <iostream>
#include <iomanip>
#include "MethodRating.h"


/* Name: Julissa Su Qiu
Date: 11/26/2022
Section: 0013
Assignment: Coffee Customer Rating Using a Class Program 
Due Date: 11/27/2022
About this project: This project is about creating a minimal class and
creating three instances of this class in the main function. Then it will
display 3 favorite methods via those instances.
Assumptions: 
* Need an accessor and mutator for each member function
* Need a Display function
All work below was performed by Julissa Su Qiu */

using namespace std;
//function prototype
void DisplayMethod(MethodRating method);

int main()
{
    //Create instances for three methods
    MethodRating method1;
    method1.setMethod("Dine in");
    method1.setRating1(0);
    method1.setRating2(1);
    method1.setRating3(17);
    method1.setRating4(16);
    method1.setRating5(10);
    method1.computeAvgRatingGT4();
    DisplayMethod(method1);


    MethodRating method2;
    method2.setMethod("Drive-thru");
    method2.setRating1(0);
    method2.setRating2(1);
    method2.setRating3(9);
    method2.setRating4(9);
    method2.setRating5(1);
    method2.computeAvgRatingGT4();
    DisplayMethod(method2);

    MethodRating method3;
    method3.setMethod("Take away");
    method3.setRating1(0);
    method3.setRating2(2);
    method3.setRating3(9);
    method3.setRating4(25);
    method3.setRating5(12);
    method3.computeAvgRatingGT4();
    DisplayMethod(method3);

    return 0;
}

//function definition of DisplayMethod
void DisplayMethod(MethodRating method)
{
    cout << setw(22) << "Method:" << setw(10) << method.getMethod() << endl;
    cout << "Num Serve Ratings Eq1:" << setw(10) << method.getRating1() << endl;
    cout << "Num Serve Ratings Eq2:" << setw(10) << method.getRating2() << endl;
    cout << "Num Serve Ratings Eq3:" << setw(10) << method.getRating3() << endl;
    cout << "Num Serve Ratings Eq4:" << setw(10) << method.getRating4() << endl;
    cout << "Num Serve Ratings Eq5:" << setw(10) << method.getRating5() << endl;
    cout << setw(22) << "Per Rating >= 4:" << setw(10) << method.computeAvgRatingGT4() << endl;
}
