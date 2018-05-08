/*
When you select a contiguous block of text in a PDF viewer, the selection is highlighted with a blue rectangle. In 
this PDF viewer, each word is highlighted independently.
In this challenge, you will be given a list of letter heights in the alphabet and a string. Using the letter heights 
given, determine the area of the rectangle highlight in sq. mm assuming all letters are 1 mm wide.
*/


#include <bits/stdc++.h>

using namespace std;

int designerPdfViewer(vector <int> h, string word) {
    int n = word.length();
    int wordHeight[n];
    for(int i = 0 ; i < n ; i++) {
        int c = (int)word[i];
        c = c - 97;
        wordHeight[i] = h[c];
    }
    int max = 0;
    for(int i = 0 ; i< n ; i++) {
        if(wordHeight[i] > max) {
            max = wordHeight[i];
        }
    }
    int result = n*1*max;
    return result;
    // Complete this function
}

int main() {
    vector<int> h(26);
    for(int h_i = 0; h_i < 26; h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    int result = designerPdfViewer(h, word);
    cout << result << endl;
    return 0;
}
