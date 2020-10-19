//
// Created by Mohamed Hashim on 10/19/2020.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;


vector<string> splitString(string str) {
    vector<string> res;
    string word = "";
    for (auto x : str) {
        if (x == ' ') {
            res.push_back(word);
            word = "";
        } else {
            word = word + x;
        }
    }
    res.push_back(word);
    return res;
}

int maxCount(string str) {
    int mx = 0;
    for (int i = 0; i < str.size(); ++i) {
        int cnt = count(str.begin(), str.end(), str[i]);
        mx = max(mx, cnt);
    }
    return mx;
}

string SearchingChallenge(string str) {
    vector<int> counts;
    vector<string> res = splitString(str);
    bool check = true;
    int mx = 0, temp = 0, idx;
    for (int i = 0; i < res.size(); ++i) {

        temp = maxCount(res[i]);
        if (temp != 1) check = false;
        if (temp > mx) {
            mx = temp;
            idx = i;
        }
        counts.push_back(temp);
    }

    if (check)
        return "-1";
    else
        return res[idx];

}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    cout << SearchingChallenge("Geeks for Gooks") << endl;

    return 0;
}