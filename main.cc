/*
The program allows the user to enter a positive decimal number that will be
converted into a fraction and an egyptian fraction using an implementation
of the greedy algorithm.
*/

//Mattia Ballabio, 10/14/2024

#include <iostream>
#include <cmath>

using namespace std;

void approximate(double x, int &num, int &den) {

    int
        nlow = 0,
        dlow = 1,
        nhigh = 1,
        dhigh = 0;

    while (true) {

        num = nlow + nhigh;
        den = dlow + dhigh;

        if ((den > 1000000000) || (fabs(x - static_cast<double>(num)/static_cast<double>(den)) <= 1e-8)) {
            break;
        }

        if (x < static_cast<double>(num)/static_cast<double>(den)) {
            nhigh = num;
            dhigh = den;
        }

        else {
            nlow = num;
            dlow = den;
        }
    }
}

void egyptian(int num, int den) {

    int
        m = num / den,
        q = den,
        p = num - m * q;

    cout << m;

    while (p != 0) {

        int n = (q + p - 1) / p;

        cout << " + 1/" << n;

        p = n * p - q;
        q = q * n;
    }
}

int main(int argc, char *argv[]) {

    int num, den;

    //Making sure argc is 2
    if (argc != 2) {
        cout << "Try again with just one decimal number." << endl;
        return 1;
    }

    //Convert argv[1] to numeric form
    double x = strtod(argv[1], nullptr);

    //Making sure the input is a positive number
    if (x <= 0) {
        cout << "Please try again with a positive number." << endl;
        return 1;
    }

    //Call approx. function
    approximate(x, num, den);

    cout << x << " = " << num << "/" << den << " = ";

    //Call egyptian function
    egyptian(num, den);

    return 0;
}