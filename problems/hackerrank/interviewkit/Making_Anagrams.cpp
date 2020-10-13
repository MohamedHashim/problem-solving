//
// Created by Mohamed Hashim on 10/14/2020.
//
#include "bits/stdc++.h"

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a << endl << b << endl;
    stack<char> x;
    stack<char> y;
    int ans = 0;
    for (char &i : a) {
        x.push(i);
    }
    for (char &j : b) {
        y.push(j);
    }
    for (int i = 0; i < a.size() + b.size(); ++i) {
        if (!x.empty() && !y.empty()) {
            if (x.top() == y.top()) {
                x.pop();
                y.pop();
            } else if (x.top() > y.top()) {
                cout << "remove top x>>  " << x.top() << endl;
                ans++;
                x.pop();
            } else if (y.top() > x.top()) {
                ans++;
                cout << "remove top y>>  " << y.top() << endl;
                y.pop();
            }
        } else
            break;
    }
    ans += max(x.size(), y.size());
    return ans;
}

int main() {
//    ofstream fout(getenv("OUTPUT_PATH"));
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

//    fout.close();

    return 0;
}

