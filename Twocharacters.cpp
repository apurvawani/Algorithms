/*
Given a string s, convert it to the longest possible string t made up only of altrenating characters. Print the length of string t on a new 
line. If no string t can be formed, print 0 instead.
To get string t, you must remove characters until the string is made up of any two alternating characters. When you choose a character to 
remove, all instances of that character must be removed.
*/
#include <bits/stdc++.h>

using namespace std;

int twoCharaters(string s , int l) {
    int a[l];
    for(int i = 0 ; i < l ; i++){
        a[i] = 1;
    }
    int j;
    for(int i = 0 ; i < l ; i++){
        if(a[i]){
            for(j = i+1 ; j < l ; j++){
                if(s[i]==s[j]){
                    a[j] = 0;
                }
            }
        }
    }
    int result = 0 , count , check;
    for(int i = 0 ; i < l ; i++){
        if(a[i]){
            j = i+1;
            while(s[i]==s[j]){
                j++;
            }
            if(j==i+1){
                for(j = i+1 ; j < l ; j++){
                    if(a[j]){
                        check = 0;
                        for(int k = i+1 ; k < j ; k++){
                            if(s[i]==s[k]){
                                check = 1;
                                k = j;
                            }
                        }
                        if(check==0){
                            count = 2;
                            for(int k = j+1 ; k < l ; k++){
                                if(s[k]==s[i]){
                                    if(count%2==0){
                                        count++;
                                    }
                                    else{
                                        count = 0;
                                        k = l;
                                    }
                                }
                                if(s[k]==s[j]){
                                    if(count%2==1){
                                        count++;
                                    }
                                    else{
                                        count = 0;
                                        k = l;
                                    }
                                }
                            }
                            result = max(result , count);
                        }
                    }
                }
            }
        }
    }
    return result;
    // Complete this function
}

int main() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    int result = twoCharaters(s , l);
    cout << result << endl;
    return 0;
}
