#ifndef METHODRATING_H
#define METHODRATING_H
#include <string> 

using namespace std;

class MethodRating
{
    private:
        //member variables
        string Method;
        int NumSerRateEq1;
        int NumSerRateEq2;
        int NumSerRateEq3;
        int NumSerRateEq4;
        int NumSerRateEq5;
    public:
        //Constructor #1 (default constructor)
        MethodRating();
        //Constructor #2
        MethodRating(string m);
       
        //Mutator functions
        void setMethod(string m);
        void setRating1(int r);
        void setRating2(int r);
        void setRating3(int r);
        void setRating4(int r);
        void setRating5(int r);

        //Accessor functions
        string getMethod() const;
        int getRating1() const;
        int getRating2() const;
        int getRating3() const;
        int getRating4() const;
        int getRating5() const;

        //function to calculate the avg percentage
        double computeAvgRatingGT4();

};
#endif