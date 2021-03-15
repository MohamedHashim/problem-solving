#include"bits/stdc++.h"
#include<iostream>
 
using namespace std;
 
int main() {
 
	int n,cnt=1; 
    string str;
    string ls[100001];
    
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>str;
    	ls[i]= str;
    }
    for(int i=0;i<n-1;i++){
    	if(ls[i]!=ls[i+1])
    		cnt++;
    }
    cout<<cnt;
    return 0;
}