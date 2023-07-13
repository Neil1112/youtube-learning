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
string reverse3(string word) {
    // base case: if the string has length 0 or 1, it is already reversed
    if (word.length() <= 1) {
        return word;
    }

    // Recursive step: reverse the substring that excludes the first and last character
    // and swap the first and last character
    return word.back() + reverse3(word.substr(1, word.length() - 2)) + word.front();
}


// Function to detect palindrome
bool palindrome(string word) {
    if (word == reverse3(word))
        return true;
    
    return false;
}


int main() {
    string word = "hello";

    cout << "Reverse of string - " << word << " is: " << reverse1(word) << endl;
    cout << "Reverse of string - " << word << " is: " << reverse2(word.length(), word) << endl;
    cout << "Reverse of string - " << word << " is: " << reverse3(word) << endl;

    if (palindrome(word))
        cout << "String - " << word << " is a palindrome" << endl;
    else
        cout << "String - " << word << " is not a palindrome" << endl;

    return 0;
}