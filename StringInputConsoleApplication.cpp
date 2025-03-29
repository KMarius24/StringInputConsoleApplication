//============================================================================================
// Name        : StringInputConsoleApplication.cpp
// Author      : Marius Karaliunas
// Description : Concatenate the two strings and then print the resulting output (three times)
//============================================================================================

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Checks if individual strings are within length limits
bool isSafe(const char* s1, const char* s2, size_t& len1, size_t& len2) {
    len1 = strlen(s1);  // Calculates length of first string
    len2 = strlen(s2);  // Calculates length of second string

    if (len1 >= 10) return false;  // Check if first string exceeds 9 chars (plus null)
    if (len2 >= 10) return false;  // Check if second string exceeds 9 chars (plus null)
    return true;
}

int main() {
    // Declare character arrays with fixed sizes and temporary strings
    char str1[10], str2[10], result[20]; // str1, str2: max 9 chars each; result: max 19 chars
    string temp1, temp2;                 // Temporary strings to capture full input
    size_t len1, len2;                   // Variables to store string lengths

    // Loop three times to get user input
    for(int i = 1; i <= 3; i++) {
        // Clears arrays before use to prevent leftover data
        memset(str1, 0, sizeof(str1));   // Fill str1 with null characters
        memset(str2, 0, sizeof(str2));   // Fill str2 with null characters

        // Displays prompt for current test number
        cout << "\nTest # " << i << ": ";

        // Get first string from user
        cout << "\nPlease enter first string: ";
        getline(cin, temp1);

        // Get second string from user
        cout << "Please enter second string: ";
        getline(cin, temp2);

        // Calculate lengths
        len1 = temp1.length();
        len2 = temp2.length();

        if(isSafe(temp1.c_str(), temp2.c_str(), len1, len2)) {
            strcpy(str1, temp1.c_str()); // Copy to fixed array only if safe
            strcpy(result, str1);        // Copy first string to result
            strcat(result, temp2.c_str()); // Append second string to result
            cout << "Result: " << result << " (String length: " << strlen(result) << ")" << endl; // Prints result
        } else {
            // Displays specific error messages based on which string was too long
            if (len1 >= 10)
                cout << "Error: First string too long (" << len1 << " characters)" << endl;
            else
                cout << "Error: Second string too long (" << len2 << " characters)" << endl;
        }
    }
    return 0;
}
