/*
Rish is helping his crush Sunshine to study for the coming exams. This is his golden chance to impress her. She need 
to cover atleast M topics .She also needs to practice for the intra-college events so she cannot study more than Ai 
topics on ith day.
Rish studies K topics everyday,he agrees to explain the same to sunshine. Also, Rish cannot disturb his schedule for 
her. i.e He will not teach her the topics which she misses due to her practice. But as Rish likes her,he asks for your
help to choose a minimum number K such that she is able to cover atleast M topics if she comes to him for N days.
See the 1st test case for more details.

Input Format :
2 integers N and M , the number of days and the number of topics needed to cover over the n days
2nd line contains N integers, Ai the number of topics she can study on the ith day

Constraints :
1 <= N <= 1e5
0 <= Ai <= 1e9
1 <= M <= Sum of all Ai

Output Format :
A single integer K, the minimum number of topics Rish should Cover
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n , m;
    cin >> n >> m;
    long long int a[n] , result , sum = 0;
    for(long long int i = 0 ; i < n ; i++) {
        cin >> a[i];
        sum += a[i];
    }
    long long int top = ceil(m*1.0/n) , t , mid;
    while(top <= sum) {
        mid = (top + sum)/2;
        t = 0;
        for(long long int i = 0 ; i < n ; i++) {
            t += min(a[i] , mid);
        }
        if(t >= m) {
            sum = mid - 1;
            result = mid;
        }
        else {
            top = mid + 1;
        }
    }
    cout << result;
    return 0;
}
