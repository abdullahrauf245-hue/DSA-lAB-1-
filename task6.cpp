#include <iostream>
#include <vector>
using namespace std;

vector<int> findMode(int arr[], int size) {
vector<int> modes;
if (size == 0) return modes;
int maxCount = 0;
for (int i = 0; i < size; i++) {
int count = 0;
for (int j = 0; j < size; j++) {
if (arr[j] == arr[i]) {
count++;
}
}
if (count > maxCount) {
maxCount = count;
}
}
for (int i = 0; i < size; i++) {
int count = 0;
for (int j = 0; j < size; j++) {
if (arr[j] == arr[i]) {
count++;
}
}
if (count == maxCount) {
bool alreadyAdded = false;
for (int k = 0; k < modes.size(); k++) {
if (modes[k] == arr[i]) {
alreadyAdded = true;
break;
}
}
if (!alreadyAdded) {
modes.push_back(arr[i]);}}}
return modes;
}
int main() {
int arr1[] = {1, 2, 2, 3, 2, 4};
vector<int> result1 = findMode(arr1, 6);
cout << "Test 1 (unique mode): ";
for (int i = 0; i < result1.size(); i++) cout << result1[i] << " ";
cout << "(expect 2)" << endl;

int arr2[] = {1, 1, 2, 2, 3};
vector<int> result2 = findMode(arr2, 5);
cout << "Test 2 (multiple modes): ";
for (int i = 0; i < result2.size(); i++) cout << result2[i] << " ";
cout << "(expect 1 and 2)" << endl;

int arr3[] = {};
vector<int> result3 = findMode(arr3, 0);
cout << "Test 3 (empty array) size: " << result3.size() << " (expect 0)" << endl;

return 0;
}