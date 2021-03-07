#include"bits/stdc++.h"
#include<iostream>

using namespace std;

const int N = 1e5 + 7;

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    long long n;
    cin >> n;
    if (n % 2 == 0)
        cout << n / 2;
    else
        cout << -(n+1) / 2;
    return 0;
}
