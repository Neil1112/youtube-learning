#include <iostream>
#include <vector>
using namespace std;


// struct for returning values
struct Result {
    int max_value;
    size_t max_row_index;
    size_t max_col_index;

    // constuctor
    Result(int max_value, size_t max_row_index, size_t max_col_index) :
        max_value(max_value), 
        max_row_index(max_row_index),
        max_col_index(max_col_index)
        {}
};


// Recursive function that returns indices of max value in the matrix
Result findMax(int row, int col, const vector<vector<int>>& matrix) {
    // base cases
    // case1: if index out of bounds
    if (row >= matrix.size() || row < 0 || col >= matrix[row].size() || col < 0 || matrix.size() <= 0) {
        return Result(-1, -1, -1);
    }

    // case2: last element - if row == matrix.size()-1 and col == matrix[rox].size()-1
    if (row == matrix.size()-1 && col == matrix[row].size()-1) {
        return Result(matrix[row][col], row, col);
    }


    // Recursive step
    // case1: there are still elements in current row
    Result result(-1, -1, -1);
    if (col < matrix[row].size() - 1) {
        result = findMax(row, col+1, matrix);
        if (matrix[row][col] >= result.max_value) {
            result.max_value = matrix[row][col];
            result.max_row_index = row;
            result.max_col_index = col;
        }
        return result;
    }

    // case2: there are still rows in the matrix
    result = findMax(row+1, 0, matrix);
    if (matrix[row][col] >= result.max_value) {
        result.max_value = matrix[row][col];
        result.max_row_index = row;
        result.max_col_index = col;
    }
    return result;
}


// wrapper function for findMax
Result findMax(const vector<vector<int>>& matrix) {
    return findMax(0, 0, matrix);
}


// print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0},
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0},
        {1, 2, 3, 4, 5}
    };

    printMatrix(matrix);

    Result result = findMax(0, 0, matrix);
    cout << "Max value: " << result.max_value << endl;
    cout << "Max row index: " << result.max_row_index << endl;
    cout << "Max col index: " << result.max_col_index << endl;

    return 0;
}