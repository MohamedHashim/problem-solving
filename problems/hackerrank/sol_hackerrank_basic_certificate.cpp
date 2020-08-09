//
// Created by Mohamed Hashim on 8/9/2020.
//
#include "../../bits/stdc++.h"

using namespace std;


/*
 * Complete the 'decryptPassword' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string decryptPassword(string s) {
    string res;
    string digits;
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i]) && islower(s[i + 1]) && s[i + 2] == '*') {
            res.push_back(s[i + 1]);
            res.push_back(s[i]);
            i += 2;
        } else if (isdigit(s[i]) && s[i] != '0') {
            digits.push_back(s[i]);
        } else if (s[i] == '0') {
            res.push_back(digits.back());
            digits.pop_back();
        } else
            res.push_back(s[i]);
    }
    return res;
}

int main() {
    decryptPassword("51Pa*0Lp*0e");
    return 0;
}