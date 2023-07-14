/*
    Challenge: Return Minimum value while doing 3 branches at each step
*/

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


// Recursive function that finds the min of the list using divide and conquer
// Strategy - divide the list in 3 parts. and compare the min of the parts
Result findMin(size_t start_index, size_t end_index, const vector<int>& list) {
    // base case
    if (start_index == end_index)
        return Result(start_index, list[start_index]);


    // recursive step
    size_t mid1 = start_index + (end_index - start_index) / 3;
    size_t mid2 = start_index + 2 * (end_index - start_index) / 3;

    Result subarray_1 = findMin(start_index, mid1, list);
    Result subarray_2 = findMin(mid1+1, mid2, list);
    Result subarray_3 = findMin(mid2+1, end_index, list);

    // compare the min of the 3 subarrays
    if (subarray_1.value < subarray_2.value && subarray_1.value < subarray_3.value)
        return subarray_1;
    if (subarray_2.value < subarray_1.value && subarray_2.value < subarray_3.value)
        return subarray_2;
    return subarray_3;     
}


// Wrapper function
Result findMin(const vector<int>& list) {
    return findMin(0, list.size()-1, list);
}


int main() {
    vector<int> list = {7, 2, 9, 3, 1, 6, 8, 5, 4};

    Result result = findMin(list);
    cout << "Min value: " << result.value << " at index: " << result.index << endl;

    return 0;
}