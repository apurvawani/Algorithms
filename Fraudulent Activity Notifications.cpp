/*
HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. 
If the amount spent by a client on a particular day is greater than or equal to 2*the client's median spending 
for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send
the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days d and a client's total daily expenditures for a period of n days, find and print
the number of times the client will receive a notification over all n days.

Function Description :

Complete the function activityNotifications in the editor below. It must return an integer representing the number 
of client notifications.

activityNotifications has the following parameter(s):
1. expenditure: an array of integers representing daily expenditures
2. d: an integer, the lookback days for median spending

Input Format :

The first line contains two space-separated integers n and d, the number of days of transaction data, and the number
of trailing days' data used to calculate median spending.
The second line contains n space-separated non-negative integers where each integer i denotes expenditure[i].

Constraints :
1 <= n <= 2*100000
1 <= d <= n
0 <= expenditure[i] <= 200

Output Format :

Print an integer denoting the total number of times the client receives a notification over a period of n days.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

map <int,int> freq;

int median(int d) {
    int sum = 0;
    for(auto x = freq.begin() ; x != freq.end() ; x++) {
        sum += x->second;
        if(2*sum > d)
            return 2*x->first;
        else if(2*sum == d) {
            int p = x->first;
            x++;
            return x->first + p;
        }
    }
    return -1;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    for(int i = 0 ; i < d ; i++)
        freq[expenditure[i]]++;
    int result = 0;
    for(int i = d ; i < expenditure.size() ; i++) {
        if(expenditure[i] >= median(d))
            result++;
        freq[expenditure[i-d]]--;
        freq[expenditure[i]]++;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
