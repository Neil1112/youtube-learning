#include <iostream>
#include <string>
using namespace std;


// Recursive function to check for palindromes outside in
// e.g. - dragon -
// 1. d_rago_n - False - d != n

// e.g. - rotator -
// 1. r_otato_r - True - r == r
// 2. ro_tat_or - True - o == o
// 3. rot_a_tor - True - t == t
bool palindrome(string word) {
    // base case
    // case1: string is empty
    if (word.length() < 1)
        return false;

    // case2: unit length string
    if (word.length() ==1 )
        return true;

    // recursive step
    // compare first and last element and then check for the substring excluding them
    // case1: if first and last elementa are equal
    if (word[0] == word[word.length()-1])
        return palindrome(word.substr(1, word.length()-2));

    // case2: if first and last element are not equal
    return false;
}


int main() {
    string word = "hello";

    if (palindrome(word))
        cout << "String - " << word << " is a palindrome" << endl;
    else
        cout << "String - " << word << " is not a palindrome" << endl;

    return 0;
}