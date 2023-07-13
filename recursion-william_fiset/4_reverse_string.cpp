#include <iostream>
#include <string>
using namespace std;


// Reverse function 1: reverse by using a for loop
string reverse1(string word) {
    string reverse_word = "";
    for (int i = word.length(); i >= 0; i--) {
        reverse_word += word[i];
    }
    return reverse_word;
}


// Reverse function 2: reverse by using a recursive function
string reverse2(int index, string word) {
    // base case
    if (index < 0)
        return "";

    // recursive call
    return word[index] + reverse2(index-1, word);
}


// Reverse function 3 : outside_in recursive function - more efficient
// dragon - 
// 1. n_rago_d
// 2. no_ag_rd
// 3. nogard
string reverse3(int start_index, int end_index, string word) {
    // check if index is out of bound
    if (start_index < 0 || end_index >= word.length())
        return "";

    // base case
    if (start_index > end_index) {
        return word;
    }

    // recursive call
    char a = word[start_index];
    char b = word[end_index];

    word[start_index] = b;
    word[end_index] = a;
    return reverse3(start_index+1, end_index-1, word);
}


// Function to detect palindrome
bool palindrome(string word) {
    if (word == reverse3(0, word.length()-1, word))
        return true;
    
    return false;
}


int main() {
    string word = "hello";

    cout << "Reverse of string - " << word << " is: " << reverse1(word) << endl;
    cout << "Reverse of string - " << word << " is: " << reverse2(word.length(), word) << endl;
    cout << "Reverse of string - " << word << " is: " << reverse3(0, word.length()-1, word) << endl;

    if (palindrome(word))
        cout << "String - " << word << " is a palindrome" << endl;
    else
        cout << "String - " << word << " is not a palindrome" << endl;

    return 0;
}