/*


Consider a 3x3 matrix, s, of integers in the inclusive range [1,9].
We can convert any digit, a, to any other digit, b, in the range [1,9] at 
cost |a-b|. 
Given s, convert it into a magic square at minimal cost by changing zero or more of its digits. 
Then print this cost on a new line.


*/
#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(vector < vector<int> > s) {
    int magic_matrix[8][3][3] = {
        {{4,9,2}, {3,5,7}, {8,1,6}},
        {{2,9,4}, {7,5,3}, {6,1,8}},
        {{8,1,6}, {3,5,7}, {4,9,2}},
        {{4,3,8}, {9,5,1}, {2,7,6}},
        {{2,7,6}, {9,5,1}, {4,3,8}},
        {{8,3,4}, {1,5,9}, {6,7,2}},
        {{6,1,8}, {7,5,3}, {2,9,4}},
        {{6,7,2}, {1,5,9}, {8,3,4}},
    };
    int min_cost = 72;
    for(int k = 0 ; k < 8 ; k++) {
        int sum = 0;
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                sum += abs( s[i][j] - magic_matrix[k][i][j] );
            }
        }
        if(sum < min_cost) {
            min_cost = sum;
        }
    }
    return min_cost;
    // Complete this function
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }
    int result = formingMagicSquare(s);
    cout << result << endl;
    return 0;
}
