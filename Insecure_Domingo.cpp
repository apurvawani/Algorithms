/*
S1MPLE wants to go with any two among N numbers of girls which makes maximum product.
'N' number of girls are standing in a row. Their heights are given.
Calculate the maximum value of a Product, if it is defined by 
Product = max(heights of any 2 girls) * (distance between them)

Note : distance between any two girls is the absolute difference of their Indices.

Input Format :
The first line of the input contains one integer N — the number of girls standing in a row.
Next line contain integer hi , where hi is height of ith girl

Constraints :
2 <= N <= 10 ^ 5
1 <= hi <= 10 ^ 9

Output Format :
maximum product

Sample Input 0
6
2 5 6 5 2 1 

Sample Output 0
20
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int h[n];
    for(long long int i = 0 ; i < n ; i++) {
        cin >> h[i];
    }
    long long int t = 0 , max_product = 0;
    for(long long int i = 0 ; i < n-1 ; i++) {
        t = (h[i] > h[n-1] ? h[i] : h[n-1]) * (i > n-1-i ? i : n-1-i);
        if(max_product < t) {
            max_product = t;
        }
    }
    cout << max_product;
    return 0;
}
