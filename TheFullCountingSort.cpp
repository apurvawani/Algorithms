/*
In this challenge you need to print the string that accompanies each integer in a list 
sorted by the integers. If two strings are associated with the same integer, they must be 
printed in their original order so your sorting algorithm should be stable. There is one 
other twist. The first half of the strings encountered in the inputs are to be replaced with
the character "-"(dash).
Insertion Sort and the simple version of Quicksort are stable, but the faster in-place 
version of Quicksort is not since it scrambles around elements while sorting.
In this challenge, you will use counting sort to sort a list while keeping the order of the 
strings preserved.

Input Format :
The first line contains n, the number of integer/string pairs in the array arr.
Each of the next n contains x[i] and s[i], the integers (as strings) with their associated 
strings.

Constraints :
1 <= n <= 1000000
n is even
1 <= |s| <= 10
0 <= x < 100
s[i] consists of characters in the range ascii[a-z] 

Output Format :
Print the strings in their correct order, space-separated on one line. 
*/

#include <bits/stdc++.h>
using namespace std;

/*void countSort(vector<vector<string>> arr) {

}*/

int main()
{
    long int n;
    cin >> n;
    string arr[n];
    for(long int i = 0 ; i < n/2 ; i++) {
        int key;
        cin >> key;
        string s;
        cin >> s;
        arr[key] = arr[key] + "-" + " ";
    }
    for(long int i = n/2 ; i < n ; i++) {
        int key;
        cin >> key;
        string s;
        cin >> s;
        arr[key] = arr[key] + s + " ";
    }
    for(long int i = 0 ; i < n ; i++) {
        cout << arr[i];
    }
    return 0;
}