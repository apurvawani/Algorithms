/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Input Format:
The first line contains n, the number of buildings.
The second line contains n space-separated integers, each representing the height of a building.

Output Format:
Print a long integer representing the maximum area of rectangle formed.

Example 1:
Input: 6
       2 1 5 6 2 3
Output: 10

Example 2:
Input: 5
       1 2 3 4 5
Output: 9
*/

#include<bits/stdc++.h>
using namespace std;

long largestRectangle(vector<int> h) {
    long result = 0 , area = 0;
    stack<int> s;
    int n = h.size() , top , i = 0;
    while(i < n) {
        if(s.empty() || h[i] >= h[s.top()]) {
            s.push(i);
            i++;
        }   
        else {
            while(!s.empty() && h[i] < h[s.top()]) {
                top = s.top();
                s.pop();
                if(s.empty())
                    area = h[top]*i;
                else
                    area = h[top]*(i-s.top()-1);

                if(area > result)
                    result = area;    
            }
        }
    }

    if(!s.empty() && i == n) {
        while(!s.empty()) {
            top = s.top();
            s.pop();
            if(s.empty())
                area = h[top]*i;
            else  
                area = h[top]*(i - s.top() - 1);
            if(result < area)
                result = area;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0 ; i < n ; i++)
        cin >> h[i];
    cout << largestRectangle(h) << endl;
    return 0;
}
