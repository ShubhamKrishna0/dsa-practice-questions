//https://codeforces.com/contest/2008/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to solve each test case
void solve() {
    int strLength;  // Length of the string
    cin >> strLength;
    string inputString;  // The input string of lowercase Latin letters
    cin >> inputString;

    // 2D array `frequencyCount` to store the frequency of characters at even and odd positions
    // frequencyCount[0] -> frequency of characters at even positions
    // frequencyCount[1] -> frequency of characters at odd positions
    int frequencyCount[2][26] = {};  // Initialize to 0 for both even and odd positions

    // Traverse the string and count the frequency of each character at even and odd indices
    for (int index = 0; index < strLength; index++) {
        frequencyCount[index % 2][inputString[index] - 'a']++;
          // Increase frequency for even or odd based on index
          /*
          The second part of the statement, inputString[index] - 'a', 
          converts the character at position index into a number between 0
           and 25. This works because the ASCII value of 'a' is subtracted 
           from the current character, giving a value between:

 0 for 'a'
 1 for 'b'
 ...
 25 for 'z'
  This maps each character to an index in the frequency array.*/
    }

    // Initialize the result to the length of the string, assuming worst-case scenario where all characters need to be changed.
    int minOperationsRequired = strLength;

    // Handle the case where the length of the string is even
    if (strLength % 2 == 0) {
        // For even-length strings, we find the max frequency of characters at even and odd positions.
        // The minimum operations required will be to transform other characters to match the most frequent ones.
        int maxEvenFreq = *max_element(frequencyCount[0], frequencyCount[0] + 26);  // Max frequency at even positions
        int maxOddFreq = *max_element(frequencyCount[1], frequencyCount[1] + 26);   // Max frequency at odd positions
        minOperationsRequired = strLength - maxEvenFreq - maxOddFreq;  // Total length minus the characters already in place
    }

    // Handle the case where the length of the string is odd
    // We can perform one deletion and check for the minimal transformation required
    for (int index = 0; index < strLength; index++) {
        // Decrease the frequency of the current character since we're considering it "removed"
        frequencyCount[index % 2][inputString[index] - 'a']--;

        // If the string has an odd length, check for the minimum operations after deletion
        if (strLength % 2 == 1) {
            int maxEvenFreq = *max_element(frequencyCount[0], frequencyCount[0] + 26);  // Max frequency at even positions
            int maxOddFreq = *max_element(frequencyCount[1], frequencyCount[1] + 26);   // Max frequency at odd positions
            minOperationsRequired = min(minOperationsRequired, strLength - maxEvenFreq - maxOddFreq);  // Minimize operations
        }

        // Restore the frequency count for the next iteration, as the deletion isn't permanent
        frequencyCount[(index + 1) % 2][inputString[index] - 'a']++;
    }

    // Output the minimum number of operations required to make the string alternating
    cout << minOperationsRequired << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);  // Optimize input/output operations
    cin.tie(0);                    // Tie cin to cout for faster output
    cout.tie(0);

    int testCases;
    cin >> testCases;  // Read the number of test cases

    // Loop through all the test cases and solve each one
    while (testCases--) {
        solve();
    }

    return 0;
}

/*
To solve this problem, we need to transform a string into an "alternating string" as defined in the problem:

The characters at even indices must be the same.
The characters at odd indices must be the same.
The length of the string must be even.
Approach:
1. Handling Single-Character Strings:
If the string has only one character (n=1), it's impossible to have an alternating string of even length. Therefore, we need to delete the character, and the answer for such cases is 1 operation.

2. Check for Even-Length Strings:
If the string's length is already even, then the goal is to check whether the characters at even and odd positions match their respective patterns.

Create two sets of characters:
One set for characters at even indices (s[0], s[2], s[4], ...)
One set for characters at odd indices (s[1], s[3], s[5], ...)
Operations for Even Length:

If there are multiple distinct characters in the even or odd positions, we will have to make replacements to make all characters in those positions the same.
Count the number of positions that don’t match the alternating pattern, and these mismatches are the number of replacements required.
3. Handling Odd-Length Strings:
If the string's length is odd, it's impossible to make the string alternating while maintaining the same length. We can either:
Delete one character to make the length even.
Follow the same process as for even-length strings to check the remaining part after the deletion.
Thus, in case of odd-length strings, the optimal approach is:

Either delete one character (typically the last one).
After that, proceed to check the remaining even-length string as described for the even case.
Steps to Implement:
Loop over the number of test cases.
For each test case:
If the string has length 1, the answer is 1 (since deleting the character is the only solution).
If the string has an odd length:
Consider deleting a character to make the length even.
For even-length strings:
Count how many characters need to be replaced at the even and odd indices to make all even-indexed characters the same and all odd-indexed characters the same.
Output the minimum number of operations required.

*/
