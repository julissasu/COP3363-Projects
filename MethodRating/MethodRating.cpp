#include "MethodRating.h"
using namespace std;

//Constructor #1 (default constructor)
MethodRating :: MethodRating()
        {
            //method is blank
            Method = "";
            NumSerRateEq1 = 0;
            NumSerRateEq2 = 0;
            NumSerRateEq3 = 0;
            NumSerRateEq4 = 0;
            NumSerRateEq5 = 0;
        }
//Constructor #2
MethodRating :: MethodRating(string m)
        {
            //Assign the value to method
            Method = m;
            //Initialize each rating
            NumSerRateEq1 = 0;
            NumSerRateEq2 = 0;
            NumSerRateEq3 = 0;
            NumSerRateEq4 = 0;
            NumSerRateEq5 = 0;
        }

//mutators
void MethodRating :: setMethod(string m)
{
    Method = m;
}
void MethodRating :: setRating1(int r)
{
    NumSerRateEq1 = r;
}
void MethodRating :: setRating2(int r)
{
    NumSerRateEq2 = r;
}
void MethodRating :: setRating3(int r)
{
    NumSerRateEq3 = r;
}
void MethodRating :: setRating4(int r)
{
    NumSerRateEq4 = r;
}
void MethodRating :: setRating5(int r)
{
    NumSerRateEq5 = r;
}

//accessors
string MethodRating :: getMethod() const
{
    return Method;
}
int MethodRating :: getRating1() const
 {
    return NumSerRateEq1;
 }
int MethodRating :: getRating2() const
{
    return NumSerRateEq2;
}
int MethodRating :: getRating3() const
{
    return NumSerRateEq3;
}
int MethodRating :: getRating4() const
{
    return NumSerRateEq4;
}
int MethodRating :: getRating5() const
{
    return NumSerRateEq5;
}


//function to compute the percentage
double MethodRating :: computeAvgRatingGT4()
{
    //add the amount of each rating
    double total = NumSerRateEq1 + NumSerRateEq2 + NumSerRateEq3 +
                  NumSerRateEq4 + NumSerRateEq5;
    //compute the percentage of ratings >= 4
    double per = ((NumSerRateEq4 + NumSerRateEq5) / total) * 100;
    return per;
}

