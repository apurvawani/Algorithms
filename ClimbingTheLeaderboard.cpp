/*
Alice is playing an arcade game and wants to climb to the top of the leaderboard. Can you help her track her ranking 
as she plays? The game uses Dense Ranking, so its leaderboard works like this:
1.The player with the highest score is ranked number 1 on the leaderboard.
2.Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately 
following ranking number.
We want to determine Alice's rank as she progresses up the leaderboard. For example, the four players on the 
leaderboard have high scores of , , , and . Those players will have ranks 100, 90, 90, and 80, respectively. If 
Alice's scores are 70, 80 and 105, her rankings after each game are 4, 3 and 1.
You are given an array, scores, of monotonically decreasing leaderboard scores, and another array, alice, of Alice's 
scores for the game. You must print m integers. The integer at 'j'th position should indicate the current rank of 
alice after her 'j'th game.
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int n = scores.size();
    int m = alice.size();
    vector<int> ar;
    for (int i = 1 ; i < n ; i++) {
        if(scores[i-1]!=scores[i]) {
            ar.push_back(scores[i-1]);        
        }
    }
    ar.push_back(scores[n-1]);
    vector<int> result;
    int i = ar.size() - 1;
    for(int j = 0 ; j < m ; j++) {
        //cout << j;
        while(i >= 0) {
            if(alice[j] >= ar[i]) {
                i--;
                //cout << i;
            }
            else {
                result.push_back(i+2);
                break;
            }
        }
        if(i < 0) {
            result.push_back(1);
        }
    }
    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int scores_itr = 0; scores_itr < scores_count; scores_itr++) {
        int scores_item = stoi(scores_temp[scores_itr]);

        scores[scores_itr] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int alice_itr = 0; alice_itr < alice_count; alice_itr++) {
        int alice_item = stoi(alice_temp[alice_itr]);

        alice[alice_itr] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
