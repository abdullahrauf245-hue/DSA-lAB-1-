#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(int arr[], int size, int key) {
    vector<int> result;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    // Test 1: multiple occurrences
    int arr1[] = {1, 2, 3, 2, 4, 2, 5};
    int size1 = 7;
    vector<int> result1 = findAllIndices(arr1, size1, 2);

    cout << "Test 1 - indices of 2: ";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl; // expect 1 3 5

    // Test 2: key not present
    int arr2[] = {1, 2, 3, 4};
    int size2 = 4;
    vector<int> result2 = findAllIndices(arr2, size2, 99);

    cout << "Test 2 - indices of 99: ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << "(should be empty)" << endl;

    // Test 3: empty array
    int arr3[] = {};
    int size3 = 0;
    vector<int> result3 = findAllIndices(arr3, size3, 5);

    cout << "Test 3 - empty array size: " << result3.size() << " (should be 0)" << endl;

    return 0;
}