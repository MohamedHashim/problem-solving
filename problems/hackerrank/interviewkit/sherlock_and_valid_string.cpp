//
// Created by Mohamed Hashim on 10/13/2020.
//

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    if (s.size() == 1)
        return "YES";
    else {
        sort(s.begin(), s.end());
        cout << s << endl;
        vector<int> res;
        vector<int> temp;
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i + 1])cnt++;
            else {
                res.push_back(cnt);
                cnt = 1;
            }
        }
        int ans = 1, x;
        bool check = true;
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size() - 1; ++i) {
            cout << res[i] << endl;
            if (res[i] == res[i + 1])
                ans++;
            else break;
        }
        temp = res;
        vector<int>::iterator ip;
        ip = unique(temp.begin(), temp.end());
        temp.resize(distance(temp.begin(), ip));
        if (temp.size() > 2)
            return "NO";
        else {
            cout << "total " << ans << endl;
            x = res.size() - ans;
            if (ans == res.size() || x == 1 && res.back() - res[res.size() - 2] == 1 ||
                ans == 1 && res[1] - res[0] == 1 || ans==1)
                return "YES";
            else {
                return "NO";
            }
        }
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
