#include <iostream>
#include <vector>
using namespace std;
// simple factorial-free way: build each row from the previous row
vector<vector<int>> pascalsTriangle(int n) {
    vector<vector<int>> triangle;
    for (int row = 0; row < n; row++) {
        vector<int> currentRow;
        for (int col = 0; col <= row; col++) {
            if (col == 0 || col == row) {
                currentRow.push_back(1); // first and last of every row is 1
            } else {
                // each middle value = sum of two values above it
                int above = triangle[row - 1][col - 1] + triangle[row - 1][col];
                currentRow.push_back(above);}}
        triangle.push_back(currentRow);}
    return triangle;}
void printTriangle(vector<vector<int>> triangle) {
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;}}
int main() {
    cout << "n = 0:" << endl;
    printTriangle(pascalsTriangle(0)); // nothing
    cout << "---" << endl;
    cout << "n = 1:" << endl;
    printTriangle(pascalsTriangle(1)); // just "1"
    cout << "---" << endl;
    cout << "n = 5:" << endl;
    vector<vector<int>> t = pascalsTriangle(5);
    printTriangle(t);
    cout << "---" << endl;
    // check row 5 (index 4) is {1, 4, 6, 4, 1}
    cout << "Row 5: ";
    for (int i = 0; i < t[4].size(); i++) {
        cout << t[4][i] << " ";}
    cout << endl;
    return 0;}