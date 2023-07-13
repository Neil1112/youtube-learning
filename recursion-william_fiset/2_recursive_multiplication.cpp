#include <iostream>
using namespace std;


// Recursive function to calculate the product of 2 integers
int mul(int a, int b) {
    // base case
    if (a == 0) {
        return 0;
    }

    // recursive call
    // case 1: a > 0
    if (a > 0)
    return mul(a-1, b) + b;

    // case 2: a < 0
    return mul(a+1, b) - b;
}


int main() {
    int a = 5;
    int b = 10;

    cout << "Multiplication of " << a << " and " << b << " is: " << mul(a, b) << endl;

    a = a * -1;
    cout << "Multiplication of " << a << " and " << b << " is: " << mul(a, b) << endl;

    a = a * -1;
    b = b * -1;
    cout << "Multiplication of " << a << " and " << b << " is: " << mul(a, b) << endl;

    a = a * -1;
    cout << "Multiplication of " << a << " and " << b << " is: " << mul(a, b) << endl;

    return 0;
}