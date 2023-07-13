#include <iostream>
using namespace std;


// Recursive function to find the sum of first n numbers
int sum(int n) {
    // base case
    if (n <= 0) {
        return 0;
    }

    // recursive call
    return sum(n-1) + n;
}


int main () {
    int num = 10;
    cout << "Sum of first " << num << " numbers is: " << sum(num) << endl;

    return 0;
}