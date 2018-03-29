/*
Given an array of integers, find and print the maximum number of integers you can select from the array such that the absolute difference 
between any two of the chosen integers is <=1.
2 <= n <= 100 ,where n denoting size of the array a.
0 < ai < 100.
*/
#include <bits/stdc++.h>

using namespace std;

int pickingNumbers(vector <int> a , int n) {
    int ar[100];
    for(int i = 0 ; i < 100 ; i++) {
        ar[i] = 0;
    }
    for(int i = 0 ; i < n ; i++) {
        ar[a[i]]++;
    }
    int max_sum = 0 , sum;
    for(int i = 1 ; i < 100 ; i++) {
        sum = ar[i-1] + ar[i];
        if(sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = pickingNumbers(a , n);
    cout << result << endl;
    return 0;
}
