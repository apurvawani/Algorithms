/*
Whenever George asks Lily to hang out, she's busy doing homework. George wants to help her 
finish it faster, but he's in over his head! Can you help George understand Lily's homework 
so she can hang out with him?
Consider an array of n distinct integers, arr = [a[0], a[1],...a[n-1]] . George can swap any 
two elements of the array any number of times. An array is beautiful if the sum of 
|arr[i] - arr[i-1]|among is minimal.Given the array arr, determine and return the minimum 
number of swaps that should be performed in order to make the array beautiful.

Input Format :
The first line contains a single integer,n, the number of elements in arr. The second line 
contains n space-separated integers arr[i].

Constraints : 
1 <= n <= 10^5
1 <= arr[i] <= 2*10^9

Output Format :
Return the minimum number of swaps needed to make the array beautiful.
*/

#include <bits/stdc++.h>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

int lilysHomework(int *arr , int size) {
    int asc[size] , ar[size];
    map <int , int> m1;
    for(int i = 0 ; i < size ; i++) {
        m1[arr[i]] = i;
        asc[i] = arr[i];
        ar[i] = arr[i];
    }
    sort(asc , asc+size);
    int c1 = 0 , c2 = 0;
    for(int i = 0 ; i < size ; i++) {
        if(asc[i] != arr[i]) {
            //cout << arr[i] <<  " " << asc[i] << endl;
            c1++;
            m1[arr[i]] = m1[asc[i]];
            //cout << "index = " << m1[asc[i]] << endl;
            swap(arr[i] , arr[m1[asc[i]]]);
        }
    }
    //cout << "c1 = " << c1 << endl;
    m1.clear();
    std::reverse(ar , ar+size);
    for(int i = 0 ; i < size ; i++) {
        m1[ar[i]] = i;
    }
    for(int i = 0 ; i < size ; i++) {
        if(asc[i] != ar[i]) {
            //cout << ar[i] <<  " " << asc[i] << endl;
            c2++;
            m1[ar[i]] = m1[asc[i]];
            //cout << "index = " << m1[asc[i]] << endl;
            swap(ar[i] , ar[m1[asc[i]]]);
        }
    }
    //cout << "c2 = " << c2 << endl;
    return c1 < c2 ? c1 : c2;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    cout << lilysHomework(a , n);
    return 0;
}