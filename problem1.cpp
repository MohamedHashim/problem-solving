    #include<bits/stdc++.h>
    #include<iostream>
    using namespace std;
    int main() {
      int n;
      unordered_map<int,int>::iterator itr;
      vector<pair<int,int>> vec;
      unordered_map<int,int> res;
      int i=0;
      while(scanf("%d", &n) !=EOF){
        // vec.push_back(make_pair(n,1));
        // int cnt= find(vec.begin(),vec.end(),n)!=vec.end()?count(vec.begin(),vec.end(),n):1;
        // int cnt;
        // if(find(vec.begin(),vec.end(),n)!=vec.end())
        int cnt= find(vec.begin(),vec.end(),n)!=vec.end()?count(vec.begin(),vec.end(),n)+1:1;
        // else
          // cnt=1;
        
        // cout<<">>> "<<cnt<<endl;
        // vec.push_back(n);
        res[n]=cnt;
        // map[i][n]++;
        // i++;
      }
      // remove_vec(vec);
      // itr= unique(vec.begin(),vec.end());
      // vec.resize(distance(vec.begin(),vec.end()));
      //for(int i=0;i<vec.size();i++){
      //  cout<<">>vec>>>  "<<vec[i].first<<"    "<<vec[i].second<<endl;
      //}
      // cout<<"...."<<res.size()<<endl;
      for(itr = res.begin(); itr!=res.end();itr++){
        cout<<(*itr).first <<"   "<<(*itr).second<<endl;
      }
    return 0;
}


    // int n,m,ans,x,min,max;
    //     deque<int>dq;
    //     deque<int>::iterator it;
    //     cin>>n>>m;
    //     for (int i = 0; i < m; ++i) {
    //         cin>>x;
    //         dq.push_back(x);
    //     }
    //     sort(dq.begin(),dq.end());
    //     int i=0;
    //     int mini=100000;
    //       while(i<=m-n) {
    //               min = *min_element(dq.begin(), dq.begin() + n);
    //               max = *max_element(dq.begin(), dq.begin() + n);
    //               ans = max - min;
    //               if (ans < mini)
    //                   mini = ans;
    //               dq.pop_front();
    //               i++;
    //       }
    //     cout<<mini<<endl;
    //             cout<<"AAAAA"<<endl;

    //     return 0;
  
  
  
    // }