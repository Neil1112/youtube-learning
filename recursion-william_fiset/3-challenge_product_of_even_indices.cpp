#include <iostream>
#include <vector>
using namespace std;


// Recursive function to find product of even indices of the array
int product_even(int index, vector<int> list) {
    // base cases
    // case1: if list is empty
    if (list.size() == 0)
        return 0;
    
    // case2: if list is not empty
    if (index >= list.size())
        return 1;


    // Recursive calls
    // case1: if even index
    if (index % 2 == 0)
        return product_even(index+1, list) * list[index];

    // case2: if odd index
    return product_even(index+1, list);
}


// wrapper function for product_even that just takes the list as input
int product_even_wrapper(vector<int> list) {
    return product_even(0, list);
}


int main() {
    vector<int> list;
    list.push_back(2);
    list.push_back(6);
    list.push_back(4);
    list.push_back(7);
    list.push_back(9);
    list.push_back(5);
    list.push_back(-3);
    list.push_back(8);
    list.push_back(1);

    cout << "Product of even indexed elements of the list is: " << product_even_wrapper(list) << endl;

    return 0;
}