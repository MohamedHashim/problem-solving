//
// Created by Mohamed Hashim on 8/9/2020.
//
#include"../../bits/stdc++.h"
#include<iostream>

using namespace std;

int longestSubarray(vector<int> arr) {

    stack<int> s;
    int mx, tmp = 0;
    for (int j = 0; j < arr.size(); ++j) {
        while (!s.empty())
            s.pop();
        int cnt = 1, cnt1 = 1, cnt2 = 1;
        s.push(arr[j]);
        for (int i = j + 1; i < arr.size() - 1; i++) {
            if (arr[i] == s.top()) {
                s.push(arr[i]);
                cnt1++;
            } else if (arr[i] != s.top() && cnt == 2)
                break;
            else if (arr[i] != s.top()) {
                s.push(arr[i]);
                cnt++;
                tmp = cnt1;
                cnt1 = cnt2;
            }
        }
        int sz = s.size();
        if (tmp != cnt1)
            sz = min(cnt1, cnt2);
        mx = max(sz, mx);
    }
    return mx;
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    vector<int> vec={1,2,3,4,5,9};
    cout << longestSubarray(vec) << endl;

    return 0;
}
