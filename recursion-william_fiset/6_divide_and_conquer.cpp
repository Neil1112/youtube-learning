#include <iostream>
#include <vector>
using namespace std;


// Struct for the result
struct Result {
    size_t index;
    int value;

    // constructor
    Result(size_t index, int value) :
        index(index),
        value(value) {}
};


// Recursive function that finds the max of the list using divide and conquer
// Strategy - divide the list in 2 parts. and compare the max of the parts
Result findMax(size_t start_index, size_t end_index, const vector<int>& list) {
    // base case
    // only 1 element - already the max element in the list
    if (start_index == end_index)
        return Result(start_index, list[start_index]);


    // recursive step
    size_t mid = (start_index + end_index) / 2;
    Result subarray_1 = findMax(start_index, mid, list);
    Result subarray_2 = findMax(mid+1, end_index, list);

    if (subarray_1.value > subarray_2.value)
        return subarray_1;
    return subarray_2;   
}


int main() {
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8};

    Result result = findMax(0, list.size()-1, list);
    cout << "Max value: " << result.value << " at index: " << result.index << endl;

    return 0;
}