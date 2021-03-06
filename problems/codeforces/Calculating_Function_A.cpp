#include"bits/stdc++.h"
#include<iostream>

using namespace std;

const int N = 1e5 + 7;


int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    int n, cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2!=0)
            i=i*-1;
        cnt+=i;
    }
    cout<<cnt;
    return 0;
}
