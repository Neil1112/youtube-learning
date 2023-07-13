#include <iostream>
#include <vector>
using namespace std;


// Recursive function to find sum of odd index elements of a list
int sum_odd(int index, vector<int> list) {
    // base case
    if (index >= list.size())
        return 0;

    // Recursive calls
    // case1: if current element is at odd index
    if (index % 2 != 0)
        return sum_odd(index+1, list) + list[index];
    
    // case2: if current element is at even index
    return sum_odd(index+1, list);
}


// wrapper function for sum_odd that just takes the list as input
int sum_odd_wrapper(vector<int> list) {
    return sum_odd(0, list);
}


int main() {
    vector<int> list;
    list.push_back(2);
    list.push_back(6);
    list.push_back(4);
    list.push_back(7);
    list.push_back(9);
    list.push_back(5);
    list.push_back(3);
    list.push_back(8);
    list.push_back(1);

    cout << "Sum of odd indexed elements of the list is: " << sum_odd_wrapper(list) << endl;

    return 0;
}