#include <iostream>
#include <string>
using namespace std;

int naiveSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return -1; // empty pattern case

    // try matching pattern starting at every position in text
    for (int i = 0; i <= n - m; i++) {
        bool found = true;

        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            return i; // pattern matched starting at index i
        }
    }

    return -1; // no match found anywhere
}

int main() {
    cout << "Test 1 (pattern at start): " << naiveSearch("hello world", "hello") << endl; // 0
    cout << "Test 2 (pattern at end): " << naiveSearch("hello world", "world") << endl;   // 6
    cout << "Test 3 (pattern not present): " << naiveSearch("hello world", "xyz") << endl; // -1
    cout << "Test 4 (empty pattern): " << naiveSearch("hello world", "") << endl; // -1

    return 0;
}