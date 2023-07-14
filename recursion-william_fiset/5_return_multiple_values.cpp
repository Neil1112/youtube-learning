#include <iostream>
#include <vector>
using namespace std;


// struct for returning values
struct Result {
    int max_value;
    int max_index;

    // constuctor
    Result(int max_value, int max_index) : max_value(max_value), max_index(max_index) {}
};


// Recursive function that returns multiple values
// Recursive fuction to find the max value and the index of that value
Result findMax(int index, vector<int> list) {
    // base case
    // case1: index is out of bounds
    if (index > list.size() || list.size() <= 0)
        return Result(-1, -1);

    // case2: index is at the last element
    if (index == list.size() - 1)
        return Result(list[index], index);

    // recursive step
    Result result = findMax(index+1, list);

    if (list[index] >= result.max_value)
        result = Result(list[index], index);
    
    return result;   
}


// wrapper function for findMax
Result findMax(vector<int> list) {
    return findMax(0, list);
}


int main() {
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Result result = findMax(list);
    cout << "Max value: " << result.max_value << endl;
    cout << "Max index: " << result.max_index << endl;

    return 0;
}